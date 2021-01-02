/*
    242. Valid Anagram

    Given two strings s and t , write a function to determine if t is an anagram of s.

    Example 1:
    Input: s = "anagram", t = "nagaram"
    Output: true

    Example 2:
    Input: s = "rat", t = "car"
    Output: false

    Note:
    You may assume the string contains only lowercase alphabets.
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        auto sortString = [] (string& strIn) {
            sort(strIn.begin(), strIn.end()); 
            return strIn; 
        };
                
        return sortString(s) == sortString(t);
        
    }
};