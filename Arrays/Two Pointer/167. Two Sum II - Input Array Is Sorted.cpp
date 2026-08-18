/* https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/ */
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            /* since array is sorted and there is only one solution, the start and end pointer works just fine */
            /* time complexity → O(n), space complexity → O(1) */

            int start = 0, end = nums.size() - 1;
            vector<int>ans;

            while(start < end) {
                int current_sum = nums[start] + nums[end];
                
                if(current_sum == target) {
                    ans.emplace_back(start + 1);
                    ans.emplace_back(end + 1);
                    break;
                } else if(current_sum < target) {
                    start++;
                } else {
                    end--;
                };
            };

            return ans;
        };
};

/* https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1 → 3 solutions */
class Solution {
	public:
    	int countPairs(vector<int> &arr, int target) {
            /* 2 pointer → only works with sorted arrays */
    		int l = 0;
    		int r = arr.size() - 1;
    		int ans = 0;
    		
    		while (l < r) {
    			int sum = arr[l] + arr[r];
    			
    			if (sum < target) {
    				l++;
    			} else if (sum > target) {
    				r--;
    			} else {
    				if (arr[l] == arr[r]) {
    					int n = r - l + 1;
    					ans += n * (n - 1) / 2;
    					break;
    			    };
    				/* this extra block is becuase there are duplicates */
    				int leftCount = 1;
    				int rightCount = 1;
    				
    				while (l + 1 < r && arr[l] == arr[l + 1]) {
    					leftCount++;
    					l++;
    				};
    				
    				while (r - 1 > l && arr[r] == arr[r - 1]) {
    					rightCount++;
    					r--;
    				};
    				
    				ans += leftCount * rightCount;
    				
    				l++;
    				r--;
    			};
    		};
    		
    		return ans;
	    };
};

class Solution {
    public:
        int countPairs(vector<int> &arr, int target) {
            /* HashMap → works with both sorted and unsorted arrays but extra space → O(n) */
            unordered_map<int, int>mpp;
            int counter = 0;
            
            for(int it: arr) {
                int rem = target - it;
                if(mpp.find(rem) != mpp.end()) {
                    counter += mpp[rem];
                };
                mpp[it]+= 1;
            };
            
            return counter;
        };
}; /* solution → https://www.youtube.com/watch?v=NC9r8D2QnHk */