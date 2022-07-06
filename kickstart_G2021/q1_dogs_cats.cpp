#include <bits/stdc++.h>

using namespace std;

// int main()
// {	
// 	ios::sync_with_stdio(0);
// 	cin.tie(0);
// 	int T;
// 	cin >> T;
// 	//cout<< T<< "\n";
// 	// long long N, B;
//     int N;
//     int D,C, M;
// 	for( int t = 0; t<T; t++ ){
//         cin >> N >> D >>C >> M;
//         string s;
//         cin>>s;
//         bool dog_left = false;
//         bool cat_over = false;
//         int i;
//         if((t+1) == 9){
//             cout<<s<<endl;   
//         }
//         for(i =0;i <N; i++){
//             if(s[i]=='D'){
//                 if(D>0){D--; C+=M;}
//                 else{
//                     dog_left = true;
//                     break;
//                 }
//             }else{
//                 if(C>0){
//                     C--;
//                 }else{
//                     cat_over = true; break;
//                 }
//             }
//         }
        
//         if(dog_left){
//             cout<<"Case #"<<t+1<<": "<<"NO"<<"\n";
//             continue;        
//         }
//         else if(i==N && !dog_left){
//             cout<<"Case #"<<t+1<<": "<<"YES"<<"\n";
//             continue;
//         }
//         for(;i<N;i++){
//             if(s[i]=='D') {dog_left = true; break;}
//         }
//         if(dog_left){
//             cout<<"Case #"<<t+1<<": "<<"NO"<<"\n";
//             continue;        
//         }
//         else{
//             cout<<"Case #"<<t+1<<": "<<"YES"<<"\n";
//             continue;
//         }
        
// 	//	cout << N <<" "<< B << "\n";
        

// 	// cout<<"Case #"<<t+1<<": "<<num<<"\n";	
// 	}
// return 0;
// }

#define ll long long
#define mod 1e9 + 7

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,n,d,c,m,i,j,f;
    string a;
    cin>>t;
    for(j=1;j<t; j++){
        f = 0;
        cin>>n>>d>>c>>m;
        cin>>a;
        for(i=0;i<n;i++){
            if(a[i]=='D'){
                if(d>0){
                    d--;
                    c+=m;
                }else{
                    break;
                }
            }else{
                if(c>0){
                    c--;
                }else{
                    break;
                }
            }
        }
        for(;i<n;i++){
            if(a[i]=='D'){
                f++;
                break;
            }
        }
        if(f==0){
            cout<<"Case #"<<j<<":"<<"YES"<<endl;
        }else{
            cout<<"Case #"<<j<<":"<<"NO"<<endl;
        }
    }
}



