#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define el "\n"

void chuyen(int n, int c1, int c3)
{
    cout << "Chuyen 1 dia tu cot " << c1 << " sang cot " << c3 << el;
}

void thapHaNoi(int n, int c1, int c2, int c3)
{
    if (n == 1)
    {
        chuyen(n, c1, c3);
    }
    else
    {
        thapHaNoi(n - 1, c1, c3, c2);
        chuyen(1, c1, c3);
        thapHaNoi(n - 1, c2, c1, c3);
    }
}

// thap ha noi khu de quy

struct Call{
	int n;
	char a, b, c;
};
struct Stack{
	int top;
	Call *e;
};

void create(Stack &s){
	s.top = -1;
	s.e = NULL;
}
bool empty(Stack s){
	return s.top == -1;
}
void push(Stack &s, Call call_in){
	if(empty(s)){
		s.e = new Call[1];
	}
	else{
		s.e = (Call *)realloc(s.e, (s.top + 2) * sizeof(Call));
	}
	s.top++;
	s.e[s.top] = call_in;
}

void pop(Stack &s, Call &call_out)
{
    if(empty(s)) return;
    call_out = s.e[s.top];
    if(s.top == 0){
    	delete[] s.e;
    	create(s);
	}
    else{
    	s.e = (Call *)realloc(s.e, s.top * sizeof(Call));
    	s.top--;
	}
}

void thapHaNoi(Call firt_call)
{
    Call call_in, call_out;
    Stack s;
    create(s);
    call_in = firt_call;
    push(s, call_in);
    while (!empty(s))
    {
        pop(s, call_out);
        if (call_out.n == 1)
        {
            cout << "..." << call_out.a << "..." << call_out.c << el;
        }
        else
        {
            call_in.n = call_out.n - 1;
            call_in.a = call_out.b;
            call_in.b = call_out.a;
            call_in.c = call_out.c;
            push(s, call_in);
            call_in = call_out;
            call_in.n = 1;
            push(s, call_in);
            call_in.n = call_out.n - 1;
            call_in.a = call_out.a;
            call_in.b = call_out.c;
            call_in.c = call_out.b;
            push(s, call_in);
        }
    }
}
int main()
{
    Call first_call = {3, 'A', 'B', 'C'};
    thapHaNoi(first_call);
}