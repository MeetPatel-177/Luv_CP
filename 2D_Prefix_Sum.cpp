//Problem :
//given 2d array of n*n integers . Given q queries and in each query we have been given
//a,b,c, and d and print sum of rectangle represented as (a,b) as top left point and (c,d)
//as bottom right point
//Constraints :
//1 <= N <= 10^3
//1 <= arr[i][j] <= `0^9
//1 <= q <= 10^5
//1 <= a,b,c,d <= N

//Now the first approach is to calculate given thing for every qyery separately
//so it will take around O(q*n^2) = 10^11 iterations 
//so it will not be accepted so we have to optimise it using prefix sum

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int arr[N][N];
int pf[N][N];

int main() {
    int n;
    cin >> n;
    //take 1 based index input
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            pf[i][j] = pf[i-1][j] + (pf[i][j-1] - pf[i-1][j-1]) + arr[i][j];
        }
    }

    int q;
    cin >> q; 
    while(q--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        cout << pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1] << endl;
    }
    return 0;
}