#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//time ./Methode_simple > /dev/null
//
// pour une matrice de 10x10
//
//real    0m1,568s
//user    0m1,517s
//sys     0m0,049s
//

//time ./Methode_simple > /dev/null
//
// pour une matrice de 11x11
//
//real    0m17,513s
//user    0m16,975s
//sys     0m0,516s
//

// pour une matrice de 20x20 ça devrait prendre environ 32000 ans.
// ça ne semble par être la bonne méthode pour une matrice 100x100 ou 1000x1000

int calcul_matrice_2x2(int matrice[]);
int repartition_matrice(int matrice[],int size);
int my_rand (void);

int resultat_global = 0;

int main(){
    int taille_matrice = 11;
    int taille_tab = taille_matrice*taille_matrice;
    int * tab = malloc(sizeof(int) * taille_tab);
    
    srand (time (NULL));
    for(int i = 0;i<taille_tab;i++){
        tab[i] = rand() % 10;
    }

    for(int i = 0;i<taille_tab;i++){
        
        printf("%d ",tab[i]);
        if(i%taille_matrice == taille_matrice-1){
            printf("\n");
        }
    }

    printf("\n");

    printf("Res : %d\n\n",repartition_matrice(tab,taille_matrice));
    printf("Determinant calculé : %d\n", resultat_global);
    return 0;
}

int my_rand (void)
    {
    return (rand ());
    }

int  calcul_matrice_2x2(int matrice[]){
    
    for(int i = 0;i<4;i++){
        printf("%d ",matrice[i]);
        if(i%2 == 2-1){
            printf("\n");
        }
    }
    printf("\n");

    int res = (matrice[0] * matrice[3]) - (matrice[1] * matrice[2]);
    return res;
}

int repartition_matrice(int matrice[],int size){

    for(int i = 0;i<size*size;i++){
        printf("%d ",matrice[i]);
        if(i%size == size-1){
            printf("\n");
        }
    }
    // on cherche la longueur de la matrice passée en argument
    // Si la matrice est de longueur 3, on calcule directement les 3 matrice 2x2.
    // Si la matrice est de longueur n superieur à 3, on calcule ses n-1 sous matrice de taille (n-1)x(n-1)
    printf("\n\n\n");
    if(size == 3){
        int res_local = 0;

        for(int a = 0;a<3;a++){
            int  * sous_matrice = malloc(sizeof(int) * 4);
            int coef = 0;

            int id = 0;
            for(int i = 0;i<9;i++){
                if(i == a){
                    coef = matrice[i];
                    continue;
                }
                else if(i < 3){continue;}
                else if(i%3 == a){continue;}
                else{
                    sous_matrice[id] = matrice[i]; 
                    id+=1;
                }
            }
            if(a % 2 == 0){
                res_local += coef * calcul_matrice_2x2(sous_matrice);
            }
            else{
                res_local += (coef * -calcul_matrice_2x2(sous_matrice));
            }
        }
        return res_local;
    }
    else{
        int res_local = 0;
        for(int a = 0;a<size;a++){
            int  * sous_matrice = malloc(sizeof(int) * size*size);
            int coef = 0;

            int id = 0;
            for(int i = 0;i<size*size;i++){
                if(i == a){
                    coef = matrice[i];
                    continue;
                }
                else if(i < size){continue;}
                else if(i%size == a){continue;}
                else{
                    sous_matrice[id] = matrice[i]; 
                    id+=1;
                }
            }
            if(a % 2 == 0){
                res_local += coef * repartition_matrice(sous_matrice,size-1);
            }
            else{
                res_local += (coef * -repartition_matrice(sous_matrice,size-1));
            }
        }
        return res_local;
    }
}
