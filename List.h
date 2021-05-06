#pragma once

#include <iostream>

using namespace std;
typedef unsigned int uint;

class DoubleList
{
private:

    struct Node 
    {
        int value;

        Node* prevPoint;
        Node* nextPoint;
    };

    Node* _first;
    Node* _last;
    Node* _iterator;

    uint _size;

    Node& Find(const uint pos);

public:

    DoubleList();
	DoubleList(const int value);
    //DoubleList(const DoubleList&);

    ~DoubleList();

    void PushBack(const int value);
    void Insert(const int value, const uint pos);

    void PopBack();
    void Pop(const uint pos);

    uint GetSize() const { return _size; };

    

    friend ostream& operator<<(ostream& os, DoubleList& list);
};