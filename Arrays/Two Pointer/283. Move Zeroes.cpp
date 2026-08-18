/* https://leetcode.com/problems/move-zeroes/description/ */
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void moveZeroes(vector<int> &nums) {
            /* brute force solution */
            /* time complexity -> O(n), space complexity -> O(n) */

            vector<int> ans(nums.size(), 0); /* all elements initialized to zero */
            int ptr = 0; /* pointer for iterating over ans */

            for (vector<int>::iterator idx = nums.begin(); idx != nums.end(); idx++) {
                if (*idx != 0)
                {
                    ans[ptr] = *idx;
                    ptr++;
                };
            };

            nums = ans; /* inplace change */
            return;
        };
};

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            /* literally following the question as it is → harder way */
            int start = 0, next = 1;

            while(next < nums.size()) {
                if(nums[start] == 0) {
                    swap(nums[start], nums[next]); /* inplace swapping */
                    // next++; → [1, 0]
                };

                if(nums[start] != 0) {
                    start++;
                    /* point 1 → always check for non-zero element after swapping and not in the next iteration because next pointer is always incrementing - [0,1,0,3,12] */
                };
                
                next++; /* point 2 → increment next pointer irrespective of zero or non-zero element otherwise start pointer will move ahead of next opointer - [1, 0] */
            };

            return ;
        };
};

class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            /* reverse question → moving non-zero elements at the start (easy way) */
            int start = 0;

            for(int i = 0; i < nums.size(); i++) {
                if(nums[i] != 0) {
                    swap(nums[i], nums[start]);
                    start++;
                };
            };
            return ;
        }; /* if you try to move zeros at the end by reverse looping then you wont be able to maintain the relative ordering of non-zero elements */
};