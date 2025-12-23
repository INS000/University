#include<iostream>
#include<cmath>
using namespace std;



int main(){
    long long c, ha, hb, wa, wb, maxh = 0, tmp;
    cin >> c >> ha >> hb >> wa >> wb;
    long long b = sqrt(c);
    if(wa > b || wb > b){
        if(wa > wb){
            for(int i = 0; i <= b && i*wa <= c; i++){
                tmp = i * ha + (c - i * wa) / wb * hb;
                if(tmp > maxh)
                    maxh = tmp;
            }
        }
        else{
            for(int i = 0; i <= b && i*wb <= c; i++){
                tmp = i * hb + (c - i * wb) / wa * ha;
                if(tmp > maxh)
                    maxh = tmp;
            }
        }
    }
    else{

        double hwa = (double)ha/wa, hwb = (double)hb/wb;
        // cout << hwa << ' ' << hwb <<'\n';
        if(hwa >= hwb){
            // cout <<"a\n";
            for(int i = 0; i <= wa; i++){
                tmp = i * hb + (c - i * wb) / wa * ha;
                if(tmp > maxh)
                    maxh = tmp;
            }
        }
        else{
            // cout <<"b\n";
            for(int i = 0; i <= wb; i++){
                tmp = i * ha + (c - i * wa) / wb * hb;
                if(tmp > maxh)
                    maxh = tmp;
            }
        }
    }
    cout << maxh;
}
