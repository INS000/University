#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

struct point{
    int x;
    int y;
};

point make_point(int x, int y){
    point a;
    a.x = x;
    a.y = y;
    return a;
}



int main(){
    int n, x, y;
    cin >> n;
    cout << setprecision(12);
    for(int i = 0; i < n; i++){
        point tri[3];
        for(int i = 0; i < 3; i++){
            cin >> x >> y;
            tri[i] = make_point(x, y);
        }
        if(tri[0].y == tri[1].y && tri[2].y < tri[1].y){
            cout << sqrt(pow(tri[0].x - tri[1].x, 2) + pow(tri[0].y - tri[1].y, 2));
        }
        else if(tri[2].y == tri[1].y && tri[0].y < tri[1].y){
            cout << sqrt(pow(tri[2].x - tri[1].x, 2) + pow(tri[2].y - tri[1].y, 2));
        }
        else if(tri[0].y == tri[2].y && tri[2].y > tri[1].y){
            cout << sqrt(pow(tri[0].x - tri[2].x, 2) + pow(tri[0].y - tri[2].y, 2));
        }
        else{
            cout << 0;
        }
        cout << '\n';
    }
}
