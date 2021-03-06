#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void matrice_triangle(long double matrice[],int size);

int main(){

    int taille_matrice = 2000;
    int taille_tab = taille_matrice*taille_matrice;
    long double * tab = malloc(sizeof(long double) * taille_tab);
    
    srand (time (NULL));

    long double it = 0;
    for(int i = 0;i<taille_tab;i++){
        tab[i] = rand() % 10;
    }
    /*
    for(int i = 0;i<taille_tab;i++){
        printf("%.0Lf ",tab[i]);
        if(i%taille_matrice == taille_matrice-1){printf("\n");}
    }
    */

    clock_t start, finish;
    start = clock();
    double duration;

    matrice_triangle(tab,taille_matrice);
    printf("\n");

    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );

    return 0;
}

void matrice_triangle(long double matrice[],int size){
    if(matrice[0] == 0){
        for(int i = 0;i<size*size;i+=size){
            printf("%.0Lf \n\n\n",matrice[i]);
            if((int)matrice[i]%size != 0){
                for(int j = 0;j<size;j++,i++){
                    matrice[j] = matrice[j] + matrice[i];
                }
                break;
            }
        }
    }
    printf("\n\n\n\n\n");
    
    for(int i = 0;i<size-1;i++){
        if(matrice[i+i*size] == 0){
            printf("\noui\n");
            for(int id = i*size;id<size*size;id+=size){
                if(matrice[id+i] != 0){
                    for(int j = 0;j<size;j++){
                        matrice[i*size+j] = matrice[i*size+j] + matrice[id+j];
                    }
                    break;
                }
            }
        }
        long double denominateur = matrice[i+i*size];
        for(int j = 1;j<size-i;j++){
            if(matrice[j*size+i+i*size] == 0){continue;}
            long double numerateur = matrice[j*size+i+i*size];
            long double facteur = numerateur/denominateur;
            for(int k = 0;k<size;k++){
                matrice[j*size+k+i*size] -= matrice[i*size+k] * facteur;
            }
        }
    }
    
    /*
    for(int i = 0;i<taille_tab;i++){
        printf("%.0Lf ",tab[i]);
        if(i%taille_matrice == taille_matrice-1){printf("\n");}
    }
    */
    
    long double res = 1;
    printf("\n\n\n\n\n");

    for(int i = 0;i<size;i++){
        res *=matrice[i+i*size];
        printf("%.0Lf * ",matrice[i+i*size]);
    }
    printf("\n\n\n\n\n");
    printf("R??sultat final : Determinant = %.0Lf",res);

}
