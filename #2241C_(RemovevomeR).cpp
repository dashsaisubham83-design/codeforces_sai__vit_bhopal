#2241C (RemovevomeR)
Question :
You are given a binary string s consisting only of the characters 0 and 1.

In one operation, you can do the following:

    Choose a substring∗ of s that is a palindrome† of length at least 2.
    Delete exactly one character from this chosen substring. 

The remaining parts of the string are then concatenated to form the new string s.

Find the minimum possible length of the string s that can be achieved after applying this operation any number of times (possibly zero).

∗A string a is a substring of a string b if a can be obtained from b by the deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

†A string a of length m is said to be palindrome if ai=am+1−i for all 1≤i≤m.
Input

The first line contains a single integer t (1≤t≤100) — the number of test cases. Description of each test case follows.

The first line of each test case contains a single integer n (1≤n≤100) — the length of the binary string s.

The second line of each test case contains a binary string s of length n. It is guaranteed that each character of s is either 0 or 1.
Output

For each test case, print the minimum possible length of the string s that can be achieved after applying the operation any number of times.






Answer :
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        char buf[105];
        scanf("%s", buf);
        string s(buf);

        int blocks = 1;
        for(int i = 1; i < n; i++)
            if(s[i] != s[i-1]) blocks++;

        int ans;
        if(blocks == 1) ans = 1;      // all same char -> reduce to 1
        else if(blocks == 2) ans = 2; // two blocks -> stuck at 2
        else ans = 1;                 // 3+ blocks -> reduce to 1

        printf("%d\n", ans);
    }
    return 0;
}
