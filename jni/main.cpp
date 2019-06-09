#include "class/PolyalphabeticCipher/PolyalphabeticCipher.h"
#include "class/PolybiusSquare/PolybiusSquare.h"
#include "class/Menu/Menu.h"

#define MESSAGE_PATH "/storage/emulated/0/AppProjects/DecryptionCiphers/jni/MESSAGES/Message1Clue2.txt"

//const char alphabet[ ] = { 'a', 'b', 'c', 'd','e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

int main()
{
	//need to set and collect date for the hile Menu map
	int options[] = { 0, 1, 2, 3, 4 };
	int sizes[] = { 0, 0, 0, 0, 0 };
	int menuSize = 5; // # of options inside Menu;
	string menuName = "Main Menu";
	string decryptors[] = { "Exit", "Caesar Cipher", "Polyalphabetic Cipher", "Polybius-Square Cipher", "One-time pad Cipher" }; // names of available Decryptors
	
	Menu mainMenu( menuSize, menuName );
	
	Menu *p_current = NULL; // actuall menu in use

	return 0;
}
