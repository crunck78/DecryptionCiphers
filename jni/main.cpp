#include "class/PolyalphabeticCipher/PolyalphabeticCipher.h"
#include "class/PolybiusSquare/PolybiusSquare.h"
#include "class/Menu/Menu.h"
#include <vector>
#define MESSAGE_PATH "/storage/emulated/0/AppProjects/DecryptionCiphers/jni/MESSAGES/Message1Clue2.txt"

//const char alphabet[ ] = { 'a', 'b', 'c', 'd','e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

int main()
{
	Menu *p_menuHead = NULL;
	//need to set and collect date for the hole Menu tree
	vector<int>menusIndex( 6 );//#total number of menus
	
	int sizes[] = { 5, 0, 0, 0, 0 };
	string menuNames[] = { "Main Menu", "Caesar Cipher", "Polyalphabetic Cipher", "Polybius-Square Cipher", "One-time pad Cipher" }; // names of available Decryptors
	
	Menu *p_current = NULL; // actuall menu in use
	
	// as long as choise is not 0 
	//and current menu is not Main Menu run the loop
	while()
	{
		
	}

	return 0;
}
