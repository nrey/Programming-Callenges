// In this version I use a table so that the program runs fasterr
// ni
// Mistakes: ( I did no check taht (n < MAX_SIZE) && (cycle[n] != 0), n was less than MAX_SIZE, then when I included I put first (cycle[n] != 0), but I turns out that the if looks at the conditions serially, so it also crashed. Alson when debuggin I did increase the MAX_SIZE to a huge number but i turns out that that number was trying to allocate a huge amout on memory. Also, before cycle was of type ushort, but it turns out that is not enough to store the number of cycles.

#include <iostream>

static const int MAX_SIZE = 1000001;
static unsigned int cycle[ MAX_SIZE ];

unsigned int step( unsigned int n );
unsigned int convergence( unsigned int n );
unsigned int cycles( unsigned int begin, unsigned int end );
bool read( unsigned int &begin, unsigned int &end );



int main ( void )
{
// 	std::cout<<"Hi";
	for( unsigned int i = 0; i<MAX_SIZE; ++i)
	{
		cycle[i] = 0;
// 		std::cout<<i;
	}
	
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
	if( (n < MAX_SIZE) && (cycle[n] != 0)  )
	{
// 		std::cout<<n;
		return cycle[n];
	}

// 	std::cout<<n;
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
