#include <iostream>
#include "Vehicle.h"


Vehicle::Vehicle(){
    make = "COP3503";
    model = "Rust Bucket";
    year = 1900;
    price = 0.0f;
    miles = 0;
}

Vehicle::Vehicle(string make, string model, int year, float price, int miles){
    this->make = make;
    this->model = model;
    this->year = year;
    this->price = price;
    this->miles = miles;
}

void Vehicle::Display(){
    cout<< this->year << " " << this->make << " " << this->model << " $" << this->price << " " << this->miles <<endl;
}
string Vehicle::GetYearMakeModel(){
    string strYear = to_string(this->year);
    string yearmakemodel = strYear + " " + this->make + " " + this->model;
    return yearmakemodel;
}
float Vehicle::GetPrice(){
    return this->price;
}