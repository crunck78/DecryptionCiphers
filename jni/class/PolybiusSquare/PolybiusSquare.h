#ifndef POLYBIUS_SQUARE_H
#define POLYBIUS_SQUARE_H

#include "class/Decryptor/Decryptor.h"

										//  1    2    3    4    5
const char alphabet[ 6 ][ 6 ] = { 	{ '0', '0', '0', '0', '0', '0' },
									{ '0', 'a', 'b', 'c', 'd', 'e' }, //1
									{ '0', 'f', 'g', 'h', 'i', 'j' }, //2
									{ '0', 'k', 'l', 'm', 'n', 'o' }, //3
									{ '0', 'p', 'q', 'r', 's', 't' }, //4
									{ '0', 'u', 'v', 'x', 'y', 'z' } };//5

class PolybiusSquare: public Decryptor
{
	public:
		PolybiusSquare( const string &message );
		~PolybiusSquare();
		
		void decrypteMessage( const string &message );
		
		void setEncryptedLetters( const string &message );
		string getEncryptedLetters( const int index );
		
		char getAlphabetLetter( int col, int row );
		
	private:
		string *_encryptedLetters;
};
#endif
