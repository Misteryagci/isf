%Exercice 8 - Tests
function []=atest()
  printf("Analyse de l'image rectangle1-0.pgm");
  analyse('rectangle1-0.pgm')
  analyse('rectangle1-20.pgm')
  analyse('rectangle1-50.pgm')
  analyse('rectangle1-100.pgm')
  analyse('rectangle2+0.pgm')
  analyse('rectangle2+15.pgm')
  analyse('rectangle2+30.pgm')
  analyse('rectangle2+70.pgm')
  analyse('poisson.pgm')
  analyse('avion1.pgm')
  analyse('avion2.pgm')
  analyse('visage.pgm')
  analyse('pise.pgm')
 endfunction 