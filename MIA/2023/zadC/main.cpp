#include<bits/stdc++.h>
using namespace std;

int modfix(int a, int b){
    if(a < 0)
        a = b + (a % b);
    else
        a = a % b;
    return a;
}

deque<int> pot;


int main(){
    string key;
    int a, b;
    cin >> key >> a >> b;
    int modb = 0, moda = 0, potpom = 1;

    for(int i = 0; i < key.size(); i++){
        modb *= 10;
        modb += key[i] - '0';
        modb %= b;
        pot.push_front(potpom);
        potpom = (potpom * 10) % b;
    }

    int ending = -1;

    for(int i = 0; i < key.size() - 1; i++){
        modb = modfix(modb - (key[i] - '0') * pot[i], b);
        moda *= 10;
        moda += key[i] - '0';
        moda %= a;
        if(key[i + 1] == '0')
            continue;
        if(moda == 0 && modb == 0){
            ending = i + 1;
            break;
        }
    }

    if(ending == -1){
        cout << "NO";
    }
    else{
        cout << "YES\n" << key.substr(0, ending) << '\n' << key.substr(ending, key.size() - ending);
    }


}
