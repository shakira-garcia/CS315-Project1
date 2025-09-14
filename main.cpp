#include "Maze.h"
#include <iostream>
using namespace std;

int main() {
    // Create a Maze object to work with
    Maze maze;

    // Load the maze from the input file.
    // If loading fails, exit the program with error code 1.
    if (!maze.loadFromFile("maze0-1_input.txt")) {
        return 1; // quit if file not found
    }

    // Print the maze exactly as it looks in the file
    cout << "Original maze:\n";
    maze.printMaze();

    // Try to solve the maze using the Maze class's solve() function
    if (maze.solve()) {
        // If a solution is found, print the maze again
        // The solution path will be shown as blank spaces
        cout << "\nSolved maze:\n";
        maze.printMaze();
    } else {
        // If no solution exists, let the user know
        cout << "\nNo path found.\n";
    }

    // End of program
    return 0;
}



