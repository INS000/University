#include<iostream>
// #include<string>
#include<cstdio>
using namespace std;


// char swap_let(string s1, string s2, int k){
//     // for(int i = 'a'; i <= 'c'; i++){
//     //     if(i != s1[k] && i != s2[k]){
//     //         return i;
//     //     }
//     // }
//     // return 0;
//     if('a' != s1[k] && 'a' != s2[k]){
//         return 'a';
//     }
//     else if('b' != s1[k] && 'b' != s2[k]){
//         return 'b';
//     }
//     return 'c';
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t, eq = 0;
    string s1, s2;
    cin >> n >> t >> s1 >> s2;
    bool change = 0;
    int cha, pom = n - t;
    for(int i = 0; i < n; i++){
        if(s1[i] != s2[i] && eq < pom){
            if(change == 0){
                change = 1;
                cha = i;
            }
            else{
                change = 0;
                s1[i] = s2[i];
                eq++;
            }
        }
        else if(eq < pom){
            eq++;
        }
        else{
            // s1[i] = swap_let(s1, s2, i);
            if('a' != s1[i] && 'a' != s2[i]){
                s1[i] = 'a';
            }
            else if('b' != s1[i] && 'b' != s2[i]){
                s1[i] = 'b';
            }
            else {
            s1[i] = 'c';
            }
        }
    }
    if(change == 1){
        // s1[cha] = swap_let(s1, s2, cha);
        if('a' != s1[cha] && 'a' != s2[cha]){
            s1[cha] = 'a';
        }
        else if('b' != s1[cha] && 'b' != s2[cha]){
            s1[cha] = 'b';
        }
        else{
        s1[cha] = 'c';
        }
    }

    if(eq < pom){
        cout << "-1";
    }
    else{
        cout << s1;
    }

}
