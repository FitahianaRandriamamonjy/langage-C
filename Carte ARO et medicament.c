#include <stdio.h>

#define MAX 50

typedef struct {
    char NumSC[20];
    char NomAss[20];
    char PrenomAss[20];
    char DateNaissAss[11];
    float PourcentRemb;
} CarteARO;

typedef struct {
    char NomMedic[20];
    float PrixMedic;
    int QteMedic;
} Medicament;

int main() {
    CarteARO carte;
    Medicament Medoc[MAX];
    int nbremedic, i;
    float montantTotal = 0;
    float remboursement;
    float montantPayer;

    printf("==== Saisie de la Carte ARO ====\n");

    printf("Numero de securite sociale de l'assure : ");
    scanf("%s", carte.NumSC);
    printf("Nom de l' assure : ");
    scanf("%s", carte.NomAss);
    printf("Prenom de l' assure : ");
    scanf("%s", carte.PrenomAss);
    printf("Date naissance de l'assure (jj/mm/aaaa) : ");
    scanf("%s", carte.DateNaissAss);
    printf("Pourcentage de remboursement (ex: 0.8) : ");
    scanf("%f", &carte.PourcentRemb);

    printf("\n==== Carte ARO ====\n");
    printf("Num SC : %s\n", carte.NumSC);
    printf("Nom : %s\n", carte.NomAss);
    printf("Prenom : %s\n", carte.PrenomAss);
    printf("Date naissance : %s\n", carte.DateNaissAss);
    printf("Pourcentage remboursement : %.2f\n", carte.PourcentRemb);

    printf("\nNombre de medicaments : ");
    scanf("%d", &nbremedic);

    for(i=0; i<nbremedic; i++) {
        printf("\n==== Medicament %d ====\n", i+1);

        printf("Nom medicament : ");
        scanf("%s", Medoc[i].NomMedic);
        printf("Prix unitaire : ");
        scanf("%f", &Medoc[i].PrixMedic);
        printf("Quantite (nb boites) : ");
        scanf("%d", &Medoc[i].QteMedic);

        montantTotal += Medoc[i].PrixMedic * Medoc[i].QteMedic;
    }
    remboursement = montantTotal * carte.PourcentRemb;
    montantPayer = montantTotal - remboursement;

    printf("\n==== RESULTAT ====\n");
    printf("Montant total ordonnance : %.2f\n", montantTotal);
    printf("Montant remboursement : %.2f\n", remboursement);
    printf("Montant a payer : %.2f\n", montantPayer);
    return 0;
}
