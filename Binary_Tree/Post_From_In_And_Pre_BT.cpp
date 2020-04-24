#include <bits/stdc++.h>
using namespace std;
#define int long long
using ldb = long double;
using pa = pair < int, int >;
#define F  first
#define S  second
#define f(i,x,n) for(int i=x;i<n;i++) 
#define all(c) c.begin(),c.end()
 
const int MOD = 1e9 + 7, INF = INT_MAX, N = 5e5 + 10;
const double PI = acos(-1);
const int LINF = LLONG_MAX;

map<int,int>maps;
int i = 0;
void postorder(int in[],int pre[],int start,int end){
    if(start > end){
        return;
    }
    int index = maps[pre[i++]];
    postorder(in,pre,start,index-1);
    postorder(in,pre,index+1,end);
    cout << in[index] << " ";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int in[] = { 4, 2, 5, 1, 3, 6 };  
    int pre[] = { 1, 2, 4, 5, 3, 6 };
    int n = 6;
    for(int i = 0;i < 6;i++){
        maps[in[i]] = i;
    }
    postorder(in,pre,0,5);
    return 0;
}