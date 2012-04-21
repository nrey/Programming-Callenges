#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
 
#define PRINTCHARV	'|'
#define PRINTCHARH	'-'
#define FILLCHAR	' '
 
using namespace std;
 
vector< char > row_fill(int cols, char c1, char c2, char c3)
{
	const int firstcol = 0, lastcol = cols - 1;
	vector< char > v(cols);
 
	v.at(firstcol) = c1;
	for(int i = firstcol + 1; i <= lastcol - 1; i++) {
		v.at(i) = c2;
	}
	v.at(lastcol) = c3;
 
	return v;
}
 
vector< char > row_mid(int cols)
{
	return row_fill(cols, FILLCHAR, PRINTCHARH, FILLCHAR);
}
 
vector< char > row_left_side(int cols)
{
	return row_fill(cols, PRINTCHARV, FILLCHAR, FILLCHAR);
}
 
vector< char > row_right_side(int cols)
{
	return row_fill(cols, FILLCHAR, FILLCHAR, PRINTCHARV);
}
 
vector< char > row_both_sides(int cols)
{
	return row_fill(cols, PRINTCHARV, FILLCHAR, PRINTCHARV);
}
 
vector< char > row_empty(int cols)
{
	return row_fill(cols, FILLCHAR, FILLCHAR, FILLCHAR);
}
 
vector< vector< char > > col_empty(int s)
{
	const int rows = 2 * s + 3;
	vector< vector< char > > v(rows);
 
	for(int i = 0; i < rows; i++) {
		v.at(i).push_back(FILLCHAR);
	}
 
	return v;
}
 
vector< vector< char > > lcd(int s, int n)
{
	const int rows = 2 * s + 3;
	const int cols = s + 2;
	const int firstrow = 0,
		midrow = static_cast<int>(floor(rows / 2.00)),
		lastrow = rows - 1;
	vector< vector< char > > v(rows);
	vector< char > (*table[10][5])(int) = {
	// 0
	{row_mid, row_both_sides, row_empty, row_both_sides, row_mid},
	// 1
	{row_empty, row_right_side, row_empty, row_right_side, row_empty},
	// 2
	{row_mid, row_right_side, row_mid, row_left_side, row_mid},
	// 3
	{row_mid, row_right_side, row_mid, row_right_side, row_mid},
	// 4
	{row_empty, row_both_sides, row_mid, row_right_side, row_empty},
	// 5
	{row_mid, row_left_side, row_mid, row_right_side, row_mid},
	// 6
	{row_mid, row_left_side, row_mid, row_both_sides, row_mid},
	// 7
	{row_mid, row_right_side, row_empty, row_right_side, row_empty},
	// 8
	{row_mid, row_both_sides, row_mid, row_both_sides, row_mid},
	// 9
	{row_mid, row_both_sides, row_mid, row_right_side, row_mid}
	};
 
	for(int i = 0; i < rows; i++) {
		v.at(i).resize(cols);
	}
 
	v.at(firstrow) = (*table[n][0])(cols);
 
	for(int i = firstrow + 1; i <= midrow - 1; i++) {
		v.at(i) = (*table[n][1])(cols);
	}
 
	v.at(midrow) = (*table[n][2])(cols);
 
	for(int i = midrow + 1; i <= lastrow - 1; i++) {
		v.at(i) = (*table[n][3])(cols);
	}
 
	v.at(lastrow) = (*table[n][4])(cols);
 
	return v;
}
 
ostream& operator<<(ostream &out, const vector< vector< char > > &v)
{
 
	vector< vector< char > >::const_iterator p;
 
	for(p = v.begin(); p < v.end(); p++) {
		copy((*p).begin(), (*p).end(),
			ostream_iterator< char >(cout, ""));
		cout<<endl;
	}
 
	return out;
}
 
int main(int argc, char *argv[])
{
	int s = -1, n = -1;
 
	cin>>s>>n;
	while(s != 0) {
		const int rows = 2 * s + 3;
 
		ostringstream oss;
		oss<<n;
		istringstream iss(oss.str());
 
		vector< vector< char > >v(rows);
		char c;
		int counter = 0;
		while(iss>>c) {
			int digit = c - '0';
			vector< vector< char > > vd = lcd(s, digit);
 
 
			if(counter > 0) {
				vector< vector< char > > ve
					= col_empty(s);
 
				for(int i = 0; i < rows; i++) {
					copy(ve.at(i).begin(),
						ve.at(i).end(),
						back_inserter(v.at(i)));
				}
			}
 
			for(int i = 0; i < rows; i++) {
				copy(vd.at(i).begin(),
					vd.at(i).end(),
					back_inserter(v.at(i)));
			}
 
			counter++;
		}
		cout<<v<<endl;
 
		cin>>s>>n;
	}
 
	return 0;
}