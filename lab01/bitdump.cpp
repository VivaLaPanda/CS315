#include<iostream>

void dumpBits0(unsigned long v, int digitsPrinted=0)
{
    if( v == 0 ) {
        int leadingZerosToPrint = sizeof(unsigned long) * 8 - digitsPrinted;
        for( int i = 0; i < leadingZerosToPrint; i++ ) 
            std::cout << 0;
    } else {
        dumpBits0(v / 2, digitsPrinted + 1);
        std::cout << ( v % 2 ? 1 : 0 );
    }
    if( digitsPrinted == 0 )
        std::cout << std::endl;
}

int main()
{
    unsigned long inValue = 1;  
    std::cout << "This program prints the bit representation of its input repeatedly.\n";
    std::cout << "The input should fit in a 64 bit integer. This is not enforced.\n"; 
    std::cout << "Enter 0 to stop the program.\n\n";

    while( inValue ) {
        std::cout << "Enter an unsigned integer (long) to see its "
                  << 8 * sizeof(unsigned long) << "-bit representation: ";
        std::cin >> inValue;
        dumpBits0(inValue);
    }
}
