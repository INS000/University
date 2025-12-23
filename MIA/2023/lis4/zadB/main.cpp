    #include <bits/stdc++.h>
    using namespace std;

    long long len[1000006];

    int cuts(int n, int fav){
        int counter = 0;
        for(int i = 1; i < n; i++){
            if(len[i] > fav && len[i + 1] <= fav){
                counter++;
            }
        }
        if(len[n] > fav)
            counter++;
        return counter;
    }

    int main(){
        int hair, req, fav, currreq, a, b, currcut;
        scanf("%d %d %d", &hair, &req, &fav);

        for(int i = 1; i <= hair; i++){
            scanf("%ld", &len[i]);
        }

        currcut = cuts(hair, fav);

        for(int i = 1; i <= req; i++){
            scanf("%d", &currreq);
            if(currreq == 0){
                printf("%d\n", currcut);
            }else{
                scanf("%d %d", &a, &b);
                len[a] += b;
                if(len[a] - b <= fav && len[a] > fav){
                    if(len[a - 1] > fav && len[a + 1] > fav)
                        currcut--;
                    else if(len[a - 1] <= fav && len[a + 1] <= fav)
                        currcut++;
                }
            }
        }
    }
