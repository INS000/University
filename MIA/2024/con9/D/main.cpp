#include<iostream>
#include<utility>
#include<vector>
using namespace std;

int tab[3003];

vector<int> res[3003];

int main()
{
    int n, k;
    cin >> n >> k;
    char c;
    for(int i = 0; i < n; i++)
    {
        cin >> c;
        if(c == 'R'){
            tab[i] = 1;
        }
        else{
            tab[i] = 0;
        }
    }
    int mink = 0, maxk = 0;
    bool swaped;

    for(int i = 0; i < n; i++){
        swaped = false;
        for(int j = 0; j < n - 1; j++){
            if(tab[j] == 1 && tab[j + 1] == 0){
                swap(tab[j], tab[j + 1]);
                j++;
                swaped = true;
                maxk++;
                res[i].push_back(j);
            }
        }
        if(!swaped){
            break;
        } else {
            mink++;
        }
    }
    if(k < mink || k > maxk){
        cout << -1 << "\n";
        return 0;
    }

    int diff = k - mink, last = -1, last_index = 0;
    // for(int i = 0; i < n; i++){
    //     if(diff == 0){
    //         last = i;
    //         break;
    //     }
    //     cout << "TEST1\n";
    //     for(int j = 0; j < res[i].size(); j++){
    //         if(diff == 0){
    //             last = i;
    //             last_index = j + 1;
    //             break;
    //         }
    //         cout << 1 << ' ' << res[i][j] << "\n";
    //         // if(res[i].size() == 1) continue;
    //         diff--;
    //     }
    // }
    // if(last_index < res[last].size() && last_index != res[last].size()) {
    //     cout << "TEST2\n";
    //     cout << res[last].size() - last_index << ' ';
    //     for(int j = last_index; j < res[last].size(); j++){
    //         cout << res[last][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // for(int i = last + 1; i < n; i++){
    //     cout << "TEST3\n";
    //     if(res[i].size() == 0){
    //         break;
    //     }
    //     cout << res[i].size() << ' ';
    //     for(int j = 0; j < res[i].size(); j++){
    //         cout << res[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    bool flag = false;
    while(diff > 0){
        for(int i = 0; i < n; i++){
            if(flag) break;
            if(diff == 0){
                last = i;
                break;
            }
            for(int j = 0; j < res[i].size(); j++){
                if(diff == 0){
                    last = i;
                    last_index = j;
                    flag = true;
                    break;
                }
                // cout << diff << "\n";
                cout << 1 << ' ' << res[i][j] << "\n";
                if(res[i].size() - j == 1) continue;
                diff--;
            }
        }
    }

    if(res[last].size() != 0){
        cout << res[last].size() - last_index << ' ';
        for(int j = last_index; j < res[last].size(); j++){
            cout << res[last][j] << " ";
        }
        cout << "\n";
    }

    for(int i = last + 1; i < n; i++){
        if(res[i].size() == 0){
            break;
        }
        cout << res[i].size() << ' ';
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }



}



