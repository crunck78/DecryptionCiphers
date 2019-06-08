#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#include "class/Decryptor/Decryptor.h"
#include "class/FileWriter/FileWriter.h"
#include "class/FileReader/FileReader.h"

class CaesarCipher : public Decryptor
{
	public:
		const string decryptorType = "Caesar Cipher";
		CaesarCipher( const string &message, const int shift )
			: _shift( shift )
			{
				setFrequency( message );
				decrypteMessage( message );
			}
			
		CaesarCipher()
			: _shift( 0 )
			{};
	
		void decrypteMessage( const string &encryptedMessage );
		
		void setFrequency( const string &encryptedMessage );
		map<char, int> getFrequencyMap();
		void frequencyToFile( const string &encryptedMessage );
		
		void setShift( const char mostFrequentLetter );
		void setShift( const int shift );
		int getShift();

	private:
		static const char _mostFrequentEnglishLetter = 'e';
		static const int _totalLetters = 26;
		
		int _shift;
		map<char, int> _frequency;
		
		string _letterFrequencyHightBar( const int hight );
};
#endif
