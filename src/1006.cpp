#include<iostream>
#include<iomanip>
using namespace std;
inline double Max(double a , double b , double c) {
    double tmp = a > b ? a : b;
    tmp = tmp > c ? tmp : c;
    return tmp;    
}
inline double Min(double a , double b , double c) {
    double tmp = a < b ? a : b;
    tmp = tmp < c ? tmp : c;
    return tmp;    
}
int main() {
    double ss , mm , hh , sm , mh , sh , t_sm , t_mh , t_sh;
    ss = 6.0 , mm = 0.1 , hh = 0.1/12.0;
    sm = 6.0 - 0.1;
    mh = 0.1 - 0.1/12.0;
    sh = 6.0 - 0.1/12.0;//相对速度 
    t_sm = 360.0/sm;
    t_mh = 360.0/mh;//=43200.0/11
    t_sh = 360.0/sh;//相对周期
    int D;
    double m[3] , n[3] , x[3] , y[3];            //x[3]和y[3]记录的是第一个开始满足条件的时间和第一个开始不满足条件的时间。
    while(cin>>D) {                              //m[3],n[3]则是根据相对周期来扩大x[3],y[3]以获得所有满足条件的时间集合，并求交集。
        if(D == -1) break;
        x[0] = D/sm;
        x[1] = D/mh;
        x[2] = D/sh;
        y[0] = (360.0-D)/sm;
        y[1] = (360.0-D)/mh;
        y[2] = (360.0-D)/sh;
        double st , ed;
        double ans = 0;
        for(m[0] = x[0] , n[0] = y[0] ; m[0]<=43200 ; m[0] += t_sm , n[0] += t_sm) { 
           for(m[1] = x[1] , n[1] = y[1] ; m[1] <= 43200 ; m[1] += t_mh , n[1] += t_mh) {
                if(m[0] > n[1]) continue;
                if(n[0] < m[1]) break;
                for(m[2] = x[2] , n[2] = y[2] ; m[2] <= 43200 ; m[2] += t_sh , n[2] += t_sh) {
                    if(n[2] < m[1] || n[2] < m[0]) continue;
                    if(m[2] > n[0] || m[2] > n[1]) break;
                    st = Max(m[0] , m[1] , m[2]);
                    ed = Min(n[0] , n[1] , n[2]);
                    if(ed > st) ans += ed - st;
                }
            }     
        }         /*取交集 记录区间的过程*/
		cout<<setiosflags(ios::fixed)<<setprecision(3)<<ans*100.0/43200<<endl;
        //printf("%.3lf\n",ans/432.0);
    } 
}