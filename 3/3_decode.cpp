#include <fstream>
struct binlabel
{
	unsigned int i : 3;
	unsigned int data : 8;
	unsigned int p1 : 1;
	unsigned int j : 3;
	unsigned int p2 : 1;
};
union binu
{
	binlabel bl;
	unsigned short int val;
};
using namespace std;
int main()
{
	ifstream fin("outincode.txt");
	ofstream fout("outdecode.txt");
	binu incode[64];
	for (int i(0); i < 64; i++)
		fin >> incode[i].val;
	char decode[8][8];
	for (int i(0); i < 64; i++)
		decode[incode[i].bl.i][incode[i].bl.j] = char(incode[i].bl.data);
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