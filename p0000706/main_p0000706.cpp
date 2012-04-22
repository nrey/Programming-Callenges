// I think that we have to wait for all the inputs before sending the output
// make -j2;./p0010189exe < ../input.txt 2>&1|tee ../output.txt
// If I dont include the std::endl at the end I get and error in the jude !!!!
#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

void fill( unsigned char * p, int jump, unsigned int scale, unsigned int ini, unsigned int type )
{
	for( unsigned int i=0; i<scale; ++i )
	{
		p[ini + jump*i] = type;
	}
}

void write_l1( unsigned char * p, int jump, unsigned int scale )
{
	int ini = 1;
	int jump_2 = 1;
	fill( p, jump_2, scale, ini, 45 );
}

void write_l2( unsigned char * p, int jump, unsigned int scale )
{
	int ini = (1+scale)+jump;
	int jump_2 = jump;
	fill( p, jump_2, scale, ini, 124 );
}

void write_l3( unsigned char * p, int jump, unsigned int scale )
{
	int ini = (1+scale)+(2+scale)*jump;
	int jump_2 = jump;
	fill( p, jump_2, scale, ini, 124 );
}

void write_l4( unsigned char * p, int jump, unsigned int scale )
{
	int ini = 1+(2+2*scale)*jump;
	int jump_2 = 1;
	fill( p, jump_2, scale, ini, 45 );
}

void write_l5( unsigned char * p, int jump, unsigned int scale )
{
	int ini = (scale+2)*jump;
	int jump_2 = jump;
	fill( p, jump_2, scale, ini, 124 );
}

void write_l6( unsigned char * p, int jump, unsigned int scale )
{
	int ini = jump;
	int jump_2 = jump;
	fill( p, jump_2, scale, ini, 124 );
}

void write_l7( unsigned char * p, int jump, unsigned int scale )
{
	int ini = 1+(scale+1)*jump;
	int jump_2 = 1;
	fill( p, jump_2, scale, ini, 45 );
// 	std::cout << std::endl << ini << " " << jump_2;
}

void write( unsigned char * p, int jump, unsigned int scale, unsigned int digito )
{
	if( digito == 0 )
	{
		write_l1( p, jump, scale );
		write_l2( p, jump, scale );
		write_l3( p, jump, scale );
		write_l4( p, jump, scale );
		write_l5( p, jump, scale );
		write_l6( p, jump, scale );
	}
	else if( digito == 1 )
	{
		write_l2( p, jump, scale );
		write_l3( p, jump, scale );
	}
	else if( digito == 2 )
	{
		write_l1( p, jump, scale );
		write_l2( p, jump, scale );
		write_l4( p, jump, scale );
		write_l5( p, jump, scale );
		write_l7( p, jump, scale );
	}
	else if( digito == 3 )
	{
		write_l1( p, jump, scale );
		write_l2( p, jump, scale );
		write_l3( p, jump, scale );
		write_l4( p, jump, scale );
		write_l7( p, jump, scale );
	}
	else if( digito == 4 )
	{
		write_l2( p, jump, scale );
		write_l3( p, jump, scale );
		write_l6( p, jump, scale );
		write_l7( p, jump, scale );
	}
	else if( digito == 5 )
	{
		write_l1( p, jump, scale );
		write_l3( p, jump, scale );
		write_l4( p, jump, scale );
		write_l6( p, jump, scale );
		write_l7( p, jump, scale );
	}
	else if( digito == 6 )
	{
		write_l1( p, jump, scale );
		write_l3( p, jump, scale );
		write_l4( p, jump, scale );
		write_l5( p, jump, scale );
		write_l6( p, jump, scale );
		write_l7( p, jump, scale );
	}
	else if( digito == 7 )
	{
		write_l1( p, jump, scale );
		write_l2( p, jump, scale );
		write_l3( p, jump, scale );
	}
	else if( digito == 8 )
	{
		write_l1( p, jump, scale );
		write_l2( p, jump, scale );
		write_l3( p, jump, scale );
		write_l4( p, jump, scale );
		write_l5( p, jump, scale );
		write_l6( p, jump, scale );
		write_l7( p, jump, scale );
	}
	else if( digito == 9 )
	{
		write_l1( p, jump, scale );
		write_l2( p, jump, scale );
		write_l3( p, jump, scale );
		write_l4( p, jump, scale );
		write_l6( p, jump, scale );
		write_l7( p, jump, scale );
	}
}


int main ( void )
{
	unsigned int in1,in2;
	
	int flag = 0;
	while(true)
	{
		// INPUT
		std::cin >> in1 >> in2;
		if( (in1 == 0) && (in2 == 0) )
			break;
		
		// SPACE BETWEEN PRINTS
		if( flag == 1 )
			std::cout << std::endl;
		flag = 1;

		// PROCESS
		int n = 3 + 2*in1;
		int m = 2 + in1;

		unsigned int digits = 0;
		if( (0 <= in2) && (in2 <= 9) )
			digits = 1;
		else if( (10 <= in2) && (in2 <= 99) )
			digits = 2;
		else if( (100 <= in2) && (in2 <= 999) )
			digits = 3;
		else if( (1000 <= in2) && (in2 <= 9999) )
			digits = 4;
		else if( (10000 <= in2) && (in2 <= 99999) )
			digits = 5;
		else if( (100000 <= in2) && (in2 <= 999999) )
			digits = 6;
		else if( (1000000 <= in2) && (in2 <= 9999999) )
			digits = 7;
		else if( (10000000 <= in2) && (in2 <= 99999999) )
			digits = 8;

		int m_big = m*digits+(digits-1);
		
		unsigned int digitos[digits];
		unsigned int temp = in2;
		for( unsigned int i=0; i<digits; ++i )
		{
			digitos[i] = (int)temp/pow(10,digits-1-i);
			temp = temp - digitos[i]*pow(10,digits-1-i);
		}
		
// 		unsigned char horz = 45;
// 		unsigned char vert = 124;
		unsigned char spac = 32;
		
		unsigned char p[n][m_big];
		for( unsigned int i=0; i<n; ++i )
		{
// 			p[i] = new unsigned char [m];
			for( unsigned int j=0; j<m_big; ++j )
				p[i][j] = spac;
		}
		// Write each digits
		for( unsigned int i=0; i<digits; ++i )
		{
			write( &(p[0][i*m+i]), m_big, in1, digitos[i] );
		}

		// PRINT
		for( unsigned int i=0; i<n; ++i )
		{
			for( unsigned int j=0; j<m_big; ++j )
			{
				printf("%c", p[i][j]);
			}
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
	return 0;
}
