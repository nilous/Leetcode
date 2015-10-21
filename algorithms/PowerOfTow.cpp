/*
Given an integer, write a function to determine if it is a power of two.
*/

/*
 * 2进制中1的个数只能为1
 */

bool isPowerOfTwo(int n) {
    int bits = 0;

    while (n != 0) {
        if (n & 0x1) {
            bits++;
            if (bits > 1)  // 已经不止一个1了
                return false;
        }
        n = n >> 1;
    }

    return bits == 1;
}
