//Wilson Staley
//12/11/17
//Stack Implementation

#include <iostream>

using namespace std;

template <typename T>
class Stack{
    private:
        T* data; //points to backing array
        T* top; //keeps track of top element
        size_t size;  //size of the backing array
    public:
        Stack(int size = 50): size(size), top(nullptr), data(new T [size]){}
        ~Stack();
        void push(T element);
        void pop();
        void print();
        void clear();
        bool is_empty();
        bool is_full();
        size_t length();
        T peek_front();
        T peek_back();
};

template <typename T>
Stack<T>::~Stack(){
    delete [] data;
    data = top = nullptr;
}

template <typename T>
void Stack<T>::push(T element){
    if(is_full()){
        cout << "The Stack is full. \n";
        return;
    }
    else if(is_empty()){
        top = data;
        *top = element;
    }
    else{
        top++;
        *top = element;
    }
}

template <typename T>
void Stack<T>::pop(){
    if(is_empty()){
        cout << "The Stack is empty.\n";
        return;
    }
    if(top == &data[0]){
        top = nullptr;
    }
    else top--;
}

template <typename T>
void Stack<T>::print(){
    if(is_empty()){
        cout << "[ ]\n";
        return;
    }
    cout << "[ ";
    T* curr = data;
    for(int i=0; i<length(); i++){
        cout << *curr << " ";
        curr++;
    }
    cout << "]\n";
}

template <typename T>
void Stack<T>::clear(){
    top = nullptr;
}

template <typename T>
bool Stack<T>::is_empty(){
    if(top == nullptr) return true;
    return false;
}

template <typename T>
bool Stack<T>::is_full(){
    if(top == &data[size-1]) return true;
    return false;
}

template <typename T>
size_t Stack<T>::length(){
    if(is_empty()) return 0;
    size_t len = 0;
    T* curr = data;
    while(curr != top){
        len++; 
        curr++;
    }
    len++;
    return len;
}

template <typename T>
T Stack<T>::peek_front(){
    if(is_empty()) return -1;
    return *top;
}

template <typename T>
T Stack<T>::peek_back(){
    if(is_empty()) return -1;
    return data[0];
}

int main() {
    Stack<int> a(5);
    for(int i=0; i<6; i++){
        a.push(i+1);
    }
    a.print();
    cout << a.peek_front() << endl << a.peek_back() << endl;
    a.pop();
    a.print();
    return 0;
}

