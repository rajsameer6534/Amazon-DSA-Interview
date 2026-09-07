class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>pq;
        for(int ele=0;ele<nums.size();ele++){
            if(nums[ele]!=val) pq.push_back(nums[ele]);
        }
        nums.assign(pq.begin(),pq.end());
        return nums.size();
    }
};