#ifndef DECRYPTOR_H
#define DECRYPTOR_H

#include <iostream>
#include <string>

class Decryptor
{
	protected:
		std::string m_encryptedMessage;
		std::string m_decryptedMessage;
		
	public:
	
		virtual ~Decryptor()
		{
			
		}
	
		void setEncryptedMessage( const std::string& message )
		{
			m_encryptedMessage = message;
		}
		const std::string getEncryptedMessage() const
		{
			return m_encryptedMessage;
		}
		
		void setDecryptedMessage( const char &letter )
		{
			m_decryptedMessage += letter;
		}
		
		const std::string getDecryptedMessage()
		{
			return m_decryptedMessage;
		}
		
		const int getSize( const std::string& message ) const
		{
			return message.size();
		}
		
		virtual void decrypteMessage() = 0;
		
};
#endif
