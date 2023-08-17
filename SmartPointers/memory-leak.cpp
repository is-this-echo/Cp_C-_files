#include<bits/stdc++.h>
#include<memory>
using namespace std;



// RAII - Resource Acquisition Is Initialization
class WrapperPtr {
public:
    WrapperPtr(int *a) : mem(a) 
    {
        cout << "ctor" <<"\n";
    } 

    ~WrapperPtr()
    {
        cout << "dtor" <<"\n";
        delete mem;
    }

private:
    int *mem;
};


// will lead to memory leak as space allocated not freed up
void solve(){
    for(int i=0; i<1000000; i++){
        int * a = new int(90);

        cout<< "allocated";
    }
}

  
int main(){
    
    solve();

    WrapperPtr obj(new int(23));

    return 0;
}