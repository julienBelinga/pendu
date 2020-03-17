#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dico_mot.h"
//notion � revoir=*
void game();
char readchar();
int gagner(int lettretrouver[], long taillemot);
int searchletter(char letter, char motCache[], int lettreTrouver[]);

int main()
{
    int recommencerpartie=1;

     printf("Voici mon pendu\n");

   do{
        game();

        printf("Vouler recommencer\n ?");
        printf("1/ NON        2/ OUI \n");
        scanf("%d", &recommencerpartie);

   }while(recommencerpartie!=1);

   printf("A bientot! :D\n\n");

    return 0;
}

void game()
{
    char lettre=0;// l'entr�e
    char motcache[50]={0};//le mot � trouver
    int *lettretrouver=NULL;
    long cpt=10;
    long i=0;
    long TailleMot=0;

    printf("\n\n=====PENDU=====\n");

    if (!piochermot(motcache))
        exit(0);//sort du programme si on ne trouve pas la fonction piocher mot

    TailleMot=strlen(motcache);
    lettretrouver=malloc(TailleMot*sizeof(int));//allocation dynamique*

    if(lettretrouver==NULL)
        exit(0);// sort du programme si il n'y a aucun caract�re dans la variable lettretrouver

    for (i=0; i<TailleMot; i++)
    {
        while (cpt!=0 && !gagner(lettretrouver, TailleMot))
        {
            printf("il vous reste %ld coups a jouer :)\n", cpt);
            printf("Deviner le mot cacher\n");

            for (i=0; i<TailleMot; i++)
            {
                if (lettretrouver[i])
                    printf("%c", motcache[i]);
                else
                    printf("*");
            }
            printf("saisissez une lettre:\n");
            lettre=readchar();//"uniformisation" des caract�res

            if (!searchletter(lettre, motcache, lettretrouver))//si le joueur ne trouve pas de lettre inscrit dans le mot cacher
                cpt--;
        }
        if (gagner(lettretrouver, TailleMot))
            printf("Bien jou�! le mot etait en effet: %s \n", motcache);
        else
            printf("Perdu! dommage, le mot etait: %s \n", motcache);
    }

    free(lettretrouver);
}

int gagner(int lettretrouver[], long taillemot)
{
    long i=0;
    int joueurwin=1;//*

    for (i=0; i<taillemot; i++)
    {
        if (lettretrouver[i]==0)
            joueurwin=0;//*
    }
    return joueurwin;
}

char readchar()//Notion � revoir*
{
    char caractere = 0;

    caractere = getchar(); // On lit le premier caract�re*
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas d�j�*
    // On lit les autres caract�res m�moris�s un � un jusqu'au \n
    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caract�re qu'on a lu
}

int searchletter(char letter, char motCache[], int lettreTrouver[])
{
    int i=0, bon=0;
    for(i=0; motCache!='\0'; i++)
    {
        if(letter==motCache[i])
        {
            bon=1;//m�morisation de la bonne lettre
            lettreTrouver[i]=1;//apposition de la valeur 1 � la case correspondante
        }
    }
    return bon;
}
