/*
ID: skap1991
LANG: C++
TASK: zerosum
*/
#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> res;

void Solve(int num,string cad){
    if(num==n+1){
        num = 0;
        vector<int> total;

        for(int i=0;i<cad.size();i++){
            if( cad[i]=='+' ){
                total.push_back(num);
                num = 0;
            }
            else if(cad[i]=='-'){
                total.push_back(num);
                num = 0;
            }
            else num = num * 10 + ( cad[i] - 48 );
        }

        total.push_back(num);
        int j = 1;
        int sum = total[0];
        
        for(int i=0;i<cad.size();i++){
            if( cad[i]=='+' )
                sum += total[j++];
            else if(cad[i]=='-')
                sum -= total[j++];
        }

        if(sum==0){
            string aux = "";
            for(int i=0;i<cad.size();i++){
                if(isdigit(cad[i]) && aux.size()>0 && isdigit( aux[ aux.size() - 1 ] ) )
                    aux += ' ';
                aux += cad[i];
            }
            res.push_back( aux );
        }
        return;
    }

    cad += num + 48;
    Solve( num + 1 , cad );

    if(cad.size()>1 && isdigit(cad[ cad.size() - 2 ]) ){
        cad[ cad.size() - 1 ] = '-';
        Solve( num , cad );
    }

    if(cad.size()>1 && isdigit(cad[ cad.size() - 2 ]) ){
        cad[ cad.size() - 1 ] = '+';
        Solve( num , cad );
    }
}

int main(){

    freopen( "zerosum.in" , "r" , stdin );
    freopen( "zerosum.out" , "w" , stdout );

    scanf("%d",&n);

    Solve(1,"");

    sort( res.begin() , res.end() );
    for(int i=0;i<res.size();i++)
        printf("%s\n",res[i].c_str());

    return 0;
}
