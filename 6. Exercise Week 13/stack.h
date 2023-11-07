#ifndef STACK_H
#define STACK_H

class stack {
    private:
        int n, top;
        int *data;
    public:
        stack(int m = 10);
        ~stack();
        stack(const stack &s);
        bool push(int x);
        bool pop(int &x);
        bool 
};
#endif