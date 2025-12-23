#include <stdio.h>

int rowpros(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy){
    double wekax = bx - ax, wekay = by - ay, wekbx = dx - dy, wekby= dy - dx;
    if(wekax * wekbx + wekay * wekby == 0)
        return -1;
    if(wekax * wekbx - wekay * wekby == 0)
        return 1;
    return 0;

}



int main(){
    int n = 1;
    double ax, ay, bx, by, cx, cy, dx, dy;
    while(n == 1){
        printf("Podaj xa, ya, xb, yb, xc, yc, xd, yd: ");
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
        if(ax == bx && cx == dx || ay == by && cy == dy)
            printf("rownolegle\n");
        else if(ax == bx && cy == dy || ay == by && cx == dx)
            printf("prostopadle\n");
        else if(rowpros(ax, ay, bx, by, cx, cy, dx, dy) == 1)
            printf("prostopadle\n");
        else if(rowpros(ax, ay, bx, by, cx, cy, dx, dy) == -1)
            printf("rownolegle\n");
        else if(rowpros(ax, ay, bx, by, cx, cy, dx, dy) == 0)
            printf("-\n");
    }

}
