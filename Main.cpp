// Новохатский Максим КМБО-05-20
// Двухсвязный Список

#include "List.h"

int main()
{
    DoubleList list(1);

    list.PushBack(2);
    list.PushBack(3);
    list.PushBack(4);

    cout << "SIZE: " << list.GetSize() << endl << endl;
    cout << list << endl;

    list.Insert(9, 5);

    cout << "SIZE: " << list.GetSize() << endl << endl;
    cout << list << endl;

    list.PopBack();
    cout << "SIZE: " << list.GetSize() << endl << endl;
    cout << list << endl;

    list.Pop(4);
    cout << "SIZE: " << list.GetSize() << endl << endl;
    cout << list << endl;

    list.~DoubleList();

    DoubleList list1(1);
    cout << "SIZE: " << list1.GetSize() << endl << endl;
    cout << list1 << endl;

    list1.PopBack();

    cout << "EXIT" << endl;

    return 0;
}