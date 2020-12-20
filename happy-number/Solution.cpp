/*
    488. Happy Number
    Write an algorithm to determine if a number is happy.

    A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

    Example
    Example 1:

    Input:19
    Output:true
    Explanation:

    19 is a happy number

        1^2 + 9^2 = 82
        8^2 + 2^2 = 68
        6^2 + 8^2 = 100
        1^2 + 0^2 + 0^2 = 1

    Example 2:

    Input:5
    Output:false
    Explanation:

    5 is not a happy number

    25->29->85->89->145->42->20->4->16->37->58->89
    89 appears again.
 */

class Solution {
public:
    /**
     * @param n: An integer
     * @return: true if this is a happy number or false
     */
    bool isHappy(int n) {
        // write your code here
        unordered_set<int> numSet; 
        
        int val = n; 
        
        while (val != 1) {
            val = calcNumber(val); 
            
            // happy number
            if (val == 1) {
                return true; 
            }
            
            // if the number already exists in the set
            if (numSet.find(val) != numSet.end()) {
                return false; 
            }
            numSet.insert(val); 
        }
    }
    
private: 
    int calcNumber(int valIn) {
        // convert the number into a string and traverse each character
        string valStr = to_string(valIn);
        int valOut{0};
        for (int i = 0; i < valStr.length(); ++i) {
            valOut += (valStr[i] - '0') * (valStr[i] - '0'); 
        }
        return valOut;
    }

};