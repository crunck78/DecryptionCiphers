#include "Menu.h"

int Menu::_nextIndex = 0;
int Menu::_choise = 0; 


Menu::Menu( const int size, const string &name )
			: _size( size ), _name( name ), _index( _getNextIndex() )
			{
				setList();
			};
			
Menu::Menu()
			: _p_options( NULL ), _name( "" ), _size( 0 ), _index( _getNextIndex() )
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

/* possible error trow methode 
* can allocate too much memory
* need to set a limit
* size should not be less then 0*/

//need more work
void Menu::setList()
{
	/* guard not too allocate to much memory
	*	or against negative integer
	*/
	if( _size <= 0 || _size > 100 )
		_p_options = NULL;
	else
		_p_options = new Menu[ _size ];
}

/* possible error trow method,
* if instance has no size, nor options*/
/* dumm ass, it will not run the loop if size equals 0
*/
void Menu::displayList()
{
	for( int i = 0; i < _size; i++ )
	{
		cout << i << ". " << _p_options[ i ]._name << endl;
	}
}


Menu* Menu::getOption( const int num )
{
	return &_p_options[ num ];
}

void Menu::setIndex( int index )
{
	_index = index;
}

int Menu::getIndex()
{
	return _index;
}

int Menu::_getNextIndex()
{
	return _nextIndex++;
}

void Menu::setParent( Menu &parent )
{
	_p_parentMenu = &parent;
}

Menu* Menu::getParent()
{
	return _p_parentMenu;
}

int Menu::getChoise()
{
	return _choise;
}

void Menu::setChoise( int choise )
{
	_choise = choise;
}

void Menu::initialiseMenu( string names[] )
{

	for( int i = 0; i < _size; i++ )
	{
		_p_options[ i ].setParent( *this );
		_p_options[ i ].setName( names[ i ] );
	}
}
