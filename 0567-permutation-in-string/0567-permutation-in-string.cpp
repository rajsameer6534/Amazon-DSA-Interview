class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<int>freq1(256,0);
        for(int i=0;i<n;i++){
            freq1[s1[i]]++;
        }
        vector<int>freq2(256,0);
        int left=0;
        for(int right=0;right<m;right++){
            freq2[s2[right]]++;
            if(right - left + 1 > n){
                freq2[s2[left]]--;
                left++;
            }
            if(freq1==freq2) return true;
        }
        return false;
    }
};