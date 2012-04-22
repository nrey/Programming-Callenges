//Author: Jair Cazarin <slipvayne@gmail.com>

#include<iostream>
#include<string>
#define MAX 250

using namespace std;

int m, n;
char Image[MAX+1][MAX+1];



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
			Image[i][j] = c;
		}
	}
}

void F(int x, int y, char k, char c)
{
    if(k == c)
        return;
    if(x > 0 && x <= m && y > 0 && y <= n)
    {
        Image[y-1][x-1] = c;
        if(Image[y-2][x-1] == k)
            F(x,y-1,k,c);
        if(Image[y][x-1] == k)
            F(x,y+1,k,c);
        if(Image[y-1][x-2] == k)
            F(x-1,y,k,c);
        if(Image[y-1][x] == k)
            F(x+1,y,k,c);
    }
    else
        return;
}

void funS( std::string name, int m, int n )
{
// 	std::cout << "l";
	std::cout << name;
	std::cout << std::endl;
	for( int i=0; i<n; ++i )
	{
// 		std::cout << std::endl;
		for( int j=0; j<m; ++j )
		{
			std::cout << Image[i][j];
		}
		std::cout << std::endl;
// 		std::cout << std::endl << "h";
	}
// 	std::cout << std::endl;
// 	std::cout << "l";
	
}

void read()
{
       char a, c, k;
    string name;
    int x, y, x1, y1, x2, y2;
    while(cin >> a)
    {
        switch(a)
        {
		case 'I':
			cin >> m >> n;
// 			m = x1;
// 			n = y1;
			funI(m,n);
			break;
		case 'C':   
			funI(m,n);
			break;
		case 'L':   
			cin >> x >> y >> c;
			funL(x,y,c);
                        break;
		case 'V':
			cin >> x >> y1 >> y2 >> c;
			funV(x,y1,y2,c);
			break;
		case 'H':
			cin >> x1 >> x2 >> y >> c;
			funH(x1,x2,y,c);
			break;
		case 'K':   
			cin >> x1 >> y1 >> x2 >> y2 >> c;
			funK(x1,y1,x2,y2,c);
			break;
		case 'F':   
			cin >> x >> y >> c;
			k = Image[y-1][x-1];
			F(x,y,k,c);
			break;
		case 'S':   
			cin >> name;
// 			cout << name << endl;
			funS(name,m,n);
			break;
		case 'X':       
			return;
		default:
			break;
        }
    }
}

int main()
{
        read();
        return 0;
}
