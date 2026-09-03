class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n= nums.size();
        int i=0;
        int j= n-1;

        while(i<j-1){
            int mid= i+(j-i)/2;
            
            if(nums[mid]!=nums[mid-1] && nums[mid]!= nums[mid+1]) return nums[mid];

            if((mid-i+1)%2==0){
                if(nums[mid]== nums[mid-1]) i=mid+1; 
                else j=mid-1;
            }

            else{
                if(nums[mid]==nums[mid-1]) j=mid-2; 
                else i=mid+2;
            }
        }
        return nums[i];
    }
};
