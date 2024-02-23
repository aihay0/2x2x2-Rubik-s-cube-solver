#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("-Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef int in;
#define int long long
#define double long double
#define f first
#define s second
#define pb push_back
#define pp push
#define ceill(x,y) ((x/y)+(x%y!=0)*(x*y<0?0:1))
#define floorr(x,y) ((x/y)+(x%y!=0)*(x*y<0?-1:0))
const int MAAX=1e18;
const int MOD=1e9+7;
const int MAX=1e9;

#define WHITE 0
#define GREEN 1
#define RED 2
#define BLUE 3
#define ORANGE 4
#define YELLOW 5

struct cube{
    int cur[6][2][2],h;
    void init(){
        for(int i=0;i<6;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    this->cur[i][j][k]=i;
                    this->h*=6;
                    this->h+=cur[i][j][k];
                    this->h%=MOD;
                }
            }
        }
    }
    void print(){
        for(int i=0;i<6;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    int x=this->cur[i][j][k];
                    if(x==WHITE)
                        cout<<'W';
                    else if(x==GREEN)
                        cout<<'G';
                    else if(x==RED)
                        cout<<'R';
                    else if(x==BLUE)
                        cout<<'B';
                    else if(x==ORANGE)
                        cout<<'O';
                    else
                        cout<<'Y';
                }
                cout<<"\n";
            }
            cout<<"\n";
        }
    }
    void R(){
        swap(this->cur[0][0][1],this->cur[3][1][0]);
        swap(this->cur[0][0][1],this->cur[5][0][1]);
        swap(this->cur[0][0][1],this->cur[1][0][1]);
        swap(this->cur[0][1][1],this->cur[3][0][0]);
        swap(this->cur[0][1][1],this->cur[5][1][1]);
        swap(this->cur[0][1][1],this->cur[1][1][1]);
        swap(this->cur[2][0][0],this->cur[2][0][1]);
        swap(this->cur[2][0][0],this->cur[2][1][1]);
        swap(this->cur[2][0][0],this->cur[2][1][0]);
        this->h=0;
        for(int i=0;i<6;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    this->h*=6;
                    this->h+=cur[i][j][k];
                    this->h%=MOD;
                }
            }
        }
    }
    void R2(){
        this->R();
        this->R();
    }
    void Rp(){
        this->R();
        this->R();
        this->R();
    }
    void U(){
        swap(this->cur[1][0][0],this->cur[4][0][0]);
        swap(this->cur[1][0][0],this->cur[3][0][0]);
        swap(this->cur[1][0][0],this->cur[2][0][0]);
        swap(this->cur[1][0][1],this->cur[4][0][1]);
        swap(this->cur[1][0][1],this->cur[3][0][1]);
        swap(this->cur[1][0][1],this->cur[2][0][1]);
        swap(this->cur[0][0][0],this->cur[0][0][1]);
        swap(this->cur[0][0][0],this->cur[0][1][1]);
        swap(this->cur[0][0][0],this->cur[0][1][0]);
        this->h=0;
        for(int i=0;i<6;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    this->h*=6;
                    this->h+=cur[i][j][k];
                    this->h%=MOD;
                }
            }
        }
    }
    void U2(){
        this->U();
        this->U();
    }
    void Up(){
        this->U();
        this->U();
        this->U();
    }
    void F(){
        swap(this->cur[0][1][0],this->cur[2][0][0]);
        swap(this->cur[0][1][0],this->cur[5][0][1]);
        swap(this->cur[0][1][0],this->cur[4][1][1]);
        swap(this->cur[0][1][1],this->cur[2][1][0]);
        swap(this->cur[0][1][1],this->cur[5][0][0]);
        swap(this->cur[0][1][1],this->cur[4][0][1]);
        swap(this->cur[1][0][0],this->cur[1][0][1]);
        swap(this->cur[1][0][0],this->cur[1][1][1]);
        swap(this->cur[1][0][0],this->cur[1][1][0]);
        this->h=0;
        for(int i=0;i<6;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    this->h*=6;
                    this->h+=cur[i][j][k];
                    this->h%=MOD;
                }
            }
        }
    }
    void F2(){
        this->F();
        this->F();
    }
    void Fp(){
        this->F();
        this->F();
        this->F();
    }
    void domoves(string moves){
        for(int i=0;i<moves.size();i++){
            if(moves[i]!='R'&&moves[i]!='U'&&moves[i]!='F')
                continue;
            if(i==moves.size()-1||moves[i+1]==' '){
                if(moves[i]=='R')
                    this->R();
                else if(moves[i]=='F')
                    this->F();
                else
                    this->U();
            }
            else if(moves[i+1]=='\''){
                if(moves[i]=='R')
                    this->Rp();
                else if(moves[i]=='F')
                    this->Fp();
                else
                    this->Up();
            }
            else{
                if(moves[i]=='R')
                    this->R2();
                else if(moves[i]=='F')
                    this->F2();
                else
                    this->U2();
            }
        }
    }
}cur;
map<int,string> sol;
string curs;
string rev(string s){
    string ans="";
    for(int i=s.size();i>=0;i--){
        if(s[i]!='R'&&s[i]!='U'&&s[i]!='F')
            continue;
        ans+=s[i];
        if(i==s.size()-1||s[i+1]==' ')
            ans+='\'';
        else if(s[i+1]=='2')
            ans+='2';
        ans+=' ';
    }
    return ans;
}
void fun(int dep=0){
    cube mv=cur;
    mv.domoves(curs);
    if(sol[mv.h].empty()||sol[mv.h].size()>rev(curs).size())
        sol[mv.h]=rev(curs);
    if(dep==6)
        return;
    string pre=curs;
    curs+="R ";
    fun(dep+1);
    curs=pre;
    curs+="F ";
    fun(dep+1);
    curs=pre;
    curs+="U ";
    fun(dep+1);
    curs=pre;
    curs+="R' ";
    fun(dep+1);
    curs=pre;
    curs+="F' ";
    fun(dep+1);
    curs=pre;
    curs+="U' ";
    fun(dep+1);
    curs=pre;
    curs+="R2 ";
    fun(dep+1);
    curs=pre;
    curs+="F2 ";
    fun(dep+1);
    curs=pre;
    curs+="U2 ";
    fun(dep+1);
    curs=pre;
    return;
}
string ans;
void fun2(int dep=0){
    cube mv=cur;
    mv.domoves(curs);
    if(sol[mv.h].size()&&(sol[mv.h].size()+curs.size()<ans.size()||ans.empty())){
        ans=curs+sol[mv.h];
        return;
    }
    if(dep==6)
        return;
    string pre=curs;
    curs+="R ";
    fun2(dep+1);
    curs=pre;
    curs+="F ";
    fun2(dep+1);
    curs=pre;
    curs+="U ";
    fun2(dep+1);
    curs=pre;
    curs+="R' ";
    fun2(dep+1);
    curs=pre;
    curs+="F' ";
    fun2(dep+1);
    curs=pre;
    curs+="U' ";
    fun2(dep+1);
    curs=pre;
    curs+="R2 ";
    fun2(dep+1);
    curs=pre;
    curs+="F2 ";
    fun2(dep+1);
    curs=pre;
    curs+="U2 ";
    fun2(dep+1);
    curs=pre;
    return;
}

in main(){
    int tc=1;
    //cin>>tc;
    while(tc--){
        cur.init();
        fun();
        string s;
        getline(cin,s);
        cur.domoves(s);
        fun2();
        cur.domoves(ans);
        cout<<ans<<"\n";
    }
    return 0;
}
