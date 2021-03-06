/*
	- https://www.ioi-jp.org/camp/2018/2018-sp-tasks/day2/asceticism-review.pdf
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mxN=1e5, M=1e9+7;
int n, k;
ll fi[mxN+1], ans;

ll exp(ll b, int p) {
	ll r=1;
	while(p) {
		if(p&1)
			r=b*r%M;
		b=b*b%M;
		p/=2;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	fi[0]=1;
	for(int i=1; i<=n; ++i)
		fi[i]=exp(i, M-2)*fi[i-1]%M;
	for(int j=0; j<=1; ++j)
		for(int i=0; i<k-j; ++i)
			ans+=(i&1^j?M-1:1)*exp(k-j-i, n)%M*fi[i]%M*fi[n-i]%M;
	for(int i=2; i<=n; ++i)
		ans=i*ans%M;
	cout << ans;
}
