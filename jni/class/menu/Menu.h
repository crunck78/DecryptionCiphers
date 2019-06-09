#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "class/Input.h"

using namespace std;

class Menu
{
	public:
		Menu( const int size, const int sizes[], const string &name, const string names[] );
		Menu();	
		~Menu();
		//Menu& operator=( const Menu& newMenu );
	
		void setName( const string &name );
		string getName();
		
		void setSize( const int size );
		int getSize();
		
		void displayList();
		
		void setList();
		Menu* getOption( const int num );
		
		void setIndex( int index );
		int getIndex();
		
		void setParent( Menu &parent );
		Menu* getParent();
	
		static int getChoise();
		static void setChoise( int choise );
		
		void initialiseMenu( const string names[] );
		
	private:
		
		static int _nextIndex;
		static int _getNextIndex();
	
		bool _optionsNull; //guard to not reallocate @_p_options;
		string _name;
		int _index;
		int _size;
		Input<int> *_p_choise;
		
		Menu *_p_options;
		Menu *_p_parentMenu;
};
#endif
