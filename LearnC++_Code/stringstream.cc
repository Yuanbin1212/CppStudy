#include <iostream>
#include <iomanip>

int main(){
    std::stringstream os_in;
    os_in << "en garde!\n"; // insert "en garde!" into the stringstream
    std::cout << os_in.str();

    std::stringstream os_in2;
    os_in2 << "12345 67.89"; // insert a string of numbers into the stream

    std::string strValue;
    os_in2 >> strValue;

    std::string strValue2;
    os_in2 >> strValue2;

    // print the numbers separated by a dash
    std::cout << strValue << " - " << strValue2 << '\n';

    std::stringstream os3;
    os3 << "Hello ";

    os3.str(""); // erase the buffer
    os3.clear(); // reset error flags

    os3 << "World! \n";
    std::cout << os3.str();

}