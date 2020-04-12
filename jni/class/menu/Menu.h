#ifndef MENU_H
#define MENU_H

#include <iostream>

class Menu
{
private:
		
	static int _nextIndex;
	static int _getNextIndex();
	
	std::string _name;
		
	int _size;
	int _index;
		
	Menu *_p_options;
	Menu *_p_parentMenu;
public:
	Menu( const std::string &name, const int size )
		: _name( name ), _size( size ), _index( _getNextIndex() ), _p_options( new Menu[ size ] )
	{};
	Menu()
		:  _name( "" ), _size( 0 ), _index( _getNextIndex() ), _p_options( NULL )
	{};
	~Menu()
	{
		if( _p_options != NULL )
			delete []_p_options;
	}
	//Menu& operator=( const Menu& newMenu );
	
	void setName( const string &name )
	{
		_name = name;
	}
		
	const char* getName() const
	{
		return _name.c_str();
	}

		void Menu::setSize( const int size )
{
	_size = size;
}

int Menu::getSize()
{
	return _size;
}

void Menu::setIndex( int index )
{
	_index = index;
}

int Menu::getIndex()
{
	return _index;
}

void Menu::setOptions( const int size )
{
	_p_options = new Menu[ size ];
}

Menu* Menu::getOption( const int num )
{
	return &_p_options[ num ];
}

void Menu::displayList()
{
	for( int i = 0; i < _size; i++ )
	{
		cout << i << ". " << _p_options[ i ]._name << endl;
	}
}

void Menu::setParent( Menu &parent )
{
	_p_parentMenu = &parent;
}

Menu* Menu::getParent()
{
	return _p_parentMenu;
}

int Menu::_getNextIndex()
{
	return _nextIndex++;
}
};
#endif
