// 28. Find the Index of the First Occurrence in a String

#include <iostream>

using namespace std; 

class Solution {
public:
    int strStr(string haystack, string needle) {

        if (haystack.length() == 0 || needle.length() == 0) {
            return -1; 
        }

        unordered_map<char, vector<int>> mapCharIdx; 

        for (int i = 0; i < haystack.length(); ++i) {
            char curChar = haystack[i]; 
            if (mapCharIdx.find(curChar) == mapCharIdx.end()) {
                mapCharIdx.insert(make_pair(curChar, vector<int>{i}));
            }
            else {
                mapCharIdx[curChar].push_back(i);
            }
        }

        char firstChar = needle[0]; 
        if (mapCharIdx.find(firstChar) == mapCharIdx.end()) {
            return -1; 
        }

        int sizeNeedle = needle.length(); 
        for (int i = 0; i < mapCharIdx[firstChar].size(); ++i) {
            int start = mapCharIdx[firstChar][i]; 
            if (haystack.substr(start, sizeNeedle) == needle) {
                return start; 
            }
        }

        return -1;
    }
};