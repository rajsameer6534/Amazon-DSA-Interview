class Solution {
public:
    bool f(vector<int>& bloomDay,int day, int m, int k){
        int cnt=0;
        int number_book=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day) cnt++;
            else{
                number_book+=cnt/k;
                cnt=0;
            }
        }
        number_book+=cnt/k;
        if(number_book>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int lo=1;
        int ans=INT_MAX;
        int hi=*max_element(bloomDay.begin(),bloomDay.end());
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(f(bloomDay,mid,m,k)==true){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};