#include <iostream>
#include <map>
#include <random>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

struct State{
    string name;
    int perCapIncome;
    int population;
    int medianHouseIncome;
    int numHouseholds;
};

mt19937 random_mt;

int Random(int min, int max)
{
    uniform_int_distribution<int> dist(min, max);
    return dist(random_mt);
}

void RollDice(int numberOfRolls, int numberOfSides){
    map<int, int> results;
    int i = 1;
    while (i <= numberOfSides){
        results.insert (pair<int,int>(i,0));
        i++;
    }
    i = 0;
    while (i < numberOfRolls){
        int roll = Random(1,numberOfSides);
        results[roll]++;
        i++;
    }
    i = 0;
    for (const auto& entry : results) {
        cout << entry.first << " : " << entry.second << endl;
    }


}

int main()
{
    cout << "1. Random Numbers\n";
    cout << "2. State Info\n";

    int option;
    cin >> option;
    if (option == 1)
    {
        int randomSeed;
        cout << "Random seed value: ";
        cin >> randomSeed;
        random_mt.seed(randomSeed);
        int rollamt;
        cout << "Number of times to roll the die: ";
        // user input
        cin >> rollamt;
        int dicesides;
        cout << "Number of sides on this die: ";
        // user input
        cin >> dicesides;
        // Roll Dice
        RollDice(rollamt, dicesides);

    }
    else if (option == 2)
    {
        // Load the states
        map <string, State> stateMap;
        ifstream inputFile("states.csv");
        int index;
        if (inputFile.is_open()){
            string state;
            getline(inputFile, state);

            while (!inputFile.eof()){
                getline(inputFile,state);
                State stateData;
                stateData.name = state.substr(0,state.find(','));
                if(stateData.name.substr(0) == " "){
                    string name = "";
                    int i = 0;
                    while (i < stateData.name.size()){
                        if(i == 0){
                            continue;
                        }
                        else{
                            name += stateData.name.substr(i);
                        }
                    }
                    stateData.name = name;
                }
                index = state.find(',');

                stateData.perCapIncome = stoi(state.substr(index+1, state.find(',', index+1) - index - 1));
                index = state.find(',',index+1);

                stateData.population = stoi(state.substr(index+1, state.find(',', index+1) - index - 1));
                index = state.find(',',index+1);

                stateData.medianHouseIncome = stoi(state.substr(index+1, state.find(',', index+1) - index - 1));
                index = state.find(',',index+1);

                if (inputFile.eof()){
                    stateData.numHouseholds = stoi(state.substr(index+1, state.find(',', index+1) - index));
                }
                else{
                    stateData.numHouseholds = stoi(state.substr(index+1, state.find(",", index+1) - index - 1));
                }
                stateMap.insert(pair<string, State> (stateData.name ,stateData));
            }
            inputFile.close();

            // Get input for option 1 (show all states) or 2 (do a search for a particular state)
            cout << "1. Print all states" << endl;
            cout << "2. Search for a state" << endl;
            int option2;
            cin >> option2;
            if (option2 == 1){
                for (const auto& entry : stateMap) {
                    const State& stateData = entry.second;
                    cout << entry.first << endl;
                    cout << "Population: " << stateData.population << endl;
                    cout << "Per Capita Income: " << stateData.perCapIncome << endl;
                    cout << "Median Household Income: " << stateData.medianHouseIncome << endl;
                    cout << "Number of Households: " << stateData.numHouseholds << endl;
                    cout << endl;
                }
            }
            else if (option2 == 2){
                string inputState;
                getline(cin, inputState);
                auto iterator = stateMap.find(inputState);
                if (iterator != stateMap.end()){
                    const State& stateData = iterator->second;
                    cout << "Population: " << stateData.population << endl;
                    cout << "Per Capita Income: " << stateData.perCapIncome << endl;
                    cout << "Median Household Income: " << stateData.medianHouseIncome << endl;
                    cout << "Number of Households: " << stateData.numHouseholds << endl;
                    cout << endl;
                }
                else {
                    cout << "No match found for " << inputState << endl;
                }
            }
            else{
                cout << "That is not a valid option" << endl;
            }
        }
        else{
            cout << "Unable to open states.csv" << endl;
        }
    }

    return 0;
}
