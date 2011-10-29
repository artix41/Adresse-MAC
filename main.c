#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int NBR_CARACTERES_ADRESSE_MAC = 17; // En comptant les tirets
const int NBR_CARACTERES_DEBUT_ADRESSE_MAC = 8; // 3 premiers octets en comptant les tirets
const int NBR_SEPARATIONS_ADRESSE_MAC = 5;
const int NBR_CARACTERES_AVANT_CONSTRUCTEUR = 18; // Pour la manipulation de fichier
const int TAILLE_MAX_MOT = 100;

void modifierFormatAdresse (char adresseDepart[])
{
	char adresseBonFormat[NBR_CARACTERES_ADRESSE_MAC + 1];
	int iDigit = 0;

	if ((adresseDepart[2] >= '0' && adresseDepart[2] <= '9') || (toupper (adresseDepart[2]) >= 'A' && toupper (adresseDepart[2]) <= 'F')) // Format aabbccddeeff
	{
		for (int iCaractere = 0; iCaractere < NBR_CARACTERES_ADRESSE_MAC; iCaractere++)
		{
			if ((iCaractere + 1) % 3 != 0)
			{
				adresseBonFormat[iCaractere] = toupper (adresseDepart[iDigit]);
				iDigit++;
			}
			else
				adresseBonFormat[iCaractere] = '-';
		}

		strcpy (adresseDepart, adresseBonFormat);
		adresseDepart[NBR_CARACTERES_ADRESSE_MAC] = '\0';
	}
	else // Format aa:bb:cc:dd:ee:ff, en remplaçant ':' par n'importe quelle séparation
	{
		for (int iCaractere = 2; iCaractere < NBR_CARACTERES_ADRESSE_MAC; iCaractere += 3)
		{
			adresseDepart[iCaractere] = '-';
		}
	}
}

void afficherConstructeur (char adresseRecherchee[])
{
	char adresseAct[TAILLE_MAX_MOT];
	char caractereAct = ' ';

	FILE* flisteAdresses;
	flisteAdresses = fopen ("oui.txt", "r");

	if (flisteAdresses == NULL)
	{
		printf ("Echec à l'ouverture du fichier oui.txt !\n");
		exit (1);
	}

	rewind (flisteAdresses);

	do
	{
		if (fscanf (flisteAdresses, "%s", adresseAct) == EOF)
		{
			printf ("Adresse MAC non trouvée !\n");
			exit (1);
		}
	} while (strcmp (adresseRecherchee, adresseAct));

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
	char adresseMacRecherchee[NBR_CARACTERES_ADRESSE_MAC + 1];
	char debutAdresseMacRecherchee[NBR_CARACTERES_DEBUT_ADRESSE_MAC + 1];

	if (argc != 2)
	{
		printf ("Le nombre d'entrées fournis en paramètre est incorrect\n");
		exit (1);
	}

	strcpy (adresseMacRecherchee, argv[1]);
	adresseMacRecherchee[NBR_CARACTERES_ADRESSE_MAC] = '\0';

	modifierFormatAdresse (adresseMacRecherchee);

	strncpy (debutAdresseMacRecherchee, adresseMacRecherchee, NBR_CARACTERES_DEBUT_ADRESSE_MAC);
	debutAdresseMacRecherchee[8] = '\0';

	afficherConstructeur (debutAdresseMacRecherchee);

	return 0;
}
