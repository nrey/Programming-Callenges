#include <iostream>
#include <list>

using namespace std;

struct point
{
    point(int x, int y) : x(x), y(y) {}
    int x, y;
};

void swaparoo(int& a, int& b)
{
    if (b < a)
        swap(a, b);
}

void myfill(list<point> &stack, char buffer[][252], int x, int y, char fillFrom, char fillTo, int m, int n)
{
    if (buffer[x][y] != fillFrom || buffer[x][y] == fillTo)
        return;

    if (x < 1 || x > m || y < 1 || y > n)
        return;  

    buffer[x][y] = fillTo;

    // Can't tail recurse, will need to switch to managing stck ourself
    stack.push_back(point(x-1, y));
    stack.push_back(point(x+1, y));
    stack.push_back(point(x, y-1));
    stack.push_back(point(x, y+1));
}

void myfill(char buffer[][252], int x, int y, char color, int m, int n)
{
    list<point> stack;
    char colorAtXY(buffer[x][y]);

    if (color == colorAtXY)
        return;

    stack.push_back(point(x, y));
    while (!stack.empty())
    {
        list<point>::iterator loc(stack.end());
        --loc;
        point pt(*loc);
        stack.pop_back();
        myfill(stack, buffer, pt.x, pt.y, colorAtXY, color, m, n);
    }
}

int main(int argc, char **argv)
{
    char c;
    int m(0), n(0);
    char buffer[252][252]; // lazy addressing for fun and profit

    // guard border
    for (int i(0); i < 252; i++)
        buffer[0][i] = buffer[251][i] = buffer[i][0] = buffer[i][251] = -1;

    while (cin >> c)
    {
        switch(c)
        {
        case 'I':
            cin >> m >> n;
            // cascade into 'C'
        case 'C':
            for (int y(1); y <= n; y++)
                for (int x(1); x <= m; x++)
                    buffer[x][y] = 'O';
            break;
        case 'L':
            {
                int x, y;
                char color;
                cin >> x >> y >> color;
                buffer[x][y] = color;
            }
            break;
        case 'V':
            {
                int x, y1, y2;
                char color;
                cin >> x >> y1 >> y2 >> color;
                swaparoo(y1, y2);
                for (int i(y1); i <= y2; ++i)
                    buffer[x][i] = color;
            }
            break;
        case 'H':
            {
                int x1, x2, y;
                char color;
                cin >> x1 >> x2 >> y >> color;
                swaparoo(x1, x2);
                for (int i(x1); i <= x2; ++i)
                    buffer[i][y] = color;
            }
            break;
        case 'K':
            // If we were relaly being smart this would be the general case and we'd just call this as a function.
            // But I'm lazy.  Actually.  We'd probably refactor most of this crap into a generic setter/fill function.
            {
                int x1, x2, y1, y2;
                char color;
                cin >> x1 >> y1 >> x2 >> y2 >> color;
                swaparoo(x1, x2);
                swaparoo(y1, y2);

                for (int y(y1); y <= y2; y++)
                    for (int x(x1); x <= x2; x++)
                        buffer[x][y] = color;
            }
            break;
        case 'F':
            {
                int x, y;
                char color;
                cin >> x >> y >> color;
                myfill(buffer, x, y, color, m, n);
            }
            break;
        case 'S':
            {
                std::string name;
                cin >> name;
                cout << name << endl;
                for (int y(1); y <= n; y++)
                {
                    for (int x(1); x <= m; x++)
                        cout << buffer[x][y];
                    cout << endl;
                }
            }
            break;
        case 'X':
            return 0;
            break;
        default:
                // Ignore the entire line; we'll assume it's <= 1000 characters after the errant command
                break;
        }
        cin.ignore(1000, '\n');
    }

    return 0;
}