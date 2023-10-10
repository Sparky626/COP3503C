#include <iostream>
#include <string>
#pragma once
using namespace std;

template <class T> class ABQ{
private:
    int current_capacity;
    int max_capacity;
    float scale_factor;
    T* data_array;

public:
    ABQ(){
        current_capacity = 0;
        max_capacity = 1;
        scale_factor = 2.0f;
        data_array = new T[max_capacity];
    };
    ABQ(int capacity){
        this->max_capacity = capacity;
        current_capacity = 0;
        scale_factor = 2.0f;
        data_array = new T[this->max_capacity];
    };
    ABQ(const ABQ &d){
        this->current_capacity = d.current_capacity;
        this->max_capacity = d.max_capacity;
        this->scale_factor = d.scale_factor;
        data_array = new T[max_capacity];
        for (int i = 0; i < current_capacity; i++){
            data_array[i] = d.data_array[i];
        }
    };
    ABQ &operator=(const ABQ &d){
        delete[] data_array;
        current_capacity = d.current_capacity;
        max_capacity = d.max_capacity;
        scale_factor = d.scale_factor;
        data_array = d.data_array;

        data_array = new T[max_capacity];
        for (int i = 0; i < current_capacity; i++){
            data_array[i] = d.data_array[i];
        }

        return *this;
    };
    ~ABQ(){
        delete [] data_array;
    };
    void enqueue(T data){
        if (max_capacity==current_capacity){
            int scalar = current_capacity * scale_factor;
            T *new_data_array = new T[scalar];
            for(int i = 0; i< current_capacity; i++){
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
    T dequeue(){
        if (current_capacity == 0){
            throw runtime_error("The stack is empty!");
        }
        T dequeued = data_array[0];
        for (int i=0;i< current_capacity-1;i++){
            data_array[i] = data_array[i+1];
        }
        float percent_full = (float)current_capacity/(float)max_capacity;
        float x = 1.0f/(float)scale_factor;
        if(percent_full < x){
            int scalar = max_capacity/scale_factor;
            T *new_data_array = new T[scalar];
            for(int i = 0; i<scalar; i++){
                new_data_array[i] = data_array[i];
            }
            max_capacity = scalar;
            delete [] data_array;
            data_array = new_data_array;
        }
        return dequeued;

    };
    T peek(){
        if (current_capacity == 0){
            throw runtime_error("The stack is empty!");
        }
        T peeked = data_array[0];
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





