#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//int ReadFile(const char*file)
//{
//
//	if (file == NULL)
//	{
//		return 1;
//	}
//	FILE*fout = fopen(file, "r");
//	if (fout == NULL)
//	{
//		//return errno;
//		if (errno == 2)
//		{
//			string e("�ļ�������");
//			throw e;
//		}
//	}
//	else
//	{
//		cout << "��ȡ�ļ�" << endl;
//		return 0;
//	}
//}
//int main()
//{
//	try
//	{
//		cout << ReadFile("test.txt") << endl;
//	}
//	
//	catch (int errId)
//	{
//		cout << "����int���͵��쳣";
//	}
//	return 0;
//}
//template<class T>
//class Scoped
//{
//public:
//	Scoped(T *ptr) :_ptr(ptr)
//	{}
//	~Scoped()
//	{
//		printf("ptr=%p", _ptr);
//		delete _ptr;
//	}
//	T& operator *()
//	{
//		return *_ptr;
//	}
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//private:
//	Scoped(const T &ptr);
//
//	T* _ptr;
//};
//struct Date
//{
//	int year;
//	int month;
//	int day;
//};
//int main()
//{
//	Scoped<Date>temp(new Date);
//	//*temp = 0;
//	//*temp = 1;
//	//*temp = 2;
//	temp->year = 2017;
//	temp->month = 9;
//	temp->day = 18;
//	return 0;
//}
//template<class T>
//class ScopedArray
//{
//public:
//	ScopedArray( T *ptr) :_ptr(ptr)
//	{}
//	~ScopedArray()
//	{
//		printf("ptr=%p", _ptr);
//		delete[] _ptr;
//	}
//	T& operator *()
//	{
//		return *_ptr;
//	}
//	T* operator+(int n)
//	{
//		T*ret = (_ptr+n);
//		return ret;
//	}
//	T&operator[](int n)
//	{
//		return *(_ptr + n);
//	}
//private:
//	ScopedArray(const T &ptr);
//	void operator=(const T&ptr);
//	T* _ptr;
//};
//struct Date
//{
//	int year;
//	int month;
//	int day;
//};
//int main()
//{
//	ScopedArray<int> t1(new int[5]);
//	ScopedArray<string> t2(new string[5]);
//	ScopedArray<Date>temp(new Date[5]);
//	string s1("123");
//	(*(t2 + 0)) = s1;
//	t1[0]= 1;
//	temp[0].year = 1999;
//	temp[0].month = 9;
//	temp[0].day = 9;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//template<class T>
//class weakptr;
//template<class T>
//class shareptr
//{
//
//public:
//	shareptr( T*ptr=NULL) 
//		:_ptr(ptr),
//		_pcount(new int(1))
//	{};
//	shareptr(const shareptr<T>& object)
//		:_ptr(object._ptr),
//		_pcount(object._pcount)
//	{
//		++(*_pcount);
//	}
//	~shareptr()
//	{
//		if (--(*_pcount) == 0)
//		{
//			printf("%p\n", _ptr);
//			delete _ptr;
//			delete _pcount;
//		}
//	}
//	shareptr<T>& operator=(const shareptr<T> &object)
//	{
//		if (--(*_pcount) == 0)
//		{
//			delete _ptr;
//			delete _pcount;
//		}
//		_ptr = object._ptr;
//		_pcount = object._pcount;
//		++(*_pcount);
//		return *this;
//	}
//	T operator*()
//	{
//		return *_ptr;
//	}
//	T*operator->()
//	{
//		return _ptr;
//	}
//	friend class weakptr<T>;
//private:
//	T* _ptr;
//	int* _pcount;
//
//};
//
//template<class T>
//class weakptr
//{
//public:
//	weakptr()
//		:_ptr(NULL)
//	{};
//	weakptr( shareptr<T>&object)
//		:_ptr(object._ptr)
//	{};
//	T operator*()
//	{
//		return *_ptr;
//	}
//	T*operator->()
//	{
//		return _ptr;
//	}
//
//private:
//	T* _ptr;
//
//};
//
//struct listnode
//{
//	shareptr<listnode>next;
//	shareptr<listnode>prev;
//};
//struct ListNode
//{
//	weakptr<ListNode>next;
//	weakptr<ListNode>prev;
//};
//void testshareptr()
//{
//	shareptr<listnode>cur = new listnode;
//	shareptr<listnode>next = new listnode;
//	���ѭ�����ã�������������ֵ֮������cur->next������next���ͷ�Ȩ��
//	��next->prev������cur���ͷ�Ȩ����cur��next���˺�����Χ֮�����ǵ���Դ����
//	cur->next��next->prev�����ţ���ǰ��Ľڵ���Ҫ�ͷ�ʱ����ȵ��������ü���Ϊ0
//	Ҳ���ǰѺ���һ���ڵ��next->prev�ͷţ���next->prev���ͷ��ֱ���ȵ�cur->next�ͷ�
//	���Ծ����һ��ѭ��
//	cur->next= next;
//	next->prev = cur;
//}
//void testshareweakptr()
//{
//	shareptr<ListNode>cur = new ListNode;
//	shareptr<ListNode>next = new ListNode;
//	cur->next = next;
//	next->prev = cur;
//}
//int main()
//{
//	//testshareptr();
//	testshareweakptr();
//	return 0;
//
//}