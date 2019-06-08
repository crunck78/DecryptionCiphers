#ifndef FIBONACCI_H
#define FIBONACCI_H

#include <vector>

using namespace std;

class Fibonacci
{
	public:
		Fibonacci( int number )
		{
			setFibonacciNumber( number );
		}
		
		void setFibonacciNumber( int number );
		int getFibonacciNumber( int index );
		
	private:
		vector<int> _fibonacciNumber = { 0, 1 };
};
#endif
