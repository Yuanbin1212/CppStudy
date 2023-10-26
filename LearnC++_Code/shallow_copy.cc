#include <cstring> // for strlen()
#include <cassert> // for assert()
#include <iostream>

class MyString
{
private:
    char* m_data{};
    int m_length{};

public:
    MyString(const char* source = "" )
    {
        assert(source); // make sure source isn't a null string

        // Find the length of the string
        // Plus one character for a terminator
        m_length = std::strlen(source) + 1;

        // Allocate a buffer equal to this length
        m_data = new char[m_length];

        // Copy the parameter string into our internal buffer
        for (int i{ 0 }; i < m_length; ++i)
            m_data[i] = source[i];
    }

    ~MyString() // destructor
    {
        // We need to deallocate our string
        std::cout << "调用析构函数" << '\n';
        delete[] m_data;
    }

    char* getString() { return m_data; }
    int getLength() { return m_length; }
};


#include <iostream>

int main()
{
    MyString hello{ "Hello, world!" };
    std::cout << "准备生成copy" << '\n';
    {   
        // free(): double free detected in tcache 2
        MyString copy{ hello }; // use default copy constructor
    } // copy is a local variable, so it gets destroyed here. 
    //The destructor deletes copy's string, which leaves hello with a dangling pointer
    std::cout << "copy生成结束" << '\n';
    std::cout << hello.getString() << '\n'; // this will have undefined behavior

    return 0;
}
