#include <bits/stdc++.h>

#define all(c) c.begin(), c.end()
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvi vector< vi >
#define mk make_pair
#define ii pair <int, int>
#define fi first
#define se second
#define mx max_element
#define mn min_element
#define rep(i,n)    for(__typeof(n) i = 0; i < n; i++)
#define rep1(i,n)   for(__typeof(n) i = 1; i <= n; i++)
double tick(){static clock_t oldt,newt=clock();double diff=100.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}

using namespace std;

ll inf=1e18+1;  
ll N; 
vll v,q,st;
ll in=0,i=0,j=0,k=0,ans=0,p,value,l,r;
ll n=0,m=0,t=0,v1=0,v2=0;
char c; string s;
vi sg(800,0);

void build(){
    for(i=n-1; i>0; i--) sg[i] = sg[i<<1] + sg[i<<1|1];
}

void update(){
    for(sg[p += n]=value; p>1; p>>=1) sg[p>>1] = sg[p]+sg[p^1]; 
}

void query(){
    ans = 0;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1){
        if(l&1) ans += sg[l++];
        if(r&1) ans += sg[--r];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    rep(i,n) cin >> sg[n+i];
    build();
    cout << sg[1] << endl;
    cin >> p >> value;
    update();
    cout << sg[1] << endl;
    cin >> l >> r;
    query(); 
    cout << ans << endl;
    //cout<<"\n"<<"Execution time : "<<tick()<<"\n";
    return 0;
}

