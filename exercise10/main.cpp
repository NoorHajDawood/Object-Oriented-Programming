#include <iostream>
#include <fstream>

using namespace std;

struct Person
{
	char name[50];
	int age;
	char phone[24];
};

int main()
{
	Person me = { "Robert", 28, "364-2534" };
	int book[30] = {1};
	int x = 123;
	double fx = 34.54;
	ofstream outfile;
	outfile.open("junk.dat", ios::binary | ios::out);
	outfile.write((char*)&x, sizeof(int)); // sizeof can take a type
	outfile.write((char*)&fx, sizeof(fx)); // or it can take a variable name
	outfile.write((char*)&me, sizeof(me));
	outfile.write((char*)book, 30 * sizeof(int));
	outfile.close();

	ifstream infile;
	infile.open("junk.dat", ios::binary | ios::in);
	int y = 0;
	double fy = 0;
	Person p;
	int booky[30];
	infile.read((char*)&y, sizeof(y));
	infile.read((char*)&fy, sizeof(fy));
	infile.read((char*)&p, sizeof(p));
	infile.read((char*)&booky, 30 * sizeof(int));

	cout << y << endl;
	cout << fy << endl;
	cout << p.age << endl;
	cout << p.name << endl;
	cout << p.phone << endl;
	for( int i = 0; i < 30; ++i)
		cout << booky[i] << ",";

	cin.get();
}