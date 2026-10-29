class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(const auto &str : strs)
        {
            ans+=to_string(str.length()) + "#" + str;
        }
        return ans;
    }

    vector<string> decode(string s) {
      vector<string>ans;
      int n = s.length();
      int len = 0;
      int i;
      int j = 0;
      while(j<n)
      { 
        i = j;
        while(i<n && s[i]!='#')
        {
            len = len*10 + s[i] - '0';
            i++;
        }
        ans.push_back(string(s.begin() + i + 1, s.begin() + i + 1 + len));
        j = i+1+len;
        len = 0;
      }
      return ans;

    }
};
