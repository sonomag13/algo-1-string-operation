/*
    1352. Compare Version Numbers
    Compare two version numbers version1 and version2.
    If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

    You may assume that the version strings are non-empty and contain only digits and the . character.
    The . character does not represent a decimal point and is used to separate number sequences.
    For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

    Example
    Example1

    Input: version1 = "1"，version2 = "01"
    Output: 0
    Example2

    Input: version1 = "4.9"，version2 = "4.5"
    Output: 1
 */

#include <iostream>

#include "Solution.h"

using namespace std;

int main() {

    Solution solution;

    string ver1 = "4.9";
    string ver2 = "4.5";
    int answer = Solution::compareVersion(ver1, ver2);

    cout << "answer = " << answer << endl;

    return EXIT_SUCCESS;
}
