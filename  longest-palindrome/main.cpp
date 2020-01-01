#include <iostream>
#include "longest_palindrome.h"

using namespace std;

int main() {
    // std::cout << "Hello, World!" << std::endl;

    Solution get_longest_palindrome;
    int maxlen;
    bool isPalindrome;
    string longestPalindomeStr;
    string str = "1a2";

    /*
    longestPalindomeStr = get_longest_palindrome.longestSubStrPalindrome(str);
    cout << "max sub-string palindrome length = " << longestPalindomeStr << endl;
    maxlen = get_longest_palindrome.longestPalindrome(str);
    cout << "max palindrome length = " << maxlen << endl;
    */


   // cout << "A == 65: " << ("A" == 65) << endl;

    isPalindrome = get_longest_palindrome.isPalindrome(str);
    cout << "isPalindrome = " << isPalindrome << endl;

    return 0;
}