#include <iomanip>
#include <iostream>


int main()
{
    std::cout.setf(std::ios::showpos); // turn on the std::ios::showpos flag
    std::cout << 27 << '\n';
    std::cout.setf(std::ios::showpos | std::ios::uppercase); // turn on the std::ios::showpos and std::ios::uppercase flag
    std::cout << 1234567.89f << '\n';

    std::cout.setf(std::ios::showpos); // turn on the std::ios::showpos flag
    std::cout << 27 << '\n';
    std::cout.unsetf(std::ios::showpos); // turn off the std::ios::showpos flag
    std::cout << 28 << '\n';

    std::cout.setf(std::ios::hex); // turn on hexadecimal output
    std::cout << 27 << '\n';    
    // Turn on std::ios::hex as the only std::ios::basefield flag
    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout << 27 << '\n';

    std::cout << "=====std::ios::boolalpha=====" << '\n';
    std::cout << true << ' ' << false << '\n';
    std::cout.setf(std::ios::boolalpha);
    std::cout << true << ' ' << false << '\n';
    std::cout << std::noboolalpha << true << ' ' << false << '\n';
    std::cout << std::boolalpha << true << ' ' << false << '\n';


    std::cout << "=====std::ios::uppercase=====" << '\n';
    std::cout << 12345678.9 << '\n';

    std::cout.setf(std::ios::uppercase);
    std::cout << 12345678.9 << '\n';
    std::cout << std::nouppercase << 12345678.9 << '\n';
    std::cout << std::uppercase << 12345678.9 << '\n';

    std::cout << 27 << '\n';

    std::cout << "=====std::ios::basefield=====" << '\n';
    std::cout.setf(std::ios::dec, std::ios::basefield);
    std::cout << 27 << '\n';

    std::cout.setf(std::ios::oct, std::ios::basefield);
    std::cout << 27 << '\n';

    std::cout.setf(std::ios::hex, std::ios::basefield);
    std::cout << 27 << '\n';

    std::cout << std::dec << 27 << '\n';
    std::cout << std::oct << 27 << '\n';
    std::cout << std::hex << 27 << '\n';

    std::cout.clear();
    std::cout << "=====Precision, notation, and decimal points=====" << '\n';
    std::cout << std::showpoint << '\n';
    std::cout << std::setprecision(3) << 123.456 << '\n';
    std::cout << std::setprecision(4) << 123.456 << '\n';
    std::cout << std::setprecision(5) << 123.456 << '\n';
    std::cout << std::setprecision(6) << 123.456 << '\n';
    std::cout << std::setprecision(7) << 123.456 << '\n';

    std::cout.clear();
    std::cout << std::fixed << '\n';
    std::cout << std::setprecision(3) << 123.456 << '\n';
    std::cout << std::setprecision(4) << 123.456 << '\n';
    std::cout << std::setprecision(5) << 123.456 << '\n';
    std::cout << std::setprecision(6) << 123.456 << '\n';
    std::cout << std::setprecision(7) << 123.456 << '\n';

    std::cout.clear();
    std::cout << std::scientific << '\n';
    std::cout << std::setprecision(3) << 123.456 << '\n';
    std::cout << std::setprecision(4) << 123.456 << '\n';
    std::cout << std::setprecision(5) << 123.456 << '\n';
    std::cout << std::setprecision(6) << 123.456 << '\n';
    std::cout << std::setprecision(7) << 123.456 << '\n';

    std::cout.clear();
    const double d = 1.2345678901234;
    std::cout << "The  default precision is " << std::cout.precision() << "\n\n";
    std::cout << "With default precision d is " << d << '\n';
    std::cout.precision(12);
    std::cout << "With high    precision d is " << d << '\n';

    std::cout << "=====Width, fill characters, and justification=====" << '\n';
    std::cout.unsetf(std::ios_base::basefield);
    std::cout << -12345 << '\n'; // print default value with no field width
    std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
    std::cout << std::setw(10) << std::left << -12345 << '\n'; // print left justified
    std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified
    std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internally justified

    std::cout.fill('*');
    std::cout << -12345 << '\n'; // print default value with no field width
    std::cout << std::setw(10) << -12345 << '\n'; // print default with field width
    std::cout << std::setw(10) << std::left << -12345 << '\n'; // print left justified
    std::cout << std::setw(10) << std::right << -12345 << '\n'; // print right justified
    std::cout << std::setw(10) << std::internal << -12345 << '\n'; // print internally justified


    std::cout << "=====格式化打印*=====" << '\n';
    for(int64_t i=0; i<5; i++){

        for(int64_t k=0; k<5-i; k++){
            std::cout  << '+';
        }

        for(int64_t j=0; j<i; j++){
            std::cout << j;
        }
        std::cout << '\n';
    }

    return 0;
}
