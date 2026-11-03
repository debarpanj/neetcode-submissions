class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int mp[128] ={0};
        auto is_repeated =[&]()
        {
            for(int i=0;i<128;i++)
            {
                if(mp[i]==2)return true;
            }
            return false;
        };

        int i=0,j=0;
        int maxlen = 0;
        while(j<n)
        {
            mp[s[j]]++;
            while(is_repeated() && i<j)
            {
                mp[s[i++]]--;
            }
            maxlen = max(maxlen,j-i+1);
            j++;

        }

        return maxlen;
    }
};
