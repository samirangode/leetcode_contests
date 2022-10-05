#include <bits/stdc++.h>

using namespace std;

int main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	//cout<< T<< "\n";
	// long long N, B;
    int N;
    unordered_map<string,string> um;
    for(int i = 0; i<10;i++){
        string key = to_string(i%10) + to_string((i+1)%10);
        um[key] = to_string((i+2)%10);
    }
	for( int t = 0; t<T; t++ ){
		cin >> N;
        string S;
        cin >> S;
        int changes; string new_str= "";
        string old = S;
        string ans = "";
        do{
            changes = 0; int i=0,n = old.length();
            while (i<n)
            {
                if(um.find(old.substr(i,2))!=um.end()){
                    new_str+=um[old.substr(i,2)];
                    i+=2; changes+=1;
                }
                else{
                    new_str+=old.substr(i,1);
                    i+=1;
                }
            }
            ans = old;
            old =new_str;
            new_str = "";

        }while(changes!=0);
	//	cout << N <<" "<< B << "\n";
        

	cout<<"Case #"<<t+1<<": "<<ans<<"\n";	
	}
return 0;
}

