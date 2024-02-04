class Solution {
public:
    string minWindow(string s, string t) {
        int sn = s.size();
        int tn = t.size();
        int left = 0, right;
        int mp[64]={0};
        int tmp[64]={0};

        for (char c : t){
            int cnt = 0x3f &c;
            tmp [cnt]++;
        }

        int count = 0;

        int minimumLen = INT_MAX;
        int minimumLeft = 0;

        for (right = 0; right < sn; right ++){
            char c = s[right];
            int cnt = 0x3f & c;
            if (tmp[cnt] == 0) continue;

            mp[cnt]++;

            if (mp[cnt] <= tmp[cnt]) count++;

            if (count == tn){
                while (tmp[0x3f & s[left]] == 0 || mp[0x3f & s[left]] > tmp[0x3f & s[left]]){
                    if (mp[0x3f & s[left]] != 0) mp[0x3f & s[left]]--;
                    left++;
                }

                if (right - left + 1 < minimumLen){
                    minimumLen = right - left + 1;
                    minimumLeft = left;
                }
            }
        }

        if (minimumLen == INT_MAX) return "";

        return s.substr(minimumLeft, minimumLen); 
    }
};