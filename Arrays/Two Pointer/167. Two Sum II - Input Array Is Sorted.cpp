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

/* https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1 → sorted */
/* https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum--150253/1 → unsorted, duplicates, negative numbers*/
class Solution {
	public:
    	int countPairs(vector<int> &arr, int target) {
            unordered_map<int, int>freq_map;
            int counter = 0;
            
            for(vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
                freq_map[*it]++; /* storing the frequency of all the numbers to find the frequency of second value for each value in array */
            };
            
            for(vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
                int rem = target - (*it); /* finding second value */
                counter += freq_map[rem]; /* finding all the combinations that will create from the current number */
                
                if(rem == *it) {
                    counter--; 
                    /* 
                        important → if you dont add this then the current element will also add into the counter 
                            array = [1, 1, 1], target = 2
                            for 1st element -> rem = 2 - 1 = 1, in freq_map the freq of 1 is 3, so if you directly add it into the counter that means you have also considered the pair of current number with itself.
                    */
                };
                
                freq_map[*it]--;
            };
            
            return counter;
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