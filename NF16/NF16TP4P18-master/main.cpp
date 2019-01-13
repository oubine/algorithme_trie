#include <stdio.h>
#include <stdlib.h>

int main()
{
    T_Arbre abr = initABR();
    T_Arbre noeud = creerNoeud(3);
    ajouterElement(&abr, 4);
    ajouterElement(&abr, 5);
    ajouterElement(&abr, 7);
    ajouterElement(&abr, 3);
    ajouterElement(&abr, 6);
    ajouterElement(&abr, 3);
    ajouterElement(&abr, 1);
    ajouterElement(&abr, 2);
    ajouterElement(&abr, 6);
    afficher_t(abr);

    printf("\n");
    supprimerNoeud(&abr, rechercherElement(abr, 6));

    afficher_t(abr);
    printf("\n");
    afficher_t(abr);

    return 0;
}
