#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "class/Input/Input.h"

using namespace std;

class Menu
{
	public:
		Menu( const string &name, const int size );
		Menu();	
		~Menu();
		//Menu& operator=( const Menu& newMenu );
	
		void setName( const string &name );
		string getName();
		
		void setSize( const int size );
		int getSize();
		
		void setIndex( int index );
		int getIndex();
		
		void setChoise( const vector<int> &values );
		int getChoise();

		void setOptions( const int size );
		Menu* getOption( const int num );
		
		void displayList();
		
		void setParent( Menu &parent );
		Menu* getParent();
		
		void initialiseMenu( const string names[], const int sizes[] );
		
	private:
		
		static int _nextIndex;
		static int _getNextIndex();
	
		string _name;
		
		int _size;
		int _index;
		
		Input<int> *_p_choise;
		
		Menu *_p_options;
		Menu *_p_parentMenu;
};
#endif
