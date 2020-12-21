//
// Created by luther on 12/21/20.
//

#include <iostream>
#include <vector>
#include "Solution.h"

using namespace std;

int main() {

    vector<string> vecString {"bdddddddddd", "bbbbbbbbbbc"};

    Solution solution;

    vector<vector<string>> result{solution.groupAnagrams(vecString)};

    return 0;
}