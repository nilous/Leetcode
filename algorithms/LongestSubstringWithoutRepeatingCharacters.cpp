#include <algorithm>
#include <string>

using std::string;

int lengthOfLongestSubstring(string s) {
    if (s.empty()) return 0;

    int lastOccupation[256];
    memset(lastOccupation, -1, sizeof(int)*256);

    int ret = 0;
    int thisStreakStart = 0;
    while (1) {
        int i;
        for (i = thisStreakStart; i < s.size(); i++) {
            if (lastOccupation[s[i]] >= thisStreakStart 
                    && lastOccupation[s[i]] != i) {  // <- Don't check conflict with itself!
                if (ret < (i-thisStreakStart)) ret = i-thisStreakStart;
                thisStreakStart = lastOccupation[s[i]]+1;
                lastOccupation[s[i]] = i;
                break;
            }
            lastOccupation[s[i]] = i;
        }
        if (i == s.size()) {
            if (ret < (i-thisStreakStart)) ret = i-thisStreakStart;
            break;
        }
    }

    return ret;
}