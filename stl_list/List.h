#pragma once
#include <iostream>
using namespace std;

template <class T>
struct ListNode
{
	ListNode<T>* _pPre;
	ListNode<T>* _pNext;
	T _data;
	ListNode(const T& data)
	{
		_pPre = nullptr;
		_pNext = nullptr;
		_data = data;
	}
};
template <class T>
struct _ListIteartor
{
	typedef ListNode<T> Node;
	Node* node;
	T& operator* ()
	{
		return node->_data;
	}
	T operator++()
	{
		node = node->_pNext;
		return *this;
	}
};
template <class T>
class List
{
	typedef ListNode<T> Node;
public:
	List()
		:_pHead(new Node(T()))  //匿名对象
	{
		//带头双向循环链表
		pHead->_pNext = _pHead;
		_pHead->_pPre = _pHead;
	}
	List(const List& l);
	List<T>& operator=(List<T> l);

	void PushBack(const T& data);
	void PopBack();
	void PushFront(const T& data);
	void PopFront();
	void Insert(iterator pos, const T& data);
	void Erase(iterator pos);
	size_t Size();
	bool Empty();

	~List()
	{
		if (_pHead)
		{
			delete[] _pHead;
			_pHead = nullptr;
		}
	}
private:
	Node* _pHead;
};

void TestList();
