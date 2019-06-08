#ifndef DECRYPTOR_H
#define DECRYPTOR_H

#include <iostream>
#include <fstream>
#include <iterator>
#include <map>

using namespace std;

class Decryptor
{
	public:
	
		virtual ~Decryptor();
	
		void setEncryptedMessage( const string &message );
		string getEncryptedMessage();
		
		void setDecryptedMessage( const char &letter );
		string getDecryptedMessage();
		
		virtual void decrypteMessage( const string &message ) = 0;

	private:
	
		string _encryptedMessage;
		string _decryptedMessage;
		
};
#endif
