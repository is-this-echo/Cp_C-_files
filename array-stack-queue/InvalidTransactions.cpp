/* Debjyoti Ghosh*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define INF 2e18
#define PI 3.1415926535897932384626
#define mod 998244353
#define f first
#define s second 

double eps = 1e-12;

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
void google(int t) {cout << "Case #" << t << ": ";}
    

class Solution {
    struct Transaction {
        string name{};
        int time{};
        int val{};
        string city{};
        bool seen{};
    };
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<Transaction> txs;
        vector<string> res;

        // input processing
        for (const auto& csv : transactions) {
            Transaction tx;

            istringstream iss(csv);
            string token;
            for (int i = 0; i < 4 && getline(iss, token, ','); ++i) {
                if (i == 0) {
                    tx.name = token;
                } else if (i == 1) {
                    tx.time = stoi(token);
                } else if (i == 2) {
                    tx.val = stoi(token);
                } else {
                    tx.city = token;
                }
            }

            txs.emplace_back(tx);
        }

        for (int i = 0; i < txs.size(); ++i) {
            if (txs[i].val > 1000)
                txs[i].seen = true;
            for (int j = 0; !txs[i].seen && j < txs.size(); ++j) {
                // need to go through every one of the transactions as time
                // values are not sorted for any user, so we can't do j = i + 1
                if (i != j
                    && txs[i].name == txs[j].name 
                    && txs[i].city != txs[j].city
                    && abs(txs[i].time - txs[j].time) <= 60) {
                    txs[i].seen = true;
                    txs[j].seen = true;
                }
            }
        }

        for (int i = 0; i < txs.size(); ++i)
            if (txs[i].seen)
                res.emplace_back(transactions[i]);

        return res;
    }
};


//  Modern C++
class Solution {
    struct Transaction
    {
        std::string name;
        int time;
        int amount;
        std::string city;
        bool isMarked;

        Transaction(std::string name, int time, int amount, std::string city)
            : name(std::move(name)), time(time),
                amount(amount), city(std::move(city)), isMarked(false) {}
    };

public:
    vector<string> invalidTransactions(vector<string>& transactions)
    {
        std::vector<std::shared_ptr<Transaction>> txns;
        for (const auto& txn : transactions)
        {
            std::istringstream iss(txn);
            std::string token;

            std::getline(iss, token, ',');
            std::string name = token;

            std::getline(iss, token, ',');
            int time = std::stoi(token);

            std::getline(iss, token, ',');
            int amount = std::stoi(token);

            std::getline(iss, token, ',');
            std::string city = token;

            txns.emplace_back(std::make_shared<Transaction>(name, time, amount, city));
        }

        for (int i = 0; i < txns.size(); ++i)
        {
            if (txns[i]->amount > 1000)
                txns[i]->isMarked = true;

            for (int j = 0; j < txns.size(); ++j)
            {
                if (i != j
                    && txns[i]->name == txns[j]->name
                    && txns[i]->city != txns[j]->city
                    && abs(txns[i]->time - txns[j]->time) <= 60)
                {
                    txns[i]->isMarked = true;
                    txns[j]->isMarked = true;
                }
            }
        }

        std::vector<std::string> ans;
        for (int i = 0; i < txns.size(); ++i)
        {
            if (txns[i]->isMarked)
                ans.emplace_back(transactions[i]);
        }

        return ans;
    }
};


class transaction {
public:
    int time;
    int amount;
    string city;
    string tran;
    bool marked;

    transaction (int t, int a, string c, string tr) {
        tran = tr;
        time = t;
        amount = a;
        city = c;
        marked = false;
    }
};


class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        if(transactions.empty())
            return {};

        unordered_map<string, vector<transaction*>> trans;

        for(string &st : transactions) {
            istringstream ss(st);
            string token = "";

            getline(ss, token, ',');
            string name = token;
            getline(ss, token, ',');
            int time = stoi(token);
            getline(ss, token, ',');
            int amount = stoi(token);
            getline(ss, token, ',');
            string city = token;

            transaction *t = new transaction(time, amount, city, st);
            trans[name].push_back(t);
        }

        vector<string> result;
        for(auto &p : trans) {
            sort(p.second.begin(), p.second.end(), [](const transaction* a, const transaction* b) {
                return a->time < b->time;
            });

            for(int i=0; i<p.second.size(); i++) {
                if(p.second[i]->amount > 1000) {
                    result.push_back(p.second[i]->tran);
                    p.second[i]->marked = true;
                }

                if(i > 0 && p.second[i]->time <= p.second[i-1]->time + 60) {
                    int r = i-1;
                    while(r >= 0 && p.second[r]->time >= p.second[i]->time - 60) {
                        if(p.second[i]->city != p.second[r]->city) {
                            if(!p.second[r]->marked) {
                                result.push_back(p.second[r]->tran);
                                p.second[r]->marked = true;
                            }
                            if(!p.second[i]->marked) {
                                p.second[i]->marked = true;
                                result.push_back(p.second[i]->tran);
                            }
                        }
                        r--;
                    }
                }
            }
        }
        return result;
    }
};


int main() {
    fastio();
    
    return 0;
}