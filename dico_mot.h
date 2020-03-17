#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
int nombreAleatoire(int nombreMax);

int piochermot(char* motpiocher)
{
    FILE*dico=NULL;
    int nbmot=0, nummotpick=0;
    int charread=0;

    dico=fopen("liste.txt","r");

    if (dico==NULL)
    {
        printf("Erreur dans l'ouverture du fichier texte\n");
        exit(0);
    }
    do{
        charread= fgetc(dico);
        if(charread=='\n')
            nbmot++;
        }while(charread!=EOF);//on définit le nombre de mot que comporte le fichier texte externe

    nummotpick=nombreAleatoire(nbmot);//appel de le fonction retournant un nombre au hasard

    rewind(dico);
    while (nummotpick>0)//cette boucle cherche le mot selectioner par la fonction "nombreAleatoire"
    {
        charread=fgetc(dico);
        if (charread='\n')
            nbmot--;
    }

    fgets(motpiocher, 100, dico);
    motpiocher[strlen(motpiocher)-1]='\0';

    fclose(dico);

    return 1;
}

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand()%nombreMax);
}

