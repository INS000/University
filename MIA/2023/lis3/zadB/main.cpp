    #include<bits/stdc++.h>
    using namespace std;


    int main(){
        int n, len[3], cuts = 0, n1;
        cin >> n >> len[0] >> len[1] >> len[2];
        sort(len, len + 3);
        int max = 1;
        for(int i = 0; i <= n / len[2]; i++){
            for(int j = 0; j <= n / len[1]; j++){
                if(n - i * len[2] - j * len[1] >= 0){
                    int n1 = n - i * len[2] - j * len[1];
                    if(n1 % len[0] == 0){
                        if(i + j + n1 / len[0] > max){
                            max = i + j + n1 / len[0];
                        }
                    }
                }
            }
        }
        cout << max << '\n';
    }
