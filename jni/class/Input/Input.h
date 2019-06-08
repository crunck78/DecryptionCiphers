#ifndef INPUT_H
#define INPUT_H

#include <iostream>

using namespace std;

template<typename T> class Input
{
	public:
		Input( T values[], int size );
		Input();

		T getInput();

	private:
		bool _checkInput;
		T _input;
		T *_values; 
		int _size;
		void _setInput();
		bool _badInput();
};

template <typename T> Input<T>::Input()
	: _values( NULL ), _size( 0 ), _checkInput( false )
	{}
// not done, exception mith be trow becase size mith not coincide with values's size
template <typename T> Input<T>::Input( T values[], int size )
	: _values( values ), _size( size ), _checkInput( true )
	{}

template <typename T> void Input<T>::_setInput()
{
	cin >> _input;
	while( cin.fail() )
	{
		cin.clear();
		cin.ignore(32767, '\n' );
		cin >> _input;
	}
}

template <typename T> T Input<T>::getInput()
{
	_setInput();
	if( _checkInput )
	{
		while( _badInput() )
		{
			_setInput();
		}
	}
	return _input;
}

template <typename T> bool Input<T>::_badInput()
{
	for( int i = 0; i < _size; i++ )
	{
		if( _input == _values[ i ] )
			return false;//match found, return no bad input
	}
	return true;//no match found, return bad input
}
#endif
