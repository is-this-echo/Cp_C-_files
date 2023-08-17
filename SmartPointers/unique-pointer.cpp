#include<bits/stdc++.h>
#include<memory>
using namespace std;


// unique ptr : one resource -> 1 object
template <typename T>
class uniqueptr {
public:
    uniqueptr(T* a = nullptr) : res(a) 
    {
        cout << "ctor";
    }

    uniqueptr(const uniqueptr<T>& ptr) = delete;
    uniqueptr& operator= (const uniqueptr<T>& ptr) = delete;

// move copy constructor
    uniqueptr(uniqueptr<T>&& ptr)
    {
        res = ptr.res;
        ptr.res = nullptr;
    }

// move assignment operator
    uniqueptr& operator= (uniqueptr<T>&& ptr)
    {
        if(this != &ptr)
        {
            if(res)
            {
                delete res;
            }

            res = ptr.res;
            ptr.res = nullptr;
        }
        return *this;
    }

    T* operator->() 
    {
        return res;
    }

    T& operator*()
    {
        return *res;
    }

    T* get()
    {
        return res;
    }

    // not thread safe
    void reset(T* new_res = nullptr)
    {
        if(res)
        {
            delete res;
        }
        res = new_res;
    }

    /* 
    can improve to provide an allocator using which we can run custom code in 
    destructor such as logging something before memory is freed
    */ 
    ~uniqueptr()
    {
        if(res)
        {
            delete res;
            res = nullptr;
        }
    }

private:
    T* res;
};

// shared ptr : one resource -> multiple objects

int main(){

    // solve();
    uniqueptr<int> ptr1(new int(2));

    // uniqueptr<int> ptr2(ptr1);  // will throw compilation error as ptr can't be shared
    // uniqueptr<int> ptr3 = ptr1;  //throw compilation error, copy constructor
    uniqueptr<int> ptr3 = std::move(ptr1); // possible as it moves ownership to ptr3

    uniqueptr<int> ptr4(new int(300));
    // ptr4 = ptr3; // throw compilation error, copy assignment operation
    ptr4 = std::move(ptr3); // correct code

    //  ptr1->func();
    //  cout << *(ptr1);  -> runtime-error, as  ptr1 is moved to ptr3
     ptr1.get();
     ptr1.reset(new int(230));

    return 0;
}