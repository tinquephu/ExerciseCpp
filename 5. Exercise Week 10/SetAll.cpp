#include <iostream>

using namespace std;
struct Node {
			int data;
			Node* next;
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

struct TapHop {
	private:
		int n;
		List head;
	public:
		TapHop();
		TapHop(const TapHop& X);
		const TapHop& operator= (const TapHop& X);
		
		TapHop operator+ (float);
		TapHop operator- (float);
		bool operator() (float) const;
		TapHop operator+ (const TapHop& X);
		TapHop operator- (const TapHop& X);
		TapHop operator* (const TapHop& X);
		
		friend ostream& operator<< (ostream& os, const TapHop& X);
};
TapHop::TapHop() {
	n = 0;
}

// khoi tao thanh vien ??????
TapHop::TapHop(const TapHop& X):n (X.n), head(X.head)  {	
}
// tuong duong 
// TapHop::TapHop(const TapHop&X) {
//	n = X.n;
//	}
const TapHop& TapHop::operator= (const TapHop& X){
	while (this == &X) return *this;
    while (head.Head != NULL) {
		head.DelHead();
	}
	n = 0;
	pNode p = X.head.Head;
	while (p != NULL) {
		head.InsertTail(p->data);
		p = p->next;
	}
	return *this;
	}
TapHop TapHop::operator+ (float x) {
	TapHop h = *this;
	pNode q = h.head.Head, t=NULL;
	if (q == NULL || q->data > x){
       h.head.InsertHead(x);
       h.n++;
       return h;
    }
	while (q != NULL) {
          if (q->data == x) return h;
          if (q->data > x) {
             h.head.InsertAfter(t,x); h.n++;
             return h;
          }
          t = q; q = q->next;
	} 
	h.head.InsertTail(x); h.n++;
	return h;
}
TapHop TapHop::operator- (float x) {
	TapHop h = *this;
	if ( h(x) ) {
		h.head.DelX(x);
		h.n--;
	}
	return h;
}
bool TapHop::operator() (float x) const {
	pNode p = head.Head;
	if (head.Head == NULL) return false;
	while (p->next != NULL && p->data < x)
		p = p->next;
	return (p->data == x);
}
TapHop TapHop::operator+ (const TapHop& X) {
	TapHop h = *this;
	pNode q;
	q = X.head.Head;
	while(q!=NULL) {
          h = h + q->data;
          q = q-> next;
          }
	return h;
}
TapHop TapHop::operator- (const TapHop& X) {
	pNode p;
	TapHop h = *this;
	p = (*this).head.Head;
	while (p != NULL){
		if ( X(p->data)) h = h - p->data;
		p = p->next;
	}
	return h;
}
TapHop TapHop::operator * (const TapHop& X) {
	pNode p;
	TapHop h = *this;
	p = (*this).head.Head;
	while (p != NULL){
		if ( !X(p->data)) h = h - p->data;
		p = p->next;
	}
	return h;
}

ostream& operator<< (ostream& os, const TapHop& X) {
	pNode p = X.head.Head;
	if (p == NULL){
		os <<"{}";
	} else {
		os<<"{";
		os << p->data;
		while (p->next != NULL){
            p = p->next;
			os <<"," <<p->data;
		}
		os <<"}";
	}
	return os;
}
int main() {
	TapHop A, B;
	float x;
	A = A + 8 + 10 + 13 + 4 + 20 + 12; 
	cout <<"A = " <<A <<endl;
	cout <<"Nhap phan tu can xoa: "; cin >> x;
	A = A - x;
	cout <<"Nhap phan tu can them: "; cin >> x;
	A = A + x;
	cout <<"A = " <<A <<endl<<endl;
	B = B + 5 + 10 + 8 + 13 + 20 + 14;
	cout <<"B = " <<B<< endl;
	TapHop H = A + B;
	//h = a+b;
	cout <<"A hop B = " << H <<endl;
	TapHop K = A - B;
	cout <<"A - B = " << K <<endl;
	TapHop L = A * B;
	cout <<"A giao B = "<<L <<endl;
	return 0;
}
