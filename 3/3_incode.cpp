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
	ifstream fin("inincode.txt");
	ofstream fout("outincode.txt");
	char info[8][9];
	for (int i(0); i < 8; i++)
		fin.getline(info[i], 9);
	for (int i(0); i < 8; i++)
		for (int j(strlen(info[i])); j < 8; j++)
			info[i][j] = ' ';
	binu incode[64];
	int ind = 0;
	for (int i(0); i < 8; i++)
		for (int j(0); j < 8; j++)
		{
			incode[ind].val = 0;
			incode[ind].bl.i = i;
			incode[ind].bl.data = info[i][j];
			int p = 0;
			for (int k(0); k < 11; k++)
				if (((incode[ind].val & (1 << k)) >> k) == 1)
					p++;
			if (p % 2) incode[ind].bl.p1 = 1;
			else incode[ind].bl.p1 = 0;
			incode[ind].bl.j = j;
			p = 0;
			for (int k(0); k < 3; k++)
				if (((j & (1 << k)) >> k) == 1)
					p++;
			if (p % 2) incode[ind].bl.p2 = 1;
			else incode[ind].bl.p2 = 0;
			ind++;
		}
	for (int i(0); i < 64; i++)
		fout << incode[i].val << ' ';
	fin.close();
	fout.close();
	system("pause");
	return 0;
}