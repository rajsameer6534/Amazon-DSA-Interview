class Solution {
public:

    int f(vector<int>& nums, int val){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum += (nums[i] + val - 1) / val;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int lo=1;
        int hi=*max_element(nums.begin(),nums.end());
        int ans=INT_MAX;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int thres_val=f(nums,mid);
            if(thres_val<=threshold){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;

        }
        return ans;
    }
};