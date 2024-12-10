#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <vector>
using namespace std;
class InMemoryDB { 
    map<string, int> accounts;  
    vector<map<string, int>> pre; 
    bool transaction = false; 
    public: 
    void put(string key, int val) { 
        try { 
            if (transaction == false) { 
                string error = "Transaction has not taken place for " + key; 
                throw runtime_error(error); 
            }
            else { 
                map<string, int> mini; 
                mini[key] = val; 
                pre.push_back(mini);  
            }
        }
        catch (const std::runtime_error& e) { 
            cerr << "Exception: " << e.what() << endl; 
        }
        
    }
    bool find_vec(string key, vector<string> arr) { 
        for (int i = 0; i < arr.size(); i++) { 
            if (arr[i] ==  key) { 
                return true; 
            }
        }
        return false; 
    }
    int get(string key) { 
        if (accounts.find(key) == accounts.end()) { 
            cout << "Account " << key << " not found!" << endl; 
            return -1; 
        }
        else { 
            cout << "Account " << key << ": " << accounts[key] << endl; 
            return accounts[key]; 
        }
    }
    void begin_transaction() {
        if (transaction == true) { 
            cout << "Transaction already in place!" << endl; 
        }
        else { 
            cout << "Transaction started" << endl; 
            transaction = true; 
        }
    }
    void commit() { 
        try { 
            if (transaction == false) { 
                string error = "Transaction has not taken place"; 
                throw runtime_error(error); 
            }
            else { 
                for (int i = 0; i < pre.size(); i++) { 
                    auto iter = pre[i].begin(); 
                    accounts[iter->first] = iter->second; 
                    
                } 
                pre.clear(); 
                transaction = false; 
                cout << "Transactions committed" << endl; 
                    
            }
        }
        catch (const std::runtime_error& e) { 
            cerr << "Exception: " << e.what() << endl; 
        }
        
        
    }
    void rollback() { 
        try { 
            if (transaction == false) { 
                string error = "Transaction has not taken place"; 
                throw runtime_error(error); 
            }
            else { 
                 cout << "Transactions roll backed" << endl; 
                 pre.clear(); 
                 transaction = false; 
                    
            }
        }
        catch (const std::runtime_error& e) { 
            cerr << "Exception: " << e.what() << endl; 
        }
        
       
        
    }




};

int main() { 
    //write your tests here
    cout << "TESTS FOR EXTRA CREDIT" << endl;

    return 0; 
}