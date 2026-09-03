class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n= nums.size();
        int lo=0;
        int hi= n-1;

        while(lo<=hi){
            int mid= lo+(hi-lo)/2;
            
            if(nums[mid]!=nums[mid-1] && nums[mid]!= nums[mid+1]) return nums[mid];

            if((mid-lo+1)%2==0){
                if(nums[mid]== nums[mid-1]) lo=mid+1; 
                else hi=mid-1;
            }

            else{
                if(nums[mid]==nums[mid-1]) hi=mid-2; 
                else lo=mid+2;
            }
        }
        return nums[lo];
    }
};
