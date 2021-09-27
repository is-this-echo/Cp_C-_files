#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

class Node{
public:
    char ch;
    unordered_map<char,Node*> m;
    bool isTerminal;

    Node(char ch){
        this->ch=ch;
        isTerminal=false;
    }
};

class Trie{
public:
    Node* root;

    Trie(){
        root = new Node('\0'); 
    }

    void insert(string word){
        Node* temp=root;

        for(auto ch : word){
            if(temp->m.count(ch)==0){
                Node* n = new Node(ch);
                temp->m[ch]=n;
            }
            temp = temp->m[ch];
        }
        temp->isTerminal  =true;
    }

    bool search(string word){
        Node* temp =root;

        for(char ch: word){
            if(temp->m.count(ch)==0){
                return false;
            }
            temp=temp->m[ch];
        }
        return temp->isTerminal;
    }
};


int main()
{
    string words[] = {"apple","ape","app","orange","little","news","new","n"};
    Trie t;
    int n;
    string searchWord;
    
    for(string word : words)
        t.insert(word);
    
    cout<<"Enter number of queries: ";
    cin>>n;

    while(n){
        cin>>searchWord;
        if(t.search(searchWord))
            cout<<"Word found"<<endl;
        else 
            cout<<"Not found"<<endl;
        n--;
    }
    
    return 0;
}