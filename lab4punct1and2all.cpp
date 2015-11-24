#include "sdt.h"
char convert_in_hex(uint8_t x)
{   switch (x)
    {
    case 0b0000: return '0'; break;
    case 0b0001: return '1'; break;
    case 0b0010: return '2'; break;
    case 0b0011: return '3'; break;
    case 0b0100: return '4'; break;
    case 0b0101: return '5'; break;
    case 0b0110: return '6'; break;
    case 0b0111: return '7'; break;
    case 0b1000: return '8'; break;
    case 0b1001: return '9'; break;
    case 0b1010: return 'A'; break;
    case 0b1011: return 'B'; break;
    case 0b1100: return 'C'; break;
    case 0b1101: return 'D'; break;
    case 0b1110: return 'E'; break;
    case 0b1111: return 'F'; break;
    }
}
void print_in_hex1(uint8_t byte)
  { char x,x1;
      uint8_t byte1=(byte&0b11110000)>>4;
      x=convert_in_hex(byte1);

      uint8_t byte2=byte&0b00001111;
      x1=convert_in_hex(byte2);
  cout << /*"Your num in hex: " <<*/x<<x1;
  }

void print_in_hex(const void* data, size_t size)
{
const uint8_t* data1=reinterpret_cast<const uint8_t*>(data);
for(int i=0; i<size; ++i)
{
 print_in_hex1(data1[i]);
 cout << ' ';
}


}
void print_in_binary1(uint8_t byte)
{ char x;
    for(int i=7; i>-1; --i)

   { uint8_t byte1=(byte&((0b10000000)>>(7-i)))>>i;
      switch (byte1)
      {
      case 1: x='1'; break;
      case 0: x='0'; break;
      }
     cout <<x;
    }

}

void print_in_binary(const void* data, size_t size)
{
 const uint8_t* data1=reinterpret_cast<const uint8_t*>(data);
for(int i=0; i<size; ++i)
{
 print_in_binary1(data1[i]);
 cout << ' ';
}
}

int main()
{

int x,y,xy;
char z;

cout << "Please input your expr next, use &, |, ^ only!: ";
cin >>x>>z>>y;
 switch (z)
 {case '&': xy=x&y; break;
  case '|': xy=x|y; break;
  case '^': xy=x^y; break;
  default: cerr << "Incorrect statement, use &, |, ^ only! \n";
 }
cout << " = " <<x<<z<<y<<" =\n";
print_in_hex(&x,sizeof(x));cout<<" "<<z<<" ";print_in_hex(&y,sizeof(y)); cout<<" ==\n";
print_in_binary(&x,sizeof(x));cout <<" "<<z<<" ";print_in_binary(&y,sizeof(y)); cout <<" == \n";

cout <<"RESULT IN HEX: "; print_in_hex(&xy,sizeof(xy)); cout<<"\n";
cout <<"RESULT IN BINARY: "; print_in_binary(&xy,sizeof(xy)); cout<<"\n";
  }



