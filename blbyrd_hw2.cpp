//
//  blbyrd_hw2.cpp
//  Homework
//  Brandon L. Byrd
//  COMP 280
//
//  Created by Brandon Byrd on 2/6/23.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    // 1. https://leetcode.com/problems/shuffle-string/
    string restoreString(string s, vector<int>& indices) {
        string result_string = s;
        for (int i=0; i<indices.size(); i++) result_string[indices[i]] = s[i];
        return result_string;
    }
    
    // 2. https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
    int countNegatives(vector<vector<int>>& grid) {
        int counter = 0;
        for (int i=0; i<grid.size();i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (grid[i][j] < 0) counter++;
                else continue;
            }
        }
        return counter;
    }
    
    // 3. https://leetcode.com/problems/increasing-decreasing-string/
    string sortString(string s) {
        string res = "";
        int n = (int) s.size();
        int freq[26] = {};
        
        for (int i=0; i<n; i++) freq[s[i] - 'a']++;
        
        while (n > 0) {
            for (int i=0; i<26; i++) {
                if (freq[i] != 0) {
                    res.push_back((char)(i+97));
                    freq[i]--;
                    n--;
                }
            }
            for (int i=25; i >= 0; i--) {
                if (freq[i] != 0) {
                    res.push_back((char)(i+97));
                    freq[i]--;
                    n--;
                }
            }
        }
        return res;
    }
    
    // 4. https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        int abs_diff = abs(arr[1] - arr[0]);
        for (int i=1; i < arr.size()-1; i++){
            if (abs_diff != abs(arr[i+1]-arr[i])) return false;
        }
        return true;
    }
    
    // 5. https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/
    double average(vector<int>& salary) {
        double sum = 0.00;
        sort(salary.begin(), salary.end());
        for (int i=1; i<salary.size()-1; i++){
            sum += salary[i];
        }
        double avg = sum / (salary.size()-2);
        return avg;
    }
};


