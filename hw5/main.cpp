//
//  main.cpp
//  hw5
//
//  Created by Valeria Dudinova on 15.10.2024.
//

#include <iostream>
#include <initializer_list>
using namespace std;

class MyString
{
private:
    char* str;
    size_t size;

public:
    MyString() : str(nullptr), size(0) {}

    // Конструктор з параметром initializer_list
    MyString(initializer_list<char> initList)
    {
        size = initList.size();
        str = new char[size + 1];
        size_t i = 0;
        for (char ch : initList)
        {
            str[i++] = ch;
        }
        str[size] = '\0';
    }

    // Конструктор переносу
    MyString(MyString&& other) noexcept
    {
        str = other.str;
        size = other.size;
        other.str = nullptr;
        other.size = 0;
    }

    MyString& operator=(MyString&& other) noexcept
    {
        if (this != &other)
        {
            delete[] str;
            str = other.str;
            size = other.size;
            other.str = nullptr;
            other.size = 0;
        }
        return *this;
    }

    ~MyString()
    {
        delete[] str;
    }

    void print() const
    {
        if (str != nullptr)
        {
            cout << str << endl;
        } else
        {
            cout << "String is empty" << endl;
        }
    }
};

int main()
{
    MyString obj{'H', 'e', 'l', 'l', 'o'};
    obj.print();

    MyString movedObj = move(obj);
    movedObj.print();
    obj.print();

    return 0;
}
