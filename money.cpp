/*
ID: skap1991
LANG: C++
TASK: money
*/
#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int coin[30];
lli memo[30][10005];

int main(){
    
    freopen( "money.in" , "r" , stdin );
    freopen( "money.out" , "w" , stdout );

    int n,m;
    scanf("%d %d",&m,&n);

    for(int i=0;i<m;i++)
        scanf("%d",&coin[i]);

    for(int i=0;i<m;i++)
        memo[i][ 0 ] = 1;

    for(int id=m-1;id>=0;id--){
        for(int num=1;num<=n;num++){
            if(coin[id]<=num)
                memo[id][num] = memo[id][num - coin[id]];
            memo[id][num] += memo[id + 1][num];
        }
    }

    printf("%lld\n",memo[0][n]);
    return 0;
}
