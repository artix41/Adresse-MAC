#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "usage.h"

#define CHAR_COUNT_MAC_ADDRESS 17 // En comptant les tirets
#define CHAR_COUNT_BEGIN_MAC_ADDRESS 8 // 3 premiers octets en comptant les tirets
#define CHAR_COUNT_BEFORE_CONSTRUCTOR 18 // Pour la manipulation de fichier
#define MAX_SIZE_WORD 100

void formatting_address (char address_start[])
{
        /* La fonction prend une adresse MAC en paramètre et la met dans un format aa-bb-cc-dd-ee-ff si elle est correct */

        char address_formatted[CHAR_COUNT_MAC_ADDRESS + 1];
        int idx_digit = 0;

        if ((address_start[2] >= '0' && address_start[2] <= '9') || (toupper (address_start[2]) >= 'A' && toupper (address_start[2]) <= 'F')) // Format aabbccddeeff
        {
                for (int idx_char = 0; idx_char < CHAR_COUNT_MAC_ADDRESS; idx_char++)
                {
                        if ((idx_char + 1) % 3 != 0)
                        {
                                address_formatted[idx_char] = toupper (address_start[idx_digit]);
                                idx_digit++;
                        }
                        else
                                address_formatted[idx_char] = '-';
                }

                strcpy (address_start, address_formatted);
                address_start[CHAR_COUNT_MAC_ADDRESS] = '\0';
        }
        else // Format aa:bb:cc:dd:ee:ff, en remplaçant ':' par n'importe quelle séparation
        {
                for (int idx_char = 2; idx_char < CHAR_COUNT_MAC_ADDRESS; idx_char += 3)
                {
                        address_start[idx_char] = '-';
                }
        }
}

int address_well_formatted (char mac_address[])
{
        /* La fonction prend une adresse MAC en paramètre et renvoie un booléen qui vaut 1 si l'adresse est bien formattée, 0 sinon */

        for (int idx_char = 0; idx_char < CHAR_COUNT_MAC_ADDRESS; idx_char++)
        {
                if (((idx_char + 1) % 3 != 0 
                        && !(mac_address[idx_char] >= '0' && mac_address[idx_char] <= '9') && !(mac_address[idx_char] >= 'A' && mac_address[idx_char] <= 'F'))
                        || ((idx_char + 1) % 3 == 0 && mac_address[idx_char] != '-'))
                        return 0;
        }

        return 1;
}

void print_manufacturer (char searched_address[])
{
        /* La fonction prend en paramètre le début d'une adresse MAC sous la forme aa-bb-cc et affiche son constructeur */

        char cur_address[MAX_SIZE_WORD];
        char cur_char = ' ';

        FILE* file_oui;
        file_oui = fopen ("oui.txt", "r");

        if (file_oui == NULL)
                usage (FILE_NOT_FOUND);

        rewind (file_oui);

        do
        {
                if (fscanf (file_oui, "%s", cur_address) == EOF)
                        usage (MAC_ADDRESS_NOT_FOUND);
                
        } while (strcmp (searched_address, cur_address));

        fseek (file_oui, CHAR_COUNT_BEFORE_CONSTRUCTOR - CHAR_COUNT_BEGIN_MAC_ADDRESS, SEEK_CUR);

        while (cur_char != '\n')
        {
                cur_char = fgetc (file_oui);
                printf ("%c", cur_char);
        }

        fclose (file_oui);
}