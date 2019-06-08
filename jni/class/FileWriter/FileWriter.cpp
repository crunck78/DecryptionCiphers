#include "FileWriter.h"

FileWriter::FileWriter( const char path[] )
{
	setFileWriter( path );
}

FileWriter::~FileWriter()
{
	closeFile();
}

void FileWriter::setFileWriter( const char filePath[] )
{
	_fileWriter.open( filePath, ios::app | ios::ate );
	if( ! _fileWriter.is_open() )
	{
		cout << "Could not open file at: " << filePath << endl;
	}
}

void FileWriter::closeFile()
{
	_fileWriter.close();
}

template <typename T>
void FileWriter::setTextLine( T textLine )
{
	_fileWriter << textLine;
}

void FileWriter::insertEndLine()
{
	_fileWriter << endl;
}
