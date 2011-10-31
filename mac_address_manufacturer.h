#ifndef MAC_ADDRESS_MANUFACTURER
#define MAC_ADDRESS_MANUFACTURER

#define CHAR_COUNT_MAC_ADDRESS 17 // Separations counted
#define CHAR_COUNT_BEGIN_MAC_ADDRESS 8 // 3 first bytes of the address, separations counted.
#define CHAR_COUNT_BEFORE_CONSTRUCTOR 18 // To the manipulation of the file
#define MAX_SIZE_WORD 100

void formatting_address (char address_start[]);
int address_well_formatted (char mac_address[]);
void print_manufacturer (char searched_address[]);

#endif