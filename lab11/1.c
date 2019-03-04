#include <stdio.h>
 
#define BUFMAX 1005
 
int main(int argc, char **argv)
{
   FILE * pFile;
   char buffer [BUFMAX];
 
   pFile = fopen("myfile.txt" , "r");
   if (pFile == NULL)
      fprintf(stderr, "Eroare! Nu am putut deschide fisierul!");
   else
      {
         while (fgets(buffer, BUFMAX, pFile) != NULL)
	    {
               fputs (buffer, stdout);
               // sau:
               //puts(buffer);

            }
         fclose (pFile);
      }
   return 0;
}

