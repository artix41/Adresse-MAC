#ifndef MAC_ADDRESS_MANUFACTURER
#define MAC_ADDRESS_MANUFACTURER

#define CHAR_COUNT_MAC_ADDRESS 17 // En comptant les tirets
#define CHAR_COUNT_BEGIN_MAC_ADDRESS 8 // 3 premiers octets en comptant les tirets
#define CHAR_COUNT_BEFORE_CONSTRUCTOR 18 // Pour la manipulation de fichier
#define MAX_SIZE_WORD 100

void formatting_address (char address_start[]);
int address_well_formatted (char mac_address[]);
void print_manufacturer (char searched_address[]);

#endif