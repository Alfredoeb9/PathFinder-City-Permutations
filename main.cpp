#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int NUM_OF_CITIES = 4;
    vector<string> cities = {"Riverside", "Moreno Valley", "Perris", "Hemet"};

    int graph[NUM_OF_CITIES][NUM_OF_CITIES] = {
        {0, 16, 24, 33}, // Riverside -> MV = 16, Riverside -> Perris = 24, Riverside -> Hemet = 33
        {16, 0, 18, 26}, // MV -> Riverside = 16; MV -> MV = 0; MV -> Perris = 18; MV -> Hemet = 26
        {24, 18, 0, 30}, // Perris -> ...
        {33, 26, 30, 0}
    };

    vector<int> order = {1, 2, 3};
    int bestDistance = INT_MAX;    // give me the biggest number you can
    vector<int> bestPath; 

    do {
        int distance = 0;
        int current = 0;    // Starting at Riverside

        for (int next : order) {
            distance += graph[current][next];
            current = next;
        }
        
        // As we return to the orginal city we return back to riverside in this case
        distance += graph[current][0];

        // Print out the path
        cout << cities[0] << " -> ";

        for (int i = 0; i < order.size(); i++) {
            cout << cities[order[i]] << (i + 1 < order.size() ? " -> " : " -> ");
        }

        cout << cities[0] << " | Total: " << distance << " miles\n";

        if (distance < bestDistance) {
            bestDistance = distance;
            bestPath = order;
        }

    } while(next_permutation(order.begin(), order.end()));

    cout << "Shortest route: " << bestDistance << " miles\n";


    cout << "Shortest Path: Riverside ->";

    for (int i = 0; i < bestPath.size(); i++) {
        cout << cities[bestPath[i]] << (i + 1 < bestPath.size() ? " -> " : " -> ");
    }

    cout << "Riverside" << endl;

    return 0;
}