#include <iostream>
#include <string>
#include <stack>
using namespace std;

template <class T> class ABS{
private:
    int current_capacity;
    int max_capacity;
    float scale_factor;
    T* data_array;

public:
    ABS(){
        current_capacity = 0;
        max_capacity = 1;
        scale_factor = 2.0f;
        data_array = new T[max_capacity];
    };
    ABS(int capacity){
        this->max_capacity = capacity;
        current_capacity = 0;
        scale_factor = 2.0f;
        data_array = new T[this->max_capacity];
    };
    ABS(const ABS &d){
        this->current_capacity = d.current_capacity;
        this->max_capacity = d.max_capacity;
        this->scale_factor = d.scale_factor;
        data_array = new T[max_capacity];
        for (int i = 0; i < current_capacity; i++){
            data_array[i] = d.data_array[i];
        }
    };
    ABS &operator=(const ABS &d){
        current_capacity = d.current_capacity;
        max_capacity = d.max_capacity;
        scale_factor = d.scale_factor;
        data_array = d.data_array;
        return *this;
    };
    ~ABS(){
        delete [] data_array;
    };
    void push(T data){
        if (max_capacity==current_capacity){
            int scalar = current_capacity * scale_factor;
            T *new_data_array = new T[scalar];
            for(int i = 0; i<current_capacity; i++){
                new_data_array[i] = data_array[i];
            }
            max_capacity = scalar;
            delete [] data_array;
            data_array = new_data_array;
            this->data_array[current_capacity] = data;
            current_capacity++;
        }
        else{
            this->data_array[current_capacity] = data;
            current_capacity++;
        }
    };
    T pop(){
        if (current_capacity == 0){
            throw runtime_error("The stack is empty!");
        }
        T popped = data_array[current_capacity-1];
        current_capacity--;
        double percent_full = current_capacity/max_capacity;
        double x = 1/scale_factor;
        if(percent_full < x){
            int scalar = current_capacity/scale_factor;
            T *new_data_array = new T[scalar];
            for(int i = 0; i<scalar; i++){
                new_data_array[i] = data_array[i];
            }
            max_capacity = scalar;
            delete [] data_array;
            data_array = new_data_array;
        }
        return popped;

    };
    T peek(){
        if (current_capacity == 0){
            throw runtime_error("The stack is empty!");
        }
        T peeked = data_array[current_capacity-1];
        return peeked;
    };
    unsigned int getSize(){
        return this->current_capacity;
    };
    unsigned int getMaxCapacity(){
        return this->max_capacity;
    };
    T* getData(){
        return this->data_array;
    };


};





