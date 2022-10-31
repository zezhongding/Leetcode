//https://leetcode.cn/problems/magical-string/
//模拟
class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int tmp = 2;
        int ans = 1;
        while(s.size() < n) {
            int e = s[s.size() - 1];
            char c = (e == '1') ? '2' : '1';
            for(int i = 0; i < int(s[tmp] - '0'); ++i) {
                s.push_back(c);
                if(c == '1') ans += 1;
                if(s.size() == n) break;
            }
            tmp += 1;
        }
        return ans;
    }
};