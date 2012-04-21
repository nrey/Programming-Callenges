#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char **argv)
{
    unsigned int n; // number of students on trip
    while (cin >> n && 0 != n)
    {
        double* payments = new double[n];
        double above(0), below(0), sum(0);
        for (unsigned int i(0); i < n; ++i)
        {
            cin >> payments[i];
            sum += payments[i];
        }
        double average(static_cast<double>(static_cast<long>(0.5 + ((sum / static_cast<double>(n)) * 100.0)))/100.0);
	
	std::cout << std::endl << "\t" << average;
	
        for (unsigned int i(0); i < n; ++i)
            if (payments[i] > average)
                above += payments[i] - average;
            else
                below += average - payments[i];
        delete[] payments;

        printf("$%.2f\n", min(above, below));

    }
    return 0;
}