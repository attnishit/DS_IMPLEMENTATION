#include <bits/stdc++.h>
using namespace std;
#define int long long 
using ldb = long double;
using pa = pair < int, int >;
#define F  first
#define S  second
#define f(i,x,n) for(int i=x;i<n;i++) 
#define all(c) c.begin(),c.end()
const int MOD = 1e9 + 7, N = 5e5 + 10;
const int LINF = LLONG_MAX;
int n;
int f = 0;
string s1,s2,s;
int c ;
char solve(int index){
	if(index >= n){
		return '*';
	}
	if(s[index] == '.'){
		f = 1;
	}
	if(f == 0){
		s1 += s[index];
	}
	else{
		s2 += s[index];
	}
	solve(index+1);

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    s1 = "";
    s2 = "";
    n = s.size();
    solve(0);
    cout << "integer part " << s1 << endl;
    cout << "real part "  << s2 << endl;
    cout << "original no " << s1 + s2 << endl;

    return 0;
}
 