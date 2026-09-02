class Solution {
public:
    int f(vector<int>& nums, int pages){
        int stud=1;
        long long pagesstud=0;
        for(int i=0;i<nums.size();i++){
            if(pagesstud+nums[i]<=pages){
                pagesstud+=nums[i];
            }
            else{
                stud+=1;
                pagesstud=nums[i];
            }
        }
        return stud;
    }
    int findpages(vector<int>& nums, int n ,int k){
        int lo=*max_element(nums.begin(),nums.end());
        int hi=accumulate(nums.begin(),nums.end(),0);
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int students=f(nums,mid);
            if(students>k){
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return lo;
    }
    int splitArray(vector<int>& nums, int k) {
        return findpages(nums,nums.size(),k);
    }
};