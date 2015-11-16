/**
Implement strStr().

Returns the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.
*/

#include <iostream>
#include <string>
using namespace std;

int strStr(string haystack, string needle) {
    int hsize = haystack.size();
    int nsize = needle.size();
    for (auto i = 0; i < hsize-nsize+1; ++i) {
        int j;
        for (j = 0; j < nsize; ++j)
            if (haystack[i+j] != needle[j])
                break;
        if (j == nsize) return i;
    }
    return -1;
}

int main(int ac, char **av) {
    cout << strStr(av[1], av[2]) << '\n';
    return 0;
}
