#include<iostream>
using namespace std;

bool ifa(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a')
            return true;
    }

    return false;
}

void repls(string s, string t){
    bool b = ifa(t);
    if(b & t.size() == 1){
        cout << 1;
    } else if(b){
        cout << -1;
    } else{
        long long odp = 1;
        odp = odp << s.size();
        cout << odp;
    }
    cout << '\n';
}

int main(){
    int q;
    string s, t;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> s >> t;
        repls(s, t);
    }
}
