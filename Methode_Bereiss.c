#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

long double Determinant_Bareiss(long double tab[],int taille_matrice);
int main(){
    int taille_matrice = 1500;
    int taille_tab = taille_matrice*taille_matrice;
    long double * tab = malloc(sizeof(long double) * taille_tab);
    
    tab[0] = 0;

    //long double it = 0;
    while(tab[0] == 0){
        srand (time (NULL));

        for(int i = 0;i<taille_matrice;i++){
            for(int j = 0;j<(taille_matrice);j++){
                
                    tab[j+(i*taille_matrice)] = rand() % 10;
                    //pour tester avec une même matrice si on trouve le même résultat avec la méthode par triangulation.
                    //tab[j+(i*taille_matrice)] = (long double)(((int)it)%20+1);
                    //it+=2.3;
            }
        }
    }
    /*
    for(int i = 0;i<taille_matrice;i++){
            for(int j = 0;j<taille_matrice;j++){

                printf("%.0Lf ",tab[j+(i*taille_matrice)]);
            }
            printf("\n");
    }
    */
    
    clock_t start, finish;
    start = clock();
    double duration;

    Determinant_Bareiss(tab,taille_matrice);
    printf("\n");

    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    

}

long double Determinant_Bareiss(long double tab[],int taille_matrice){
    int colonne = taille_matrice;
    int ligne = taille_matrice;
    for(int i = 0;i<ligne;i++){
        
        long double pivot = tab[i + i*taille_matrice];
        if(pivot == 0){
            printf("0");
            return 0;
        }


        for(int j = 0;j<ligne;j++){
            if(i != j){
                for(int k = i+1;k < ligne;k++){
                    long double diviseur = 1.0;
                    if(i > 0){
                        diviseur = tab[i-1 + ((i-1)*taille_matrice)];
                        
                    }
                    long double a = pivot * tab[j+ (k*taille_matrice)];
                    long double b = tab[j + (i*taille_matrice)] * tab[i + (k*taille_matrice)];
                    long double ab = a - b; 
                    if(isnan(a)) { printf("a is nan\n"); /*exit(1);*/ }                   
                    if(isnan(b)) { printf("b is nan\n");/*exit(1);*/ }
                    if(isnan(ab)) { printf("ab is nan %Lf - %Lf\n",a,b);/*exit(1);*/ }
                    long double c;
                    if(ab == 0.0 && diviseur == 0.0)
                        { 
                            printf("ab is 0.0 and disiseur is 0.0 \n");  
                           c= 0.0;
                        }
                    else
                        c = ab/diviseur;
                    if(isnan(c)) {
                        printf("c is nan a(%Lf) b(%Lf) ab(%Lf) diviseur(%Lf) \n",a,b,ab,diviseur);/*exit(1);*/
                        return 0;
                    }
                    tab[j + (k*taille_matrice)] = c;
                }
            }
        }
    }
    
    printf("\n\n\n");
    /*
    for(int i = 0;i<taille_matrice;i++){
            for(int j = 0;j<taille_matrice;j++){

                printf("%.0Lf ",tab[j+(i*taille_matrice)]);
            }
            printf("\n");
    }
    */
    


    printf("Le determinant est : %.0Lf",tab[taille_matrice-1 + ((taille_matrice-1)*(taille_matrice))]);
    
}
