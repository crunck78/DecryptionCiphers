#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include <iostream>
#include <map>
#include "Constants.h"

#include "class/Decryptor/Decryptor.h"
#include "class/FileWriter/FileWriter.h"

class CaesarCipher : public Decryptor
{
private:
		
	unsigned int m_shift;
	map<char, unsigned int> m_frequency;
		
public:
	const std::string decryptorType = "Caesar Cipher";
	CaesarCipher()
	{};
	
	CaesarCipher( const std::string& message, const unsigned int shift )
		: m_encryptedMessage(message), m_shift( shift )
		{
			setFrequency();
			decrypteMessage();
		};
			
	void decrypteMessage();
	void setFrequency();
		
	const map<char, unsigned int> getFrequencyMap() const
	{
		return m_frequency;
	}
		
	const unsigned int getShift() const
	{
		return m_shift;
	}
		
	void frequencyToFile( const std::string& encryptedMessage );
		
	void setShift( const char mostFrequentLetter );
	void setShift( const unsigned int shift )
	{
		m_shift = shift;
	}
		
private:
	const std::string m_letterFrequencyHeightBar( const unsigned int hight ); const
};

void CaesarCipher::decrypteMessage()
{
	for( int i = 0; i < m_encryptedMessage.length(); i++ )
	{
		if( ( m_encryptedMessage[ i ] - m_shift ) < ALPHABET_BEGIN )
			setDecryptedMessage( m_encryptedMessage[ i ] + ( ALPHABET_SIZE - _shift ) );
		else
			setDecryptedMessage( m_encryptedMessage[ i ] - m_shift );
	}
}
		
void CaesarCipher::setFrequency()
{
	for( char letter = ALPHABET_BEGIN; letter <= ALPHABET_END; letter++ )
	{
		unsigned int counter = 0;
		for( int i = 0; i < m_encryptedMessage.length(); i++ )
		{
			if( letter == encryptedMessage[ i ] )
				counter++;
		}
		m_frequency[ letter ] = counter;
	}
}

const void CaesarCipher::frequencyToFile() const
{
	FileWriter frequencyWriter( FREQUENCY_PATH );
	frequencyWriter.setTextLine( "\n" + m_encryptedMessage + "\n" );
	for( map<char, unsigned int>::iterator letterFrequency = m_frequency.begin(), end = m_frequency.end(); letterFrequency != end; ++letterFrequency )
	{
		frequencyWriter.setTextLine( letterFrequency->first );
		frequencyWriter.setTextLine( m_letterFrequencyHeightBar( letterFrequency->second ) );
		frequencyWriter.setTextLine( letterFrequency->second + "\n" );
	}
}

void CaesarCipher::setShift( const char mostFrequentLetter )
{	
	if( mostFrequentLetter < MOST_FREQUENT_LETTER )
		m_shift =  ALPHABET_SIZE + ( mostFrequentLetter - MOST_FREQUENT_LETTER );
	else
		m_shift =  mostFrequentLetter - MOST_FREQUENT_LETTER;
}

void CaesarCipher::setShift( const int shift )
{
	_shift = shift;
}

const std::string CaesarCipher::m_letterFrequencyHeightBar( const int hight ) const
{
	string hightBar = "";
	for( int i = 0; i < hight; i++ )
	{
		hightBar += "-";
	}
	
	return hightBar.c_str();
}

#endif
