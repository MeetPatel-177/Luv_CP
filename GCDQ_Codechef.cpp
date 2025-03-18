/*
Problem : 
we have given T test cases and in each test case 
we have been given an array of N integers and we have given Q queries in each query we have 
given two integers L and R . for each query we have to find gcd of whole array excluding
the part of the array from L to R
Constraints : 
2 <= T,N <= 10^5 
1 <= Q <= N
1 <= a[i] <= 10^5
1 <= L,R <= N
L <= R
sum of N over all test cases will always be less than or equal to 10^6
*/

/*
the first approach that came to mind is brute force approach that is we will calculate gcd of
all the elements from i=1 to i=L-1 and then we will calculate gcd of all the elements rom
i=R to i=N and then we will add both and we will get our answer 
but the main prolem is with TC O(T*N*Q) but here T will be ignored as last line is given
so we have to optimise it
*/

/*
now for optimisation we will use pre computation for gcd 
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,q;
        cin >> n >> q;
        vector<int>arr(n+10);
        //always take 1 based index when we are trying to use pre computation like stuff
        for(int i=1; i<=n; i++) cin >> arr[i];
        //why we are using 2 arrays for pre computation 
        //forward gcd will store gcd of 1 to i for any i
        //backward gcd will store gcd from i to n for any i
        //so we will calculate gcd of 1 to L from forward and gcd of R to n from backward
        vector<int>forward_gcd(n+10);
        vector<int>backward_gcd(n+10);
        for(int i=1; i<=n; i++) {
            forward_gcd[i] = __gcd(forward_gcd[i-1], arr[i]);
        }
        for(int i=n; i>=1; i--) {
            backward_gcd[i] = __gcd(backward_gcd[i+1], arr[i]);
        }

        while(q--) {
            int l,r;
            cin >> l >> r;
            int gcd_before_L = forward_gcd[l-1];
            int gcd_after_R = backward_gcd[r+1];
            cout << __gcd(gcd_after_R, gcd_before_L) << endl;
        }
    }
    return 0;
}