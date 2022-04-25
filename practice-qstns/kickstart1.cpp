#include<iostream>
#include<string>
using namespace std;

# define ll long long

bool canEat(string &s,int n ,ll c, int d, int m){
    int dogs=0;   

    for(int i=0;i<n;i++)
        if(s[i]=='D') dogs+=1;

    for(int i=0;i<n;){
        if(dogs==0)
            return true;

        if(s[i]=='C'){
            if(c>0){
                c-=1;
                i++;
            }
            else{
                if(dogs>0)
                    return false;
            }
        }
        else {
            if(d>0){
                d-=1;
                c+=m;
                dogs--;
                i++;
            }
            else 
                return false;
        }

    }    
    return true;
}




int main()
{   
    int t,n,c,d,m;
    cin>>t;

    for(int i=0;i<t;i++){
        cin>>n>>d>>c>>m;

        string s;
        char ch;
        //getline(cin,s);
        for(int j=0;j<n;j++){
            cin>>ch;
            s.push_back(ch);
        }

        if(canEat(s,n,c,d,m))
            cout<<"Case #"<<i+1<<": YES"<<endl;
        else 
            cout<<"Case #"<<i+1<<": NO"<<endl;
    }
    
    return 0;
}