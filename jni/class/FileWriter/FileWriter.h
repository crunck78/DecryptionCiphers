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
		
	void setFileWriter( const char path[] )
	{
		m_fileWriter.open( path, std::ios::app | std::ios::ate );
		if( ! m_fileWriter.is_open() )
		{
			std::cout << "Could not open file at: " << path << std::endl;
		}
	}
		
	template <typename T>
	void setTextLine( T textLine )
	{
		m_fileWriter << textLine;
	}
	
	void insertEndLine()
	{
		m_fileWriter << std::endl;
	}
};
#endif
