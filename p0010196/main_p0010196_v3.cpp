#include<iostream>
#include<string>
#define MAX 8

using namespace std;

char board[MAX][MAX];
 
typedef struct Coordinates
{
        int x;
        int y;
} coordinates;

coordinates white, black;

bool isInCheck(int y, int x, char piece)
{
        if((x>=0 && x<=7) && (y>=0 && y<=7))
                if(board[y][x] == piece)
                        return true;
        return false;
}

bool blackPawn()
{
        //sprintf("Black pawn");
        if(isInCheck(white.y-1, white.x-1, 'p'))                return true;
        else if(isInCheck(white.y-1, white.x+1, 'p'))   return true;
        return false;
}

bool whitePawn()
{
        //printf("White pawn");
        if(isInCheck(black.y+1, black.x-1, 'P'))                return true;
        else if(isInCheck(black.y+1, black.x+1, 'P'))   return true;
        return false;
}

bool blackKnight()
{
        //printf("Black knight");
        if(isInCheck(white.y - 1, white.x - 2, 'n')) return true;
    if(isInCheck(white.y - 1, white.x + 2, 'n')) return true;
    if(isInCheck(white.y - 2, white.x - 1, 'n')) return true;
    if(isInCheck(white.y - 2, white.x + 1, 'n')) return true;
    if(isInCheck(white.y + 1, white.x - 2, 'n')) return true;
    if(isInCheck(white.y + 1, white.x + 2, 'n')) return true;
    if(isInCheck(white.y + 2, white.x - 1, 'n')) return true;
        if(isInCheck(white.y + 2, white.x + 1, 'n')) return true;
        
        return false;
}

bool whiteKnight()
{
        //printf("White Knight");
        if(isInCheck(black.y - 1, black.x - 2, 'N')) return true;
    if(isInCheck(black.y - 1, black.x + 2, 'N')) return true;
    if(isInCheck(black.y - 2, black.x - 1, 'N')) return true;
    if(isInCheck(black.y - 2, black.x + 1, 'N')) return true;
    if(isInCheck(black.y + 1, black.x - 2, 'N')) return true;
    if(isInCheck(black.y + 1, black.x + 2, 'N')) return true;
    if(isInCheck(black.y + 2, black.x - 1, 'N')) return true;
    if(isInCheck(black.y + 2, black.x + 1, 'N')) return true;
        
        return false;
}

bool whiteRookQueen()
{
        //printf("White Rook Queen");
        int x, y;
        x = black.x;
        
    while(--x >= 0)
        if(board[black.y][x] != '.') 
                {
            if((board[black.y][x] == 'R') || (board[black.y][x] == 'Q')) 
                                return true;
                        else 
                                break;
                }
                
        
    x = black.x;
    while(++x <= 7)
        if(board[black.y][x] != '.')
                {
            if((board[black.y][x] == 'R') || (board[black.y][x] == 'Q'))
                                return true;
                        else {
                                break;
                        }
                }
        
                
    y = black.y;
    while(--y >= 0)
        if(board[y][black.x] != '.')
                {
            if((board[y][black.x] == 'R') || (board[y][black.x] == 'Q'))
                                return true;
                        else {
                                break;
                        }
                }
                
                
    y = black.y;
    while(++y <= 7)
        if(board[y][black.x] != '.')
                {
            if((board[y][black.x] == 'R') || (board[y][black.x] == 'Q'))
                                return true;
                        else {
                                break;
                        }
                }
        return false;
}

bool blackRookQueen()
{
        int  x, y;
        
        x = white.x;
        while(--x >= 0)
        if(board[white.y][x] != '.')
                {
            if((board[white.y][x] == 'r') || (board[white.y][x] == 'q'))
                return true;
                        else {
                                break;
                        }               
                }               
                
        x = white.x;
    while(++x <= 7)
        if(board[white.y][x] != '.')
        {
                        if((board[white.y][x] == 'r') || (board[white.y][x] == 'q'))
                return true;
                        else {
                                break;
                        }
                }
                
        y = white.y;
    while(--y >= 0)
        if(board[y][white.x] != '.')
        {
                        if((board[y][white.x] == 'r') || (board[y][white.x] == 'q'))
                return true;
                        else {
                                break;
                        }
                }
        
    y = white.y;
    while(++y <= 7)
        if(board[y][white.x] != '.')
                {
            if((board[y][white.x] == 'r') || (board[y][white.x] == 'q'))
                return true;
                        else {
                                break;
                        }
                }               
        return false;
}

bool whiteBishopQueen()
{
        int x, y;
        
        x = black.x;
    y = black.y;
    while((--x >= 0) && (--y >= 0))
        if(board[y][x] != '.')
                {
            if((board[y][x] == 'B') ||(board[y][x] == 'Q'))
                return true;
                        else {
                                break;
                        }
                }
        

        x = black.x;
    y = black.y;
    while((++x <= 7) && (--y >= 0))
        if(board[y][x] != '.')
                {
            if((board[y][x] == 'B') ||(board[y][x] == 'Q'))
                                return true;
                        else {
                                break;
                        }
                }
                
        x = black.x;
    y = black.y;
    while((--x >= 0) && (++y <= 7))
        if(board[y][x] != '.')
        {
                        if((board[y][x] == 'B') ||(board[y][x] == 'Q'))
                return true;
                        else {
                                break;
                        }
                }
                
    x = black.x;
    y = black.y;
    while((++x <= 7) && (++y <= 7))
        if(board[y][x] != '.')
        {
                        if((board[y][x] == 'B') ||(board[y][x] == 'Q'))
                return true;
                        else {
                                break;
                        }
                }
        return false;
}

bool blackBishopQueen()
{
        int x,y;
        
        x = white.x;
    y = white.y;
        //printf("%d %d", x, y);
        
        while((--x >= 0) && (--y >= 0))
        if(board[y][x] != '.')
                {
            if((board[y][x] == 'b') || (board[y][x] == 'q'))
                return true;
                        else {
                                break;
                        }
                }
                
        x = white.x;
    y = white.y;
    while((++x <= 7) && (--y >= 0))
        if(board[y][x] != '.')
                {
            if((board[y][x] == 'b') || (board[y][x] == 'q'))
               return true;
                        else {
                                break;
                        }
                }
                
        x = white.x;
    y = white.y;
    while((--x >= 0) && (++y <= 7))
        if(board[y][x] != '.')
                {
            if((board[y][x] == 'b') || (board[y][x] == 'q'))
                return true;
                        else {
                                break;
                        }
                }
                
    x = white.x;
    y = white.y;
    while((++x <= 7) && (++y <= 7))
        if(board[y][x] != '.')
                {
            if((board[y][x] == 'b') || (board[y][x] == 'q')) 
                return true;
                        else {
                                break;
                        }
                }
        return false;
}



bool isTheEnd()
{
        for(int i=0; i<8; i++)
                for(int j=0; j<8; j++)
                        if(board[i][j] != '.')
                                return false;
        return true;
}

void read() 
{
        int counter = 1;
        while(true)
        {
                for(int i=0; i<8; i++)
            for(int j=0; j<8; j++)
            {
                cin >> board[i][j];
                if(board[i][j] == 'k')
                {
                    black.y = i;
                    black.x = j;
                }
                if(board[i][j] == 'K')
                {
                    white.y = i;
                    white.x = j;
                }
            }
                
                if(isTheEnd())
                        break;
                        
                if(blackPawn() || blackRookQueen() || blackBishopQueen() || blackKnight()) {
                        cout << "Game #" << counter++ << ": " << "white king is in check." << endl;
                }
                else if(whitePawn() || whiteKnight() || whiteRookQueen() || whiteBishopQueen())
                        cout << "Game #" << counter++ << ": "  << "black king is in check." << endl;
                else
                        cout << "Game #" << counter++ << ": " << "no king is in check." << endl;
                
        }
}

int main() 
{
        read();
        return 0;
}
