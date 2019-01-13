#ifndef TP4_H_INCLUDED
#define TP4_H_INCLUDED

typedef struct Noeud {
    int cle;
    unsigned int nb_occurrence;
    struct Noeud* gauche;
    struct Noeud* droite;
} T_Noeud;

typedef T_Noeud* T_Arbre;

T_Arbre initABR(){
    T_Arbre abr = malloc(sizeof (T_Noeud));
    abr=NULL;
    return abr;
}

T_Arbre initABR();
T_Noeud* creerNoeud(int cle);
void ajouterElement(T_Arbre* abr, int entier);
void afficher_t(T_Arbre abr);
T_Noeud* rechercherElement(T_Arbre abr, int entier);
T_Noeud* pere(T_Arbre noeud, T_Noeud* n);
T_Noeud* successeur(T_Arbre abr, T_Noeud* n);
void supprimerNoeud(T_Arbre* abr, T_Noeud* noeud);
void decrementerElement (T_Arbre* abr, int entier);

#endif // TP4_H_INCLUDED
