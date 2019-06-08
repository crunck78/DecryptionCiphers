#include "PolyalphabeticCipher.h"

/* @_shiftWord should not exceed @_encryptedMessage
*/
PolyalphabeticCipher::PolyalphabeticCipher( const string &word, const string &message )
	: _shiftWord( word ), 
	_encryptedSequances( new string[ word.length() ] ),
	_decryptedSequances( new string[ word.length() ] ),
	_sequances( new CaesarCipher[ word.length() ] )
	{
		setEncryptedSequances( message );
	
		for( int i = 0; i < word.length(); i++ )
		{
			_sequances[ i ].setEncryptedMessage( _encryptedSequances[ i ] );
			_sequances[ i ].setShift( word[ i ] - 'a' );
			_sequances[ i ].decrypteMessage( getEncryptedSequance( i ) );
			_decryptedSequances[ i ] = _sequances[ i ].getDecryptedMessage();
		}
		decrypteMessage( message );
	}

/* does order counts? as @_sequances uses @_encryptedSequances
* to set encrypted messages thru reference
*/
PolyalphabeticCipher::~PolyalphabeticCipher()
{
	if( _encryptedSequances != NULL )
		delete []_encryptedSequances;
	if( _decryptedSequances != NULL )
		delete []_decryptedSequances;
	if( _sequances != NULL )
		delete []_sequances;
}

void PolyalphabeticCipher::decrypteMessage( const string &message )
{
	int index = 0;
	int letterPossition = 0;
	while( index < message.length() )
	{
		for( int i = 0; i < _shiftWord.length(); i++ )
		{
			if( letterPossition < _decryptedSequances[ i ].length() )
			{
				setDecryptedMessage( _getLetter( _decryptedSequances[ i ], letterPossition ) );
				index++;
			}
		}
		letterPossition++;
	}
}

void PolyalphabeticCipher::setShiftWordLength( const int length )
{
	_shiftWordLength = length;
}

int PolyalphabeticCipher::getShitfWordLength()
{
	return _shiftWordLength;
}

void PolyalphabeticCipher::setEncryptedSequances( const string &message )
{
	int sequance = 0;
	while( sequance < _shiftWord.length() )
	{
		for( int i = 0; ( i * _shiftWord.length() + sequance ) < message.length(); i++ )
		{
			_encryptedSequances[  sequance ] += message[ ( i * _shiftWord.length() ) + sequance ];
		}
		sequance++;
	}
}

string PolyalphabeticCipher::getEncryptedSequance( const int index )
{
	return _encryptedSequances[ index ];
}

void PolyalphabeticCipher::setDecryptedSequance( const int index, const string &sequance )
{
	_decryptedSequances[ index ] = sequance;
}

string PolyalphabeticCipher::getDecryptedSequance( const int index )
{
	return _decryptedSequances[ index ];
}

void PolyalphabeticCipher::setShiftWord( const string &word )
{
	_shiftWord = word;
}

string PolyalphabeticCipher::getShiftWord()
{
	return _shiftWord;
}

char PolyalphabeticCipher::_getLetter( const string &sequance, const int index )
{
	return sequance[ index ];
}
