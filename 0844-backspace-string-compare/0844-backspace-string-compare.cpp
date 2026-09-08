class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;

        for (char c : s) {
            if (c == '#') {
                if (!st1.empty()) {
                    st1.pop();
                }
            } else {
                st1.push(c);
            }
        }

        for (char c : t) {
            if (c == '#') {
                if (!st2.empty()) {
                    st2.pop();
                }
            } else {
                st2.push(c);
            }
        }

        string ans1 = "";
        string ans2 = "";

        while (!st1.empty()) {
            ans1 += st1.top();
            st1.pop();
        }

        while (!st2.empty()) {
            ans2 += st2.top();
            st2.pop();
        }

        return ans1 == ans2;
    }
};