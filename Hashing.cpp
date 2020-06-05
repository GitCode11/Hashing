#include<iostream>
#include<cstring>
using namespace std;
template<typename T>
class node{
    public:
    string key;
    T val;
    node<T>* next;
    node(string k,T v)
    {
        key=k;
        val=v;
    }
};
template<typename T>
class hashtable{
    int cs; // Current Size
    int ts; // Max Array Size
    node<T>** buckets;
    int hashfn(string key)
    {
        int L=key.length();
        int ans=0;
        int p=1;
        for(int i=0;i<L;i++)
        {
            ans+=key[L-i-1]*p;
            p=p*37;
            p%=ts;
            ans%=ts;
        }
        return ans;
    }
public:
    hashtable(int ds=7)
    {
        cs=0;
        ts=ds;
        buckets=new node<T>*[ts];
        for(int i=0;i<ts;i++)
        {
            buckets[i]=NULL;
        }
    }
    void insert(string key,T value)
    {
        int i=hashfn(key);
        node<T>* n=new node<T>(key,value);
        n->next=buckets[i];
        buckets[i]=n;
    }
    void print()
    {
        for(int i=0;i<ts;i++)
        {
            node<T>* temp=buckets[i];
            cout<<"Bucket "<<i<<endl;
            while(temp!=NULL)
            {
                cout<<temp->key<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};
