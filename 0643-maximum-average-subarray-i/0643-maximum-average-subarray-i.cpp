class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left=0;
        double window=0;
        double ans=INT_MIN;
        for(int right=0;right<nums.size();right++){
            window+=nums[right];
            if(right-left+1>k){
                window-=nums[left];
                left++;
            }
            if(right-left+1==k){
                ans=max(ans,window/k);
            }
        }
        return ans;

    }
};