class Solution {
public:
    string minWindow(string s, string t) {

        if (t.size() > s.size()) return "";

        vector<int> need(256, 0);
        vector<int> window(256, 0);

        // Frequency required from t
        for (char c : t) {
            need[c]++;
        }

        int required = 0;   // number of unique characters required
        for (int i = 0; i < 256; i++) {
            if (need[i] > 0)
                required++;
        }

        int have = 0;       // unique characters currently satisfied

        int left = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            // Add s[right] to window
            char c = s[right];
            window[c]++;

            // Did this character just become satisfied?
            if (need[c] > 0 && window[c] == need[c]) {
                have++;
            }

            // Window is valid
            while (have == required) {

                // Update answer
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove s[left]
                char removeChar = s[left];
                window[removeChar]--;

                // Did removing it make the window invalid?
                if (need[removeChar] > 0 &&
                    window[removeChar] < need[removeChar]) {
                    have--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};