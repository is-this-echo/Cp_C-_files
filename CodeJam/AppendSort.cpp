#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 2e18
#define mod 998244353
double eps = 1e-12;
    
 
    
signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
    int ts;
    cin>>ts;
    
    for(int tt=0;tt<ts;tt++){
        int n;
        cin>>n;
        
        vector<int>arr(n);
        int ans=0;

        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        for(int i=1;i<n;i++){
            string prev = to_string(arr[i-1]), curr = to_string(arr[i]);
            int prev_len = prev.length();
            int curr_len = curr.length();
            
            if(curr_len>prev_len)
                continue;
                
            else if(curr_len==prev_len){
                if(arr[i]>arr[i-1])
                    continue;
                
                else if(arr[i]<=arr[i-1]){
                    ans++;
                    arr[i]= arr[i]*10;
                }
            }

            else{
                if(prev[0]>curr[0]){
                    int k = prev_len - curr_len +1;
                    ans += k;
                    arr[i] = arr[i] * pow(10,k);
                }
                else if(prev[0]<curr[0]){
                    int k = (prev_len-curr_len);
                    ans += k;
                    arr[i] = arr[i]*pow(10,k);
                }
                else{
                    char c1 = to_string(arr[i-1]+1)[0], c2 = prev[0];
                    if(c1!=c2){
                        int k = prev_len-curr_len +1;
                        ans+= k;
                        arr[i] = arr[i]*pow(10,k);
                    }
                    else{
                        int cnt=0,flag=3;

                        while(cnt<curr_len){
                            if(prev[cnt]<curr[cnt]){
                                flag=2;
                                break;
                            }
                            else if(prev[cnt]>curr[cnt]){
                                flag =1;
                                break;
                            }
                            cnt++;
                        }

                        if(flag==3){
                            int k = prev_len-curr_len;
                            ans+= k;
                            arr[i]=arr[i-1]+1;
                        }
                        else if(flag==2){
                            int k = prev_len-curr_len;
                            ans+= k;
                            arr[i]=arr[i]*pow(10,k);
                        }
                        else{
                            int k = prev_len-curr_len + 1;
                            ans+= k;
                            arr[i]=arr[i]*pow(10,k);
                        }

                    }
                }
 
            }
                
        }
        
        cout<<"Case #"<<tt+1<<": "<<ans<<"\n";
    }
    
    return 0;
}