class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){

             if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left=i+1;
            int right=n-1;
            
            while(left<right){
                int sum=0;
                sum=nums[i]+nums[left]+nums[right];

                if(sum==0){
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    ans.push_back(temp);
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1]) left++;
                    while(left<right && nums[right]==nums[right+1]) right--;

                }
                else if(sum<0) left++;
                else right--;

            }
        }
        return  ans;
    }
};