class Solution {
public:
    int f(vector<int>& weights, int cap){
        int day=1;
        int load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>cap){
                day+=1;
                load=weights[i];
            }
            else load+=weights[i];
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int lo=*max_element(weights.begin(),weights.end());
        int hi=accumulate(weights.begin(),weights.end(),0);
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int possible=f(weights,mid);
            if(possible<=days){
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return lo;
    }
};