class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()) return false;
        int mp_s1[26] = {0};

        int n = s1.length(), m = s2.length();
        for(int i=0;i<n;i++) mp_s1[s1[i]-'a']++;
        int mp_s2[26] = {0};

        auto is_equal = [&]()
        {
            for(int i=0;i<26;i++)
            {
                if(mp_s1[i]!=mp_s2[i]) return false;
            }
            return true;
        };
        for(int i=0;i<n;i++)
        {
            mp_s2[s2[i]-'a']++;
        }
        if(is_equal()) return true;

        for(int i=n;i<m;i++)
        {
            mp_s2[s2[i-n]-'a']--;
            mp_s2[s2[i]-'a']++;
            if(is_equal()) return true;
        }

        return false;
    }
};
