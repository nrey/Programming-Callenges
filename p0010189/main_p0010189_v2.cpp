/* 
 * A solution for the Minesweeper problem.
 * UVa ID: 10189
 */
#include <stdio.h>

#define MINE '*'
#define MATRIX_OFFSET 1

int main (int argc, const char * argv[]) {
	/* number of lines of the mine field */
	long n;
	
	/* number of colums of the mine field */
	long m;
	
	/* iterators for retrieving the content of each field line*/
	long i, j;
	
	/* field number identifier */
	long fieldNumber = 0;

	while(scanf("%ld %ld", &n, &m) != EOF) {
			
		/* 0 0, ends the program */
		if (!n && !m) {
			return 0;
		} else {
			if (fieldNumber > 0) {
				/* 
				 * workaround for the extra line on the output, 
				 * which was giving me a Wrong Answer verdict..
				 * so only insert an extra line if there's more
				 * to come :-) 
				 */
				printf("\n");
			}
		}
		
		/* increment field id */
		fieldNumber++;
				
		/* a bidimensional array representing the input mine field */
		char inputField[n + MATRIX_OFFSET + 1][m + MATRIX_OFFSET + 1];
		
		/* a bidimensional array to output the mine field */
		int outputField[n + MATRIX_OFFSET + 1][m + MATRIX_OFFSET + 1];
		
		/* temporary variable to retrieve mine field lines */
		char line[m];
		
		/* init, O(n2) */
		for (i = 0; i < n + MATRIX_OFFSET + 1; i++) {
			for (j = 0; j < m + MATRIX_OFFSET + 1; j++) {
				outputField[i][j] = 0;
			}
		}
		
		/* read mine field, O(n2) */
		for (i = 0; i < n; i++) {
			scanf("%s\n",line);
			for (j = MATRIX_OFFSET; j < m + MATRIX_OFFSET; j++) {
				inputField[i + MATRIX_OFFSET][j] = line[j - MATRIX_OFFSET];
			}
		}
		
		/* update output, O(n2) */ 
		for (i = MATRIX_OFFSET; i < n + MATRIX_OFFSET; i++) {
			for (j = MATRIX_OFFSET; j < m + MATRIX_OFFSET; j++) {
				if (inputField[i][j] == MINE) {
				
					/* upper neighbours */
					outputField[i-1][j-1]++;
					outputField[i-1][j]++;
					outputField[i-1][j+1]++;
					
					/* same level neighbours */
					outputField[i][j-1]++;
					outputField[i][j+1]++;
					
					/* lower neighbours */
					outputField[i+1][j-1]++;
					outputField[i+1][j]++;
					outputField[i+1][j+1]++;
				}
			}
		}
		
		/* present output, O(n2) */
		printf("Field #%ld:\n",fieldNumber);
		for (i = MATRIX_OFFSET; i < n + MATRIX_OFFSET; i++) {
			for (j = MATRIX_OFFSET; j < m + MATRIX_OFFSET; j++) {
				if (inputField[i][j] == MINE)
					printf("%c", MINE);
				else	
					printf("%d",outputField[i][j]);
			}
			printf("\n");
		}

	}

    return 0;
}