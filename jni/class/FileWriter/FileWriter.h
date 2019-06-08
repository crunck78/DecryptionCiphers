#ifndef FILE_WRITER
#define FILE_WRITER

#include <iostream>
#include <fstream>

using namespace std;

class FileWriter
{
	public:
		FileWriter( const char path[] );
		~FileWriter();
		
		void setFileWriter( const char path[] );
		void closeFile();
		
		template <typename T>
		void setTextLine( T textLine );
		
		void insertEndLine();
		
	private:
		ofstream _fileWriter;
};
#endif
