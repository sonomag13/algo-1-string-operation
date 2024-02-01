// 14. Longest Common Prefix

#include <iostream>

using namespce std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.size() == 0) {
            return NULL; 
        }

        string prefix = strs[0]; 

        for (int i = 1; i < strs.size(); ++i) {
            if (prefix.length() == 0) {
                break; 
            }
            while (strs[i].rfind(prefix, 0) != 0 && prefix.length() > 0) {
                prefix = prefix.substr(0, prefix.length() - 1); 
            }
        }

        return prefix; 
    }
};