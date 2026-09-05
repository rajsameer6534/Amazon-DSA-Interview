class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (p.size() > s.size())
            return ans;

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        for (char c : p) {
            need[c - 'a']++;
        }

        int left = 0;

        for (int right = 0; right < s.size(); right++) {

            // Add right character
            window[s[right] - 'a']++;

            // Keep window size = p.size()
            if (right - left + 1 > p.size()) {
                window[s[left] - 'a']--;
                left++;
            }

            // Check fixed-size window
            if (right - left + 1 == p.size()) {

                if (window == need) {
                    ans.push_back(left);
                }
            }
        }

        return ans;
    }
};