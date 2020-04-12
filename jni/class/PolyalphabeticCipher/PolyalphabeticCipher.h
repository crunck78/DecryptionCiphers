#ifndef POLYALPHABETIC_CIPHER_H
#define POLYALPHABETIC_CIPHER_H

#include "class/CaesarCipher/CaesarCipher.h"

class PolyalphabeticCipher : public Decryptor
{
	private:
		
		std::string m_shiftWord;
		std::string *m_encryptedSequances;
		std::string *m_decryptedSequances;
		CaesarCipher *m_sequances;

	public:
			 
		PolyalphabeticCipher( const std::string& word, const std::string& message );
		/* does order counts? as @_sequances uses @_encryptedSequances
		 * to set encrypted messages thru reference
		 */
		~PolyalphabeticCipher()
		{
			if( m_encryptedSequances != NULL )
				delete []m_encryptedSequances;
			if( m_decryptedSequances != NULL )
				delete []m_decryptedSequances;
			if( m_sequances != NULL )
				delete []m_sequances;
		}
		
		void decrypteMessage();
		
		void setEncryptedSequances()
		{
			int sequance = 0;
			while( sequance < m_shiftWord.length() )
			{
				for( int i = 0; ( i * m_shiftWord.length() + sequance ) < m_encryptedMessage.length(); i++ )
				{
					m_encryptedSequances[  sequance ] += m_encryptedMessage[ ( i * m_shiftWord.length() ) + sequance ];
				}
				sequance++;
			}
		}
		
		const std::string getEncryptedSequance( const unsigned int index ) const
		{
			return m_encryptedSequances[ index ];
		}
		
		void setDecryptedSequance( const unsigned int index, const std::string& sequance )
		{
			m_decryptedSequances[ index ] = sequance;
		}
		
		const std::string getDecryptedSequance( const unsigned int index ) const
		{
			return m_decryptedSequances[ index ];
		}
		
		void setShiftWord( const std::string &word )
		{
			m_shiftWord = word;
		}
		
		const std::string getShiftWord() const
		{
			return m_shiftWord;
		}
	
	private:
		const char _getLetter( const std::string& sequance, const unsigned int index ) const
		{
			return sequance[ index ];
		}
};


/* @_shiftWord should not exceed @_encryptedMessage
*/
PolyalphabeticCipher::PolyalphabeticCipher( const std::string& word, const std::string& message )
	: m_encryptedMessage( message ),m_shiftWord( word )
	m_encryptedSequances( new std::string[ word.length() ] ),
	m_decryptedSequances( new std::string[ word.length() ] ),
	m_sequances( new CaesarCipher[ word.length() ] )
	{
		setEncryptedSequances();
	
		for( int i = 0; i < word.length(); i++ )
		{
			m_sequances[ i ].m_encryptedMessage = m_encryptedSequances[ i ];
			m_sequances[ i ].setShift( word[ i ] - ALPHABET_BEGIN );
			m_sequances[ i ].decrypteMessage();
			m_decryptedSequances[ i ] = m_sequances[ i ].getDecryptedMessage();
		}
		decrypteMessage();
	}

void PolyalphabeticCipher::decrypteMessage()
{
	int index = 0;
	int letterPossition = 0;
	while( index < m_encryptedMessage.length() )
	{
		for( int i = 0; i < m_shiftWord.length(); i++ )
		{
			if( letterPossition < m_decryptedSequances[ i ].length() )
			{
				setDecryptedMessage( m_getLetter( m_decryptedSequances[ i ], letterPossition ) );
				index++;
			}
		}
		letterPossition++;
	}
}
#endif
