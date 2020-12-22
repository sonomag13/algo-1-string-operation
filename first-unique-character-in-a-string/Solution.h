/*
    387. First Unique Character in a String

    Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

    Examples:

    s = "leetcode"
    return 0.

    s = "loveleetcode"
    return 2.

 */

#include <iostream>

class Solution {
public:
    int firstUniqChar(const string& s) {
        
        int idx{INT_MAX}; 
        
        /* 
         * key: character in the string
         * val: a pair:
         *      first: index of the first appearance, i.e. a fixed value as the key is generated
         *      second: count of the appearance
         */ 
        unordered_map<char, pair<int, int>> mapCharIdxCnt; 
            
        // traverse the characters in the string and build up the map
        for (int i = 0; i < s.size(); ++i) {            
            char currChar{s[i]};             
            if (mapCharIdxCnt.find(currChar) == mapCharIdxCnt.end()) {
                // the character has not been seen before, such that set the count as 1
                mapCharIdxCnt[currChar] = make_pair(i, 1); 
            }
            else {
                // the character has been seen, such that increase the count by 1
                mapCharIdxCnt[currChar].second++; 
            }            
        }
        
        // traverse the map to find the minimum index of the character with only 1 count
        for (auto val : mapCharIdxCnt) {
            if (val.second.second == 1) {
                if (val.second.first < idx) {
                    idx = val.second.first; 
                }
            }
        }
        
        return idx < INT_MAX ? idx : -1; 
        
    }
    
};