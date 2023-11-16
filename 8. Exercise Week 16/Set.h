#include <iostream>
using namespace std;

#ifndef SET_H
#define SET_H
struct Node 
{
    int data;
    Node *next;
};
typedef struct Node* pNode;

struct List
{
		pNode Head;
		List(); 
		List(const List& X);
		~List(); 
		void InsertHead(int); 
		void InsertTail(int); 
		void InsertAfter(pNode&, int); 
		void DelHead(); 
		void DelTail();
		void DelAfter(pNode&);
		void DelX(int); 
		void Duyet(); 
};

class Set
{
    private:
        int n;
        List head;
    public:
        Set();
        Set(const Set&);
        const Set &operator=(const Set &X);
        Set operator+(int);
        Set operator-(int);
        bool operator()(int) const;
        Set operator+ (const Set& S);
		Set operator- (const Set& S);
		Set operator* (const Set& S);
        int operator[](int i) const;
        friend ostream &operator<<(ostream&, const Set&);
};

#endif