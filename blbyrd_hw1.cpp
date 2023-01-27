//
//  blbyrd_hw1.cpp
//  Homework #1
//  COMP 280-01
//  Created by Brandon Byrd on 1/27/23.
//

#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
class Solutions {
public:
    
    // 1. (Angry Professor) https://www.hackerrank.com/challenges/angry-professor/problem
    string angryProfessor(int k, vector<int> a) {
        int students=0;
        for (int s:a) if (s <= 0) students++; // for each s in a... counts students that are on time.
        return students >= k ? "NO" : "YES"; // ternary operator
    }
    
    // 2. (Equalize the Array) https://www.hackerrank.com/challenges/equality-in-a-array/problem
    int equalizeArray(vector<int> arr) {

        vector<int> counts(101);
        int max = INT_MIN;
        int length = (int) arr.size();
        
        for (int i=0; i<length; i++) {
            ++counts[arr[i]];
        }
        
        for (int i=0; i< counts.size(); i++){
            if (counts[i] > max) max = counts[i];
        }
        
        return length - max;
    }
    
    // 3. (Two Sum) https://leetcode.com/problems/two-sum/ //there's probable a bettter way but this is my answer O(n^2)
    vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> resarr = {0,0};
            for (int i=0;i <nums.size(); i++) {
                for (int j=i+1; j<nums.size(); j++) {
                    if (nums[i]+nums[j]==target) {
                        cout << nums[i] << ", " << nums[j] << endl;
                        resarr[0] = i;
                        resarr[1] = j;
                        break;
                    }
                }
            }
            return resarr;
    }
    
    // 4. (Remove Duplicates from Sorted Array) https://leetcode.com/problems/remove-duplicates-from-sorted-array/
    int removeDuplicates(vector<int>& nums) {
            auto it = unique(nums.begin(), nums.end()); // reverse iterator type; used auto for readablilty
            nums.erase(it, nums.end());
            return (int) nums.size();
    }
    
    // 5. (Best Time to Buy and Sell Stock II) https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    int maxProfit(vector<int>& prices) {
            int totalprofit = 0;
            for (int i = 0; i < prices.size()-1; i++) {
                if (prices[i+1] > prices[i]) {
                    totalprofit += (prices[i+1]-prices[i]);
                }
            }
            return totalprofit;
    }
};

