#include <stdio.h>

int solve(int n){
	int max = 1;
	int tab[n+1], vis[n+1];
	for(int i = 1; i<=n; i++){
		scanf("%d", &tab[i]);
    }
    	for(int i = 1; i<=n; i++){
		vis[i]=0;
    }
	for(int i = 1; i<=n; i++){
		int wyn=1, tmp=tab[i];
		vis[i]=1;
		while(!vis[tmp]){
			vis[tmp]=1;
			wyn++;
			tmp= tab[tmp];
        }
        if (wyn > max)
            max = wyn;

    }
    return max;
}



int main(){
	int n;
	scanf("%d", &n);
	printf("%d", solve(n));


}
