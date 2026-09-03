class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        int lo=1;
        int hi=n-2;
        if(n==1) return 0;
        if(arr[n-1]>arr[n-2]) return n-1;
        if(n==2){
            if(arr[0]>arr[1]) return 0;
            else return 1;
        }
       
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;
            else if(arr[mid]>arr[mid+1]) hi=mid-1;
            else lo=mid+1;
        }
        return 0;
    }
};