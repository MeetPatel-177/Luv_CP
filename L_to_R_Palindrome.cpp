/*
Problem : 
in this we have to find if we can rearrange letters from L to R to form palindrome or not
we have given Q queries in each we have given L and R
Constraints : 
1 <= N <= 10^5
1 <= Q <= 10^5
*/

/*
so here we have given some queries that is 10^5 so we can't even think about brute force
we have to do pre computation and hashing in order to solve the problem
*/

/*
we will keep a 2d array of 26 alphabets in every alphabet we will store freq of it
then we will take prefix sum of it and we will ended up having prefix count of all the letters
then we will just take all the queries and give ans according to condition
we will ended up having O(26*n*t) nearly equals 10^6 so this is valid
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,q;
        cin >> n >> q;
        string str;
        cin >> str;
        vector<vector<int>>freq(26, vector<int>(n,0));
        for(int i=0; i<26; i++) {
            for(int j=0; j<n; j++) {
                if(str[j] == (char)(i + 'a')) freq[i][j] = 1;
            }
        }
        vector<vector<int>>prefix_count(26, vector<int>(n));
        for(int i=0; i<26; i++) {
            prefix_count[i][0] = freq[i][0];
        }
        for(int i=0; i<26; i++) {
            for(int j=1; j<n; j++) {
                prefix_count[i][j] = prefix_count[i][j-1] + freq[i][j];
            }
        }
        while(q--) {
            int l,r;
            cin >> l >> r;
            l--, r--;
            int odd_count = 0;
            for(int i=0; i<26; i++) { 
                int count_in_between = 0;
                if(l != 0) count_in_between = prefix_count[i][r] - prefix_count[i][l-1];
                else count_in_between = prefix_count[i][r];
                if(count_in_between % 2 != 0) odd_count++;
            }
            if(odd_count >= 2) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
    return 0;
}