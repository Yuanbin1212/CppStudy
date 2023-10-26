#include <iomanip>
#include <iostream>


// int main()
// {
//     char ch;
//     while (std::cin >> ch)
//         std::cout << ch;

//     return 0;
// }

// int main()
// {
//     char ch;
//     while (std::cin.get(ch))
//         std::cout << ch;

//     return 0;
// }

// int main() {
//     char ch;
//     std::cout << "Enter a character: ";
//     std::cin.get(ch);
//     std::cout << "You entered: " << ch << std::endl;

//     char str[100];
//     std::cout << "Enter a string: ";
//     std::cin.ignore();  // 忽略之前的换行符
//     std::cin.getline(str, 100);
//     std::cout << "You entered: " << str << std::endl;

//     return 0;
// }

int main()
{
    char strBuf[11];
    // Read up to 10 characters
    std::cin.get(strBuf, 11);
    std::cout << strBuf << '\n';

    // Read up to 10 more characters
    std::cin.get(strBuf, 11);
    std::cout << strBuf << '\n';
    return 0;
}
