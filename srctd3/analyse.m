function [i,s,mi,mj,sii,sij,sji,sjj,valeur_propres_mat_diag,mat_passage,ratio,theta]=analyse(nf)
  % nom_fichier : nom du fichier image au format pgm (en noir et blanc)
  [I,ngmax]=imload(nf);
  i=I;
  printf ("La somme des valeurs de la matrice correspond à l'image %s est %d\n",nf,sum(sum(I)))
  s=sum(sum(I));
  [nbligne,nbcol]=size(I);
  %calcul des premiers moments de la matrice I
  mi = 0;
  %parcours la matrice element par element
  for i = 1:nbligne
    for j = 1:nbcol
      mi=mi+I(i,j)*i;
    endfor
  endfor
  mi=mi/s; %C'est le moment de la matrice par rapport à i
  mj = 0;
  %parcours la matrice element par element
  for i = 1:nbligne
    for j = 1:nbcol
      mj=mj+I(i,j)*j;
    endfor
  endfor
  mj=mj/s; %C'est le moment de la matrice par rapport à j
   
  %Calcul des deuxièmes moments centrés de la matrice M
  sii = 0;
  %parcours la matrice element par element
  for i = 1:nbligne
    for j = 1:nbcol
      sii=sii+I(i,j)*((i-mi)^2);
    endfor
  endfor
  sii=sii/s; %C'est le moment centré de la matrice par rapport à ii
  
  sij = 0;
  %parcours la matrice element par element
  for i = 1:nbligne
    for j = 1:nbcol
      sij=sij+I(i,j)*((i-mi)*(j-mj));
    endfor
  endfor
  sij=sij/s; %C'est le moment centré de la matrice par rapport à ij
  
  sji=sij;  
   
  sjj = 0;
  %parcours la matrice element par element
  for i = 1:nbligne
    for j = 1:nbcol
      sii=sii+I(i,j)*((j-mj)^2);
    endfor
  endfor
  sjj=sjj/s; %C'est le moment centré de la matrice par rapport à jj
  I = I / ngmax;
   printf ("La somme des valeurs de la matrice dont les valeurs sont ramenés entre 0 et 1, correspond à l'image %s est %d\n",nf,sum(sum(I)))
  if mean(mean(I)) >= 0.5
    I= 1-I;
   end
  I;
  %La matrice qu'on a obtenu à la fin est identique que la matrice qu'on avait
  %ramené ses valeurs entre 0 et 1 parce que la moyenne des valeurs de cette matrice
  %est inférieur à 0.5 du coup ça ne rentre pas dans le if. 
  
  C=[sii,sij;sji,sjj];
  [V,l] = eig(C);
  valeur_propres_mat_diag = l;
  mat_passage = V
  ratio = sqrt(max(max(valeur_propres_mat_diag)) - min(min(valeur_propres_mat_diag)));
  y=mat_passage(1,1);
  x=mat_passage(2,1);
  theta = atan2(y,x)
 endfunction


