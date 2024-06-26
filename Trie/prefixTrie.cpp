#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
/*
Trie() Initializes the trie object.
void insert(String word) : Inserts the string 'word' into the trie.
boolean search(String word) : Returns true if the string 'word' is in  trie, false otherwise.
boolean startsWith(String prefix): Returns true if there is a previously inserted
string 'word' that has the given 'prefix', and false otherwise.
*/
//-----------------------
/*
 Trie data structure is an advanced data structure used for storing and searching strings efficiently.Dictionaries can be implemented efficiently using a Trie data structure and they are also used for the autocomplete features that we see in the search engines. It is faster than binary search trees and hash tables for storing and retrieving data.
 Time complexity of insertion, deletion and searching for a string of length 'k' in the Trie data structure is:
    Insert - O(k)
    Delete - O(k)
    Search - O(k)
The time complexity for building a Trie data structure is O(N * avgL), where 'N' is the number of strings we want to insert in the Trie and 'avgL' is the average length of 'N' strings.
 */
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
        temp->isTerminal  = true;
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


    bool startsWith(string prefix) {
        Node* temp=root;
        
        for(char s : prefix){
            if(temp->m.count(s)==0)
                return false;
            
            temp=temp->m[s];
        }
        return true;
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