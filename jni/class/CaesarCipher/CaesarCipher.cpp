#include "CaesarCipher.h"

#define FREQUENCY_PATH "FREQUENCES/Frequency.txt"

void CaesarCipher::decrypteMessage( const string &encryptedMessage )
{
	for( int i = 0; i < encryptedMessage.length(); i++ )
	{
		if( ( encryptedMessage[ i ] - _shift ) < 'a' )
			setDecryptedMessage( encryptedMessage[ i ] + ( _totalLetters - _shift ) );
		else
			setDecryptedMessage( encryptedMessage[ i ] - _shift );
	}
}
		
void CaesarCipher::setFrequency( const string &encryptedMessage )
{
	for( char letter = 'a'; letter <= 'z'; letter++ )
	{
		int counter = 0;
		for( int i = 0; i < encryptedMessage.length(); i++ )
		{
			if( letter == encryptedMessage[ i ] )
			counter++;
		}
		_frequency[ letter ] = counter;
	}
}

map<char, int> CaesarCipher::getFrequencyMap()
{
	return _frequency;
}

void CaesarCipher::frequencyToFile( const string &encryptedMessage )
{
	FileWriter frequencyWriter( FREQUENCY_PATH );
	frequencyWriter.setTextLine( "\n" + encryptedMessage + "\n" );
	for( map<char, int>::iterator letterFrequency = _frequency.begin(), end = _frequency.end(); letterFrequency != end; ++letterFrequency )
	{
		frequencyWriter.setTextLine( letterFrequency->first );
		frequencyWriter.setTextLine( _letterFrequencyHightBar( letterFrequency->second ) );
		frequencyWriter.setTextLine( letterFrequency->second + "\n" );
	}
}

void CaesarCipher::setShift( const char mostFrequentLetter )
{	
	if( mostFrequentLetter < _mostFrequentEnglishLetter )
		_shift =  _totalLetters + ( mostFrequentLetter - _mostFrequentEnglishLetter );
	else
		_shift =  mostFrequentLetter - _mostFrequentEnglishLetter ;
}

void CaesarCipher::setShift( const int shift )
{
	_shift = shift;
}

int CaesarCipher::getShift()
{
	return _shift;
}

string CaesarCipher::_letterFrequencyHightBar( const int hight )
{
	string hightBar = "";
	for( int i = 0; i < hight; i++ )
	{
		hightBar += "-";
	}
	
	return hightBar.c_str();
}
