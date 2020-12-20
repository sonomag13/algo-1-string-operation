//
// Created by luther on 9/27/20.
//

#pragma once

#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param version1: the first given number
     * @param version2: the second given number
     * @return: the result of comparing
     */
    static int compareVersion(string &version1, string &version2) {
        // Write your code here
        vector<int> versionSegment1{segmentVersion(version1)};
        vector<int> versionSegment2{segmentVersion(version2)};

        int len1 = versionSegment1.size();
        int len2 = versionSegment2.size();
        int numSegment = min(len1, len2);

        for (int i = 0; i < numSegment; ++i) {
            if (versionSegment1[i] > versionSegment2[i]) {
                return 1;
            }
            else if (versionSegment1[i] < versionSegment2[i]) {
                return -1;
            }
        }

        if (len1 == len2) {
            return 0;
        }
        else {
            return len1 > len2 ? 1 : -1;
        }

    }

private:
    static vector<int> segmentVersion(const string& versionStr) {
        vector<int> result;
        vector<int> dotPosition;
        for (int i = 0; i < versionStr.length(); ++i) {
            if (versionStr[i] == '.') {
                dotPosition.push_back(i);
            }
        }
        dotPosition.push_back(versionStr.length());
        int pos1 = 0;
        for (auto pos2 : dotPosition) {
            int num{0};
            for (int i = pos1; i < pos2; ++i) {
                num = num * 10 + (versionStr[i] - '0');
            }
            pos1 = pos2 + 1;
            result.push_back(num);
        }
        return result;
    }

};
