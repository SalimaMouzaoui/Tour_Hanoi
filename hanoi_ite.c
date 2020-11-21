# /*******************************************************
#                     les tours de hanoi
#                  ( Algorithme itératif )
# ********************************************************/ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
clock_t debut,fin;

#/******************************************************
#                  Partie Déclarations
# *******************************************************/ 

// On supposera dans ce qui suit qu'il ya au maximum 192 (64*3)  disques 
int t[192];
int n,i,j,k,a,b,c,x,l;

# /******************************************************
#                  Affichage des disques
# ******************************************************/ 
 
aff()
{           
      printf("A: ");
      for(i=1;i<=n;i++)           
      {if(t[i]!=0) printf(" %d ",t[i]);else break;}
      printf("\nB: ");
      for(i=(n+1);i<=(2*n);i++)           
      {if(t[i]!=0) printf(" %d ",t[i]);else break;}
      printf("\nC: ");
      for(i=(2*n)+1;i<=(3*n);i++)           
      {if(t[i]!=0) printf(" %d ",t[i]);else break;}
      printf("\n\n\n");  
            
}

# /******************************************************
#                  Deplacement des disques
# *******************************************************/ 


Hanoi(int n,int i,int j,int k)
{  
          
   while ( (t[1]!=0) || (t[n+1]!=0) ) 
   
   { 
          if ( t[i]>t[k] ) {
		                                                            if(t[k]!=0){k++;}
                                                                    t[k]=t[i]; 
                                                                    t[i]=0; 
                                                                    if((i!=1) && (i!=(2*n)+1) && (i!=n+1)){i--;}
                                                                    aff(); 
                           }                    
          if ( t[i]>t[j] ) { 
                                                                    if(t[j]!=0){j++;}
                                                                    t[j]=t[i];
                                                                    t[i]=0;
                                                                    if((i!=1) && (i!=(2*n)+1) && (i!=n+1)){i--;}
                                                                    aff(); 
                                                                    l=i;i=k;k=j;j=l;						 
                            }
          else {l=i;i=j;j=k;k=l;} 
    }
    end();      
}
end() { }                                     


# /******************************************************
#                   Programme principal
# ******************************************************/ 

main()
{     
      float f;
      printf("\nDonner le nombre de disques :");
      scanf("%d",&n);
      if (n<1)         //Vérification de nombre de disques
      {  
      printf("\nLe nombre doit être >= 1");
      printf("\n\n"); 
      }
      else 
      {
      printf("\n\n");  
      for(i=1;i<=n;i++)  {  t[i]=i;}
      aff();
      a=n; b=n+1; c=(2*n)+1;
      debut=clock();
      Hanoi(n,a,b,c);
      fin=clock();
      f=(float)(fin-debut)/CLOCKS_PER_SEC;
      printf("\t\tLe temps d'execution est : %f\n\n",f);
      }
      system("pause");    
}
