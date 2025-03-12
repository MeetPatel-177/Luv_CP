//constraints :
// 1 <= T <= 1e5
// 1 <= N <= 1e5
//Problem :
//you have to find factorial of n for every test case t
//since factorial is very large print it with modulo of 1e9 + 7

//first approach is taking t and n then we will calculate factorial of n every time
//so it will take around O(T*N) = O(N^2) since both are 10^5 this will not work

//so we will first calculate factorials for every n from 1 to 1e5 and store it in an array
//and then for every test case we will print its factorial from array
#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 1e5 + 1;
int factorial[N];

int main() {
    //why 1LL because we are sure that factorial[i-1] will be an integer but as
    //i can also be like 10^5 so when we multiply both it may go outside range of int
    //so just for calculation we will use type casting of long long and then
    //again we are doing whole modulo M so the number factorial[i] will also be an integer
    //so we can store it in an array of int type
    factorial[0] = 1;
    for(int i=1; i<N; i++) {
        factorial[i] = (1LL*factorial[i-1]*i) % M;
    }
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << factorial[n] << endl;
    }
    return 0;
}