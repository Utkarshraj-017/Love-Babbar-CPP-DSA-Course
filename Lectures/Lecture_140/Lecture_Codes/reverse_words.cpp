class Solution {
  public:
    string reverseWords(string &s) {
        // code here
        vector<string> v;
        string str = "";
        for (int i=0; i<s.length(); i++) {
            if (s[i] != '.') {
                str += s[i];
            }
            else {
                v.push_back(str);
                str = "";
            }
        }
        
        reverse(v.begin(), v.end());
        
        for (int i=0; i<v.size(); i++) {
            str += "." + v[i];
        }
        
        return str;
    }
};