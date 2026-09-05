class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int nz=0;
        int left=0;
        int ans=INT_MIN;
        for(int right=0;right<n;right++){
            if(nums[right]==0) nz++;
            while(nz>k){
                if(nums[left]==0) nz--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};