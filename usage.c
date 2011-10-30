#include <stdio.h>
#include <stdlib.h>

#define BAD_PARAMETERS_COUNT 0
#define BAD_MAC_ADDRESS_FORMAT 1
#define FILE_NOT_FOUND 2
#define MAC_ADDRESS_NOT_FOUND 3

void usage (int code)
{
        if (code == BAD_PARAMETERS_COUNT)
                printf ("Le nombre d'entrées fournis en paramètre est incorrect\n");
        else if (code == BAD_MAC_ADDRESS_FORMAT)
        {
                printf ("The MAC address in input is incorrect (bad format).\n\n");
                printf ("MAC address format :\n");
                printf ("- aabbccddeeff\n");
                printf ("- aa:bb:cc:dd:ee:ff, with ':' replaced by any separation which is nether a number nor a letter between A and F\n");
                printf ("- lowercase or upercase for letters\n");
        }
        else if (code == FILE_NOT_FOUND)
                printf ("Fail in opening of 'oui.txt' file !\n");
        else if (code == MAC_ADDRESS_NOT_FOUND)
                printf ("MAC address not found in the list\n");


        exit (1);
}