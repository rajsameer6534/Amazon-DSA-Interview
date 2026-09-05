class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n>m) return false;
        int i=0;
        int j=0;
        while(j<m && i<n){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else j++;
        } 
        return i==n;
    }
};