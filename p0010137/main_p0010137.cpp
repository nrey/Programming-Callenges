// I think that we have to wait for all the inputs before sending the output
// make -j2;./p0010189exe < ../input.txt 2>&1|tee ../output.txt
#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

int main ( void )
{
	unsigned int n; // number of students on trip
	while (std::cin >> n && 0 != n)
	{
		double* payments = new double[n];
		double above(0), below(0), sum(0);
		for (unsigned int i(0); i < n; ++i)
		{
			std::cin >> payments[i];
			sum += payments[i];
		}
		
// 		double average = ceil(sum/(double)n*100)/100;
// 		std::cout << std::endl << "\t" << average;
		double average = ((double)floor((0.5 + ((sum / (double)n) * 100.0)))/100.0);
// 		double average = (double)((int)ceil(0.5 + ((sum / (double)n) * 100.0)))/100.0;
// 		std::cout << std::endl << "\t" << average;
	
// 		std::cout << std::endl << "\t" << average;
	
		for (unsigned int i(0); i < n; ++i)
			if (payments[i] > average)
				above += payments[i] - average;
			else
				below += average - payments[i];
		delete[] payments;

		printf("$%.2f\n", std::min(above, below));
	}
	return 0;

}
