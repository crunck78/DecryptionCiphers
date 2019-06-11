#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T> class Input
{
	public:
		Input( const vector<T> &values );
		Input();

		T getInput();

	private:
		bool _checkInput;
		T _input;
		vector<T> _values; 
		void _setInput();
		bool _badInput();
};

template <typename T> Input<T>::Input()
	: _checkInput( false )
	{}

template <typename T> Input<T>::Input( const vector<T> &values )
	: _values( values ), _checkInput( true )
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
	for( int i = 0; i < _values.size(); i++ )
	{
		if( _input == _values[ i ] )
			return false;//match found, return no bad input
	}
	return true;//no match found, return bad input
}
#endif
