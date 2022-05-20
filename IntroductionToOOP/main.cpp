//IntroductionToOOP
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n--------------------------------------------\n"

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//				Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "SingleArgumentConstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
		//pause
		//Paul
		//Shallow copy
		//Deep copy
	}
	//Class(const Class& other);
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//				Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Point& operator++()
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}

	//				Methods
	double distance(const Point& other)
	{
		//this - �����, ��� ������� �������� ����� 
		//		 (�� ������� ����� ����� ����������)
		//other - �����, �� ������� ����� ����� ����������.
		//this - ��� �����
		//other - ������ �����
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	//A.set_x(-10);
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}
double operator-(const Point& left, const Point& right)
{
	double x_distance = left.get_x() - right.get_x();
	double y_distance = left.get_y() - right.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}

//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK_1
//#define ASSIGNMENT_CHECK_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	//type name;
	int a;	//���������� ���������� 'a' ���� 'int'
	Point A;//���������� ���������� 'A' ���� 'Point'
			//���������� ������� 'A' ��������� 'Point'
			//�������� ���������� 'A' ��������� 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
	cout << (*pA).x << "\t" << (*pA).y << endl;

	cout << sizeof(Point) << endl;
	cout << typeid(A).name() << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE
	Point A;
	double x = 2, y = 3;
	//cout << "������� ���������� �����: "; cin >> x >> y;
	A.set_x(x);
	A.set_y(y);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << delimiter << endl;
	cout << "���������� �� ����� A �� ����� B: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "���������� �� ����� B �� ����� A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "���������� ����� ������� A � B:   " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "���������� ����� ������� B � A:   " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE

#ifdef CONSTRUCTORS_CHECK
	/*for (int i = 0; i < 10; i++)
{
	cout << i << "\t";
}
//cout << i << endl;
cout << endl;*/
	int a(2);
	cout << a << endl;

	Point A;	//Default constructor
	A.print();

	Point B = 5;//SingleArgumentConstructor
	B.print();

	Point C(8); //SingleArgumentConstructor
	C.print();

	Point D(2, 3);
	D.print();

	Point E = D;//Copy constructor
	E.print();

	Point F(D);	//Copy constructor
	F.print();

#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK_1
	//CopyAssignment  
	Point A(2, 3);
	Point B = A;//CopyConstructor ������ ��� ������ 'B' ���������
	Point C;	//Default constructor
	C = B;		//CopyAssignment ������ ��� ������ 'C' ��� ����������  
#endif // ASSIGNMENT_CHECK_1

#ifdef ASSIGNMENT_CHECK_2
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;
	A.print();
#endif // ASSIGNMENT_CHECK_2

	Point A(2, 3);
	Point B(7, 8);

	Point C = A + B;
	C.print();
	C++;
	C.print();

	cout << A - B << endl;  //������� ����� ��������� - ��� �������� ������ Point
	cout << operator -(A, B) << endl;//����� ����� ���������
}

/*
-------------------------------------------------------
.  - �������� ������� ������� (Point operator)
-> - �������� ���������� ������� (Arrow operator)
-------------------------------------------------------
*/

/*
-------------------------------------------------------
1. Encapsulation;
2. Inheritance;
3. Polymorphism;
-------------------------------------------------------
*/

/*
-------------------------------------------------------
					ENCAPSULATION
������������ �������:
	private:	�������� ����, ��������� ������ ������ ������
	public:		�������� ����, ��������� �� ������ ����� ���������
	protected:	���������� ����.
				���� ����������� ������� ������������ ���� ��� ������������.
				protected ���� �������� ������ ����� ������, � ��� �������� �������.
Get/Set-������:
	get (�����/��������) - ��������� �������� �������� �������� (private) ����������.
	get-������ ��������� ������ � ���������� ������ �� ������.
	set (������/����������) - ��������� �������� �������� ���������� ������ ������.
	set-������ ��������� ������ � ���������� ������ ������ �� ������.
-------------------------------------------------------
*/

/*
-------------------------------------------------------
~ - Tilda
1. � �����������;
2. ��� ����������;
3. �� ��������� (Default contructor) - ��� �����������, ������� ����� ���� ������ ��� ����������;
4. ����������� �����������;
5. ����������� ��������;
-------------------------------------------------------
*/
