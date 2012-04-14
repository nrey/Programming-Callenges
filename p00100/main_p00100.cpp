#include <iostream>

unsigned int step( unsigned int n );
unsigned int convergence( unsigned int n );
unsigned int cycles( unsigned int begin, unsigned int end );
bool read( unsigned int &begin, unsigned int &end );


int main ( void )
{
	unsigned int begin, end;
	while( read( begin,end ) )
		std::cout << begin << ' ' << end << ' ' << cycles( begin, end ) << '\n';
	return 1;
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

unsigned int cycles( unsigned int begin, unsigned int end )
{
	unsigned int best = 0;
	while( begin <= end ) best = std::max( best, convergence( begin++ ) );
	return best;
}

bool read( unsigned int &begin, unsigned int &end )
{
	unsigned int a, b;
	std::cin >>  a >> b;
	
	begin = std::min(a,b);
	end = std::max(a,b);
	
	return std::cin;
}