#include "Showroom.h"

using namespace std;
class Dealership{
    string name;
    vector<Showroom> showrooms;
    int capacity;
public:
    Dealership();
    Dealership(string name, int capacity);
    void AddShowroom(Showroom s);
    float GetAveragePrice();
    void ShowInventory();


};