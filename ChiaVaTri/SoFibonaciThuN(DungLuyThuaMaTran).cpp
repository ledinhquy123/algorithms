#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
using ll = long long;
struct MaTran{
   ll a[2][2];
};
// Nạp chồng toán tử để nhân các ma trận với nhau
MaTran operator * (MaTran A, MaTran B){
   MaTran res;
   for(int i = 0; i < 2; i++){
      for(int j = 0; j < 2; j++){
         res.a[i][j] = 0;
         for(int k = 0; k < 2; k++){
            res.a[i][j] += A.a[i][k] * B.a[k][j];
            res.a[i][j] %= mod;
         }
      }
   }
   return res;
}
MaTran PowMod(MaTran a, ll n){
   if(n == 1) return a;
   MaTran tmp = PowMod(a, n / 2);
   if(n % 2 == 1) return tmp * tmp * a;
   return tmp * tmp;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   ll n; cin >> n;
   MaTran a;
   a.a[0][0] = 1, a.a[0][1] = 1, a.a[1][0] = 1, a.a[1][1] = 0;
   a = PowMod(a, n);
   cout << a.a[0][1];
   return 0;
}
int n, k;
// struct MaTran{
//     ll a[10][10];
// };
// MaTran operator * (MaTran A, MaTran B){
//     MaTran res;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             res.a[i][j] = 0;
//             for(int k = 0; k < n; k++){
//                 res.a[i][j] += A.a[i][k] * B.a[k][j];
//                 res.a[i][j] %= mod;
//             }
//         }
//     }
//     return res;
// }
// MaTran PowMod(MaTran a, ll n){
//     if(n == 1) return a;
//     MaTran temp = PowMod(a, n / 2);
//     if(n % 2 == 1) return temp * temp * a;
//     return temp * temp;
// }
// int main(){
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n >> k;
//     MaTran a;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             cin >> a.a[i][j];
//         }
//     }
//     MaTran temp = PowMod(a, k);
//     ll ans = 0;
//     for(int i = 0; i < n; i++){
//         ans += temp.a[i][n - 1];
//         ans %= mod;
//     }
//     cout << ans;

//     return 0;
// }