#include "Vehicle.h"
#include <string>
#include <vector>

using namespace std;
class Showroom{
    string name;
    vector<Vehicle> storage;
    unsigned int capacity;
public:
    Showroom();
    Showroom(string name,  unsigned int capacity);
    vector<Vehicle> GetVehicleList();
    void AddVehicle(Vehicle v);
    void ShowInventory();
    float GetInventoryValue();
    string GetName();

};