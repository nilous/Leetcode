/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

#include <string.h>
#include <string>
#include <vector>
using std::string;
using std::vector;

#include <iostream>

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    if (nums.empty()) return result;
        
    char buf[100];
    
    int startOfCurrRange = nums[0];
    int lastNum = nums[0];
    
    for (auto i = 1; i < nums.size(); ++i) {
        if (nums[i] != lastNum + 1) {
            if (lastNum == startOfCurrRange) {
                sprintf(buf, "%d", startOfCurrRange);
            } else {
                sprintf(buf,"%d->%d", startOfCurrRange, lastNum);
            }
            result.push_back(buf);
    
            startOfCurrRange = lastNum = nums[i];
        } else {
            lastNum = nums[i];
        }
    }
    
    if (lastNum == startOfCurrRange) {
        sprintf(buf, "%d", startOfCurrRange);
    } else {
        sprintf(buf,"%d->%d", startOfCurrRange, lastNum);
    }
    result.push_back(buf);
    
    return result;
}

