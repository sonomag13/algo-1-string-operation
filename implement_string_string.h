
/*

LintCode Problem 13
*/

class Solution {
public:
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    int strStr(string &source, string &target) {
        // Write your code here
        if(target.empty()) {
            return 0; 
        }
        if(source.empty()) {
            return -1; 
        }
        int target_found = -1; 
        int ntar = target.size(); 
        for(int isrc = 0; isrc <= source.size() - target.size() && source.size() >= target.size(); isrc++) {
            if(target[0] == source[isrc]) {
                // std::string str2 = str.substr (3,5); 
                target_found = str_match(ntar, source.substr(isrc, isrc+ntar), target);
                if(target_found == 1) {
                    return isrc; 
                }
            }
        }
        return target_found; 
    }

private:
    
    int str_match(int n, const std::string &str1, const std::string &str2) {
        int match = 1; 
        for(int i = 0; i < n; i++) {
            if(str1[i] != str2[i]) {
                match = -1;
                break; 
            }
        }
        return match; 
    }
    
};
