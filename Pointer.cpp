#include <iostream>
#include "Sort.cpp"
#include "Misc.cpp"
#include <Windows.h>
int Sum(int a, int b)
{
	return a + b;
}
int Multiply(int a, int b)
{
	return a * b;
}
int Subtract(int a, int b)
{
	return a - b;
}
int MathOperations(int a, int b, int (*CurrentOperation)(int, int))
{
	return CurrentOperation(a, b);
}

int main()
{
	SetConsoleOutputCP(1251);

	int a = 5;
	double ad = 5.5;
	int b = 10;

	int* p = &a;

	const int f = 100;

	const int* cp;
	cp = &f;
	//*cp = 1;
	cp = &b;

	const int c = 24;
	const int* const ccp = &c;
	//*ccp = 1;
	//ccp = &b;
	int** pp = &p;

	int arr[3]{ 1,2,3 };

	int* ap = arr;
	int* nullp = nullptr;

	void* v;
	v = &a;
	std::cout << R"(-----ϳ�������� ������ ���������------
#include <iostream>
#include "Sort.cpp"
#include "Misc.cpp"

-----������� ���� �����------

int Sum(int a, int b)
{
	return a + b;
}

-----������� �������� �����------

int Multiply(int a, int b)
{
	return a * b;
}

-----������� �������� �����------

int Subtract(int a, int b)
{
	return a - b;
}

-----������� ���. ��������, � ��������� �������� ������� �� ���� � ������� ��� �������� ��� �������------

int MathOperations(int a, int b, int (*CurrentOperation)(int,int)) 
{
	return CurrentOperation(a, b);
}

-----������� ��������------

int main()
{
	int a = 5; ---- ���������� int ����� �
	double ad = 5.5; ---- ���������� double �����  ad 
	int b = 10; ---- ���������� int ����� b

	int* p = &a; ---- ��������� � ���������� ���'�� �������� p �� ������ ����� �

	const int f = 100;

	const int* cp; ---- ��������� �������� �� ��������� cp
	cp = &f; ---- ���������� ������ ����� f �� ��������� �� ��������� cp
	!----! *f = 1; ! - ��� ��� ���� ����������, ������� � ��� �������� �� ���������  
	cp = &a; ---- ������ �������� ������ ��� ������ � ��� ��������, ����� �� �� ���������� �����.

	[����� ���ǲ���� �� ��������� �� ������ߪ ��� �̲������ �������� �̲��ί, �� ��� ����������� ���ǲ����]
	[��� ����� ²���� �̲������ �����, �� ���� ����������� ����²����]

	const int c = 24; ---- ������� ��������� ����� c

	const int* const ccp = &c; -- ��������� ����������� �������� �� ��������� ccp.

	[��ʲ���� ���ǲ���� �� ��������� ��� � �� � �����������, �� ����� ������ �������� �� ���ϲ ���ϲ��ֲ�] 

		{ ��� ���� ���� �� �������, ������� �������� �� ��������� � �����������
		*ccp = 1; ---- �� �� ������ �������� ��������, ������� �� �������� �� ���������
		ccp = &b; ---- �� �� ������ ������ ������, ��� ������ � ��� ��������, ������� �������� � �����������
		}

	int** pp = &p; ---- ��������� �������� pp �� �������� p

	int arr[3]{ 1,2,3 }; ---- ��������� ����� arr � 3 �������: 1,2,3

	int *ap = arr; ---- ��������� �������� ap, ���� ���� ���������� �� arr. ���� & ��� arr �� �������, ������� �������� ����� � ���������� 
	int* nullp = nullptr; ---- ��������� �������� nullp, ���� �� ���� ���������� � �� ��� ������

	void* v; ---- ��������� void �������� v
	v = &a; ---- ������ �������� ������ int ����� �, �� ���� ������� ��  

	std::cout << "void* for int = " << *(static_cast<int*>(v)) << std::endl;
	output: void* for int = 5

	v = &ad; ---- ������ �������� ������ double ����� ad, �� ���� ������� ��  

	std::cout << "void* for double = " << *(static_cast<double*>(v)) << std::endl;
	output: void* for double = 5.5
	
	std::cout << *(ap) << " " << *(ap + 1) << " " << *(ap + 2) << std::endl; ---- �������� �� ����� ����� ������ ������� ���������� ���������
	output: 1 2 3

	----��������� ���������� �������� � �������----

	(��� �� ������ ���� ���������� �������� � �������.)
	(�������������� MathOperations(int a, int b, (*CurrentOperation)(int,int)) 
	- �� � ��������� �������� ��������, ��� ����� ������ ����������� 䳿, �� ��� ������� ������ �������, 
	�� ���� ���������� 䳿 ��� �������))

	std::cout << a << " + " << b << " = " << MathOperations(a, b, Sum) << std::endl;
	output: 5 + 10 = 15
	
	std::cout << a << " - " << b << " = " << MathOperations(a, b, Subtract) << std::endl;
	output: 5 - 10 = -5

	std::cout << a << " * " << b << " = " << MathOperations(a, b, Multiply) << std::endl;
	output: 5 * 10 = 50
}
)";
	/*std::cout << "void* for int = " << *(static_cast<int*>(v)) << std::endl;
	v = &ad;
	std::cout << "void* for double = " << *(static_cast<double*>(v)) << std::endl;
	std::cout << *(ap) << " " << *(ap + 1) << " " << *(ap + 2) << std::endl;
	std::cout << a << " + " << b << " = " << MathOperations(a, b, Sum) << std::endl;
	std::cout << a << " - " << b << " = " << MathOperations(a, b, Subtract) << std::endl;
	std::cout << a << " * " << b << " = " << MathOperations(a, b, Multiply) << std::endl;*/



}
