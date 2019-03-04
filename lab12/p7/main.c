#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 4

typedef struct Persoana{
    char* nume;
    char* prenume;
} Persoana;

void serializeaza(Persoana v[], int nrPersoane, char* fileName)
{
    FILE* f = fopen(fileName, "wb");
    
    //TODO! Adauga codul de serializare: ~10 linii
    for (int i = 0; i < nrPersoane; i++) {
        fprintf(f, "%ld %s %ld %s \n", strlen(v[i].nume), v[i].nume, 
                                     strlen(v[i].prenume), v[i].prenume);        
    }

    fclose(f);
}

void deserializeaza(Persoana v[], int nrPersoane, char* fileName)
{
    FILE* f = fopen(fileName, "rb");

    //TODO! Adauga codul de deserializare: ~10 linii
    int len;
    for (int i = 0; i < nrPersoane; i++) {
        fscanf(f, "%d", &len);
        v[i].nume = malloc(len * sizeof(char) + 1);
        fscanf(f, "%s", v[i].nume);
        fscanf(f, "%d", &len);
        v[i].prenume = malloc(len * sizeof(char) + 1);
        fscanf(f, "%s", v[i].prenume);
    }

    fclose(f);
}

int main()
{
    Persoana v[N],w[N];
    char* prenume[N] = { "Eric", "Kyle", "Stan", "Kenny" };
    char* nume[N] = { "Cartman", "Broflovski", "Marsh", "McCormick" };
    int i;
    for (i = 0; i < N; i++){
            v[i].nume = nume[i];
            v[i].prenume = prenume[i];
    }
    
    // Serializam vectorul intr-un fisier
    serializeaza(v, N, "persoane.bin");
    // Deserializam in alt vector, din acelasi fisier. Ar trebui sa obtinem aceleasi informatii.
    deserializeaza(w, N, "persoane.bin");

    for (i = 0; i < N; i++){
            printf("%s %s\n",w[i].prenume,w[i].nume);
    }

    return 0;
}