#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORk(i,a,b,k) for(int i=a;i<b;i+=k)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define RFORk(i,a,b,k) for(int i=a;i>=b;i-=k)
#define pb push_back
typedef vector<int> vi;
typedef vector<string> vs;

int f_gcd(int a,int b,int &x,int &y){
    if(b==0) {
        x=1;
        y=0;
        return a;
    }
    int x0,y0;
    int g = f_gcd(b,a%b,x0,y0);
    x=y0;
    y=x0-(a/b)*y0;
    return g;
}

void solve(){
    int a,b,c,g,x,y;
    cin >> a >> b >>c;
    if (a>b) g = f_gcd(a,b,x,y);
    else g = f_gcd(b,a,y,x);
    if((c%g)==0) {
        cout << 'Yes' << endl;
        // cout <<"x: "<<(c/g)*x <<" y: "<< (c/g)*y  << endl;
    }
    else {
        cout << 'No' << endl;
        // cout << "No Solution Exists!" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t=1;
    cin >> t;
    FOR(i,1,t+1){
        cout << "Case "<< i << ": ";
        solve();
    }
    return 0;
}