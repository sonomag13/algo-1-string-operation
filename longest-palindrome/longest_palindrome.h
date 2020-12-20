//
// Created by lu.gao on 12/10/19.
//

#ifndef _LONGEST_PALINDROME_LONGEST_PALINDROME_H
#define _LONGEST_PALINDROME_LONGEST_PALINDROME_H

#include <iostream>

class Solution {

public:
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    std::string longestSubStrPalindrome(std::string &s) {
        // write your code here
        if(s.empty()) {
            return 0;
        }
        int maxlen = 0, start = 0, curlen = 0;
        for(int i = 0; i < s.size(); i++) {
            curlen = getPalindromeLen(s, i, i);
            if(curlen > maxlen) {
                maxlen = curlen;
                start = i - (maxlen - 1) / 2;
            }
            curlen = getPalindromeLen(s, i, i+1);
            if(curlen > maxlen) {
                maxlen = curlen;
                start = i - maxlen / 2 + 1;
            }
        }
        return s.substr(start, maxlen);
    }

    int longestPalindrome(const std::string &s) {
        int n = s.size();
        int nmax = 1010;
        int counter = 0;
        int flag[1010] = {0};
        int *ptr = &flag[0];
        /*
        std::cout << "in the calling function" << std::endl;
        std::cout << "\tptr = " << ptr << std::endl;
        std::cout << "\t*ptr = " << *ptr << std::endl;
        */
        initFlag(ptr, nmax);
        for(int i = 0; i < n; i++) {
            if(flag[i]) {
                flag[i] = 0;
                for(int j = i+1; j < n; j++) {
                    if (s[j] == s[i] && flag[j]) {
                        counter++;
                        flag[j] = 0;
                        break;
                    }
                }
            }
        }
        if(2*counter < n) {
            return 2*counter + 1;
        }
        else {
            return 2*counter;
        }
    }

    bool isPalindrome(const std::string &s) {
        bool result = true;
        int left = 0, right = s.size();
        if(s.empty()) {
            return false;
        }
        while(left < right) {
            while(!isalpha(s[left]) && !isdigit(s[left]) && left <= right) {
                left++;
            }
            while(!isalpha(s[right]) && !isdigit(s[right]) && left <= right) {
                right--;
            }
            if(left == right) {
                switch (isalpha(s[left])) {
                    case true:
                        return true;
                        break;
                    case false:
                        return false;
                        break;
                }
            }
            else {
                if(convertCase(s[left]) != convertCase(s[right])) {
                    return false;
                }
            }
            left++;
            right--;
        }
        return result;
    }

private:

    int getPalindromeLen(const std::string &str, int left, int right) {
        int len = 0;
        while(left >= 0 && right < str.size()) {
            if(str[left] != str[right]) {
                break;
            }
            len += (left == right) ? 1 : 2;
            left--;
            right ++;
        }
        return len;
    }

    void initFlag(int *ptr, int n) {
        /*
        std::cout << "in the called function" << std::endl;
        std::cout << "\tptr = " << ptr << std::endl;
        std::cout << "\t*ptr = " << *ptr << std::endl;
         */
        for(int i = 0; i < n; i++) {
            *(ptr + i) = 1;
        }
    }

    char convertCase(const char charIn) {
        // return (charIn >= 65 && charIn <= 90) ? charIn + 32 : charIn;
        char charOut = charIn;
        if(charIn >= 65 && charIn <= 90) {
            charOut = charIn + 32;
        }
        return charOut;
    }
};

#endif //_LONGEST_PALINDROME_LONGEST_PALINDROME_H
