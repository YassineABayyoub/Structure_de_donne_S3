/*
Exercice 2 - Tableau de structures 
	On souhaite gerer au maximum 100 etudiants à l’aide d’un tableau de structures. 
		1. Saisir n etudiants, avec 1 ≤ n ≤ 100. 
		2. Afficher les etudiants admis. 
		3. Calculer la moyenne de la classe. 
		4. Afficher tous les etudiants ayant la meilleure moyenne. 
		5. Rechercher un etudiant par son numero. 
		6. Donner la complexite de chaque traitement.
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
    printf("Numero : %d\n", e.numero);
    printf("Nom : %s\n", e.nom);
    printf("Moyenne : %.2f\n", e.moyenne);
}

int estAdmis(struct Etudiant e)
{
    return (e.moyenne >= 10.0);
}

void afficherAdmis(struct Etudiant tableau[], int n)
{
    int i;

    printf("\n--- Etudiants admis ---\n");
    for (i = 0; i < n; i++)
    {
        (estAdmis(tableau[i])) ? afficherEtudiant(tableau[i]) : 0;
    }
}

float moyenneClasse(struct Etudiant tableau[], int n)
{
    int i;
    float somme = 0.0;

    for (i = 0; i < n; i++)
        somme += tableau[i].moyenne;

    return (somme / n);
}

void afficherMeilleurs(struct Etudiant tableau[], int n)
{
    int i;
    float max_moyenne = tableau[0].moyenne;

    for (i = 1; i < n; i++)
    {
        (tableau[i].moyenne > max_moyenne) ? (max_moyenne = tableau[i].moyenne) : 0;
    }

    printf("\n--- Etudiants ayant la meilleure moyenne ---\n");
    for (i = 0; i < n; i++)
    {
        (tableau[i].moyenne == max_moyenne) ? afficherEtudiant(tableau[i]) : 0;
    }
}

int rechercherEtudiant(struct Etudiant tableau[], int n, int numero)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (tableau[i].numero == numero)
			return (i);
    }

    return (-1);
}

int main(void)
{
    struct Etudiant tableau[100];
    int n;
    int i;
    int numero;
    int indice;
    float moyenne;

    printf("Entrez le nombre d'etudiants (1-100) : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\n--- Etudiant %d ---\n", i + 1);
        tableau[i] = saisirEtudiant();
    }

    afficherAdmis(tableau, n);

    moyenne = moyenneClasse(tableau, n);
    printf("\nMoyenne de la classe : %.2f\n", moyenne);

    afficherMeilleurs(tableau, n);

    printf("\nEntrez le numero de l'etudiant a rechercher : ");
    scanf("%d", &numero);

    indice = rechercherEtudiant(tableau, n, numero);

    (indice != -1) ? afficherEtudiant(tableau[indice]) : printf("Etudiant non trouve.\n");

    return (0);
}

/*
La complexite de chaque traitement est la suivante :
1. Saisir n etudiants : O(n)
2. Afficher les etudiants admis : O(n)
3. Calculer la moyenne de la classe : O(n)
4. Afficher tous les etudiants ayant la meilleure moyenne : O(n)
5. Rechercher un etudiant par son numero : O(n)
*/