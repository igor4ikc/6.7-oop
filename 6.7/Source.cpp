#include<iostream>	

using namespace std;

//template <class T>
//class Predicat
//{
//public:
//	virtual bool operator() (T x) = 0;
//};

template<class T>
class Bilsh0
{
public:
	bool operator() (T x)
	{
		T zero = T();
		return x > zero;
	}
};

template <class T>
bool contains(T* begin, T* end, T elem)
{
	for (T* from = begin; from < end; from++)
	{
		if (*from == elem)
			return true;
	}
	return false;
}

template <class T>
int set_or(T* begin1, T* end1, T* begin2, T* end2, T* beginR, T* endR)
{
	int count = 0;
	T* to = beginR;
	for (T* from = begin1; from < end1; from++)
	{
		if (!contains(beginR, endR, *from))
		{
			*to++ = *from;
			count++;
		}
	}

	for (T* from = begin2; from < end2; from++)
	{
		if (!contains(beginR, endR, *from))
		{
			*to++ = *from;
			count++;
		}
	}
	return count;
}

template <class T>
int set_or_if(T* begin1, T* end1, T* begin2, T* end2, T* beginR, T* endR, Bilsh0<T>& p)
{
	int count = 0;
	T* to = beginR;
	for (T* from = begin1; from < end1; from++)
	{
		if (!contains(beginR, endR, *from))
			if (p(*from))
			{
				*to++ = *from;
				count++;
			}
	}
	for (T* from = begin2; from < end2; from++)
	{
		if (!contains(beginR, endR, *from))
			if (p(*from))
			{
				*to++ = *from;
				count++;
			}
	}
	return count;
}
int main()
{
	int a[5] = { -1,2,-3,4,-5 };
	int b[5] = { -1,-2,-3,4,5 };
	int d[10];

	//int n = set_or(&a[0],&a[5],&b[0],&b[5],&d[0],&d[10]);
	Bilsh0<int>* bilsh0 = new Bilsh0<int>();
	int n = set_or_if(&a[0], &a[5], &b[0], &b[5], &d[0], &d[10], *bilsh0);

	for (int* i = &d[0]; i < &d[0 + n]; i++)
		cout << *i << ' ';
	cout << endl;

}
