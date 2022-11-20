#include <fstream>

using namespace std;
int main()
{
	ifstream fin("inincode.txt");
	ofstream fout("outincode.txt");
	char info[8][8];
	for (int i(0); i < 8; i++)
		fin.getline(info[i], 8);
	for (int i(0); i < 8; i++)
		for (int j(strlen(info[i])); j < 8; j++)
			info[i][j] = ' ';
	unsigned short int incode[64];
	int ind = 0;
	for (int i(0); i < 8; i++)
		for (int j(0); j < 8; j++)
		{
			incode[ind] = 0;
			incode[ind] |= i;
			incode[ind] |= (int(info[i][j]) << 3);
			int p = 0;
			for (int k(0); k < 11; k++)
				if (((incode[ind] & (1 << k)) >> k) == 1)
					p++;
			if (p % 2) incode[ind] |= (1 << 11);
			incode[ind] |= (j << 12);
			p = 0;
			for (int k(0); k < 3; k++)
				if (((j & (1 << k)) >> k) == 1)
					p++;
			if (p % 2) incode[ind] |= (1 << 15);
			ind++;
		}
	for (int i(0); i < 64; i++)
		fout << incode[i] << ' ';
	fin.close();
	fout.close();
	system("pause");
	return 0;
}