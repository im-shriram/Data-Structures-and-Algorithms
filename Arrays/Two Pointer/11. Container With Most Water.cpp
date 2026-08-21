/* https://leetcode.com/problems/container-with-most-water/ */
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int start = 0, end = height.size() - 1;
            int max_area = 0;

            while(start < end) {
                int length = end - start;
                int max_holding_capacity = min(height[start], height[end]);
                int current_area = length * max_holding_capacity;
                max_area = max(max_area, current_area);

                /* Important criteria for shifting the left and right pointers: At a certain point, I have the maximum height among the start and end pointers. Why would I lose that? Instead, I should move the other pointer (the one with the minimum height) in order to find a height greater than the current one. This will definitely reduce the width, but the width only decreases by one, whereas we might gain a huge amount of height. */
                
                if(height[start] >= height[end]) end--;
                else start++;
            };

            return max_area;
        };
};