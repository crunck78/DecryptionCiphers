#ifndef POLYALPHABETIC_CIPHER_H
#define POLYALPHABETIC_CIPHER_H

#include "class/CaesarCipher/CaesarCipher.h"

class PolyalphabeticCipher : public Decryptor
{
	public:
			 
		PolyalphabeticCipher( const string &word, const string &message );
		~PolyalphabeticCipher();
		
		void decrypteMessage( const string &message );
	
		void setShiftWordLength( const int length );
		int getShitfWordLength();
		
		void setEncryptedSequances( const string &message );
		string getEncryptedSequance( const int index );
		
		void setDecryptedSequance( const int index, const string &sequance );
		string getDecryptedSequance( const int index );
		
		void setShiftWord( const string &word );
		string getShiftWord();
		

		
	private:
		
		string *_encryptedSequances;
		string *_decryptedSequances;
		
		int _shiftWordLength;
		string _shiftWord;
		
		CaesarCipher *_sequances;
		
		char _getLetter( const string &sequance, const int index );
};
#endif
