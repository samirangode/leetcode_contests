#include <bits/stdc++.h>
using namespace std;
// g++ -std=c++11 -O2 -Wall test.cpp -o test

int main(int argc, char const *argv[])
{
	int T;
	cin>>T;
	int test_cases=0;
	while(test_cases<T){
        int N;
        int D;
        int C;
        int M;
        cin>>N >>D >>C >> M;
        //debug
        // cout<<D<<endl;
        // cout<<C<<endl;
        // cout<<M<<endl;
        string s;
        cin>>s;
        bool complete = true;
        int i = 0;
        while(i<N){
            if(s[i]=='C'){
                if(C>0){
                    C--;
                }
                else{
                    complete = false;
                    break;
                }
            }
            if(s[i]=='D'){
                if(D>0){
                    D--;
                }
                else{
                    complete = false;
                    break;
                }
                if(M>0){
                    C+=M;
                }
            }
            i++;
        }
        if(complete==false && i<N && s[i]=='C'){
            while(i<N){
                if(s[i]=='D'){

                    complete = false;
                    break;
                }
            i++;
            }
            if(i==N){
            complete = true;}
        }
		// int N;
		// cin>>N;
		// vector<int> v;
		// int val = 0;
		// for (int i = 0; i < N; ++i)
		// {	cin>>val;
		// 	v.push_back(val);
		// 	/* code */
		// }
		// int maxLen = 0;
		// int len = 0;
		// int d = 0;
		// for(int i = 0; i < N; ++i){
		// 	if(i == 0) continue;
		// 	if(i == 1){ 
		// 		d = v[1] - v[0];
		// 		continue;
		// 	}
		// 	int newD = v[i] - v[i-1];
		// 	if(newD == d){
		// 		if(len<3) len = 3;
		// 		else len++;
		// 		maxLen = max(len, maxLen);
		// 	}
		// 	else{
		// 		d = newD;
		// 		len = 0;
		// 	}
		// }
		if(complete){cout<<"Case #"<<test_cases+1<<": "<<"YES"<<"\n"; test_cases ++;}
        else{
            cout<<"Case #"<<test_cases+1<<": "<<"NO"<<"\n"; test_cases ++;
        }
		// if(N<2) {cout<<"Case #"<<test_cases+1<<": "<<0<<"\n"; test_cases ++; continue;}
		// if(maxLen>2)
		// 	cout<<"Case #"<<test_cases+1<<": "<<maxLen<<"\n";
		// else
		// 	cout<<"Case #"<<test_cases+1<<": "<<2<<"\n";

		// test_cases++;
	}
	return 0;
}