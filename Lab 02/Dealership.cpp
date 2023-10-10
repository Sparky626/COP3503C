#include <iostream>
#include "Dealership.h"

Dealership::Dealership() {
    name = "Generic Dealership";
    showrooms = {};
    capacity = 0;

}

Dealership::Dealership(string name, int capacity) {
    this->name = name;
    this->capacity = capacity;

}

void Dealership::AddShowroom(Showroom s) {
    if (this->showrooms.size() == this->capacity){
        cout << "Dealership is full, can't add another showroom!" << endl;

    }
    else{
        this->showrooms.push_back(s);
    }
}

float Dealership::GetAveragePrice() {
    int counter = 0;
    float total = 0.0f;
    float average;
    for (auto& shows : this->showrooms){
        vector<Vehicle> currentShowroom = shows.GetVehicleList();
        for(auto& car: currentShowroom){
            counter++;
            total += car.GetPrice();
        }
    }
    average = total/counter;
    return average;
}

void Dealership::ShowInventory() {
    if (this->showrooms.empty()) {
        cout << this->name << " is empty!" << endl;
        cout << "Average car price: $0.00";


    } else {
        for (auto &shows: this->showrooms) {
            string showroomName = shows.GetName();
            vector<Vehicle> currentShowroom = shows.GetVehicleList();
            cout << "Vehicles in " << showroomName << endl;
            for (auto &car: currentShowroom) {
                car.Display();
            }
            cout << endl;
        }
        float average = GetAveragePrice();
        cout << "Average car price: $" << average;
    }
}
