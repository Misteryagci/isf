#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <math.h>
#include <complex.h>
#include <fftw3.h>
#include "gnuplot_i.h"

#define SAMPLING_RATE 44100.0
#define CHANNELS_NUMBER 1
#define N 16384
#define real double

typedef real frame[N];
typedef complex spectrum[N];

/* input */

static char *SOUND_FILE_NAME_READ = "tmp-in.raw";

static real cache_in[N/2];

static gnuplot_ctrl *h = NULL;

static fftw_plan plan;

fftw_complex data_in[N];
fftw_complex data_out[N];




FILE *
sound_file_open_read (char *sound_file_name)
{
#define MAX_CMD 256
  char cmd[MAX_CMD];

  assert (sound_file_name);

  snprintf (cmd, MAX_CMD,
	    "sox %s -c %d -r %d -e signed-integer -b 16 %s",
	    sound_file_name,
	    CHANNELS_NUMBER, (int)SAMPLING_RATE, SOUND_FILE_NAME_READ);

  system (cmd);

  bzero (cache_in, N/2*sizeof(real));

  return fopen (SOUND_FILE_NAME_READ, "rb");
}

void
sound_file_close_read (FILE *fp)
{
  assert (fp);

  fclose (fp);

  
  unlink (SOUND_FILE_NAME_READ);
}

int
sound_file_read (FILE *fp, frame s)
{
  int result;

  int i;

  static short tmp[N/2*CHANNELS_NUMBER];

  assert (fp && s);

  for (i=0; i<N/2; i++)
    {
      s[i] = cache_in[i];
    }

  bzero (tmp, N/2*CHANNELS_NUMBER*sizeof(short));
  result = fread (tmp, sizeof(short), N/2*CHANNELS_NUMBER, fp);

  for (i=0; i<N/2; i++)
    {
      cache_in[i] = s[N/2+i] = tmp[i*CHANNELS_NUMBER] / 32768.0;
    }

  return (result == N/2);
}

/* output */

static char *SOUND_FILE_NAME_WRITE = "tmp-out.raw";
static char *sound_file_name_write = "out.wav";

static real cache_out[N/2];

FILE *
sound_file_open_write (void)
{
  bzero (cache_out, N/2*sizeof(real));

  return fopen (SOUND_FILE_NAME_WRITE, "wb");
}

void
sound_file_close_write (FILE *fp)
{
#define MAX_CMD 256
  char cmd[MAX_CMD];

  assert (fp);

  fclose (fp);

  snprintf (cmd, MAX_CMD,
	    "sox -c %d -r %d  -e signed-integer -b 16 %s %s",
	    CHANNELS_NUMBER, (int)SAMPLING_RATE, SOUND_FILE_NAME_WRITE,
	    sound_file_name_write);

  system (cmd);

  unlink (SOUND_FILE_NAME_WRITE);
}

void
sound_file_write (frame s, FILE *fp)
{
  int i;

  static short tmp[N/2*CHANNELS_NUMBER];

  assert (fp && s);

  for (i=0; i<N/2; i++)
    {
      real v = s[i] + cache_out[i];
      short _s = (v < -1) ? -32768 : (v > 1) ? 32767 : (short) (v * 32767);

      cache_out[i] = s[N/2+i];

      int channel;

      for (channel=0; channel<CHANNELS_NUMBER; channel++)
	{
	  tmp[i*CHANNELS_NUMBER+channel] = _s;
	}
    }

  fwrite (tmp, sizeof(short), N/2*CHANNELS_NUMBER, fp);
}


/****************************/
void plot_init() 
{
	h = gnuplot_init();
	gnuplot_setstyle (h, "lines");

}

void dft (double s[N], complex S[N])
{
	int m,n;

	for(m = 0 ; m < N ; m++)
	{
		S[m]=0;
		for(n = 0 ; n < N ; n++)
		{
			S[m]+=s[n]*cexp(-I*2*M_PI/N*n*m);
		}
	}
}

void cartesian_to_polar (complex S[N], double amp[N], double phs[N])
{
	int i;

	for (i = 0 ; i < N ; i++)
	{
		/* Calcule du module et de la phase */
		amp[i] = cabs(S[i]);
		phs[i] = carg(S[i]);
	}
}

  /* init */
  void fft_init (){
       plan = fftw_plan_dft_1d(N, data_in, data_out, FFTW_FORWARD, FFTW_ESTIMATE);
           }

    void fft_exit() {
       fftw_destroy_plan (plan);
    }

    void fft_execute(){
      
                 fftw_execute (plan);
     }
 
int
main (int argc, char *argv[])
{
	int i = 0;

  FILE *input, *output;

  /* temporal */
  frame s;
	// déclaration des tableaux
	frame x_axis;
	complex S[N];
	double amp[N];
	double phs[N];

  assert (sizeof(short) == 2);

  if (argc != 2)
    {
      fprintf (stderr, "usage: %s <soundfile>\n", argv[0]);
      exit (EXIT_FAILURE);
    }


  input = sound_file_open_read (argv[1]);
  output = sound_file_open_write ();
// initialisation du graphe
  	  plot_init();  


         fft_init();

  /* process */
  while (sound_file_read (input, s))
    {
	
	for (i=0 ; i < N ; i++)
	{
		//x_axis[i] = i/SAMPLING_RATE);
		x_axis[i] = (i*SAMPLING_RATE)/N;	// dft initialisation de l'abscisse
                 data_in[i]=s[i];
	}
      /* ANALYSIS */
      sound_file_write (s, output);

	// transformée de Fourier discrète
	//dft(s, S);
	//cartesian_to_polar(S, amp, phs);

        fft_execute();


          cartesian_to_polar(data_out, amp, phs);
	/* AFFICHAGE */
      	gnuplot_resetplot(h);
	gnuplot_plot_xy (h, x_axis, amp, N/2, "son");
	//sleep(1);
    }

  /* exit */

  sound_file_close_write (output);
  sound_file_close_read (input);
	
  //fftw_destroy_plan(plan);

  fft_exit ();

  exit (EXIT_SUCCESS);

  return 0;
}
