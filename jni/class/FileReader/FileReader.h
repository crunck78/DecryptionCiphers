#ifndef FILE_READER_H
#define FILE_READER_H

#include <iostream>
#include <fstream>

using namespace std;

class FileReader
{
	public:
		FileReader( const char filePath[] );
		~FileReader();
		
		void setFileReader( const char filePath[] );
		void closeFile();
		
		void setFileText();
		string getFileText();
		
	private:
		FileReader();
		string _fileText;
		ifstream _fileReader;

};
#endif
