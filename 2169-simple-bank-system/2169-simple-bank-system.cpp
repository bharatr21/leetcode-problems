class Bank {
public:
    vector<long long> accounts;
    Bank(vector<long long>& balance) {
        int n = balance.size();
        accounts.resize(n + 1);
        for(int i = 0; i < n; i++) {
            accounts[i + 1] = balance[i];
        }
    }

    bool outBounds(int k) {
        int n = accounts.size() - 1;
        return (k < 1 || k > n);
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(outBounds(account1) || outBounds(account2) || accounts[account1] < money) return false;
        accounts[account1] -= money;
        accounts[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(outBounds(account)) return false;
        accounts[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(outBounds(account) || accounts[account] < money) return false;
        accounts[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */