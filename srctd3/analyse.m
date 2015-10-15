    function [ngmax,s,mi,mj,sii,sjj,sij,ratio,theta,lambda]=analyse(nf)
  % nom_fichier : nom du fichier image au format pgm (en noir et blanc)
  [I,ngmax]=imload(nf);
  I=I/max(max(I));
  if mean(mean(I)) >= 0.5
     I=1-I;
  endif
  s=sum(sum(I))
  [nbl,nbc]=size(I);
  mi=0;
  for i=1:nbl
    for j=1:nbc
        mi=I(i,j)*i+mi;
        endfor
        endfor
        mi=mi/s
      mj=0;  
  for i=1 :nbl
    for j=1: nbc
        mj=I(i,j)*j+mj;
        endfor
        endfor
        mj=mj/s
        
   sii=0;
     for i= 1:nbl
      for j= 1:nbc
        sii=I(i,j)*((i-mi)^2)+sii;  
       endfor
      endfor
     sii=sii/s 
     
      sij=0;
     for i= 1:nbl
      for j= 1:nbc
        sij=(I(i,j)*(i-mi)*(j-mj))+sij;  
       endfor
      endfor
     sij=sij/s 
     sji=sij
     
      sjj=0;
     for i= 1:nbl
      for j= 1:nbc
        sjj=I(i,j)*((j-mj)^2)+sjj;  
       endfor
      endfor
     sjj=sjj/s 
C=[sii,sij;sji,sjj];
[P,D]=eig(C);
H=eig(C);
H
ratio=min(H)/max(H)
ratio=max(H)/min(H)
y=P(2,1)*(-1);
x=P(1,1)*(-1);
theta=atan2(y,x)*180/pi
lambda= [H(1,1),H(2,1)]
 endfunction
