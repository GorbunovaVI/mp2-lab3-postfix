#ifndef __STACK_H__
#define __STACK_H__

const int MaxStackSize = 100;

template <class T>
class TStack
{
  T *pMem;
  int size;
  int count;
public:
	TStack(int len);
	~TStack();
	void Push(T val);
	T Pop();
	T Top();
	int Getsize() { return size; };
	bool IsEmpty();
	bool IsFull();
};

template <class T>
TStack<T>::TStack(int len)
{
	if ((len < 1) || (len > MaxStackSize))
		throw (len);
	size = len;
	count = 0;
	pMem = new T[size];
}

template<class T>
TStack<T>::~TStack()
{
	delete[] pMem;
}

template <class T>
bool TStack<T>::IsEmpty()
{
	return (count == 0);
}

template<class T>
bool TStack<T>::IsFull()
{
	return(count == size);
}

template<class T>
void TStack<T>::Push(T val)
{
	if (IsFull())
		throw("stack");
	pMem[count++] = val;
}

template <class T>
T TStack<T> ::Pop()
{
	if (IsEmpty())
		throw("Stack");
	return pMem[(count--) - 1];
}

template <class T>
T TStack<T>::Top()
{
	if (IsEmpty())
		throw("Stack");
	return pMem[(count)-1];
}
#endif
