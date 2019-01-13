#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"

T_Arbre initABR(){
    T_Arbre abr = malloc(sizeof (T_Noeud));
    abr=NULL;
    return abr;
}


T_Noeud* creerNoeud(int cle){
    T_Noeud* noeud = malloc(sizeof (T_Noeud));
    noeud->cle=cle;
    noeud->nb_occurrence=1;
    noeud->droite=NULL;
    noeud->gauche=NULL;
    return noeud;
}

void ajouterElement(T_Arbre* abr, int entier){
    if (*abr==NULL){
        *abr = creerNoeud(entier);
    }
    else {
        T_Noeud* temp = *abr;
        while (temp->cle!=entier){
            if (temp->cle>entier){
                if (temp->gauche!=NULL){
                    temp = temp->gauche;
                }
                else {
                    temp->gauche=creerNoeud(entier);
                    break;
                    }
                }
            else {
                if (temp->cle<entier){
                    if (temp->droite!=NULL){
                        temp = temp->droite;
                    }
                    else {
                        temp->droite=creerNoeud(entier);
                        break;
                    }
                }
            }
        }
        if (temp->cle==entier) temp->nb_occurrence++;
    }
}

void afficher_t(T_Arbre abr){ //tableau ordre croissant
    if (abr!=NULL){
        afficher_t(abr->gauche);
        printf("\t%d, %d", abr->cle, abr->nb_occurrence);
        afficher_t(abr->droite);
    }
}

/*void afficher_a(T_Arbre abr){
    if (abr!=NULL){
        printf("\n%d, %d\t", abr->cle, abr->nb_occurrence);
        printf("fils gauche:");
        afficher_a(abr->gauche);
        printf("fils droit:");
        afficher_a(abr->droite);
    }
}
*/

T_Noeud* rechercherElement(T_Arbre abr, int entier){
    if(abr==NULL) return NULL;
    if(abr->cle==entier) return abr;
    if (abr->cle>entier) rechercherElement(abr->gauche, entier);
    else rechercherElement(abr->droite, entier);
}

T_Noeud* pere(T_Arbre noeud, T_Noeud* n){
    if (rechercherElement(noeud, n->cle)!=NULL){
        if (noeud->cle==n->cle) return noeud;
        while (noeud->gauche!=n && noeud->droite!=n ){
            if (noeud->cle<n->cle) noeud=noeud->droite;
            if (noeud->cle>n->cle) noeud=noeud->gauche;
            }
        return noeud;
        }
    else
    {
        printf("Le noeud de cle %d n'est pas dans l'ABR!!", n->cle);
        return NULL;
    }
}

T_Noeud* successeur(T_Arbre abr, T_Noeud* n){
    if (rechercherElement(abr, n->cle)!=NULL){
        if (n->droite!=NULL) n=n->droite;
        while (n->gauche!=NULL){
            n=n->gauche;
        }
        return n;
    }
    // On ne traite pas le cas ou on doit remonter l'ABR pour trouver le successeur car dans supprimer lorsque on a besoin de faire appel au successeur c'est seulement dans le cas où le noeud a un fils droit
    else return NULL;
}

void supprimerNoeud(T_Arbre* abr, T_Noeud* noeud){
    if (abr==NULL || noeud==NULL) printf("TG tu as foiré qqpart");
    else {
        if (noeud->gauche==NULL && noeud->droite==NULL){
            T_Noeud* papa=pere(abr,noeud);
            if (papa->gauche==noeud) papa->gauche=NULL;
            else papa->droite=NULL;
            free(noeud);
            noeud=NULL;

        }
        if (noeud->gauche==NULL || noeud->droite==NULL){
            T_Noeud* fils;
            if (noeud->gauche==NULL) fils=noeud->droite;
            else fils=noeud->gauche;
            T_Noeud* papa=pere(abr,noeud);
            if (papa->gauche==noeud) papa->gauche=fils;
            else papa->droite=fils;
            free(noeud);
            noeud=NULL;
        }
        if (noeud->gauche!=NULL && noeud->droite!=NULL){
            T_Noeud* succ=successeur(abr, noeud);
            noeud->cle=succ->cle;
            supprimerNoeud(abr, succ);
        }
    }
}
 void decrementerElement (T_Arbre* abr, int entier){
    T_Noeud* n=rechercherElement(*abr, entier);
    if (n==NULL) printf("yo La valeur %d n'est pas dans le tableau!!\n", entier);
    else {
        n->nb_occurrence--;
        if (n->nb_occurrence==0) {
            supprimerNoeud(abr, n);
        }
    }
 }
