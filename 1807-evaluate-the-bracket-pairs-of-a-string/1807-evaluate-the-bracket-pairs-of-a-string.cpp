class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Build the dictionary from knowledge
        unordered_map<string, string> dict;
        for (auto &kv : knowledge) {
            dict[kv[0]] = kv[1];
        }
        
        string result;
        int n = s.size();
        int i = 0;
        while(i < n) {
            if(s[i] == '(') {
                i++; // skip the '('
                string key;
                while(i < n && s[i] != ')') {
                    key.push_back(s[i]);
                    i++;
                }
                i++; // skip the ')'
                // Lookup the key in the dictionary
                if(dict.find(key) != dict.end()) {
                    result += dict[key];
                } else {
                    result += "?";
                }
            } else {
                result.push_back(s[i]);
                i++;
            }
        }
        return result;
    }
};
