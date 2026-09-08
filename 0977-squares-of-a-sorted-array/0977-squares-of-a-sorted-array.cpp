class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        int k=n-1; //filling answr from right
        vector<int>num(n,0);
        while(l<=r){
            if(abs(nums[l])>abs(nums[r])){
                num[k]=nums[l]*nums[l];
                l++;
            }
            else{
                num[k]=nums[r]*nums[r];
                r--;
            }
            k--;
        }
        return num;
    }
};