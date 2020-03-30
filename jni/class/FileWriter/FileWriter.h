#ifndef FILE_WRITER
#define FILE_WRITER

#include <iostream>
#include <fstream>

class FileWriter
{
private:
	std::ofstream m_fileWriter;
public:
	FileWriter( const char path[] )
	{
		setFileWriter( path );
	}
	
	~FileWriter()
	{
		m_fileWriter.close();
	}
		
	void setFileWriter( const char path[] );
		
	template <typename T>
	void FileWriter::setTextLine( T textLine )
	{
		m_fileWriter << textLine;
	}
	
	void insertEndLine()
	{
		m_fileWriter << std::endl;
	}
};

void FileWriter::setFileWriter( const char filePath[] )
{
	m_fileWriter.open( filePath, ios::app | ios::ate );
	if( ! m_fileWriter.is_open() )
	{
		std::cout << "Could not open file at: " << filePath << std::endl;
	}
}

#endif
