#include <stdint.h>

#define BitAt(n, i) ((n >> i) & 0x01)
#define SetBitAt(n, i, b) (n |= (b << i))

uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    int lb, rb;
    for (int i = 0; i <= 15; i++) {
        rb = BitAt(n, i);
        lb = BitAt(n, 31-i);
    
        SetBitAt(ret, i, lb);
        SetBitAt(ret, 31-i, rb);
    }
    return ret;
}