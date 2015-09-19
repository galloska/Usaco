/*
ID: skap1991
LANG: C++
TASK: lamps
*/
#include <bits/stdc++.h>

using namespace std;

string cad;
vector<int> on;
vector<int> off;
map<string,int> check;

int main(){
    freopen( "lamps.in" , "r" , stdin );
    freopen( "lamps.out" , "w" , stdout );
    int n,a,k;
    scanf("%d %d",&n,&k);

    cad = "";
    for(int i=0;i<n;i++)
        cad += '1';

    for(;;){
        scanf("%d",&a);
        if(a==-1) break;
        on.push_back(a-1);
    }

    for(;;){
        scanf("%d",&a);
        if(a==-1) break;
        off.push_back(a-1);
    }

    vector<string> res;

    for(int i=0;i<16;i++){
        vector<int> num;
        int cont = 0;

        for(int j=0;j<4;j++)
            if( i & (1<<j) ){
                cont++;
                num.push_back(1);
            }
            else num.push_back(0);

        if(cont>k) continue;

        sort( num.begin() , num.end() );

        do{
            string aux = cad;
            if(num[0]){
                for(int j=0;j<n;j++){
                    a = aux[j] - 48;
                    aux[j] = ( 1 - a ) + 48;
                }
            }

            if(num[1]){
                for(int j=1;j<n;j+=2){
                    a = aux[j] - 48;
                    aux[j] = ( 1 - a ) + 48;
                }
            }

            if(num[2]){
                for(int j=0;j<n;j+=2){
                    a = aux[j] - 48;
                    aux[j] = ( 1 - a ) + 48;
                }
            }

            if(num[3]){
                for(int j=0;j<n;j+=3){
                    a = aux[j] - 48;
                    aux[j] = ( 1 - a ) + 48;
                }
            }

            bool flag = true;
            for(int j=0;j<on.size();j++)
                if( aux[ on[j] ]!='1' )
                    flag = false;

            for(int j=0;j<off.size();j++)
                if( aux[ off[j] ]!='0' )
                    flag = false;

            if(flag && check.find(aux)==check.end()){
                res.push_back(aux);
                check[aux] = 1;
            }

        }while( next_permutation( num.begin() , num.end() ) );
    }

    sort( res.begin() , res.end() );

    for(int i=0;i<res.size();i++)
        printf("%s\n",res[i].c_str());

    if(res.size()==0) printf("IMPOSSIBLE\n");
    return 0;
}
