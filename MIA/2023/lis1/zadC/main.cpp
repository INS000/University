    #include<bits/stdc++.h>
    using namespace std;

    int modfix(int a, int b){
        if(a < 0)
            a = b + (a % b);
        else
            a = a % b;
        return a;
    }


    int main(){
        string key;
        int a, b;
        cin >> key >> a >> b;
        int potpom = 10 % b;
        int mod_a[key.size()], mod_b[key.size()];

        mod_a[0] = (key[0] - '0') % a;
        for(int i = 1; i < key.size(); i++){
            mod_a[i] = (mod_a[i - 1] * 10 + (key[i] - '0')) % a;
        }

        mod_b[key.size() - 1] = (key[key.size() - 1] - '0') % b;
        for(int i = key.size() - 2; i >= 0; i--){
            mod_b[i] = (mod_b[i + 1] + (potpom * (key[i] - '0'))) % b;
            potpom = (potpom * 10) % b;
        }

        int ending = -1;

        for(int i = 0; i < key.size() - 1; i++){
            if(mod_a[i] == 0 && mod_b[i + 1] == 0 && key[i + 1] != '0'){
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
