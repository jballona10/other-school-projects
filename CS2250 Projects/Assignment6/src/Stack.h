#ifndef STACK_H
#define STACK_H

using std::ostream;

template <class T>
struct Node;

template <class T>
struct Node
{
        T value;
        Node<T> * next;
        Node(T = 0, Node * = nullptr);
};

template <class T>
Node<T>::Node(T data, Node * location)
{
        value = data;
        next = location;
}

template <class T>
class Stack;

template <class T>
ostream & operator<<(ostream &, const Stack<T> &);

template <class T>
class Stack
{
private:
        Node<T> * stkTop;
        unsigned int stackSize;
public:
        Stack();
        ~Stack();
        Stack(const Stack<T> &);
        Stack & operator=(const Stack<T> &);
        friend ostream & operator<< <>(ostream &, const Stack<T> &) const;
        void clear();
        unsigned int size() const;
        bool empty() const;
        const T & top() const;
        void push(const T &);
        void pop();
};

template <class T>
Stack<T>::Stack()
{
        stkTop = nullptr;
        stackSize = 0;
}

template <class T>
Stack<T>::~Stack()
{
        this->clear();
}

template <class T>
Stack<T>::Stack(const Stack<T> & obj)
{

        if (obj.stkTop == nullptr)
    {
                stkTop = nullptr;
        stackSize = 0;
    }
    else
    {
        Node * point = obj;
        while (point != nullptr)
        {
                Node * newNode = new Node;



        }
    }
}

template <class T>
ostream & operator<< <>(ostream & out, const Stack<T> & obj) const
{

}

template <class T>
void Stack<T>::clear()
{

}

template <class T>
unsigned int Stack<T>::size() const
{
        return this->stackSize;
}

template <class T>
bool Stack<T>::empty() const
{
        if (this->stackSize == 0)
                return true;
        return false;
}

template <class T>
const T & Stack<T>::top() const
{
        return this->stkTop->value;
}

template <class T>
void Stack<T>::push(const T & val)
{
        Node<T> * newNode = new Node<T>(val);
        if (this->stkTop == nullptr)
                stkTop = newNode;
        else
        {
                newNode->next = stkTop;
                stkTop = newNode;
        }
}
#endif
