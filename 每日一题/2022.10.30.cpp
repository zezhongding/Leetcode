//https://leetcode.cn/problems/letter-case-permutation/
//DFS
//可使用掩码使得时间复杂度为O(1)
class Solution {
public:
    vector<string> ans;
    int n;
    void DFS(int i, string s) {
        if(i == n) {
            ans.push_back(s);
            return;
        }
        if(s[i] >= 'a' && s[i] <= 'z') {
            DFS(i + 1, s);
            s[i] += 'A' - 'a';
            DFS(i + 1, s);
        } else if(s[i] >= 'A' && s[i] <= 'Z') {
            DFS(i + 1, s);
            s[i] += 'a' - 'A';
            DFS(i + 1, s);
        } else {
            DFS(i + 1, s);
        }
    }
    vector<string> letterCasePermutation(string s) {
        n = s.size();
        DFS(0, s);
        return ans;
    }
};


//动态规划+单调栈
class Solution {
public:
    typedef long long ll;
    const ll M = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<ll> dp(n);
        vector<ll> mystack;
        ll ans = 0ll;
        for(int i = 0; i < n; ++i) {
            while(!mystack.empty() && arr[i] < arr[mystack.back()]) {
                mystack.pop_back();
            }
            int k = mystack.empty() ? (i + 1) : (i - mystack.back());
            dp[i] = (mystack.empty() ? 0 : dp[mystack.back()]) + k * arr[i];
            mystack.push_back(i);
            ans = (ans + dp[i]) % M;
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        int m = 0;
        for (auto c : s) {
            if (isalpha(c)) {
                m++;
            }
        }
        vector<string> ans;
        for (int mask = 0; mask < (1 << m); mask++) {
            string str;
            for (int j = 0, k = 0; j < n; j++) {
                if (isalpha(s[j]) && (mask & (1 << k++))) {
                    str.push_back(toupper(s[j]));
                } else {
                    str.push_back(tolower(s[j]));
                }
            }
            ans.emplace_back(str);
        }
        return ans;
    }
};

