#include <string>
using namespace std;

class Vehicle{
private:
    string make;
    string model;
    int year;
    float price;
    int miles;
public:
    Vehicle();
    Vehicle(string make, string model, int year, float price, int miles);
    void Display();
    string GetYearMakeModel();
    float GetPrice();

};