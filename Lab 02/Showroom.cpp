#include "Showroom.h"
#include <iostream>

Showroom::Showroom() {
    name = "Unnamed Showroom";
    storage = {};
    capacity = 0;
}

Showroom::Showroom(string name, unsigned int capacity) {
    this->name = name;
    this->capacity = capacity;
}

vector<Vehicle> Showroom::GetVehicleList() {
    return this->storage;
}

void Showroom::AddVehicle(Vehicle v) {
    if (this->storage.size() == this->capacity){
        cout << "Showroom is full! Cannot add " << v.GetYearMakeModel() << endl;
    }
    else{
        this->storage.push_back(v);
    }
}

void Showroom::ShowInventory() {
    if (this->storage.empty()){
        cout << "Unnamed showroom is empty!" <<endl;
    }
    else{
        cout << "Vehicles in " << this->name << endl;
        for (auto& car : this->storage) {
            car.Display();
        }
    }
}

float Showroom::GetInventoryValue() {
    float inventoryValue = 0.0f;
    for (auto& car : this->storage){
         inventoryValue += car.GetPrice();
    }
    return inventoryValue;
}

string Showroom::GetName() {
    return this->name;
}

