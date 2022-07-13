//矩阵快速幂 给一个矩阵A和k求出A的k次幂

//快速幂的基本原理，使用二进制，把k转换成2进制表示，然后k一直右移，同时有一个值记录当前的位级，如果末位是1则把结果乘上位级

//对于矩阵的快速幂而言，只需要把乘运算重新定义一下就可以了


#include <iostream>
#include <cstring>
#define MAX_ROW 100
#define ull unsigned long long
#define mod 1000000007

using namespace std;

struct Matrix{
    ull matrix[MAX_ROW][MAX_ROW]{0};
    //生成单位矩阵
    inline void build(){
        for(int i = 0; i < MAX_ROW; i ++){
            matrix[i][i] = 1;
        }
    }
}m;//m存储初始矩阵的数据

int n;
ull k;

//读取数据
void read(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> m.matrix[i][j];
        }
    }
}

//把乘法重载
Matrix operator * (const Matrix& x,const Matrix& y){
    Matrix z;
    for(int i = 0;i < n; i++){
        for(int j = 0; j < n; j++){
            for(int l = 0; l < n; l++){
                z.matrix[i][j] += x.matrix[i][l]  * (y.matrix[l][j] ) % mod;
                z.matrix[i][j] %= mod;
            }
        }
    }
    return z;
}

void show(Matrix ans){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << ans.matrix[i][j] << " ";
        }
        cout << "\n";
    }

}


int main() {
    Matrix ans;
    ans.build();//初始值是单位矩阵
    read();
    while(k){
        if(k & 1){//末位是1，结果乘上位级
            ans = ans * m;
        }
        //位级提高
        m = m * m;
        //k向右移
        k = k >> 1;
    }
    show(ans);
}
