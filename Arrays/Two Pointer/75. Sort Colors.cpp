/* https://leetcode.com/problems/sort-colors/description/ */
#include <bits/stdc++.h>
using namespace std;

/* two pointer approach */
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int left = 0, right = nums.size() - 1, i = 0;

            while(i <= right && right > 0 && left < nums.size()) {
                if(nums[i] == 2) {
                    swap(nums[i], nums[right]);
                    right--;
                    i = left;
                } else if(nums[i] == 0) {
                    swap(nums[i], nums[left]);
                    left++;
                    i = left;
                } else {
                    i++;
                };
            };

            return;
        };
};


/*
    Two Pointer approach did not work for GFG problem because →
    arr = [0, 0, 1, 1, 1, 1, .......(1m times), 0, 0, 0, ........]
    Every time we are swapping (when criteria meets), we are re-initializing our current pointer (i) equal to left pointer that unnecessarly performing the operation of sorting those 1s that we have already performed
*/
class Solution {
	public:
        void sort012(vector<int>& nums) {
            int counter_0 = 0, counter_1 = 0, counter_2 = 0;
            
            for (int it: nums) {
                if (it == 0)
                    counter_0++;
                else if (it == 1)
                    counter_1++;
                else
                    counter_2++;
            };
            
            for (int i = 0; i < nums.size(); i++) {
                if (counter_0 > 0) {
                    nums[i] = 0;
                    counter_0--;
                } else if (counter_1 > 0) {
                    nums[i] = 1;
                    counter_1--;
                } else {
                    nums[i] = 2;
                    counter_2--;
                };
            };
            
            return;
        };
};
