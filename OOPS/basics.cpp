#include<iostream>
#include<cstring>
using namespace std;

#define ll long long
#define mod 998244353
double eps = 1e-12;
    


class Product{
private:
    int id;
    char name[100];
    int mrp;
    int selling_price;

public:
    Product(){
        cout<<"Constructor called";
    }

    // parameterised constructor or overloaded
    Product(int id, char* str, int mrp, int selling_price){
        this->id=id;
        strcpy(name,str);
        this->mrp = mrp;
        this->selling_price = selling_price;
    }

    // copy constructor, object has to be passed by reference else we will get an error
    // as if we want to pass an object by value then the copy constructor is required but we havent
    // even made the copy constructor yet, creating an infinite loop
    Product(Product &X){
        id = X.id;
        strcpy(name,X.name);
        mrp=X.mrp;
        selling_price=X.selling_price;
    }

    // setters
    void setMrp(int mrp){
        if(mrp>0)
            this->mrp=mrp;
        else 
            cout<<"Invalid Mrp provided \n";
    }

    void setSellingPrice(int x){
        if(x<=mrp)
            selling_price = x;
        else 
            cout<<"Selling price exceeds mrp \n";
    }

    // getters
    int getMrp(){
        return mrp;
    }

    int getSellingPrice(){
        return selling_price;
    }

    void showDetails(){
        cout<<"ID "<<id<<'\n';
        cout<<"NAME "<<name<<'\n';
        cout<<"MRP "<<mrp<<'\n';
        cout<<"SELLING PRICE "<<selling_price<<'\n';
        cout<<"-------------------"<<'\n';
    }

};


int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    Product camera(3,"Nikon D750",75000,72000);
    //cout<<sizeof(camera);
    //camera.setMrp(-4);
    //camera.setSellingPrice(30);

    // ways of using copy constructor
    Product webcam = camera;
    Product cctv(camera);

    camera.showDetails();
    webcam.showDetails();
    cctv.showDetails();
    
    return 0;
}