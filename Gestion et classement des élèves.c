#include <stdio.h>
#include <string.h>

#define N 5
#define M 5

typedef struct {
    char nom[50];
    float notes[M];
    float moyenne;
    int rang;
} Eleve;

int main() {
    Eleve e[N];
    int coef[M] = {1,3,2,4,1};
    int somme_coef = 11;

    for(int i = 0; i < N; i++) {
        printf("Nom de l'eleve %d : ", i+1);
        scanf("%s", e[i].nom);

        float somme = 0;
        for(int j = 0; j < M; j++) {
            printf("Note %d : ", j+1);
            scanf("%f", &e[i].notes[j]);
            somme += e[i].notes[j] * coef[j];
        }
        e[i].moyenne = somme / somme_coef;
    }

    for(int i = 0; i < N-1; i++) {
        for(int j = i+1; j < N; j++) {
            if(e[i].moyenne < e[j].moyenne) {
                Eleve temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        e[i].rang = i + 1;
    }

    printf("\nClassement des eleves :\n");
    printf("%-20s | %10s | %4s\n", "Nom", "Moyenne", "Rang");
    printf("-----------------------------------------------\n");

    for(int i = 0; i < N; i++) {
        printf("%-20s | %10.2f | %4d\n",
           e[i].nom, e[i].moyenne, e[i].rang);
    }

    return 0;
}
