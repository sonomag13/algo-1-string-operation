#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std; 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> result;
                        
        unordered_map<string, vector<string>> mapCntStr;
        
        for (const auto& str : strs) {
            string strCharFreq{_calcCharFreq(str)}; 
            
            if (mapCntStr.find(strCharFreq) != mapCntStr.end()) {
                // key is not find and append the string
                mapCntStr[strCharFreq].push_back(str);
            }
            else {
                // key is not find and create a new entry in the map
                mapCntStr[strCharFreq] = vector<string>{str};
            }
            
        }
        
        for (const auto& val : mapCntStr) {
            result.push_back(val.second);
        }
        
        return result; 
    }
    
private:
    
    static string _calcCharFreq(const string& strIn) {
        
        /*
         * string consists of lower-case English letters, such that 
         * there should be no more than 26 components in the vector
         */ 
        vector<int> vectCharFreq(26, 0); 
        string strOut; 
        
        for (int i = 0; i < strIn.size(); ++i) {
            int idx{strIn[i] - 'a'};             
            vectCharFreq[idx]++;                        
        }
        
        for (int cnt : vectCharFreq) {
            strOut += ('#' + to_string(cnt));
        }
                
        return strOut;
        
    }
    
};