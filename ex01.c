/*
Exercice 1 - Structure Etudiant 
	Un étudiant est caractérisé par un numéro, un nom de 20 caractères au maximum et une moyenne. 
		1. Définir la structure struct Etudiant. 
		2. Déclarer et initialiser un étudiant. 
		3. Écrire les fonctions : 
			struct Etudiant saisirEtudiant(void); 
			void afficherEtudiant(struct Etudiant e); 
			int estAdmis(struct Etudiant e);
*/
#include <stdio.h>

struct Etudiant {
    int numero;
    char nom[21];
    float moyenne;
};

struct Etudiant saisirEtudiant(void)
{
    struct Etudiant e;

    printf("Entrez le numero de l'etudiant : ");
    scanf("%d", &e.numero);

    printf("Entrez le nom de l'etudiant : ");
    scanf("%20s", e.nom);

    printf("Entrez la moyenne de l'etudiant : ");
    scanf("%f", &e.moyenne);

    return (e);
}

void afficherEtudiant(struct Etudiant e)
{
    printf("\n--- Informations de l'etudiant ---\n");
    printf("Numero : %d\n", e.numero);
    printf("Nom : %s\n", e.nom);
    printf("Moyenne : %.2f\n", e.moyenne);
}

int estAdmis(struct Etudiant e)
{
	return (e.moyenne >= 10.0);
}

int main(void)
{
    struct Etudiant e1 = saisirEtudiant();

    afficherEtudiant(e1);
    (estAdmis(e1)) ? printf("L'etudiant est admis.\n") : printf("L'etudiant n'est pas admis.\n");
    return (0);
}