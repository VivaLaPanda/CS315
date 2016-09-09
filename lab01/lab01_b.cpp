#include <iostream>

unsigned int invert(unsigned, int, int);
unsigned int rightRot(unsigned x, int n);

int main()
{
    unsigned x = 3;
    std::cout << rightRot(x, 2) <<  std::endl;
    return 0;
}

unsigned int invert(unsigned x, int p, int n)
{
   for(int i = 0; i < n; i++)
   {
      unsigned check = 1;
      
      check <<= (p+i);
      if (x & check)
      {
      	// Target bit is a 1
	return (~(x & check)) & x;
      }
      else
      {
	// Target bit is a 0
	return x | check;
      }
   }
}

unsigned int rightRot(unsigned x, int n)
{
   unsigned valStore = 1;
   for (int i = 0; i < n - 1; i++)
   {
      valStore <<= 1;
      valStore += 1;
   }
   unsigned max = ~0;
   valStore <<= (max - (n - 1));
   x >>= n;

   return x | valStore;
}
