// I think that we have to wait for all the inputs before sending the output
// make -j2;./p0010196exe < ../input.txt 2>&1|tee ../output.txt
// !!! MISTAKE
// Pense que el peon era facil de calcular, simplemente mirando a las direcciones 8 5 o 7 y 6, gran error porqu ele peon debe estar a una distancia de uno, asi que la embarre

// note
// dir_8 dir_1 dir_5
// dir_4       dir_2
// dir_7 dir_3 dir_6

#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <string.h>

static const int MAX_SIZE = 8;
char Chess[MAX_SIZE+1][MAX_SIZE+1];
int bKing_xy[2];
int wKing_xy[2];
char dot = '.'; // Estas comparaciones siempre son un problema para mi
char bKing = 'k';
char wKing = 'K';
int inCheck;
// char Chess_b[MAX_SIZE+1][MAX_SIZE+1];
// char Chess_w[MAX_SIZE+1][MAX_SIZE+1];

bool isWhite( char c )
{
	if( c == 'p' || c == 'r' || c == 'b' || c == 'q' || c == 'n' )
		return 0;
	return 1;
}

char isWhite2( char c, bool W )
{
	if( !isWhite( c ) )
	{
		if( W )
			return c;
		return 'y';
	}
	else
	{
		if( W )
			return 'y'; // A ficha del mismo bando
		return c;
	}
}

char dir_1( int* King_xy, bool W )
{
	for( int i = King_xy[0]-1; i>=0; --i )
	{
		
		if( Chess[i][King_xy[1]] != dot )
			return isWhite2( Chess[i][King_xy[1]], W );
	}
	return 'z';
}

char dir_2( int* King_xy, bool W )
{
	for( int j = King_xy[1]+1; j<8; ++j )
	{
		if( Chess[King_xy[0]][j] != dot )
			return isWhite2( Chess[King_xy[0]][j], W );
	}
	return 'z';
}

char dir_3( int* King_xy, bool W )
{
	for( int i = King_xy[0]+1; i<8; ++i )
	{
		if( Chess[i][King_xy[1]] != dot )
			return isWhite2( Chess[i][King_xy[1]], W );
	}
	return 'z';
}

char dir_4( int* King_xy, bool W )
{
	for( int j = King_xy[1]-1; j>=0; --j )
	{
		if( Chess[King_xy[0]][j] != dot )
			return isWhite2( Chess[King_xy[0]][j], W );
	}
	return 'z';
}

char dir_5( int* King_xy, bool W )
{
	int ii = King_xy[0]-1;
	int jj = King_xy[1]+1;
	while( ii >= 0 && jj<8 )
	{
		if( Chess[ii][jj] != dot )
			return isWhite2( Chess[ii][jj], W );
		ii--;
		jj++;
	}
	return 'z';
}

char dir_6( int* King_xy, bool W )
{
	int ii = King_xy[0]+1;
	int jj = King_xy[1]+1;
	while( ii<8 && jj<8 )
	{
		if( Chess[ii][jj] != dot )
			return isWhite2( Chess[ii][jj], W );
		ii++;
		jj++;
	}
	return 'z';
}

char dir_7( int* King_xy, bool W )
{
	int ii = King_xy[0]+1;
	int jj = King_xy[1]-1;
	while( ii<8 && jj>=0 )
	{
		if( Chess[ii][jj] != dot )
			return isWhite2( Chess[ii][jj], W );
		ii++;
		jj--;
	}
	return 'z';
}

char dir_8( int* King_xy, bool W )
{
	int ii = King_xy[0]-1;
	int jj = King_xy[1]-1;
	while( ii >= 0 && jj >= 0 )
	{
		if( Chess[ii][jj] != dot )
			return isWhite2( Chess[ii][jj], W );
		ii--;
		jj--;
	}
	return 'z';
}


void msjKin( int W, int count )
{
	if( W == 1 && inCheck == 0 )
	{
		std::cout << "Game #" << count << ": white king is in check.\n";
		inCheck = 1;
	}
	else if ( W == 0 && inCheck == 0)
	{
		std::cout << "Game #" << count << ": black king is in check.\n";
		inCheck = 1;
	}
	else if( inCheck == 0)
	{
		std::cout << "Game #" << count << ": no king is in check.\n";
	}
}

int main(void)
{
	int ii,jj;
	int count = 0;
	while(true)
	{
		inCheck = 0;
		count++;
		int out = 1;
		for( unsigned int i=0; i<8; ++i )
		{
			for( unsigned int j=0; j<8; ++j )
			{
				std::cin >> Chess[i][j];
				if( Chess[i][j] != dot )
					out = 0;
					
				if( Chess[i][j] == bKing )
				{
					bKing_xy[0] = i;
					bKing_xy[1] = j;
				}
					
				if( Chess[i][j] == wKing )
				{
					wKing_xy[0] = i;
					wKing_xy[1] = j;
				}
			}
		}
		if( out == 1 )
			break;

		// Each of the 8 directions (from the king point of view)
		char dir[8];
		
		dir[0] = dir_1(wKing_xy,1);
		dir[1] = dir_2(wKing_xy,1);
		dir[2] = dir_3(wKing_xy,1);
		dir[3] = dir_4(wKing_xy,1);
		dir[4] = dir_5(wKing_xy,1);
		dir[5] = dir_6(wKing_xy,1);
		dir[6] = dir_7(wKing_xy,1);
		dir[7] = dir_8(wKing_xy,1);
		
		
		for( int i=0; i<4; ++i )
		{
			if( dir[i] == 'r' || dir[i] == 'q' )
			{
				msjKin(1,count);
			}
		}
		
		for( int i=4; i<8; ++i )
		{
			if( dir[i] == 'b' || dir[i] == 'q' )
			{
				msjKin(1,count);
			}
		}
		
		// PEONES
		// !!! COMETI EL ERROR DE QUE REVISE SOLO 
// 		if( dir[4] == 'p' || dir[7] == 'p' )
// 		{
// 			msjKin(1,count);
// // 			flagWar = 1;
// 		}
		ii = wKing_xy[0] - 1;
		jj = wKing_xy[1] - 1;
		if( ii >= 0 && jj >= 0 && Chess[ii][jj] == 'p' )
		{
			msjKin(1,count);
		}
		
		ii = wKing_xy[0] - 1;
		jj = wKing_xy[1] + 1;
		if( ii >= 0 && jj <= 7 && Chess[ii][jj] == 'p' )
		{
			msjKin(1,count);
		}
		
		
		
		int kn[8][2];
		
		kn[0][0] = -2;
		kn[0][1] = +1;
		
		kn[1][0] = -1;
		kn[1][1] = +2;
		
		kn[2][0] = +1;
		kn[2][1] = +2;
		
		kn[3][0] = +2;
		kn[3][1] = +1;
		
		kn[4][0] = +2;
		kn[4][1] = -1;
		
		kn[5][0] = +1;
		kn[5][1] = -2;
		
		kn[6][0] = -1;
		kn[6][1] = -2;
		
		kn[7][0] = -2;
		kn[7][1] = -1;
		
		for( unsigned int kk=0; kk<8; ++kk )
		{
			int in = wKing_xy[0] + kn[kk][0];
			int jn = wKing_xy[1] + kn[kk][1];
			if( in>=0 && in<=7 && jn>=0 && jn<=7 )
			{
				if( Chess[in][jn]=='n' )
				{
					msjKin(1,count);
				}
			}
		}
		
		
		
		
		
		char dir2[8];
		
		dir2[0] = dir_1(bKing_xy,0);
		dir2[1] = dir_2(bKing_xy,0);
		dir2[2] = dir_3(bKing_xy,0);
		dir2[3] = dir_4(bKing_xy,0);
		dir2[4] = dir_5(bKing_xy,0);
		dir2[5] = dir_6(bKing_xy,0);
		dir2[6] = dir_7(bKing_xy,0);
		dir2[7] = dir_8(bKing_xy,0);

		
		for( int i=0; i<4; ++i )
		{
			if( dir2[i] == 'R' || dir2[i] == 'Q' )
			{
				msjKin(0,count);
			}
		}
		
		for( int i=4; i<8; ++i )
		{
			if( dir2[i] == 'B' || dir2[i] == 'Q' )
			{
				msjKin(0,count);
			}
		}
		
		// !!! BIG MISTAKE
// 		if( dir2[5] == 'P' || dir2[6] == 'P' )
// 		{
// 			msjKin(0,count);
// // 			flagWar = 1;
// 		}
		ii = bKing_xy[0] + 1;
		jj = bKing_xy[1] + 1;
		if( ii <= 7 && jj <= 7 && Chess[ii][jj] == 'P' )
		{
			msjKin(0,count);
		}
		
		ii = bKing_xy[0] + 1;
		jj = bKing_xy[1] - 1;
		if( ii <= 7 && jj >= 0 && Chess[ii][jj] == 'P' )
		{
			msjKin(0,count);
		}
		
		for( unsigned int kk=0; kk<8; ++kk )
		{
			int in = bKing_xy[0] + kn[kk][0];
			int jn = bKing_xy[1] + kn[kk][1];
			if( in>=0 && in<=7 && jn>=0 && jn<=7 )
			{
				if( Chess[in][jn]=='N' )
				{
					msjKin(0,count);
				}
			}
		}
		// iF NO RISK PRINT THE MSJ OF NO KING AT RISK
		msjKin(2,count);
	}
	return 0;
}
