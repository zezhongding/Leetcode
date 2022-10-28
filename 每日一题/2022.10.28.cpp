//https://leetcode.cn/problems/sum-of-subarray-minimums/
//单调栈做法
class Solution {
public:
    typedef long long ll;
    const ll M = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        ll ans = 0;
        int n = arr.size();
        vector<ll> mystack;
        vector<ll> left(n), right(n);
        for(int i = 0; i < n; ++i) {
            while(!mystack.empty() && arr[i] <= arr[mystack.back()]) {
                mystack.pop_back();
            }
            left[i] = i - (mystack.empty() ? -1 : mystack.back());
            mystack.push_back(i);
        }
        mystack.clear();
        for(int i = n - 1; i >= 0; --i) {
            while(!mystack.empty() && arr[i] < arr[mystack.back()]) {
                mystack.pop_back();
            }
            right[i] = (mystack.empty() ?  n : mystack.back()) - i;
            mystack.push_back(i);
        }
        for(int i = 0; i < n; ++i) {
            ans = (ans + left[i] * right[i] * arr[i]) % M; //模运算与乘法除法同优先级
        } 
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