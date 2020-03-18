#ifndef CLUE4_CIPHER_H
#define CLUE4_CIPHER_H

#include "class/Decryptor/Decryptor.h"
										// 0    1    2    3    4    5
const char alphabetClue4[ 6 ][ 6 ] = { 	{ 'f', 'g', 'h', 'i', 'j', 'k' }, //0
									    { 'e', 'x', 'y', 'z', '0', 'l' }, //1
									    { 'd', 'w', '0', '0', '0', 'm' }, //2
									    { 'c', 'v', '0', '0', '0', 'n' }, //3
									    { 'b', 'u', '0', '0', '0', 'o' }, //4
									    { 'a', 't', 's', 'r', 'q', 'p' } };//5

class Clue4Cipher : public Decryptor
{
	public:
		Clue4Cipher( const string &shiftMessage, const string& encryptedMessage )
			: _shiftMessage( shiftMessage )
			{
				setEncryptedMessage( encryptedMessage );
				_convertedShift = convertMessage( _shiftMessage, "NULL", "shift" );
				_convertedClue = convertMessage( getEncryptedMessage(), "NULL", "clue" );
				_convertedMessage = convertMessage( _convertedClue, _convertedShift, "message" );
				_polybiusSquareIndex = new string[ _convertedMessage.size() / 6 ]; // 6 digits string per 2 polybius square indexes
				for( int i = 0; i < (_convertedMessage.size() / 6); i++ )
				{
					_polybiusSquareIndex[ i ] = _convertedMessage.substr( (i * 6), 6 );
					decrypteMessage( _polybiusSquareIndex[ i ] );
					cout << _polybiusSquareIndex[ i ] << " " << getDecryptedMessage() << endl;
				}
			};
		
		~Clue4Cipher()
		{
			delete _polybiusSquareIndex;
		}
		
		void decrypteMessage( const string& message );
		string convertMessage( const string& message, const string&clue, const string& type );
		string getConvertedMessage( const string& type );
		
		bool isVowel( const char letter );
		bool isConsonant( const char letter );

	private:
		string _shiftMessage;
		string _convertedShift;
		
		string _convertedClue;
		string _convertedMessage;
		
		string *_polybiusSquareIndex;
		
		char _getLetterConversion( const char letter );
		string _getDigitConversion( const char digit );
		char _getReverseXOR( const char result, const char shift );
		int _getDecimalConversion( const string& binaryNumber );
};
#endif
