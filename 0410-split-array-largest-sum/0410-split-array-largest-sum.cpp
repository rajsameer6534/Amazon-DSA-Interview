class Solution {
public:
    int f(vector<int>& nums, int val, int k){
        int cnt=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]+sum<=val) sum+=nums[i];
            else{
                cnt++;
                sum=nums[i];
            }
        }
       return cnt;

    }
    int splitArray(vector<int>& nums, int k) {
       int lo=*max_element(nums.begin(),nums.end());
       int hi=accumulate(nums.begin(),nums.end(),0);
       while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        int value =f(nums,mid,k);
        if(value>k){
           lo=mid+1;
        }
        else hi=mid-1;
       } 
       return lo;
    }
};