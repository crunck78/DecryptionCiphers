#ifndef MENU_H
#define MENU_H

#include <iostream>

using namespace std;

class Menu
{
	public:
	
		Menu( const int size, const string &name );
			
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
		
		void initialiseMenu( string names[] );
		
	private:
		
		static int _nextIndex;
		static int _choise;
		bool _optionsNull; //guard to not reallocate @_p_options;
		string _name;
		int _index;
		int _size;
		static int _getNextIndex();
		Menu *_p_options;
		Menu *_p_parentMenu;
};
#endif

/*
menu is
	-a list of options
		(an option can be 
		-a sub-menu
		-a command) 
	-a sub-menu
	-a methode to select options
	
		( -get input from user )
	-a methode to cycle between sub-menus
	( go back and foword );
	more like a linked list.
*/
