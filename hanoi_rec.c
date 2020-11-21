# /*******************************************************
#                     les tours de hanoi
#                  ( Algorithme r�cursif )
# ********************************************************/ 


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
clock_t debut,fin;

#/******************************************************
#                  Partie D�claration
# *******************************************************/ 


   
int A[64],B[64],C[64];  /* 
                             - A[65],B[65],C[65] sont les tables correspondent aux tiges 
                               A(le d�part), B(l'interm�diaire) et C(la destination)
                             - 65 : le nombre maximum de disques � traiter demand� dans l'exercice
                        */

int i;
int x=0;  // Indice pour parcourir la table A
int y=0;  // Indice pour parcourir la table B
int z=0;  // Indice pour parcourir la table C

# /******************************************************
#                  affichage des disques
# ******************************************************/ 

aff() //afficher l'etat de tableau
{  
   printf("A: ");
   for(i=1;i<=64;i++)           
   {if(A[i]!=0)printf(" %d ",A[i]);}
   printf("\nB: ");
   for(i=1;i<=64;i++)           
   {if(B[i]!=0)printf(" %d ",B[i]);}
   printf("\nC: ");
   for(i=1;i<=64;i++)           
   {if(C[i]!=0)printf(" %d ",C[i]);}
   printf("\n\n\n");
}       

# /******************************************************
#                  Deplacement des disques
# *******************************************************/ 

deplacer(int *d,int *e)
{  if(d==A) 
   {  
      if(e==C){z++;C[z]=A[x];d[x]=0;x--;}// D�placement A -> C
      if(e==B){y++;B[y]=A[x];d[x]=0;x--;}// D�placement A -> B
   }
   if(d==B)  
   {  
      if(e==A){x++;A[x]=B[y];d[y]=0;y--;}// D�placement B -> A 
      if(e==C){z++;C[z]=B[y];d[y]=0;y--;}// D�placement B -> C
   }
   if(d==C)
   {  
      if(e==A){x++;A[x]=C[z];d[z]=0;z--;}// D�placement C -> A
      if(e==B){y++;B[y]=C[z];d[z]=0;z--;}// D�placement C -> B
   }
   aff();
}     

# /******************************************************
#                   fonction hanoi
# ******************************************************/ 

hanoi(int n,int *x,int *y,int *z)
{  
   if (n==1)    // Cas trivial : Dans ce cas on a un seul d�placement 
   {deplacer(x,z);}
   else {
           hanoi(n-1,x,z,y);
           deplacer(x,z);
           hanoi(n-1,y,x,z);
        } 
}

# /******************************************************
#                   Programme principal
# ******************************************************/ 

main()
{  
   float f; 
   int n;
   printf("\nDonner le nombre de disques :");
   scanf("%d",&n);
   if (n<1)         //V�rification de nombre de disques
   {  
      printf("\nLe nombre doit �tre >= 1");
      printf("\n\n"); 
   }
   else 
   {  
      printf("\n\n"); 
      for(i=1;i<=n;i++){A[i]=i;}
      x=n;
      aff();
      printf("\n");  
      debut=clock();   
      hanoi(n,A,B,C);
      fin=clock();
      f=(float)(fin-debut)/CLOCKS_PER_SEC;
      printf("\t\tLe temps d'execution est : %f\n\n",f);
      getchar();    
   } 
   system("PAUSE");
}      
