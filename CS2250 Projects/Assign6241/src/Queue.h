#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <stdexcept>

using std::cout;
using std::cin;
using std::ostream;

template <class T>
class Queue;

template <class T>
ostream & operator <<(ostream &, const Queue<T> &);

template<class T>
class Queue
{
private:
	T * head;
	unsigned int qcapacity;
	unsigned int qsize;
	int qfront;
	int qback;
public:
	Queue();
	~Queue();
	Queue(const Queue & obj);
	Queue & operator=(const Queue & obj);
	void clear();
	unsigned int size();
	unsigned int capacity();
	bool empty();
	const T & front();
	const T & back();
	void push(const T &);
	void pop();
	void reserve(unsigned int);
	friend ostream & operator<< <>(ostream &, const Queue<T> &);
};

template <class T>
ostream & operator<<(ostream & out, const Queue<T> & obj)
{
	unsigned int i;

	for (int current = obj.qfront, i = 0; i < obj.qsize; ++i)
	{
		out << obj.head[current] << ' ';

		current = (current + 1) % obj.qcapacity;
	}

	return out;
}
template <class T>
Queue<T>::Queue()
{
	qsize = 0;
	qcapacity = 0;
	head = NULL;
	qfront = 0;
	qback = -1;
}

template<class T>
Queue<T>::~Queue()
{
	delete [] head;
}

template<class T>
Queue<T>::Queue(const Queue & obj)
{
	if (obj.empty)
		return;
	qsize = obj.qsize;
	qcapacity = obj.qcapacity;
	qfront = obj.qfront;
	qback = obj.qback;
	head = new int [qsize];
	for (int i = 0; i < qcapacity - 1; i++)
		head[i] = obj.head[i];
}

template<class T>
Queue<T> & Queue<T>::operator=(const Queue & obj)
{
	if (obj.empty)
		return;
	qsize = obj.qsize;
	qcapacity = obj.qcapacity;
	head = new int [qsize];
	for (int i = 0; i < qcapacity - 1; i++)
		head[i] = obj.head[i];
}

template<class T>
void Queue<T>::clear()
{
	this->qsize = 0;
	this->qfront = 0;
	this->qback = 0;
}

template<class T>
unsigned int Queue<T>::size()
{
	return this->qsize;
}

template<class T>
unsigned int Queue<T>::capacity()
{
	return this->qcapacity;
}

template<class T>
bool Queue<T>::empty()
{
	if (this->qsize == 0)
		return true;
	return false;
}

template<class T>
const T & Queue<T>::front()
{
	return this->head[qfront];
}

template<class T>
const T & Queue<T>::back()
{
	return this->back[qback];
}

template<class T>
void Queue<T>::reserve(unsigned int val)
{
	if (val < this->qsize || val == this->capacity)
		return;
	this->qcapacity = val;
	T * temp;
	if (this->qcapacity == 0)
		temp = NULL;
	else
	{
		temp = new T [val];
		for (int i = 0; i < this->qback; i++)
			temp[i] = this->head[i];
	}
}

#endif
