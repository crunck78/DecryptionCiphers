#include "class/PolyalphabeticCipher/PolyalphabeticCipher.h"
#include "class/PolybiusSquare/PolybiusSquare.h"
#include "class/Menu/Menu.h"
#include "class/Input/Input.h"

#define MESSAGE_PATH "/storage/emulated/0/AppProjects/DecryptionCiphers/jni/MESSAGES/Message1Clue2.txt"

//const char alphabet[ ] = { 'a', 'b', 'c', 'd','e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

int main()
{
	int options[] = { 0, 1, 2, 3, 4 };
	int sizes[] = { 0, 0, 0, 0, 0 };
	int menuSize = 5; // # of options inside Menu;
	Input<int> choise( options, menuSize );
	string menuName = "Main Menu";
	string decryptors[] = { "Exit", "Caesar Cipher", "Polyalphabetic Cipher", "Polybius-Square Cipher", "One-time pad Cipher" }; // names of available Decryptors
	
	Menu mainMenu( menuSize, sizes, menuName, decryptors );
	
	Menu *p_current = NULL; // actuall menu in use
	int index = 0;
	
	while( ( Menu::getChoise() != 0 ) && ( p_current != &mainMenu ) )
	{
		break;
	}

	return 0;
}
