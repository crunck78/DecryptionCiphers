#include "Clue4Cipher.h"

void Clue4Cipher::decrypteMessage( const string& message )
{
	int col, row;
	row = _getDecimalConversion( message.substr( 0, 3 ) );
	col = _getDecimalConversion( message.substr( 3, 3 ) );
	cout << alphabetClue4[ row ][ col ] << " [ " << row << " ][ " << col << " ]\n";
	setDecryptedMessage( alphabetClue4[ row ][ col ] );
}

string Clue4Cipher::convertMessage( const string& message, const string& clue, const string& type )
{
	string convertedLetters = "";
	for( int i = 0; i < message.length(); i++ )
	{
		if( type == "shift" )
			convertedLetters += _getLetterConversion( message[ i ] );
		if( type == "clue" )
			convertedLetters += _getDigitConversion( message[ i ] );
		if( type == "message" )
			convertedLetters += _getReverseXOR( message[ i ], clue[ i ] );
	}
	return convertedLetters;
}

string Clue4Cipher::getConvertedMessage( const string& type )
{
	if( type == "shift" )
		return _convertedShift;
	if( type == "clue" )
		return _convertedClue;
	if( type == "message" )
		return _convertedMessage;
}

char Clue4Cipher::_getLetterConversion( const char letter )
{
	if( isVowel( letter ) )
		return '1';
	
	if( isConsonant( letter ) )
		return '0';
	
	return letter;//this should not happen if message has only small letters
}

string Clue4Cipher::_getDigitConversion( const char digit )
{
	switch( digit )
	{
		case '0':
			return "00";
		case '1':
			return "01";
		case '2':
			return "10";
		case '3':
			return "11";
		default:
			return "";
	}
}

int Clue4Cipher::_getDecimalConversion( const string& binaryNumber )
{
	if( binaryNumber == "000" )
		return 0;
	if( binaryNumber == "001" )
		return 1;
	if( binaryNumber == "010" )
		return 2;
	if( binaryNumber == "011" )
		return 3;
	if( binaryNumber == "100" )
		return 4;
	if( binaryNumber == "101" )
		return 5;
		
	return -1;
}

bool Clue4Cipher::isVowel( char letter )
{
	switch( letter )
	{
		case 'a':
			break;
		case 'e':
			break;
		case 'i':
			break;
		case 'o':
			break;
		case 'u':
			break;
		case 'y':
			break;
		default:
			return false;// not a vowel
	}
	return true;// is a vowel
}

bool Clue4Cipher::isConsonant( char letter )
{
	switch( letter )
	{
		case 'b':
			break;
		case 'c':
			break;
		case 'd':
			break;
		case 'f':
			break;
		case 'g':
			break;
		case 'h':
			break;
		case 'j':
			break;
		case 'k':
			break;
		case 'l':
			break;
		case 'm':
			break;
		case 'n':
			break;
		case 'p':
			break;
		case 'q':
			break;
		case 'r':
			break;
		case 's':
			break;
		case 't':
			break;
		case 'v':
			break;
		case 'w':
			break;
		case 'x':
			break;
		case 'z':
			break;
		default:
			return false;// not a consonant
	}
	return true;// is a consonant
}

char Clue4Cipher::_getReverseXOR( const char result, const char shift )
{
	if( result == '1' )
	{
		switch( shift )
		{
			case '1':
				return '0';
			case '0':
				return '1';
			default: 
				return shift;
		}
	}
	
	if( result == '0' )
	{
		return shift;
	}
	
	return result;
}

/*Clue4Cipher::void checkMessage( const string& message )
{
	check if message contains only small letters
}*/
