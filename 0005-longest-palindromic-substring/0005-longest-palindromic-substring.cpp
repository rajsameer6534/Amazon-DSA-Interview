class Solution {
public:
    vector<vector<int>> dp;

    int f(string& s1, string& s2, int i, int j) {
        if (i >= s1.size() || j >= s2.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s1[i] == s2[j]) {
            dp[i][j] = 1 + f(s1, s2, i + 1, j + 1);
        } else {
            dp[i][j] = 0;
        }
        return dp[i][j];
    }

    string longestPalindrome(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        
        int n = s1.size();
        dp.assign(n, vector<int>(n, -1));

        // Fill dp table using the recursive function.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                f(s1, s2, i, j);
            }
        }
       
        int maxLen = 0, start = 0;
        // Iterate over dp table to find the maximum length palindrome.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int len = dp[i][j];
                // Check if the common substring is a valid palindrome.
                // For s1[i...i+len-1] to be a palindrome, its starting index i must equal n - j - len.
                if (len > maxLen && (i == n - j - len)) {
                    maxLen = len;
                    start = i;
                }
            }
        }
        
        return s1.substr(start, maxLen);
    }
};
