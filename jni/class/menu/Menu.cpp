#include "Menu.h"

int Menu::_nextIndex = 0;
//int Menu::_choise = 0; 

Menu::Menu( const string &name, const int size )
			: _name( name ), _size( size ), _index( _getNextIndex() ), _p_options( new Menu[ size ] )
			{};
			
Menu::Menu()
			:  _name( "" ), _size( 0 ), _index( _getNextIndex() ), _p_options( NULL )
			{};
			
Menu::~Menu()
		{
			if( _p_options != NULL )
				delete []_p_options;
		}

/*not finished
Menu& Menu::operator=( const Menu& oldMenu )
{
	if( this == &oldMenu )
		return *this;
}*/

void Menu::setName( const string &name )
{
	_name = name;
}

string Menu::getName()
{
	return _name;
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
