#include <bits/stdc++.h>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	//cout<< T<< "\n";
	// long long N, B;
    // int N;
    int R; int A; int B; int r;
	for( int t = 0; t<T; t++ ){
        cin>>R>>A>>B;
        
        r = R; long double ans = M_PI*R*R;
        while(r>0){
            r= r*A;
            ans+=M_PI*r*r;
            r=r/B;
            if(r>0){
                ans+=M_PI*r*r;
            }
            // cout<<r<<" printing r "<<endl;
            // cout<<A<<" printing A "<<endl;
            // cout<<B<<" printing B "<<endl;
        }
    // ans = M_PI*ans;
	cout<<"Case #"<<t+1<<": "<<fixed<<setprecision(6)<<ans<<"\n";	
	}
return 0;
}

