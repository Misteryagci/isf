#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <math.h>
#include <complex.h>
#include <fftw3.h>

#define SAMPLING_RATE 1800.0
#define CHANNELS_NUMBER 1
#define N 16384
#define real double


typedef real frame[N];
typedef complex spectrum[N];

/* input */

static char *SOUND_FILE_NAME_READ = "tmp-in.raw";

static real cache_in[N/2];

static real cache_out[N/2];
static fftw_plan plan;

fftw_complex data_in[N];
fftw_complex data_out[N];

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


//DFT = Discret Fourrier Tranformation (Transformée de Fourrier discrète)
//Cette fonction calcule la transformé de fourrier discrète

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

//Permet d'ouvrir une fichier son à analyser
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


//Permet de fermer le fichier ouverte
void
sound_file_close_read (FILE *fp)
{
  assert (fp);

  fclose (fp);

  
  unlink (SOUND_FILE_NAME_READ);
}

//Permet de lire une fichier son 
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

int main (int argc, char* argv[])
{	
	  FILE *input, *output;

	//tableau des amplitudes
	double amp[N];
	//Temporal
	frame s;
	complex S[N];
	double phs[N];

	frame x_axis;
	//Exemple sur un signal musical
	//Ouverture de fichier flux1.wav
	FILE* flux1 = sound_file_open_read("./flux1.wav");

	int i;
	int aux [8];
	//lecture du fichier ouvert 
	while (sound_file_read(flux1,s)) {
		for (i=0 ; i < N ; i++)
		{
		//x_axis[i] = i/SAMPLING_RATE);
		x_axis[i] = (i*SAMPLING_RATE)/N;	// dft initialisation de l'abscisse
                 data_in[i]=s[i];
		}
      	/* ANALYSIS */
      	sound_file_write (s, output);
      	// transformée de Fourier discrète
		dft(s, S);
		cartesian_to_polar(S, amp, phs);
	}

	for (i=0;i<N;i++)
	{
		printf("%d\n",amp[i]);
		if (amp[i]>18000)
		{
			printf("Point max");
		}
	}

}





