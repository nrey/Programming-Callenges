// In this version I use a table so that the program runs fasterr
// ni

#include <iostream>

unsigned int step( unsigned int n );
unsigned int convergence( unsigned int n );
unsigned int cycles( unsigned int begin, unsigned int end );
bool read( unsigned int &begin, unsigned int &end );

static const int MAX_SIZE = 100000001;
static unsigned int cycle[ MAX_SIZE ];

int main ( void )
{
	cycle[1] = 1;
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
	if( cycle[n] != 0 )
		return cycle[n];

	n = step( n );
	return convergence( n ) + 1;
}

unsigned int cycles( unsigned int input1, unsigned int input2 )
{
	unsigned int begin, end;
	begin = std::min(input1,input2);
	end = std::max(input1,input2);
	
	unsigned int best = 0;
	while( begin <= end ) 
	{
		if( cycle[begin] == 0 )
			cycle[begin] = convergence( begin );
		best = std::max( best, cycle[begin]);
		begin++;
	}
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
