class Solution {
public:
    int longestSubstring(string s, int k) {

        int n = s.size();
        int ans = 0;

        // Try every possible number of distinct characters
        for (int targetDistinct = 1; targetDistinct <= 26; targetDistinct++) {

            vector<int> freq(26, 0);

            int left = 0;
            int unique = 0;
            int countAtLeastK = 0;

            for (int right = 0; right < n; right++) {

                // Add current character
                int idx = s[right] - 'a';

                if (freq[idx] == 0) {
                    unique++;
                }

                freq[idx]++;

                // Character has just reached frequency k
                if (freq[idx] == k) {
                    countAtLeastK++;
                }

                // Too many distinct characters
                while (unique > targetDistinct) {

                    int removeIdx = s[left] - 'a';

                    // If frequency was exactly k,
                    // removing it makes it < k
                    if (freq[removeIdx] == k) {
                        countAtLeastK--;
                    }

                    freq[removeIdx]--;

                    // Character completely removed
                    if (freq[removeIdx] == 0) {
                        unique--;
                    }

                    left++;
                }

                // Valid window
                if (unique == targetDistinct &&
                    countAtLeastK == targetDistinct) {

                    ans = max(ans, right - left + 1);
                }
            }
        }

        return ans;
    }
};