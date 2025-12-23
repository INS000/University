#include<iostream>
#include<vector>
#include<utility>
#include<cstdio>
using namespace std;

const vector<pair<int, string>> rzym = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, 
{100 , "C"}, {90 , "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

string itor(int n){
    string s = "";
    // int iter = 0;
    // while(n != 0){
    //     if(n < rzym[iter].first)
    //         iter++;
    //     else{
    //         while(rzym[iter].first <= n){
    //             s+=rzym[iter].second;
    //             n-=rzym[iter].first;
    //         }
    //     }
    // }
    for(auto h : rzym){
        while(h.first <= n){
            s += h.second;
            n -= h.first;
        }
    }
    return s;
}

bool czy_git(const string& s){
    for(char c : s){
        if(c < '0' || c > '9'){
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]){
    int n;
    string s;
    for(int i = 1; i < argc; i++){
        s = argv[i];
        try{
            n = stoi(s);
            if(!czy_git(s)){
                clog << "Podane slowo nie jest liczba," << endl <<"przechodze do kolejnego slowa" << endl;
                continue;
            }
        }catch(...){
            clog << "Podane slowo nie jest liczba," << endl << "przechodze do kolejnego slowa" << endl;
            continue;
        }
        cout << itor(n) << endl;
    }
}
    
