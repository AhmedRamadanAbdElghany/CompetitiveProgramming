#include <iostream>
#include <cstring>

/*
http://www.cnblogs.com/nicetomeetu/p/5159002.html
*/

using namespace std;
int n,ans[100];
bool finish;
void dfs(int x,int deep){
   /* cout << x << " ff " << deep << endl;
    for(int i=0;i<=x;i++)
 cout << ans[i] << " " ;
 cout << endl;
 */
    if(finish) return ;
    if(x==deep) { if(ans[x]==n)finish=1; return; }
    for(int i=0;i<=x;i++){
        for(int j=i;j<=x;j++) if(ans[i]+ans[j]>ans[x]&&ans[i]+ans[j]<=n){
                            int sum=ans[i]+ans[j];
                //cout << i << " dd " << j << endl;
                for(int k=x+2;k<=deep;k++) sum<<=1;
                if(sum<n) continue;
                ans[x+1]=ans[i]+ans[j];
                dfs(x+1,deep);
                if(finish) return ;
        }
    }
}
int main(){
while(scanf("%d",&n),n)
  {
        memset(ans,0,sizeof(ans));
        ans[finish=0]=1;
        int tmp=n,deep=0; while(tmp>>=1) deep++;
                while(!finish)/*cout << deep << endl,*/
                    dfs(0,deep++);
    //    cout<<ans[0];
      //  for(int i=1;i<deep;i++) cout<<" "<<ans[i];
   //     cout<<endl;
    }
    return 0;
}
