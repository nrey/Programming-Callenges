#include <iostream>

unsigned int step( unsigned int n );
unsigned int convergence( unsigned int n );
unsigned int cycles( unsigned int begin, unsigned int end );
bool read( unsigned int &begin, unsigned int &end );


int main ( void )
{
	unsigned int input1, input2;
	while( read( input1,input2 ) )
		std::cout << input1 << ' ' << input2 << ' ' << cycles( input1, input2 ) << '\n';
	return 0;
}

unsigned int step( unsigned int n )
{
	return n%2 ? 3*n+1 : n/2;
}

unsigned int convergence( unsigned int n )
{
	unsigned count = 1;
	while( n > 1 ) { n = step(n); ++count; }
	return count;
}

unsigned int cycles( unsigned int input1, unsigned int input2 )
{
	unsigned int begin, end;
	begin = std::min(input1,input2);
	end = std::max(input1,input2);
	
	unsigned int best = 0;
	while( begin <= end ) best = std::max( best, convergence( begin++ ) );
	return best;
}

bool read( unsigned int &input1, unsigned int &input2 )
{
// 	unsigned int a, b;
	std::cin >>  input1 >> input2;
	
// 	begin = std::min(a,b);
// 	end = std::max(a,b);
	
	return std::cin;
}