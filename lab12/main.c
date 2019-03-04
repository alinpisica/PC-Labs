#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Produs.h"

void creare_fisier(char *nume_fisier) {
    srand(time(NULL));
    FILE *fileToWriteInto;
    Produs prod;
    int x, cant;
    float pretProdus; 
    char numeProdus[15];
    char xToString[7];
    if ((fileToWriteInto = fopen(nume_fisier, "w")) != NULL) {
        for (int i = 0; i < 100; i++) {
            strcpy(prod.nume_produs, "Produs");
            x = rand();
            sprintf(xToString, "%d", x);
            strcat(prod.nume_produs, xToString);
            prod.cantitate = x % 100;
            prod.pret_produs = (x <= 100 ? x : x % 100);
            fwrite(&prod, sizeof(Produs), 1, fileToWriteInto);
        }
        fclose(fileToWriteInto);
    }
}

void afisare_ecran(char *nume_fisier) {
    Produs *p = malloc(sizeof(Produs));
    FILE *fileToReadFrom;

    if ((fileToReadFrom = fopen(nume_fisier, "r")) != NULL) {
        while (fread(p, sizeof(Produs), 1, fileToReadFrom)) {
            printf("%s | %d | %f\n", p->nume_produs, p->cantitate, p->pret_produs);
        }
        fclose(fileToReadFrom);
    }
}

int compare(const void *p1, const void *p2) {
    const Produs *elem1 = p1;
    const Produs *elem2 = p2;

    return strcmp(elem1->nume_produs, elem2->nume_produs);
}

void sortare_articole(char *nume_fisier) {
    Produs *p = malloc(sizeof(Produs));
    FILE *fileToReadFrom;
    FILE *fileToWriteInto;
    int cnt = 0;
    Produs produse[101];
    Produs *aux;

    if ((fileToReadFrom = fopen(nume_fisier, "r")) != NULL) {
        while (fread(p, sizeof(Produs), 1, fileToReadFrom)) {
            strcpy(produse[cnt].nume_produs, p->nume_produs);
            produse[cnt].cantitate = p->cantitate;
            produse[cnt].pret_produs = p->pret_produs;
            cnt++;
        }
        fclose(fileToReadFrom);
    }

    qsort(produse, 100, sizeof(Produs), compare);

    if ((fileToWriteInto = fopen(nume_fisier, "w")) != NULL) {
        for (int i = 0; i < 100; i++) {
            fwrite(&produse[i], sizeof(Produs), 1, fileToWriteInto);
        }
        fclose(fileToWriteInto);
    }
}

void gaseste_produs(char *nume_fisier) {
    char prodnam[30];
    printf("\nIntrodu numele produsului: ");
    scanf("%s", prodnam);
    FILE *fileToReadFrom;
    Produs *p = malloc(sizeof(Produs));
    int ok = 1;
    if ((fileToReadFrom = fopen(nume_fisier, "r")) != NULL) {
        while (fread(p, sizeof(Produs), 1, fileToReadFrom)) {
            if (strcmp(p->nume_produs, prodnam) == 0) {
                printf("Produsul a fost gasit!\n");
                printf("Nume: %s\n", p->nume_produs);
                printf("Cantitate: %d\n", p->cantitate);
                printf("Pret: %f\n", p->pret_produs);
                ok = 0;
            }
        }
        fclose(fileToReadFrom);
    }
    if (ok == 1) {
        printf("Produsul nu a fost gasit!\n");
    }
    return ;
}

void inlocuieste_produs(char *nume_fisier) {
    char prodnam[30];
    printf("\nIntrodu numele produsului: ");
    scanf("%s", prodnam);
    FILE *fileToReadFrom;
    FILE *fileToWriteInto;
    Produs *p = malloc(sizeof(Produs));
    int ok = 1;
    if ((fileToReadFrom = fopen(nume_fisier, "r")) != NULL) {
        fileToWriteInto = fopen("aux.txt", "w");
        while (fread(p, sizeof(Produs), 1, fileToReadFrom)) {
            if (strcmp(p->nume_produs, prodnam) == 0) {
                printf("Produsul a fost gasit!\n");
                printf("Nume: %s\n", p->nume_produs);
                printf("Cantitate: %d\n", p->cantitate);
                printf("Pret: %f\n", p->pret_produs);
                char newName[30];
                int quant;
                float price;
                printf("Introdu noile date: \n");
                printf("Nume: "); scanf("%s", newName);
                printf("Cantitate: "); scanf("%d", &quant);
                printf("Pret: "); scanf("%f", &price);
                strcpy(p->nume_produs, newName);
                p->cantitate = quant;
                p->pret_produs = price;
                ok = 0;
            }
            fwrite(p, sizeof(Produs), 1, fileToWriteInto);
        }
        fclose(fileToWriteInto);
        fclose(fileToReadFrom);
    }
    remove(nume_fisier);
    rename("aux.txt", nume_fisier);
    if (ok == 1) {
        printf("Produsul nu a fost gasit!\n");
    }
    return ;
}

int main(int argc, char *argv[]) {
    creare_fisier("Sal.txt");
    afisare_ecran("Sal.txt");
    sortare_articole("Sal.txt");
    afisare_ecran("Sal.txt");
    gaseste_produs("Sal.txt");
    inlocuieste_produs("Sal.txt");
    afisare_ecran("Sal.txt");
    return 0;
}
