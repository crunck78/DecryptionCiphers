#include "FileReader.h"

FileReader::FileReader( const char filePath[] )
{
	setFileReader( filePath );
	setFileText();
}

FileReader::~FileReader()
{
	closeFile();
}

void FileReader::setFileReader( const char filePath[] )
{
	_fileReader.open( filePath );
	if( ! _fileReader.is_open() )
	{
		cout << "Could not open file at: " << filePath << endl;
	}
}

void FileReader::closeFile()
{
	_fileReader.close();
}

void FileReader::setFileText()
{
	string messageLine; 
	while( _fileReader >> messageLine )
	{
		_fileText += messageLine;
	}
}

string FileReader::getFileText()
{
	return _fileText;
}
