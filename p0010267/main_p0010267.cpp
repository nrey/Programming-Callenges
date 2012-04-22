// I think that we have to wait for all the inputs before sending the output
// make -j2;./p0010189exe < ../input.txt 2>&1|tee ../output.txt

// UTILIZAR LA IMAGE COMO EL MAXIMO MAS 2, DE ESA FORMA NO HAY QUE TENER CUIDADO CON LOS BORDER, SIMPLEMENTE LA IMAGEN SE SALE POR UNO PERO NO SE GENERA SEGMENTATION FAULT
// funF REVISAR ESTA FUNCION CON CUIDADO COMO HACERLA MUCHO MAS RAPIDO ? PORQUE NO ME SALIO DE UNA ?

// !!! REVISAR funF2 and funF RUNCIONES RECURSIVAS UE NADA UE LOGRO HACER CLARAMENTE

#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

static const int MAX_SIZE = 260;
char Image[MAX_SIZE+1][MAX_SIZE+1];

void funI( int m, int n )
{
	for( int i=0; i<n; ++i )
	{
		for( int j=0; j<m; ++j )
		{
			Image[i][j] = 'O';
		}
	}
}

void funL( int x, int y, char c )
{
	Image[y-1][x-1] = c;
}

void funV( int x, int y1, int y2, char c )
{
	if( y2 > y1 )
	{
		for( int i=y1-1; i<=y2-1; ++i )
		{
			Image[i][x-1] = c;
		}
	}
	else
	{
		for( int i=y2-1; i<=y1-1; ++i )
		{
			Image[i][x-1] = c;
		}
	}
}

void funH( int x1, int x2, int y, char c )
{
	if( x2 > x1 )
	{
		for( int j=x1-1; j<=x2-1; ++j )
		{
			Image[y-1][j] = c;
		}
	}
	else
	{
		for( int j=x2-1; j<=x1-1; ++j )
		{
			Image[y-1][j] = c;
		}
	}
}

void funK( int x1, int y1, int x2, int y2, char c )
{
	int xmin = std::min( x1, x2 );
	int xmax = std::max( x1, x2 );
	int ymin = std::min( y1, y2 );
	int ymax = std::max( y1, y2 );
	for( int i=ymin-1; i<=ymax-1; ++i )
	{
		for( int j=xmin-1; j<=xmax-1; ++j )
		{
			Image[i][j] = c; // !!! DEMORE COMO UNA HORA PORQUE ESTE CAMPO ERA 'O' Y NO c, 
		}
	}
}

// CONNECTED COMPONNETS 
// REVISAR BIEN ESTA PARTE, PORQUE NO FUI CAPAZ DE HACERLA RAPIDO
void funF( int x, int y, char k, char c, int n, int m  )
{
    if ( x < 1 || x > m || y < 1 || y > n || Image[y-1][x-1] != k || c == k ) return;
 
    Image [y-1][x-1] = c;
 
    funF (x, y - 1, k,c,n,m); // up
    funF (x + 1, y, k,c,n,m); // right
    funF (x, y + 1, k,c,n,m); // down
    funF (x - 1, y, k,c,n,m); // left
}

void funF2( int x, int y, char k, char c, int n, int m  )
{
	if(k == c)
		return;
	if(x > 0 && x <= m && y > 0 && y <= n)
	{
		Image[y-1][x-1] = c;
// 		if( y > 1 )
// 		{
			if(Image[y-2][x-1] == k)
				funF2(x,y-1,k,c,n,m);
// 		}
		if(Image[y][x-1] == k)
			funF2(x,y+1,k,c,n,m);
// 		if( x > 1 )
// 		{
			if(Image[y-1][x-2] == k)
				funF2(x-1,y,k,c,n,m);
// 		}
		if(Image[y-1][x] == k)
			funF2(x+1,y,k,c,n,m);
	}
	else
		return;
}

void funS( std::string name, int n, int m )
{
	std::cout << name;
	std::cout << std::endl;
	for( int i=0; i<n; ++i )
	{
		for( int j=0; j<m; ++j )
		{
			std::cout << Image[i][j];
		}
		std::cout << std::endl;
	}
}

void read ( )
{
	int n,m;
	int x,y;
	int y1,y2;
	int x1,x2;
	std::string name;
	char c;
	char k;
	char option;
	std::string noopt;
	while( std::cin >> option )
	{
		switch( option )
		{
			case 'I':
// 				std::cout << std::endl << "\tI";
				std::cin >> m >> n;
				funI(m,n);
				break;
				
			case 'C':
// 				std::cout << std::endl << "\tC";
				funI(m,n);
				break;
				
			case 'L':
// 				std::cout << std::endl << "\tL";
				std::cin >> x >> y >> c;
				funL(x,y,c);
				break;
			
			case 'V':
// 				std::cout << "ee";
// 				std::cout << std::endl << "\tV";
				std::cin >> x >> y1 >> y2 >> c;
				funV(x,y1,y2,c);
				break;
				
			case 'H':
// 				std::cout << std::endl << "\tH";
				std::cin >> x1 >> x2 >> y >> c;
				funH(x1,x2,y,c);
				break;
				
			case 'K':
// 				std::cout << std::endl << "\tK";
				std::cin >> x1 >> y1 >> x2 >> y2 >> c;
				funK( x1, y1, x2, y2, c );
				break;
				
			case 'F':
// 				std::cout << "l";
// 				std::cout << std::endl << "\tF";
				std::cin >> x >> y >> c;
				k = Image[y-1][x-1];
				funF2( x, y, k, c, n, m );
				break;
				
			case 'S':
// 				std::cout << std::endl << "\tS";
				std::cin >> name;
				funS( name, n, m );
				break;
			case 'X':
				return;
				break;
			default:
				break;
		}
		std::cin.ignore(1000, '\n');
	}
}

int main(void)
{
	read();
	return 0;
}
