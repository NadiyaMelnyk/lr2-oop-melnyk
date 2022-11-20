#include <fstream>

using namespace std;
int main()
{
	ifstream fin("outincode.txt");
	ofstream fout("outdecode.txt");

	unsigned short int incode[64];
	for (int i(0); i < 64; i++)
		fin >> incode[i];
	char decode[8][8];
	for (int i(0); i < 64; i++)
		decode[incode[i] & 7][(incode[i] & 28672) >> 12] = char((incode[i] & 2040) >> 3);
	for (int i(0); i < 8; i++)
	{
		for (int j(0); j < 8; j++)
			fout << decode[i][j];
		fout << endl;
	}
	fin.close();
	fout.close();
	system("pause");
	return 0;
}