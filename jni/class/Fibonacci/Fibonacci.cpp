#include "Fibonacci.h"
		
void Fibonacci::setFibonacciNumber( int number )
{
	if( number > _fibonacciNumber.size() )
	{
		setFibonacciNumber( number - 1 );
	}
	_fibonacciNumber.push_back(  getFibonacciNumber( number - 1 ) + getFibonacciNumber( number - 2 ) ); 
}

int Fibonacci::getFibonacciNumber( int index )
{
	return _fibonacciNumber[ index ];
}
