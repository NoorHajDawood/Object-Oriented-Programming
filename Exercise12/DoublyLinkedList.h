#include <iostream>
#include <fstream>
using namespace std;

/******************************************************************************************/
template <class T>
class Node
{
    
public:
    Node(T* data)	: _data(data), _next(NULL), _prev(NULL) {}
    Node()			: _data(NULL), _next(NULL), _prev(NULL) {}
    ~Node()			{ delete _data; delete _next; }
 
public:
    Node*	next() const { return _next; }
    Node*	prev() const { return _prev; }
    void	setNext(Node* next) { _next = next; }
    void	setPrev(Node* prev) { _prev = prev; }

public:
    T*		data() const { return _data; }
    void	setData(T* data) { _data = data; }

private:
    Node<T>*	_next;
    Node<T>*	_prev;
    T* 			_data;
};

/******************************************************************************************/
template <class T>
class DoublyLinkedList
{
public:
    DoublyLinkedList() : _head(new Node<T>), _tail(new Node<T>)
    {
        _head->setNext(_tail);
        _tail->setPrev(_head);
    }
    ~DoublyLinkedList() { delete _head; }

public:
    void		insert(const T& item);
    Node<T>*	find (const T& item) const;
    void		remove (Node<T>* node);
    void		print() const;
    void		printReverse() const;

public:
    Node<T>*	begin() const { return _head->next(); }
    Node<T>*	end() const { return _tail; }

public:
    void		saveBin(ofstream& out) const;
    void		loadBin(ifstream& in);


private:
    Node<T>* _head;
    Node<T>* _tail;
};
/******************************************************************************************/
/*  Example (Inserting 4): HEAD -> 1 -> 2 -> 3 -> TAIL
                           HEAD -> 4 -> 1 -> 2 -> 3 -> TAIL
*/
template <class T>
void DoublyLinkedList<T>::insert(const T& item)
{
    // Allocates a Node and a copy of item (By calling T's copy constructor)
    Node<T>* newNode = new Node<T>(new T(item));
    
    Node<T>* currFirst = begin();
    newNode->setNext(currFirst);
    _head->setNext(newNode);
    newNode->setPrev(_head);
    currFirst->setPrev(newNode);
}

template <class T>
Node<T>* DoublyLinkedList<T>::find(const T& item) const
{
    Node<T>* p = begin();

    while (p != end())
    {
        // The following function needs to be implemented in class T for this line to work:
        //  bool operator == (const T& item) const;
        if (*(p->data()) == item)
            return p;

        p = p->next();
    }
    return p;
}

/*  Example (Removing 2): HEAD -> 4 -> 1 -> 2 -> 3 -> TAIL
                          HEAD -> 4 -> 1 -> 3 -> TAIL
 */
template <class T>
void DoublyLinkedList<T>::remove(Node<T>* node)
{
    node->prev()->setNext(node->next());
    node->next()->setPrev(node->prev());
    
    // We set the deleted node's next to NULL in order to avoid deletion of the list (Starting from node)
    node->setNext(NULL);
    delete node;
}

template <class T>
void DoublyLinkedList<T>::print() const
{
    Node<T>* p = begin();

    while (p != end())
    {
        // The following global function needs to be implemented for this line to work:
        // ostream& operator << (ostream& out, const T& item);
		cout << *(p->data()) << endl;
        p = p->next();
    }
}

template <class T>
void DoublyLinkedList<T>::printReverse() const
{
    Node<T>* p = _tail->prev();
    while (p != _head)
    {
        // The following function needs to be implemented for this line to work:
        // std::ostream& operator << (std::ostream& out, const T& item);
		cout << *(p->data()) << endl;
        p = p->prev();
    }
}

template <class T>
void DoublyLinkedList<T>::saveBin(ofstream& out) const
{
    Node<T>* p = begin();
    int count = 0;
    while (p != end())
    {
        ++count;
        p = p->next();
    }
    out.write((char*)&count, sizeof(count));
    p = begin();
    while (p != end())
    {
        // The following function needs to be implemented in class T for this line to work:
        //  void save (ofstream& out)
        p->data()->save(out);
        p = p->next();
    }
}

template <class T>
void DoublyLinkedList<T>::loadBin(ifstream& in)
{
    int count = 0;
    
    in.read((char*)&count, sizeof(count));
    
    for (int i = 0; i < count; ++i)
    {
        // Class T needs to have a default constructor for this line to work
        T item;
    
        // The following function needs to be implemented in class T for this line to work:
        //  void load (ifstream& in)
        item.load(in);
        
        insert(item);
    }
}