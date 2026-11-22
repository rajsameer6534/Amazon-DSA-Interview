class Solution {
public:
    bool checkString(string s) {
        int n=s.length();
        string rev=s;
        sort(rev.begin(),rev.end());
        for(int i=0;i<n;i++){
            if(s[i]!=rev[i]) return false;
        }
        return true;

    }
};