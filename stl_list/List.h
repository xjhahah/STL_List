#pragma once
#include <iostream>
using namespace std;

template <class T>
struct ListNode
{
	ListNode<T>* _pPre;
	ListNode<T>* _pNext;
	T _data;
	ListNode(const T& data=T()) //匿名对象
		:_pPre(nullptr)
		,_pNext(nullptr)
		,_data(data)
	{}
};
template <class T,class Ref,class Ptr>
struct _ListIteartor
{
	typedef ListNode<T> Node;
	typedef _ListIteartor<T,Ref,Ptr> Self;
	Node* _node;

	_ListIteartor(Node* node)
		:_node(node)
	{}
	Ref operator* ()  //it.operator*(&it)=data;
	{
		return _node->_data;
	}
	Ptr operator->()
	{
		return &(_node->_data);
	}

	//++i
	Self& operator++()
	{
		_node = _node->_pNext;
		return *this;
	}
	//i++  operator++(&it, 0)   构成重载
	Self& operator++(int)
	{
		Self tmp(*this);
		_node = _node->_pNext;
		return tmp;
	}

	Self& operator--()
	{
		_node = _node->_pPre;
		return *this;
	}
	
	Self& operator--(int)
	{
		Self tmp(*this);
		_node = _node->_pPre;
		return tmp;
	}
	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}
};
template <class T>
class List
{
	typedef ListNode<T> Node;
public:
	typedef _ListIteartor<T,T&,T*> iterator;
	typedef _ListIteartor<T,const T&,const T*> const_iterator;

	iterator begin()
	{
		return iterator(_pHead->_pNext);
	}
	iterator end()
	{
		return iterator(_pHead);
	}

	const_iterator begin()const
	{
		return const_iterator(_pHead->_pNext);
	}
	const_iterator end()const
	{
		return const_iterator(_pHead->_pPre);
	}

	List()
		:_pHead(new Node)  
	{
		//带头双向循环链表
		_pHead->_pNext = _pHead;
		_pHead->_pPre = _pHead;
	}
	List(const List& l)
	{
		_pHead = new Node;
		-_pHead->_pNext = _pHead;
		_pHead->_pPre = _pHead;
		const_iterator it = begin();
		while (it != end())
		{
			PushBack(*it);
			++it;
		}
	}
	List<T>& operator=(List<T> l)
	{
		swap(_pHead,l->_pHead);
		return *this;
	}
	~List()
	{
		Clear();
		delete _pHead;
		_pHead = nullptr;
	}
	void PushBack(const T& data);
	void PopBack();
	void PushFront(const T& data);
	void PopFront();
	void Insert(iterator pos, const T& data);
	void Erase(iterator pos);
	size_t Size();
	bool Empty();
	void Clear();

private:
	Node* _pHead;
};

void TestList1();
void TestList2();
