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
	for( int t = 0; t<T; t++ ){
		cin >> N;
	//	cout << N <<" "<< B << "\n";
        string num = to_string(N);
        int sum = 0;
        for(char c: num){
            sum+= c - '0';
        }
        int remainder  = sum%9;
        int n = num.length();
        if(remainder!=0){
            int digit = 9 - remainder;
            for(int i = 0;i<n;i++){
                if(digit<(num[i]-'0')){
                    // continue;
                    if(i==0){
                        num = to_string(digit) + num;
                    }
                    else{
                        num = num.substr(0,i) + to_string(digit) + num.substr(i);
                    }
                    break;
                }
                else{
                    continue;
                }
            }
            if(num.length()==n){
                num =  num + to_string(digit);
            }
        }
        else{
            num = num.substr(0,1) + "0" + num.substr(1);
        }
	

	cout<<"Case #"<<t+1<<": "<<num<<"\n";	
	}
return 0;
}
