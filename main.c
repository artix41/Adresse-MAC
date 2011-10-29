#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int NBR_CARACTERES_ADRESSE_MAC = 17; // En comptant les tirets
const int NBR_CARACTERES_DEBUT_ADRESSE_MAC = 8; // 3 premiers octets en comptant les tirets
const int NBR_CARACTERES_AVANT_CONSTRUCTEUR = 18; // Pour la manipulation de fichier
const int TAILLE_MAX_MOT = 100;

char adresseMacRecherchee[NBR_CARACTERES_ADRESSE_MAC + 1];

void afficherConstructeur (char adresseRecherchee[])
{
	char adresseAct[TAILLE_MAX_MOT] = {' '};
	char caractereAct = ' ';

	FILE* flisteAdresses;
	flisteAdresses = fopen ("oui.txt", "r");

	if (flisteAdresses == NULL)
	{
		printf ("Echec à l'ouverture du fichier oui.txt !\n");
		exit (1);
	}

	rewind (flisteAdresses);

	while (strcmp (adresseRecherchee, adresseAct))
	{
		if (fscanf (flisteAdresses, "%s", adresseAct) == EOF)
		{
			printf ("Adresse MAC non trouvée !\n");
			exit (1);
		}
	}

	fseek (flisteAdresses, NBR_CARACTERES_AVANT_CONSTRUCTEUR - NBR_CARACTERES_DEBUT_ADRESSE_MAC, SEEK_CUR);

	while (caractereAct != '\n')
	{
		caractereAct = fgetc (flisteAdresses);
		printf ("%c", caractereAct);
	}

	fclose (flisteAdresses);
}

int main (int argc, char *argv[])
{
	char debutAdresseMacRecherchee[NBR_CARACTERES_DEBUT_ADRESSE_MAC + 1];

	strncpy (debutAdresseMacRecherchee, argv[1], NBR_CARACTERES_DEBUT_ADRESSE_MAC);
	debutAdresseMacRecherchee[8] = '\0';

	afficherConstructeur (debutAdresseMacRecherchee);

	return 0;
}
