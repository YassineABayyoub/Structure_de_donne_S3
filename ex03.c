/*
Exercice 3 - Structures et pointeurs 
On considère : 
typedef struct { 
    int numero; 
    char nom[40]; 
    int quantite; 
    float prix; 
} Article; 
1. Déclarer un article a et un pointeur p initialisé avec son adresse. 
2. Affecter une quantité et un prix à l’article en utilisant p. 
3. Réécrire les accès avec la notation (*p).champ. 
4. Écrire : 
Département d’informatique 
IA S3    
2026/2027 TD 1 Structure des données Faculté des sciences 
 
 
-2- 
int modifierPrix(Article *a, float nouveauPrix); 
int ajouterStock(Article *a, int quantite); 
int vendre(Article *a, int quantite); 
Les fonctions retournent 1 si l’opération réussit, sinon 0. Une vente ne doit pas rendre le stock négatif. 
5. Expliquer pourquoi une fonction recevant seulement une copie de l’article ne modifie pas 
directement l’article du programme appelant.
*/


#include <stdio.h>

typedef struct {
    int numero;
    char nom[40];
    int quantite;
    float prix;
} Article;

int modifierPrix(Article *a, float nouveauPrix)
{
    if (nouveauPrix < 0)
        return (0);

    a->prix = nouveauPrix;
    return (1);
}

int ajouterStock(Article *a, int quantite)
{
    if (quantite <= 0)
        return (0);

    a->quantite += quantite;
    return (1);
}

int vendre(Article *a, int quantite)
{
    if (quantite <= 0 || quantite > a->quantite)
        return (0);

    a->quantite -= quantite;
    return (1);
}

int main(void)
{
    Article a = {1, "Ordinateur", 10, 999.99};
    Article *p = &a;

    /* Acces avec la notation -> */
    p->quantite = 15;
    p->prix = 1099.99;

    printf("--- Article initial ---\n");
    printf("Numero : %d\n", p->numero);
    printf("Nom : %s\n", p->nom);
    printf("Quantite : %d\n", p->quantite);
    printf("Prix : %.2f\n", p->prix);

    /* Acces avec la notation (*p).champ */
    (*p).quantite = 20;
    (*p).prix = 1199.99;

    printf("\n--- Apres modification avec (*p) ---\n");
    printf("Quantite : %d\n", (*p).quantite);
    printf("Prix : %.2f\n", (*p).prix);

    /* Modification du prix */
    (modifierPrix(p, 1299.99)) ? printf("Prix modifie avec succes.\n") : printf("Prix invalide.\n");

    /* Ajout de stock */
    (ajouterStock(p, 5)) ? printf("Stock ajoute avec succes.\n") : printf("Quantite invalide.\n");
        printf("Quantite invalide.\n");

    /* Vente */
    (vendre(p, 3)) ? printf("Vente effectuee avec succes.\n") : printf("Vente impossible.\n");

    printf("\n--- Etat final ---\n");
    printf("Nom : %s\n", a.nom);
    printf("Quantite : %d\n", a.quantite);
    printf("Prix : %.2f\n", a.prix);

    return (0);
}

/*
Une fonction recevant une copie de l'article travaille sur une
structure locale. Les modifications de cette copie ne changent
pas l'article original.

Pour modifier directement l'article du programme appelant,
on passe son adresse a la fonction avec un pointeur.
*/