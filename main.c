#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "usage.h"
#include "mac_address_manufacturer.h"

int main (int argc, char *argv[])
{
	char searched_mac_address[CHAR_COUNT_MAC_ADDRESS + 1];
	char begin_searched_mac_address[CHAR_COUNT_BEGIN_MAC_ADDRESS + 1];

	if (argc != 2)
		usage (BAD_PARAMETERS_COUNT);

	strcpy (searched_mac_address, argv[1]);
	searched_mac_address[CHAR_COUNT_MAC_ADDRESS] = '\0';

	formatting_address (searched_mac_address);

	if (!address_well_formatted (searched_mac_address))
		usage (BAD_MAC_ADDRESS_FORMAT);

	strncpy (begin_searched_mac_address, searched_mac_address, CHAR_COUNT_BEGIN_MAC_ADDRESS);
	begin_searched_mac_address[8] = '\0';

	print_manufacturer (begin_searched_mac_address);

	return 0;
}
