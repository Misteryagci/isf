function [I1,I2,min1,min2,H1,H2,m1,m2,m21,m22,m31,m32]=fonction_tp4(nom_image)
%Exercice 1 Calcul de gradients    
    
   %Obtention de la matrice de l'image et le niveau de gris maximale de l'image
  [I,ngmax]=imload(nom_image); %; pour ne pas afficher les résultats 
  %Calcul les dimensions de la matrice
  [h,l]=size(I);
  %On initialise à la matrice nulle les matrices qu'on va retourner à la fin
  I1=zeros(h,l);
  I2=zeros(h,l);
  %On parcourt la matrice élément par élément 
  for i=1:h 
    for j=1:l
      %On construit la première matrice I1
      if (i<h)
        I1(i,j)= I((i+1),j)-I(i,j);
        %On n'a pas besoin d'initialiser à 0 dans else parce que la matrice à la base est initialisé à 0
      endif
      %On construit la seconde matrice I2
      if (j<l)
        I2(i,j)=I(i,(j+1))-I(i,j);
        %On n'a pas besoin d'initialiser à 0 dans else parce que la matrice à la base est initialisé à 0
      endif
     endfor
  endfor

  %On affiche les images qu'on a obtenu
  %Affichage de premier image qu'on a obtenu
  figure(1)
  K1=I1-min(min(I1))+1;
  K1=ind2gray(K1,gray(512));
  imshow(K1)
  %Affichage de second image qu'on a obtenu
  figure(2)
  K2=I2-min(min(I2))+1;
  K2=ind2gray(K2,gray(512));
  imshow(K2)
  %On calcule les valeurs minimales des chacune des images
  min1=min(min(I1));
  min2=min(min(I2));
  %On modifie les images par rapport à l'énoncé
  I1=I1-min1+1;
  I2=I2-min2+1;
 %Fin de l'exercice 1 

 %Exercice 2 Calcul de l'histogramme
  
  %On initialise à 0 les histogrammes
  H1 = zeros(1,max(max(I1)));
  H2 = zeros(1,max(max(I2)));
  %On parcours les matrices des images élément par élément pour construire les hiostogrammes
  %Parcours de la première matrice 
  for i=1:size(I1,1)
    for j=1:size(I1,2)
      aux=I1(i,j);
      H1(1,aux)++;
    endfor
  endfor
  %Parcours de la seconde matrice
    for i=1:size(I2,1)
    for j=1:size(I2,2)
      H2(1,I2(i,j))=H2(1,I2(i,j))+1;
    endfor
  endfor
  %On normalise les histogrammes
  sum(H1);
  H1=H1/sum(H1); %La somme des valeurs de l'histogramme donne la nombre de pixel de l'image correspondant
  H2=H2/sum(H2);
  figure(3)
  bar(H1)
  figure(4)
  bar(H2)
 %Fin de l'exercice 2
 
 %Exercice 3 Calcul des caractéristiques des nouvelles images
 
 %Calcul du niveau de gris moyen pour I1 et I2 
 m1=0;
 m2=0;
 for k=1:size(H1,2)
  m1=m1+k*H1(1,k);
 endfor
 for k=1:size(H2,2)
  m2=m2+k*H2(1,k);
 endfor 
  
 %Calcul du moment centré d'ordre 2
 m21=0;
 m22=0;
 for k=1:size(H1,2)
  m21=m21+(k-m1)^2*H1(1,k);
 endfor
 for k=1:size(H2,2)
  m22=m22+(k-m2)^2*H2(1,k);
 endfor

 %Calcul d'ine mesure d'uniformité
 m31=0;
 m32=0;
 for k=1:size(H1,2)
  m31=m31+H1(1,k)^2;
 endfor
 for k=1:size(H2,2)
  m32=m32+H2(1,k)^2;
 endfor
 %Fin de l'exercice 3
 
 endfunction
 