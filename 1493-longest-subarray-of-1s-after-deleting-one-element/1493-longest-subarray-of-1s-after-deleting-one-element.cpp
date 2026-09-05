class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int nz=0;
        int maxi=0;
        int idx=-1;
        for(int right=0;right<n;right++){
            if(nums[right]==0) nz++;
            while(nz>1){
                if(nums[left]==0) nz--;
                left++;

            }
            if(right-left+1>maxi){
                maxi=right-left+1;
            }
        }
    return maxi-1;
    }
};