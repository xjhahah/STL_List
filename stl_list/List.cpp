#include "List.h"

template <class T>
void List<T>::PushBack(const T& data)
{
	//Node* tail = _pHead->_pPre;
	//Node* newNode = new Node(data);

	////_pHead newNode tail
	//tail->_pNext = newNode;
	//newNode->_pPre = tail;
	//_pHead->_pPre = newNode;
	//newNode->_pNext = _pHead;

	Insert(end(), data);
}

template <class T>
void List<T>::PopBack()
{
	Erase(--end());
}

template <class T>
void List<T>::PushFront(const T& data)
{
	Insert(begin(), data);
}

template <class T>
void List<T>::PopFront()
{
	Erase(begin());
}

template <class T>
void List<T>::Insert(iterator pos, const T& data)
{
	Node* cur = pos._node;
	Node* prev = cur->_pPre;
	Node* newNode = new Node(data);

	prev->_pNext = newNode;
	newNode->_pPre = prev;
	newNode->_pNext = cur;
	cur->_pPre = newNode;
}

template <class T>
void List<T>::Erase(iterator pos)
{
	Node* prev = pos._node->_pPre;
	Node* next = pos._node->_pNext;

	prev->_pNext = next;
	next->_pPre = prev;
	delete pos._node;
}

template <class T>
// O(N)µÄËã·¨
size_t List<T>::Size()
{
	size_t count = 0;
	iterator it = begin();
	while (it != end())
	{
		++count;
		++it;
	}
	return count;
}

template <class T>
bool List<T>::Empty()
{
	return _pHead == _pHead->_pNext;
}

template <class T>
void List<T>::Clear()
{
	iterator it = begin();
	while (it != end())
	{
		iterator del = it;
		++it;
		delete del._node;
	}
	_pHead->_pNext = _pHead;
	_pHead->_pPre = _pHead;
}




void TestList1()
{
	List<int> l;
	l.PushBack(1);
	l.PushBack(2);
	l.PushBack(3);
	l.PushBack(4);
	l.PushBack(5);
	
	cout << l.Size() << endl;
	List<int>::iterator it = l.begin();
	while (it != l.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}

//²âÊÔoperator*()   operator->()
class Date
{
public:
	int _year = 2018;
	int _month = 11;
	int _day = 27;
};
void TestList2()
{
	Date d;
	List<Date> l;
	l.PushBack(d);
	l.PushBack(d);
	l.PushBack(d);

	for (auto e : l)
	{
		cout << e._year << "-";
		cout << (&e)->_month << "-";
		cout << e._day << endl;
	}
	cout << endl;
}
