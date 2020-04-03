#ifndef STCKTP1_H_
#define STCKTP1_H_

template <typename Type>
class Stack{
	enum {SIZE=10};;
	int stacksize;   //栈大小 
	Type * items;
	int top;   //将会始终是堆顶的值 
public:
	explicit Stack(int ss=SIZE);
	Stack(const Stack & st);
	~Stack() {delete [] items;}
	bool isempty() {return top==0;}
	bool isfull() {return top==stacksize;}
	bool push(const Type & item);
	bool pop(Type & item);
	Stack & operator=(const Stack & st);
};

template <typename Type>
Stack<Type>::Stack(int ss): stacksize(ss), top(0){
	items=new Type [stacksize];
}

template <typename Type>
Stack<Type>::Stack(const Stack & st){
	stacksize=st.stacksize;
	top=st.top;
	items=new Type [stacksize];
	for (int i=0; i<stacksize; i++)
		items[i]=st.items[i];
}

template <typename Type>
bool Stack<Type>::push(const Type & item){
	if (top<stacksize){
		items[top++]=item;    //top的值也会跟着变 
		return true;
	}
	else
		return false;
}

template <typename Type>
bool Stack<Type>::pop(Type & item){
	if (top > 0){
		item=items[--top];   //top的值也会跟着变 
		return true;
	}
	else
		return false;
}

template <typename Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> & st){
	if (this==&st)
		return *this;
	delete [] items;
	stacksize=st.stacksize;
	top=st.top;
	items=new Type [stacksize];
	for (int i=0; i<stacksize; i++)
		items[i]=st.items[i];
	return *this;	
}

#endif 
