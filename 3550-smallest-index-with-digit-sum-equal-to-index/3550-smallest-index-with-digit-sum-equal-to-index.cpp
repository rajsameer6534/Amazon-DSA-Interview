class Solution {
public:
    int getSum(int x){
        int sum=0;
        while(x>0){
            int j=x%10;
            sum+=j;
            x=x/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(getSum(nums[i])==i) mini=min(mini,i);
        }
        if(mini==INT_MAX) return -1;
        else return mini;
    }
};