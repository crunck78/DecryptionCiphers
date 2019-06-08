#include "PolybiusSquare.h"

#define MESSAAGE1_CLUE3_PATH "MESSAGES/Message1Clue3.txt"

PolybiusSquare::PolybiusSquare( const string &message )
	: 	_encryptedLetters( new string[ message.length() / 2 ] ) // because every 2 digits in the polybius square encrypted message represents a letter
	{
		setEncryptedLetters( message );
		decrypteMessage( message );
	}

PolybiusSquare::~PolybiusSquare()
{
	delete []_encryptedLetters;
}

void PolybiusSquare::decrypteMessage( const string &message )
{
	int col, row;
	for( int i = 0; i < ( message.length() / 2 ); i++ )
	{
		col = _encryptedLetters[ i ][ 0 ] - '0'; // to get the right integer value
		row = _encryptedLetters[ i ][ 1 ] - '0';
		setDecryptedMessage( alphabet[ row ][ col ] );
	}
}

void PolybiusSquare::setEncryptedLetters( const string &message )
{
	const int len = 2;
	int pos = 0;
	for( int i = 0; ( i < ( message.length() / len ) ) && ( pos < message.length() ); i++ )
	{
		_encryptedLetters[ i ] = message.substr( pos, len );
		pos += len;
	}
};

string PolybiusSquare::getEncryptedLetters( const int index )
{
	return _encryptedLetters[ index ];
}

char PolybiusSquare::getAlphabetLetter( int col, int row )
{
	return alphabet[ row ][ col ];
}
