#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
void my_swap(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

template <typename T, typename C, typename G>
G foo(T x, C y, G z)
{
	return x + y + z;
}

template <typename T>
void sort(T* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n - i - 1; ++j)
			if (arr[j] > arr[j + 1])  // T needs to have an implemented operator > !
				my_swap(arr[j], arr[j + 1]);
}

// Specialization
template<> // May be omitted
void sort(char** arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n - i - 1; ++j)
			if (strcmp(arr[j], arr[j + 1]) > 0)
				my_swap(arr[j], arr[j + 1]);
}

template <typename T>
T* my_find(T* begin, T* end, const T& val)
{
	for (; begin < end; ++begin)
		if (*begin == val) // T needs to have an implemented operator == !
			return begin;

	return nullptr;
}

template <typename T>
void print(T* arr, int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " "; // T needs to have an implemented operator << !

	cout << endl;
}

template <typename T>
void print(T* arr, int n, ostream& out)
{
	for (int i = 0; i < n; ++i)
		out << arr[i] << " ";

	out << endl;
}

template<typename T, int N>
class Array
{
public:
	int GetSize() const { return N; }

private:
	T m_array[N];
};

int main()
{

	// Generates and calls: double foo(int x, float y, double z)
	double calculation = foo(1, 2.0f, 3.2);
	cout << "Calculation = " << calculation << endl;

	char charArr[] = { 'd','a','z','b' };

	// Generates and calls: print(char*, int)
	print<char>(charArr, sizeof(charArr) / sizeof(charArr[0]));

	// Generates and calls: sort(char*, int)
	sort(charArr, sizeof(charArr) / sizeof(charArr[0]));

	// Calls already generated: print(char*, int)
	print(charArr, sizeof(charArr) / sizeof(charArr[0]));

	const char* strArr[] = { "Hello", "You", "To" };

	// Generates and calls: print(char**, int)
	print(strArr, sizeof(strArr) / sizeof(strArr[0]));

	// Calls the specialization function: sort(char**, int)
	sort(strArr, sizeof(strArr) / sizeof(strArr[0]));

	// Generates and calls: print(char**, int, ostream&)
	print(strArr, sizeof(strArr) / sizeof(strArr[0]), cout);

	// Calls already generated: print(char**, int)
	print(strArr, sizeof(strArr) / sizeof(strArr[0]));

	int aa[] = { 1,5,8,2,1,4 };

	// Generates and calls: my_find(int*, int*, const int&)
	int* five_ptr = my_find(aa, aa + (sizeof(aa) / sizeof(int)), 5);

	if (five_ptr)
	{
		cout << "Found address of 5 = " << five_ptr << endl;
		cout << "Actual address of 5 = " << /**five_ptr*/&aa[1] << endl;
	}

	ofstream out("out.txt");
	if (!out.is_open())
	{
		cerr << "Could not create file: Copy.txt\n";
		return -1;
	}
	print(aa, sizeof(aa) / sizeof(int), out);


	Array<int, 5> my_array;
	//int size = 5;
	//Array<size> my_array;
	cout << my_array.GetSize() << endl;

	cin.get();
}
