#include "List.h"

DoubleList::DoubleList()
    : _size(0), _iterator(nullptr)
{
}

DoubleList::DoubleList(const int value)
    : _size(1)
{
    Node* node = new Node;

    node->value = value;
    node->nextPoint = nullptr;
    node->prevPoint = nullptr;

    _last = node;
    _first = node;
    _iterator = node;
}

DoubleList::~DoubleList()
{
    for (uint i = 0; i < _size; i++) {

        PopBack();
    }
}

DoubleList::Node& DoubleList::Find(const uint pos)
{
    _iterator = _first;

    for(uint i = 0; i < pos - 1; i++) {

        _iterator = _iterator->nextPoint;
    }

    return *_iterator;
}

void DoubleList::PushBack(const int value)
{
    _size++;

    Node* node = new Node;

    node->value = value;
    node->prevPoint = _last;
    _last->nextPoint = node;
    node->nextPoint = nullptr;

    _last = node;
}

void DoubleList::Insert(const int value, const uint pos)
{
    if (pos == (_size + 1)) {

        PushBack(value);
    }
    else{

        _size++;

        Node* node = new Node;
        node->value = value;

        if ((pos - 1) == 0) {

            Find(pos).prevPoint = node;
            node->nextPoint = &Find(pos);
            node->prevPoint = nullptr;

            _first = node;
        }
        else {

            Find(pos).prevPoint = node;
            node->nextPoint = &Find(pos);
            node->prevPoint = &Find(pos - 1);
            Find(pos - 1).nextPoint = node;
        }
    }
}

void DoubleList::PopBack()
{
    if(_size == 1) {

        delete _last;
    }
    else {

        _iterator = _last->prevPoint;
        delete _last;

        _last = _iterator;
        _last->nextPoint = nullptr;
        _size--;
    }
}

void DoubleList::Pop(const uint pos)
{
    if (pos == _size) {

        PopBack();
    }
    else {

        if ((pos - 1) == 0) {

            _iterator = _first->nextPoint;
            delete _first;

            _first = _iterator;
            _first->prevPoint = nullptr;
            _size--;
        }
        else {

            delete &Find(pos);

            Find(pos - 1).nextPoint = &Find(pos + 1);
            Find(pos + 1).prevPoint = &Find(pos - 1);
            _size--;
        }
    }
}

ostream& operator<<(ostream& os, DoubleList& list)
{
   for (uint i = 1; i <= list._size; i++) {
   
        //os << "|" << "PREV: " <<  list.Find(i).prevPoint << "; My: " << &list.Find(i) << "; VALUE: " << list.Find(i).value  << "; NEXT: "  << list.Find(i).nextPoint << "|" << endl;
        os << list.Find(i).value << "\t"; 
   }
    
    return os;
}