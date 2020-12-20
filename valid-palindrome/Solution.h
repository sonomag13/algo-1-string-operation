/*
    125. Valid Palindrome

    Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

    Note: For the purpose of this problem, we define empty string as valid palindrome.

    Example 1:
    Input: "A man, a plan, a canal: Panama"
    Output: true
    
    Example 2:
    Input: "race a car"
    Output: false
 */

using namespace std; 

class Solution {
public:
    bool isPalindrome(string s) {
        
        /*
          the keys of this problems is to know C++ built in functions:
          - function isalnum to screen out the specicial characters
          - function tolower to convert an alphabetic character to lower case
         */        
        string filteredString; 
        string reversedString; 
        
        /**
         * traverse all the characters in the string, and assemble a new string 
         * with numbers or alphabet
         **/ 
        for (auto chara : s) {            
            if (isalnum(chara)) {
                filteredString += tolower(chara);
            }                                    
        }
        
        /**
         * make a copy of the string and reverse it. If the string is palindrome
         * its reversed version should be equal to its original version
         **/ 
        reversedString = filteredString;
        reverse(reversedString.begin(), reversedString.end());
        
        return reversedString == filteredString;         
    }
    
};