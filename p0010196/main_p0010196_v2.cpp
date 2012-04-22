#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    char board[12][12]; // board
    for (int i(0); i < 12; i++) for (int j(0); j < 12; j++) board[i][j] = '~';
    int blanks(0);          
    int game(1);
    for(;;)
    {
        // NULL OUT bad spots
        // Read in input, in event of blank board we're done.
        blanks = 0;
        for (int y(2); y < 10; ++y)
            for (int x(2); x < 10; ++x)
            {
                cin >> board[x][y];
                if ('.' == board[x][y]) blanks++;
            }

        if (64 == blanks)
            break;

        // White is uppercase, starts at bottom

        bool checkW(false), checkB(false);
        for (int y(2); y < 10 && !checkW && !checkB; ++y)
            for (int x(2); x< 10 && !checkW && !checkB; ++x)
            {
                switch (board[x][y])
                {
                    // Yeah.  Code duplication all over.  Suck it.
                    case '.':
                    default:
                        break;
                    // PAWNS
                    case 'p': // Black, moves down only
                        if ('K' == board[x-1][y+1] || 'K' == board[x+1][y+1])
                            checkW = true;
                        break;
                    case 'P': // White, moves up only
                        if ('k' == board[x-1][y-1] || 'k' == board[x+1][y-1])
                            checkB = true;
                        break;
                    // KNIGHTS
                    case 'n':
                       if ('K' == board[x+1][y+2] || 'K' == board[x+1][y-2] || 'K' == board[x+2][y+1] || 'K' == board[x+2][y-1] || 'K' == board[x-1][y+2] || 'K' == board[x-1][y-2] || 'K' == board[x-2][y+1] || 'K' == board[x-2][y-1])
                           checkW = true;
                        break;
                    case 'N':
                       if ('k' == board[x+1][y+2] || 'k' == board[x+1][y-2] || 'k' == board[x+2][y+1] || 'k' == board[x+2][y-1] || 'k' == board[x-1][y+2] || 'k' == board[x-1][y-2] || 'k' == board[x-2][y+1] || 'k' == board[x-2][y-1])
                           checkB = true;
                       break;
                    // BISHOPS
                    case 'b':
                    {
                        bool processing(true);
                        for (int i(x-1), j(y-1); processing && board[i][j] != '~'; i--, j--) 
				switch (board[i][j]) { 
					case 'K': checkW = true; break; 
					case '.': continue; break; 
					default: processing = false; break; }
				if (checkW) break; processing = true;
                        for (int i(x+1), j(y-1); processing && board[i][j] != '~'; i++, j--) switch (board[i][j]) { case 'K': checkW = true; break; case '.': continue; break; default: processing = false; break; }
                        if (checkW) break; processing = true;
                        for (int i(x+1), j(y+1); processing && board[i][j] != '~'; i++, j++) switch (board[i][j]) { case 'K': checkW = true; break; case '.': continue; break; default: processing = false; break; }                
                        if (checkW) break; processing = true;
                        for (int i(x-1), j(y+1); processing && board[i][j] != '~'; i--, j++) switch (board[i][j]) { case 'K': checkW = true; break; case '.': continue; break; default: processing = false; break; }
                        break;
                    }
                    case 'B':
                    {
                        bool processing(true);
                        for (int i(x-1), j(y-1); processing && board[i][j] != '~'; i--, j--) switch (board[i][j]) { case 'k': checkB = true; break; case '.': continue; break; default: processing = false; break; }
                        if (checkB) break; processing = true;
                        for (int i(x+1), j(y-1); processing && board[i][j] != '~'; i++, j--) switch (board[i][j]) { case 'k': checkB = true; break; case '.': continue; break; default: processing = false; break; }
                        if (checkB) break; processing = true;
                        for (int i(x+1), j(y+1); processing && board[i][j] != '~'; i++, j++) switch (board[i][j]) { case 'k': checkB = true; break; case '.': continue; break; default: processing = false; break; }
                        if (checkB) break; processing = true;
                        for (int i(x-1), j(y+1); processing && board[i][j] != '~'; i--, j++) switch (board[i][j]) { case 'k': checkB = true; break; case '.': continue; break; default: processing = false; break; }
                        break;
                    }
                    case 'r':
                    {
                        bool processing(true);
                        for (int j(y-1); processing && board[x][j] != '~'; j--) switch (board[x][j]) { case 'K': checkW = true; break; case '.': continue; break; default: processing = false; }
                        if (checkW) break; processing = true;
                        for (int j(y+1); processing && board[x][j] != '~'; j++) switch (board[x][j]) { case 'K': checkW = true; break; case '.': continue; break; default: processing = false; }
                        if (checkW) break; processing = true;
                        for (int i(x-1); processing && board[i][y] != '~'; i--) switch (board[i][y]) { case 'K': checkW = true; break; case '.': continue; break; default: processing = false; }
                        if (checkW) break; processing = true;
                        for (int i(x+1); processing && board[i][y] != '~'; i++) switch (board[i][y]) { case 'K': checkW = true; break; case '.': continue; break; default: processing = false; }
                        break;
                    }
                    case 'R':
                    {
                        bool processing(true);
                        for (int j(y-1); processing && board[x][j] != '~'; j--) switch (board[x][j]) { case 'k': checkB = true; break; case '.': continue; break; default: processing = false; }
                        if (checkB) break; processing = true;
                        for (int j(y+1); processing && board[x][j] != '~'; j++) switch (board[x][j]) { case 'k': checkB = true; break; case '.': continue; break; default: processing = false; }
                        if (checkB) break; processing = true;
                        for (int i(x-1); processing && board[i][y] != '~'; i--) switch (board[i][y]) { case 'k': checkB = true; break; case '.': continue; break; default: processing = false; }
                        if (checkB) break; processing = true;
                        for (int i(x+1); processing && board[i][y] != '~'; i++) switch (board[i][y]) { case 'k': checkB = true; break; case '.': continue; break; default: processing = false; }
                        break;
                    } 
                    case 'q':
                    {
                        bool processing(true);
                        for (int i(x-1), j(y-1); processing && board[i][j] != '~'; i--, j--) switch (board[i][j]) { case 'K': checkW = true; break; case '.': continue; break; default: processing = false; break; }
                        if (checkW) break; processing = true;
                        for (int i(x+1), j(y-1); processing && board[i][j] != '~'; i++, j--) switch (board[i][j]) { case 'K': checkW = true; break; case '.': continue; break; default: processing = false; break; }
                        if (checkW) break; processing = true;
                        for (int i(x+1), j(y+1); processing && board[i][j] != '~'; i++, j++) switch (board[i][j]) { case 'K': checkW = true; break; case '.': continue; break; default: processing = false; break; }                
                        if (checkW) break; processing = true;
                        for (int i(x-1), j(y+1); processing && board[i][j] != '~'; i--, j++) switch (board[i][j]) { case 'K': checkW = true; break; case '.': continue; break; default: processing = false; break; } 
                        if (checkW) break; processing = true;
                        for (int j(y-1); processing && board[x][j] != '~'; j--) switch (board[x][j]) { case 'K': checkW = true; break; case '.': continue; break; default: processing = false; }
                        if (checkW) break; processing = true;
                        for (int j(y+1); processing && board[x][j] != '~'; j++) switch (board[x][j]) { case 'K': checkW = true; break; case '.': continue; break; default: processing = false; }
                        if (checkW) break; processing = true;
                        for (int i(x-1); processing && board[i][y] != '~'; i--) switch (board[i][y]) { case 'K': checkW = true; break; case '.': continue; break; default: processing = false; }
                        if (checkW) break; processing = true;
                        for (int i(x+1); processing && board[i][y] != '~'; i++) switch (board[i][y]) { case 'K': checkW = true; break; case '.': continue; break; default: processing = false; } 
                        break;
                    }
                    case 'Q':
                    {
                        bool processing(true);
                        for (int i(x-1), j(y-1); processing && board[i][j] != '~'; i--, j--) switch (board[i][j]) { case 'k': checkB = true; break; case '.': continue; break; default: processing = false; break; }
                        if (checkB) break; processing = true;
                        for (int i(x+1), j(y-1); processing && board[i][j] != '~'; i++, j--) switch (board[i][j]) { case 'k': checkB = true; break; case '.': continue; break; default: processing = false; break; }
                        if (checkB) break; processing = true;
                        for (int i(x+1), j(y+1); processing && board[i][j] != '~'; i++, j++) switch (board[i][j]) { case 'k': checkB = true; break; case '.': continue; break; default: processing = false; break; }
                        if (checkB) break; processing = true;
                        for (int i(x-1), j(y+1); processing && board[i][j] != '~'; i--, j++) switch (board[i][j]) { case 'k': checkB = true; break; case '.': continue; break; default: processing = false; break; }
                        if (checkB) break; processing = true;
                        for (int j(y-1); processing && board[x][j] != '~'; j--) switch (board[x][j]) { case 'k': checkB = true; break; case '.': continue; break; default: processing = false; }
                        if (checkB) break; processing = true;
                        for (int j(y+1); processing && board[x][j] != '~'; j++) switch (board[x][j]) { case 'k': checkB = true; break; case '.': continue; break; default: processing = false; }
                        if (checkB) break; processing = true;
                        for (int i(x-1); processing && board[i][y] != '~'; i--) switch (board[i][y]) { case 'k': checkB = true; break; case '.': continue; break; default: processing = false; }
                        if (checkB) break; processing = true;
                        for (int i(x+1); processing && board[i][y] != '~'; i++) switch (board[i][y]) { case 'k': checkB = true; break; case '.': continue; break; default: processing = false; }
                        break;
                    }
                }

            }

        cout << "Game #" << game++ << ": " << ((checkB || checkW) ? ((checkB) ? "black king is in check" : "white king is in check") : "no king is in check") << "." << endl;
    }

    return 0;
}