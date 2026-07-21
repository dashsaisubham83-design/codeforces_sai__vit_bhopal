### **#2240A - Another Popcount Problem**

### 

### **Question :** 



You are given two integers n and k.



Your task is to construct a sequence a consisting of k non-negative integers a1,a2,…,ak such that:



&#x20;   ∑ki=1ai≤n

&#x20;   The total number of set bits, i.e., ∑ki=1popcount(ai), is as large as possible. 



You only need to output the maximum possible value of ∑ki=1popcount(ai).



Here, popcount(x) denotes the number of 1 bits in the binary representation of x. For example, popcount(6)=popcount((110)2)=2, and popcount(0)=0.

Input



Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤103). The description of the test cases follows.



Each of the next t lines contains two integers n and k (1≤n,k≤106) — the maximum allowed sum of the sequence and the length of the sequence, respectively.

Output



For each test case, output a single integer — the maximum possible value of ∑ki=1popcount(ai).





### 



### **Answer:**



**#include <bits/stdc++.h>**

**using namespace std;**



**int main(){**

&#x20;   **int t;**

&#x20;   **scanf("%d", \&t);**

&#x20;   **while(t--){**

&#x20;       **long long n, k;**

&#x20;       **scanf("%lld %lld", \&n, \&k);**



&#x20;       **long long remaining = n;**

&#x20;       **long long countAtLevel = k;**

&#x20;       **long long total = 0;**

&#x20;       **long long cost = 1; // 2^level**



&#x20;       **while(remaining > 0 \&\& countAtLevel > 0 \&\& cost <= remaining){**

&#x20;           **long long maxAfford = remaining / cost;**

&#x20;           **long long upgrades = min(maxAfford, countAtLevel);**

&#x20;           **total += upgrades;**

&#x20;           **remaining -= upgrades \* cost;**

&#x20;           **if(upgrades < countAtLevel) break; // couldn't fully clear this level -> nothing left for higher levels**

&#x20;           **countAtLevel = upgrades;**

&#x20;           **cost \*= 2;**

&#x20;       **}**



&#x20;       **printf("%lld\\n", total);**

&#x20;   **}**

&#x20;   **return 0;**

**}**

