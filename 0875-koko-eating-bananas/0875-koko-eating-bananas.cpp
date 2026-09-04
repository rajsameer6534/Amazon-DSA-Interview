class Solution {
public:
    long long f(vector<int>& piles, int val){
        long long sum=0;
        for(int i=0;i<piles.size();i++){
            sum+=(piles[i]+val-1)/val;
        }
        return sum;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1;
        int hi=*max_element(piles.begin(),piles.end());
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            long long tot_ans=f(piles,mid);
            if(tot_ans<=h) hi=mid-1;
            else lo=mid+1;
        }
        return lo;
    }
};