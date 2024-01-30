// 58 Length of last string

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int lastIdx;

        char lastChar = s[lastIdx]; 

        for (lastIdx = s.length() - 1; lastIdx >= 0; --lastIdx) {
            if (s[lastIdx] != ' ') {
                break; 
            }
        }

        int counter = 0;
        while (lastIdx >= 0) {
           if (s[lastIdx] == ' ') {
               break; 
           }
           counter++;
           lastIdx--;
       }

        return counter;
    }
};