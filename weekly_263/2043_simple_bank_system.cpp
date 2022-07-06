
#include <bits/stdc++.h>

using namespace std;

class Bank {
private:
    vector<long long> bankb;
    int n;
public:
    Bank(vector<long long>& balance) {
        bankb = balance;
        n = bankb.size();    
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1<=n && account1>=1){
            if(bankb[account1-1]>=money){
                bankb[account1-1]-=money;
                bankb[account2-1]+=money;
                return true;
            }            
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account>=1 && account<=n){
            bankb[account-1] +=money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(account>=1 && account<=n){
            if(bankb[account-1]>=money){
                bankb[account-1]-=money;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */