class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int left=0;
        int cnt=0;
        int ans=INT_MIN;
        for(int right=0;right<fruits.size();right++){
            mp[fruits[right]]++;
            while(mp.size()>2){
                if(mp[fruits[left]]==1) mp.erase(fruits[left]);
                else mp[fruits[left]]--;
                left++;

            }
           
            ans=max(right-left+1,ans);

        }
        return ans;
    }
};