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
	std::map<char, unsigned int> m_frequency;
		
public:
	const std::string decryptorType = "Caesar Cipher";
	CaesarCipher()
	{};
	
	CaesarCipher( const std::string& message, const unsigned int shift )
		: m_shift( shift )
	{
		m_encryptedMessage = message;
		_setFrequency();
	};
		
	CaesarCipher( const std::string& message)
	{
			m_encryptedMessage = message;
			_setFrequency();
	};
	
	//TODO
	void findMostFrequentLetter()
	{
		
	}
			
	void decrypteMessage()
	{
		for( int i = 0; i < m_encryptedMessage.length(); i++ )
		{
			if( ( m_encryptedMessage[ i ] - m_shift ) < ALPHABET_BEGIN )
				setDecryptedMessage( m_encryptedMessage[ i ] + ( ALPHABET_SIZE - m_shift ) );
			else
				setDecryptedMessage( m_encryptedMessage[ i ] - m_shift );
		}
	}
	
	const std::map<char, unsigned int> getFrequencyMap() const
	{
		return m_frequency;
	}
		
	const unsigned int getShift() const
	{
		return m_shift;
	}
		
	void frequencyToFile()
	{
		FileWriter frequencyWriter( FREQUENCY_PATH );
		frequencyWriter.setTextLine( "\n" + m_encryptedMessage + "\n" );
		for( std::map<char, unsigned int>::iterator letterFrequency = m_frequency.begin(), end = m_frequency.end(); letterFrequency != end; ++letterFrequency )
		{
			frequencyWriter.setTextLine( letterFrequency->first );
			frequencyWriter.setTextLine( m_letterFrequencyHeightBar( letterFrequency->second ) );
			frequencyWriter.setTextLine( letterFrequency->second);
			frequencyWriter.insertEndLine();
		}
	}
		
	void setShift( const char mostFrequentLetter )
	{
		if( mostFrequentLetter < MOST_FREQUENT_LETTER )
			m_shift =  ALPHABET_SIZE + ( mostFrequentLetter - MOST_FREQUENT_LETTER );
		else
			m_shift =  mostFrequentLetter - MOST_FREQUENT_LETTER;
	}
	
	void setShift( const unsigned int shift )
	{
		m_shift = shift;
	}
		
private:

	void _setFrequency()
	{
		for( char letter = ALPHABET_BEGIN; letter <= ALPHABET_END; letter++ )
		{
			unsigned int counter = 0;
			for( int i = 0; i < m_encryptedMessage.length(); i++ )
			{
				if( letter == m_encryptedMessage[ i ] )
					counter++;
			}
			m_frequency[ letter ] = counter;
		}
	}

	const std::string m_letterFrequencyHeightBar( const unsigned int hight ) const
	{
		std::string hightBar = "";
		for( int i = 0; i < hight; i++ )
		{
			hightBar += "-";
		}
		return hightBar.c_str();
	}
};
#endif
