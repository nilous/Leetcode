#include <ctype.h>
#include <string>

using std::string;

bool isPalindrome(string s) {
    const char *cs = s.data();

    const char *head, *tail;
    for (head = cs, tail = cs + s.size() - 1; head < tail; head++, tail--) {
        // Skip non-alphanum characters
        while (!isalnum(*head)) {
            head++;
            if (head >= tail)  // All unchecked characters are non-alphanum
                return true;
        }
        while (!isalnum(*tail)) tail--;

        if (toupper(*head) != toupper(*tail))  // It's okay if the characters are numbers
            return false;
    }
    return true;
}