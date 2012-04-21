// I think that we have to wait for all the inputs before sending the output
// make -j2;./p0010189exe < ../input.txt 2>&1|tee ../output.txt
#include <iostream>
#include <vector>

int main ( void )
{

	std::string bomb = "*";
	unsigned int count = 0;
// 	std::vector< std::vector< std::vector< unsigned char > > > holder;
	unsigned short m,n;
	
	int flag = 0;
	while(true)
	{

		std::cin >> m >> n;
		if( (m == 0) && (n == 0) )
			break;

		
		std::vector< std::vector< unsigned char > > matrix;
		
		for( unsigned int i=0; i<m; ++i )
		{
			std::vector<unsigned char> matrix2;
// 			unsigned char nic = 0;
			for( unsigned int j=0; j<n; ++j )
			{
				matrix2.push_back(0);
			}
			matrix.push_back(matrix2);
		}
		

		for( int i=0; i<m; ++i )
		{
			std::string test;
			std::cin >> test;
// 			std::cout << std::endl << "\t";
			

			size_t found;

    			found=test.find_first_of("*");
      			while (found!=std::string::npos)
        		{
				// Hacer nueve casos ? 
				// Option 2
// 				std::cout<<std::endl<<i<<" "<<found;
				int i_min = std::max(0,i-1);
				int i_max = std::min(m-1,i+1);
				
				int j_min = std::max(0,(int)found-1);
				int j_max = std::min(n-1,(int)found+1);
				
				for( int i_1 = i_min; i_1<=i_max; ++i_1 )
				{
// 					std::cout<<i_1<<" "<<found-1<<" ";
					for( int j_1 = j_min; j_1<=j_max; ++j_1 )
					{
						if( !((i_1==i) && (j_1==(int)found)) )
							matrix.at(i_1).at(j_1)++;
						else
// 						{
							matrix.at(i_1).at(j_1) = 9;
// 							std::cout << "aca";
// 						}
// 						std::cout<<i<<" "<<found<<";";
					}
				}
	        		found=test.find_first_of("*",found+1);
		  	}
		}
		if( flag == 1 )
			std::cout << std::endl;
		flag = 1;
// 		holder.push_back(matrix);
// 	}
// 	std::cout << std::endl;
	// Print Rersult
// 	for( unsigned int k=0; k<holder.size(); ++k )
// 	{

		std::cout << "Field #" << ++count <<":";
		for( unsigned int i=0; i<matrix.size(); ++i )
		{
			std::cout << std::endl;
			for( unsigned int j=0; j<matrix.at(i).size(); ++j )
			{
				if( (int)matrix.at(i).at(j) >= 9 )
					std::cout << "*";
				else
					std::cout << (int)matrix.at(i).at(j);
			}
		}
		std::cout << std::endl;

	}
	
		//std::getline(std::cin, test);
		//std::cout << "\n nic: " << test;

	
// 	}

	return 0;

}
