#include <iostream>
#include <string>
using  namespace std;

struct Node{
    string key;
    Node* next;
    
    Node(const string& k){
        key=k;
        next=nullptr;
    }
};

struct CBHT{
    int size;
    Node** table;
    
    CBHT(int s){
        size=s;
        table=new Node*[size];
        for(int i=0;i<size;i++){
            table[i]=nullptr;
        }
    }
    
    ~CBHT() {
        for(int i = 0; i < size; i++)
            while(table[i]) {
                Node* tmp = table[i];
                table[i] = table[i]->next;
                delete tmp;
            }
        delete[] table;
    }
    
    int hashlength(const string& key){
        return key.length()%size;
    }
    
    int hashsum(const string& key){
        int sum=0;
        for(char c : key){
            sum+=c;
        }
        return sum%size;
    }
    
    int hashfirst(const string& key){
        return (key[0]-'a')%size;   // mali bukvi
    }
    
    int hashfirsttwo(const string& key){
        int val=0;
        if(key.length() >= 2){
            val=(key[0]-'a')*26 + (key[1]-'a');
        }
        else val=key[0]-'a';
        return val%size;
    }
    
    void insert(const string& key, int method=1){
        int id;
        switch(method){
            case 1: id=hashlength(key);break;
            case 2: id=hashsum(key);break;
            case 3: id=hashfirst(key);break;
            case 4: id=hashfirsttwo(key);break;
            default: id=hashlength(key);
        }
        
        Node* newn=new Node(key);
        newn->next=table[id];
        table[id]=newn;
    }
    
    void print(){
        for(int i=0;i<size;i++){
            cout<<i<<":";
            Node*p=table[i];
            while(p!=nullptr){
                cout<<p->key<<"->";
                p=p->next;
            }
            cout<<"null\n";
        }
    }
    
};
int main(){
    
    CBHT h(10);

    string words[20] = {
        "apple","banana","cherry","date","elderberry",
        "fig","grape","honeydew","kiwi","lemon",
        "mango","nectarine","orange","papaya","quince",
        "raspberry","strawberry","tangerine","ugli","violet"
    };

    cout << "length\n";
    for(string w : words) h.insert(w,1);
    h.print();

    CBHT h2(10);
    cout << "\nsum of letters\n";
    for(string w : words) h2.insert(w,2);
    h2.print();

    CBHT h3(10);
    cout << "\nfirst letter\n";
    for(string w : words) h3.insert(w,3);
    h3.print();

    CBHT h4(10);
    cout << "\nfirst two letters\n";
    for(string w : words) h4.insert(w,4);
    h4.print();

    return 0;
}
