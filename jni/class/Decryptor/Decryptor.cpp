#include "Decryptor.h"

void Decryptor::setEncryptedMessage( const string &message )
{
	_encryptedMessage = message;
}

string Decryptor::getEncryptedMessage()
{
	return _encryptedMessage;
}

void Decryptor::setDecryptedMessage( const char &letter )
{
	_decryptedMessage += letter;
}

string Decryptor::getDecryptedMessage()
{
	return _decryptedMessage;
}
