/*
    20. Valid Parentheses

    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    

    Example 1:
    Input: s = "()"
    Output: true
    
    Example 2:
    Input: s = "()[]{}"
    Output: true

    Example 3:
    Input: s = "(]"
    Output: false

    Example 4:
    Input: s = "([)]"
    Output: false

    Example 5:
    Input: s = "{[]}"
    Output: true
    
    Constraints:
    - 1 <= s.length <= 104
    - s consists of parentheses only '()[]{}'.
 */

class Solution {
public:
    bool isValid(string s) {
        
        // create a map of valid pairs        
        unordered_map<char, char> mapParenPairs {make_pair<char, char>(')', '('), 
                                                 make_pair<char, char>(']', '['), 
                                                 make_pair<char, char>('}', '{')}; 
        
        /**
         * the left half of the parentheseses (i.e. '(', '[' or '{') are push into the stack
         * If we find a right half of the parenthsis such as ')', ']' or '}', the valid value
         * of the top of the stack should be its counter part
         **/ 
        stack<char> stackParen; 

        for (auto paren : s) {
            
            if (mapParenPairs.find(paren) != mapParenPairs.end()) {                
                if (stackParen.empty() || mapParenPairs[paren] != stackParen.top()) {
                    /**
                     * either the stack is empty or its top value does not match 
                     * the right part
                     **/
                    return false; 
                }
                else {
                    // a match if found, so pop the stack
                    stackParen.pop(); 
                }                                 
            }
            else {
                // this is a left part of parenthese pair, push is into the stack
                stackParen.push(paren); 
            }
        }                
        
        // if all the parentheses are paired up, the stack should be empty
        if (stackParen.empty()) {
            return true; 
        }
        
        return false; 
    }
};