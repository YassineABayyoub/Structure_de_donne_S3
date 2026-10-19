/*
Exercice 4 - Structures imbriquées 
	Un congé comporte un nom d’employé, une date de début et une date de fin. 
		1. Définir les types Date et Conge avec typedef. 
		2. Écrire une fonction : 
			int comparerDates(Date a, Date b); 
			Elle retourne -1, 0 ou 1, selon que a précède, égale ou suit b. 
		3. Écrire une fonction vérifiant que la fin d’un congé ne précède pas son début. 
		4. Déclarer un tableau de 20 congés. 
		5. Afficher les congés commençant pendant un mois et une année donnés. 
	Pour cet exercice, on suppose que les dates fournies sont valides.
*/
#include <stdio.h>
#include <string.h>

typedef struct {
	int jour;
	int mois;
	int annee;
} Date;

typedef struct {
	char nom[50];
	Date debut;
	Date fin;
} Conge;

int comparerDates(Date a, Date b)
{
	if (a.annee < b.annee)
		return -1;
	if (a.annee > b.annee)
		return 1;
	if (a.mois < b.mois)
		return -1;
	if (a.mois > b.mois)
		return 1;
	if (a.jour < b.jour)
		return -1;
	if (a.jour > b.jour)
		return 1;
	return 0;
}

int main(void)
{
	int moisRecherche, anneeRecherche;
	Conge conges[20];
	int i;

	i = 0;
	while(i < 20)
	{
		printf("Entrez le nom de l'employe pour le conge %d (ou 'fin' pour terminer) : ", i + 1);
		scanf("%49s", conges[i].nom);
		if (strcmp(conges[i].nom, "fin") == 0)
			break;

		printf("Entrez la date de debut (jour mois annee) : ");
		scanf("%d %d %d", &conges[i].debut.jour, &conges[i].debut.mois, &conges[i].debut.annee);

		printf("Entrez la date de fin (jour mois annee) : ");
		scanf("%d %d %d", &conges[i].fin.jour, &conges[i].fin.mois, &conges[i].fin.annee);

		if (comparerDates(conges[i].fin, conges[i].debut) < 0)
		{
			printf("Erreur : la date de fin ne peut pas preceder la date de debut.\n");
			continue;
		}

		i++;
	}
	// Affichage des conges commençant pendant un mois et une année donnés
	printf("Entrez le mois recherche : ");
	scanf("%d", &moisRecherche);
	printf("Entrez l'annee recherche : ");
	scanf("%d", &anneeRecherche);

	for (int j = 0; j < i; j++)
	{
		if (conges[j].debut.mois == moisRecherche && conges[j].debut.annee == anneeRecherche)
		{
			printf("Conge de %s : %02d/%02d/%d a %02d/%02d/%d\n", conges[j].nom, conges[j].debut.jour, conges[j].debut.mois, conges[j].debut.annee, conges[j].fin.jour, conges[j].fin.mois, conges[j].fin.annee);
		}
	}

	return 0;
}