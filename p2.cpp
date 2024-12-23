#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

     // Transition table
    int numSymbols;
    cout << "Enter the number of input symbols: ";
    cin >> numSymbols;

    vector<char> symbols(numSymbols);
    cout << "Enter the input symbols: ";
    for (int i = 0; i < numSymbols; i++) {
        cin >> symbols[i];
    }

    // Number of states and initial state
    int numStates;
    cout << "Enter the number of states: ";
    cin >> numStates;

    int initialState;
    cout << "Enter the initial state: ";
    cin >> initialState;

    // Accepting states
    int numAcceptingStates;
    cout << "Enter the number of accepting states: ";
    cin >> numAcceptingStates;

    vector<int> acceptingStates(numAcceptingStates);
    cout << "Enter the accepting states: ";
    for (int i = 0; i < numAcceptingStates; i++) {
        cin >> acceptingStates[i];
    }

   
    vector<vector<int>> transitions(numStates + 1, vector<int>(numSymbols));
    cout << "Enter the transition table (state to symbol -> next state):\n";
    for (int state = 1; state <= numStates; state++) {
        for (int sym = 0; sym < numSymbols; sym++) {
            cout << "State " << state << " to symbol '" << symbols[sym] << "': ";
            cin >> transitions[state][sym];
        }
    }

    // Input string
    string input;
    cout << "Enter an input string: ";
    cin >> input;

    // Start processing the input string
    int currentState = initialState;
    for (char c : input) {
        // Determine the column index for the symbol
        int symbolIndex = -1;
        for (int i = 0; i < numSymbols; i++) {
            if (c == symbols[i]) {
                symbolIndex = i;
                break;
            }
        }

        if (symbolIndex == -1) {
            cout << "The string is not valid (invalid symbol encountered).\n";
            return 0;
        }

        // Transition to the next state
        currentState = transitions[currentState][symbolIndex];
    }

    // Check if the final state is an accepting state
    bool isAccepted = false;
    for (int i = 0; i < numAcceptingStates; i++) {
        if (currentState == acceptingStates[i]) {
            isAccepted = true;
            break;
        }
    }

    if (isAccepted) {
        cout << "The string is accepted by the finite automaton.\n";
    } else {
        cout << "The string is not accepted by the finite automaton.\n";
    }

    return 0;
}
