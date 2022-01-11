
//multiple masks
void copySetBits(unsigned x, unsigned y,
                 unsigned l, unsigned r)
{
   // l and r must be between 1 to 32 (assuming ints are stored using 32 bits)
   if (l < 1 || r > 32)
      return ;

   // Traverse in given range
   for (int i=l; i<=r; i++)
   {
       // Find a mask (A number whose only set bit is at i'th position)
       int mask = 1 << (i-1);

       // If i'th bit is set in y, set i'th bit in x also.
       if (y & mask)
          x = x | mask;
   }
}

// 1 Mask only
void copySetBits2(unsigned x, unsigned y,
                 unsigned l, unsigned r)
{
    // l and r must be between 1 to 32
    if (l < 1 || r > 32)
        return ;

    // get the length of the mask
    int maskLength = (1ll<<(r-l+1)) - 1;

    // Shift the mask to the required position "&" with y to get the set bits at between l ad r in y
    int mask = ((maskLength)<<(l-1)) & y ;
    x = x | mask;
}