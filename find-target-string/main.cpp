#include <iostream>
#include "TargetSearching.h"

using namespace std;

int main() {
    int target_found;
    // string source = "cdeabcdabc";
    // string target = "a";
    string source = "tartarget";

    string target = "target";
    Solution targe_searching;
    target_found = targe_searching.strStr(source, target);
    cout << "target_found = " << target_found << endl;
    return 0;
}