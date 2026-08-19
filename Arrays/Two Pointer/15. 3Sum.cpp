/* https://leetcode.com/problems/3sum/ */
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            /* 2 sum approach over all the elements */
            sort(nums.begin(), nums.end()); /* sorting is helping here to maintain the subset in the same order while inserting so that you dont need to sort the combination everytime */
            set<vector<int>>ans;

            for(int i = 0; i < nums.size(); i++) {
                if(i != 0 && nums[i] == nums[i - 1]) continue; // sligit optimization
                int req_sum = 0 - nums[i];
                set<int>inner;

                for(int j = i + 1; j < nums.size(); j++) {
                    /* 2 sum approach */
                    int rem = req_sum - nums[j];
                    if(inner.find(rem) != inner.end()) {
                        ans.insert({nums[i], nums[j], rem}); /* the sequency of storing this combination does not matter because the combinations made by next same number will be same as the current one so set does not insert them */
                    };
                    inner.insert(nums[j]);
                };
            };
            
            vector<vector<int>>res(ans.begin(), ans.end());
            return res;
        };
};

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            /* slight modification of 2 sum approach */
            sort(nums.begin(), nums.end());
            set<vector<int>>st;

            for(int i = 0; i < nums.size(); i++) {
                if(i != 0 && nums[i] == nums[i - 1]) continue;
                set<int>hashset;

                for(int j = i + 1; j < nums.size(); j++) {
                    int rem = 0 - (nums[i] + nums[j]);
                    if(hashset.find(rem) != hashset.end()) {
                        st.insert({nums[i], rem, nums[j]});
                    };
                    hashset.insert(nums[j]);
                };
            };

            vector<vector<int>>ans(st.begin(), st.end());
            return ans;
        };
};

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            /* two pointer approach */
            sort(nums.begin(), nums.end());
            set<vector<int>>st;

            for(int i = 0; i < nums.size(); i++) {
                if(i != 0 && nums[i] == nums[i - 1]) continue;
                int req_sum = 0 - nums[i];
                int start = i + 1, end = nums.size() - 1;

                while(start < end) {
                    int curr_sum = nums[start] + nums[end];

                    if(curr_sum == req_sum) {
                        st.insert({nums[i], nums[start], nums[end]});
                        start++;
                        end--;
                    } else if (curr_sum < req_sum) {
                        start++;
                    } else {
                        end--;
                    };
                };
            };

            vector<vector<int>>ans(st.begin(), st.end());
            return ans;
        };
};