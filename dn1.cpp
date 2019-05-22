//
//  dn1.cpp
//  dn1
//
//  Created by Andrej Avbelj on 02/04/2019.
//  Copyright © 2019 Andrej Avbelj. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

void RadixBinarySort(std::vector<unsigned char> &N, std::vector<unsigned char> &M){
	
	std::vector<unsigned int> C (2,0); //2 je st elementov, 0 je default

	for (int i = 0; i < 8; ++i)
	{
		C[0] = 0;
		C[1] = 0;
		for (int j = 0; j < N.size(); ++j)
		{
			C[(N[j] >> i)&1]++;
			//cout << N[j] << " "<< ((N[j] >> i)&1) << endl;
		}
		C[1] += C[0];

		//cout << "C[0] = " << C[0] << " C[1] = " << C[1] <<endl;

		for (int x = N.size()-1; x >= 0; x--)
		{
			//cout << N[x] << " "<< ((N[x] >> i)&1) << endl;
			//cout << C[(N[x]>>i)&1]-1 << " " << ((N[x]>>i)&1) << endl;
			//cout << "C[0] = " << C[0] << " C[1] = " << C[1] << " C[(N[x]>>i)&1]-1 = " << C[(N[x]>>i)&1]-1 << endl;

			//M[C[(N[x]>>i)&1]-1] = ((N[x]>>i)&1);

			M[C[(N[x]>>i)&1]-1] = N[x];
			//cout << ((N[x]>>i)&1) << " "<< M[C[(N[x]>>i)&1]-1] << endl;

			C[(N[x]>>i)&1]--;
		}

		for (int k = 0; k < N.size(); ++k)
		{
			N[k] = M[k];
			//cout <<  M[k] << " " << ((N[k]>>i)&1) <<endl;
			//polje[k][i] = M[k];
		}
	}
}

using namespace std;
int main(int argc, char** argv)
{
	//bool bit = (A >> 0)&1;
	char  *file;
	int a = 0;
	std::vector<unsigned char> N;

	if(argc > 1){
		file = argv[1];
	}
	else{
		cout << "Niste podali vhodne datoteke!" << endl;
		return 0;
	}

	std::fstream myfile(file, std::ios_base::in);

    while(myfile >> a){
      N.push_back(a);
    }

	std::vector<unsigned char> M(N.size());

	RadixBinarySort(N, M);

	std::ofstream outFile("out.txt");
    for (const auto &e : N){
      outFile << (int)e << " ";
    }

    return 0;
}
