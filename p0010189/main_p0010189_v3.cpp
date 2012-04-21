/* 
* File:   10189.cpp
* Author: GongZhi
* Problem: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=29&page=show_problem&problem=1130
* Created on 2009年7月25日, 下午9:08
*/

#include "stdlib.h"
#include "stdio.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

/*
 *
 */
char ans[200][200];
int P[8][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
    {1, -1},
    {1, 1},
    {-1, 1},
    {-1, -1}
};

int main() {
    int n, m, i, j, k, t,kase=1;
    while (scanf("%d%d", &n, &m), n) {
        for (i = 0; i < n; i++)scanf("%s", ans[i]);
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++) {
                if (ans[i][j] == '*')continue;
                t = 0;
                for (k = 0; k < 8; k++)
                    if (i + P[k][0] >= 0 && i + P[k][0] < n && j + P[k][1] >= 0 && j + P[k][1] < m && ans[i + P[k][0]][j + P[k][1]] == '*')t++;
                ans[i][j] = '0' + t;
            }
            if(kase!=1)printf("\n");
            printf("Field #%d:\n",kase++);
            for(i=0;i<n;i++)printf("%s\n",ans[i]);
    }
    return 0;
}