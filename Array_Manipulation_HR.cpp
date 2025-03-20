/*
Problem : 
starting with 1 indexed array of all zeroes intially , we have m queries in each query we have
given three values a,b,k and for each query we will add k to the indexes from a to b
after all operations done we have to find the maximum element in the array
Constraints : 
3 <= n <= 10^7
1 <= m <= 2*10^5
1 <= a <= b <= n
0 <= k <= 10^9
*/

/*
the first approach that came into mind is just brute force the thing which they say just do it
but here n is 10^7 so we can never think of an approach of O(m*n) so we have to optimise it
so again whenever something like query stuff is given try to use pre computation
*/

/*
this technique is hard to understand in beginning so just remember this thing in beginning
we will add k in arr[a] and subtract k from arr[b+1] and then we will take prefix sum of
whole array and we will get our desired output
let's say we have n = 6 so arr -> 0 0 0 0 0 0
query1 -> 2 3 5 so now arr -> 0 5 5 0 0 0
query2 -> 3 5 6 so now arr -> 0 5 11 6 6 0
now let us use our optimisation
after query1 arr -> 0 +5 0 -5 0 0 
after query2 arr -> 0 0 +6 0 0 -6
now take prefix sum of whole array 0 5 11 6 6 0
it is same ad above so this will work in O(n) that is 10^7
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
//we have to use global array as size in in the range of 10^7 so we can't declare it
//inside main we have to declare it globally
//as we have declared it globally so all will be initialised with zero already
int arr[N];
int main() {
    int n,m;
    cin >> n >> m;
    //O(m)
    while(m--) {
        int a,b,k;
        cin >> a >> b >> k;
        arr[a] += k;
        arr[b+1] -= k;
    }
    //O(n)
    //here we are taking prefix sum of all elements
    for(int i=1; i<=n; i++) {
        arr[i] += arr[i-1];
    }
    int maxi = -1;
    //O(n)
    for(int i=1; i<=n; i++) {
        if(maxi < arr[i]) maxi = arr[i];
    }
    cout << maxi << endl;
    //O(m + 2n) = O(n) = 10^7
    return 0;
}