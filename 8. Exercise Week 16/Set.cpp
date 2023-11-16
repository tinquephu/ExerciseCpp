#include <iostream>
#include "Set.h"

using namespace std;

List::List()
{
	Head = NULL;
}
List::List(const List& X) 
{
	this->Head = NULL; 
	pNode p = X.Head; 
	while (p != NULL) {
		this->InsertTail(p->data);
		p = p->next;
	}
}
List::~List() 
{
	while (Head != NULL) {
		DelHead();
	}
}

void List::InsertHead(int x){
	pNode p = new Node; 
	p->data = x; 
	p->next = Head;
	Head = p;
}
void List::InsertTail(int x){
	if (Head == NULL) InsertHead(x);
	else {
		pNode p = Head;
		while (p->next != NULL) {
			p = p->next;
		}
		InsertAfter(p,x);
	}
}
void List::InsertAfter(pNode& q, int x){
	pNode p = new Node;
	p->data = x;
	p->next = q->next;
	q->next = p;
}
void List::DelHead(){
	if (Head != NULL) {
		pNode p = Head;
		Head = p->next;
		delete p;
	}
}
void List::DelTail(){
	if (Head != NULL) {
		pNode p = Head, q = NULL;
		while (p->next != NULL) {
			q = p;
			p = p->next;
		}
		if (q == NULL) DelHead();
		else DelAfter(q);
	}
}
void List::DelAfter(pNode& q){
	pNode p = q->next;
	q->next = p->next;
	delete p;
}
void List::DelX(int x) {
	if (Head != NULL) {		
       pNode p=Head, q=NULL;
	   while (p!=NULL && p->data!=x) {
			q = p;
			p = p->next;
       }
	   if (p==NULL) return;
	   if (q==NULL) DelHead();
	   else DelAfter(q);
    }
}
void List::Duyet(){
	pNode p = Head;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
}

Set::Set() : n(0){};
Set::Set(const Set &S): n(S.n), head(S.head){};
const Set& Set::operator= (const Set& S)
{
	while (this == &S) return *this;
    while (head.Head != NULL) {
		head.DelHead();
	}
	n = 0;
	pNode p = S.head.Head;
	while (p != NULL) {
		head.InsertTail(p->data);
		p = p->next;
	}
	return *this;
}
Set Set::operator + (int x)
{
    Set S = *this;
    pNode q = S.head.Head;
    pNode t = NULL;
    if (q == NULL || q->data > x)
    {
        S.head.InsertHead(x);
        S.n++;
        return S;
    }
	while (q != NULL) {
        if (q->data == x) return S;
        if (q->data > x) {
            S.head.InsertAfter(t,x); 
            S.n++;
            return S;
        }
        t = q; q = q->next;
	} 
	S.head.InsertTail(x); S.n++;
	return S;
}
Set Set::operator - (int x)
{
    Set S = *this;
	if ( S(x) ) {
		S.head.DelX(x);
		S.n--;
	}
	return S;
}
bool Set::operator () (int x) const {
	pNode p = head.Head;
	if (head.Head == NULL) return false;
	while (p->next != NULL && p->data < x)
		p = p->next;
	return (p->data == x);
}

int Set::operator[](int i) const
{
	pNode p = head.Head;
	int j = 0;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	if (p == NULL) return -1;
	return p->data;
}

Set Set::operator + (const Set& X) {
	Set S = *this;
	pNode q;
	q = X.head.Head;
	while(q!=NULL) {
          S = S + q->data;
          q = q-> next;
    }
	return S;
}
Set Set::operator - (const Set& X) {
	pNode p;
	Set S = *this;
	p = (*this).head.Head;
	while (p != NULL){
		if ( X(p->data)) S = S - p->data;
		p = p->next;
	}
	return S;
}
Set Set::operator * (const Set& X) {
	pNode p;
	Set S = *this;
	p = (*this).head.Head;
	while (p != NULL){
		if ( !X(p->data)) S = S - p->data;
		p = p->next;
	}
	return S;
}
ostream &operator << (ostream &out, const Set &S)
{
    pNode p = S.head.Head;
    if (p == NULL) out << "{}";
    else {
        out << "{";
        out << p->data;
        while (p->next != NULL)
        {
            p = p->next;
            out << "," << p->data;
        }
        out << "}";
    }
    return out;
}

