/*
    8. String to Integer (atoi)

    Implement atoi which converts a string to an integer.

    The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

    The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

    If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

    If no valid conversion could be performed, a zero value is returned.

    Note:

    Only the space character ' ' is considered a whitespace character.
    Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, 231 − 1 or −231 is returned.
    

    Example 1:
    Input: str = "42"
    Output: 42

    Example 2:
    Input: str = "   -42"
    Output: -42
    Explanation: The first non-whitespace character is '-', which is the minus sign. Then take as many numerical digits as possible, which gets 42.
    
    Example 3:
    Input: str = "4193 with words"
    Output: 4193
    Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
    
    Example 4:
    Input: str = "words and 987"
    Output: 0
    Explanation: The first non-whitespace character is 'w', which is not a numerical digit or a +/- sign. Therefore no valid conversion could be performed.
    
    Example 5:
    Input: str = "-91283472332"
    Output: -2147483648
    Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer. Thefore INT_MIN (−231) is returned.
 */

#include <iostream>

using namespace std; 

class Solution {
public:
    int myAtoi(const string& s) {
        
        int i{0}; 
        int result{0};     
        int sign{+1}; 
        string numStr; 
        
        // remove the white space
        while (i < s.size()) {
            if (s[i] != ' ') {                
                break; 
            }
            i++; 
        }
        
        // the check if the character is a sign; if so, make the pointer point to the next element
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '+') ? +1 : -1;            
            i++; 
        }        
        
        // extract the number from the string                
        while (i < s.size()) {
            if(isdigit(s[i])) {
                // the character is a number
                numStr += s[i]; 
                i++; 
            }
            else {
                break; 
            }
        }
        
        // if so, the string does not start with a integer
        if (!numStr.size()) {
            return result; 
        }
        
        // convert the string to integer
        for (int j = 0; j < numStr.size(); ++j) {

            /**
             * Notice that at this point, the string contains digits only, i.e. there is no sign.
             * So we only need to take care of the overflow (technically this is not true since the 
             * absolute value of the underflow limit is larger than that of overflow by 1, but LeetCode
             * is OK with it. 
             * 
             * How to handle overflow or underflow
             * 1. previous result is greater than INT_MAX/10, then there is no point to update the result 
             *    since it must be true for result * 10 > INT_MAX
             * 
             * 2. previous result happens to be equal to INT_MAX/10, we need to determin by adding the new 
             *    digit (i.e. numStr[j]), if it will overflow. In this case, the largest value of the digit 
             *    allowed by the overflow limit is INT_MAX%10 (effectively, it is 7 since 2^32 = 2147483647 
             *    and 2147483647%10 = 7). If the new digit is larger than 7, the new result will overflow
             **/
            
            int newDigit = numStr[j] - '0'; 

            bool flag1{result > INT_MAX / 10};
            bool flag2{result == INT_MAX / 10 && newDigit > INT_MAX % 10};
            if (flag1 || flag2) {
                return (sign == +1) ? INT_MAX : INT_MIN; 
            }
            result = result * 10 + newDigit;
        }
        
        return sign * result; 
        
    }
    
};