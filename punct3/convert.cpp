#include "sdt.h"
#include "convert1.h"
char convert_in_hex(uint16_t x)
{
    switch (x)
    {
    case 0b0000:
        return '0';
        break;
    case 0b0001:
        return '1';
        break;
    case 0b0010:
        return '2';
        break;
    case 0b0011:
        return '3';
        break;
    case 0b0100:
        return '4';
        break;
    case 0b0101:
        return '5';
        break;
    case 0b0110:
        return '6';
        break;
    case 0b0111:
        return '7';
        break;
    case 0b1000:
        return '8';
        break;
    case 0b1001:
        return '9';
        break;
    case 0b1010:
        return 'A';
        break;
    case 0b1011:
        return 'B';
        break;
    case 0b1100:
        return 'C';
        break;
    case 0b1101:
        return 'D';
        break;
    case 0b1110:
        return 'E';
        break;
    case 0b1111:
        return 'F';
        break;
    }
}

void print_in_hex1(uint16_t byte)
{
    char x1=' ';
    char x2=' ';
    char x3=' ';
    char x4=' ';
    uint16_t byte4=(byte&0b0000000000001111);
    x4=convert_in_hex(byte4);

    uint16_t byte3=(byte&0b0000000011110000)>>4;
    x3=convert_in_hex(byte3);

    uint16_t byte2=(byte&0b0000111100000000)>>8;
    x2=convert_in_hex(byte2);

    uint16_t byte1=(byte&0b1111000000000000)>>16;
    x1=convert_in_hex(byte1);
    cout <<x1<<x2<<x3<<x4;
}

void print_in_hex(const void* data, size_t size)
{
    const uint16_t* data1=reinterpret_cast<const uint16_t*>(data);
    for(int i=0; i<size; ++i)
    {
        print_in_hex1(data1[i]);
        cout << ' ';
    }


}
void print_in_binary1(uint16_t byte)
{
    char x;
    for(int i=15; i>-1; --i)

    {
        uint16_t byte1=(byte&((0b1000000000000000)>>(15-i)))>>i;
        switch (byte1)
        {
        case 1:
            x='1';
            break;
        case 0:
            x='0';
            break;
        }
        cout <<x;
    }

}

void print_in_binary(const void* data, size_t size)
{
    const uint16_t* data1=reinterpret_cast<const uint16_t*>(data);
    for(int i=0; i<size; ++i)
    {
        print_in_binary1(data1[i]);
        cout << ' ';
    }
}
