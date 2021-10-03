/*

Problem Statement:

Value of an array A of length L is defined as the sum of (A[i]⊕i) for all 0≤i<L,
where ⊕ denotes bitwise xor operation. Note that array indices start from zero.

You are given an integer N and an array A consisting of 2N integers where Ai=i for all 0≤i<2N.
Example :

For N=1, you have an array A of length 21=2 and A=[0,1].
For N=2, you have an array A of length 22=4 and A=[0,1,2,3].
You can do at most K operations on this array. In one operation,
you can choose two indices i and j (0≤i,j<2N) and swap Ai and Aj (i.e. Ai becomes Aj and vice versa).

What is the maximum value of array A you can obtain after at most K operations?


Input Format

1. First line will contain T, number of testcases. Then the testcases follow.
2. Each testcase contains a single line of input, two integers N,K.

Output Format
For each testcase, output in a single line the maximum value of array after doing at most K operations.

Constraints

    1≤T≤105
    1≤N≤30
    0≤K≤109

Sample Input 1
3
2 0
2 1
10 100

Sample Output 1
0
6
204600


Explanation:

In the first test case, for N=2, you have the array A=[0,1,2,3].
No swap operation is allowed hence value of array A=(0⊕0)+(1⊕1)+(2⊕2)+(3⊕3)=0+0+0+0=0.
In the second test case, initially the array A=[0,1,2,3]. If you swap A1 and A2,
A becomes [0,2,1,3]. Now value of array A=(0⊕0)+(2⊕1)+(1⊕2)+(3⊕3)=0+3+3+0=6. T
here is no possible way such that value of array A becomes greater than 6 using one swap operation.

*/


//Solution Code:-


/* Vivek Arora */
#include<iostream>
#include<vector>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<unordered_set>
#include<cmath>
#include<numeric>
#include<iterator>
#include<set>
#include<unordered_map>
#include<map>
#include<queue>
#include<cstring>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<functional>
#include<bitset>
#include<chrono>
#include<climits>
#include<assert.h>

using namespace std;
using namespace chrono;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) (int)(x.size())


#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}


template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
//void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/


long long binpow(long long a, long long b) {
      long long res = 1;
      while (b > 0) {
            if (b & 1)
                  res = res * a;
            a = a * a;
            b >>= 1;
      }
      return res;
}

void solve() {
      int t; t = 1;
      cin >> t;
      while (t--) {

            ll n, k;
            cin >> n >> k;

            ll a = binpow(2, n);
            ll j = a - 1;
            ll v = binpow(2, (n - 1));
            cout << min(binpow(2, n), (2 * k))*(j) << nline;
           
      }

}


int main() {
      fastio();
#ifndef ONLINE_JUDGE
      freopen("Input.txt", "r", stdin);
      freopen("Output.txt", "w", stdout);
      freopen("Error.txt", "w", stderr);
#endif
      auto start1 = high_resolution_clock::now();
      solve();
      auto stop1 = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
      cerr << "Time: " << duration.count() / 1000 << endl;
#endif
      return 0;
}
