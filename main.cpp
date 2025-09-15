#include "Maze.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    Maze maze;

    // Default file name
    string filename = "maze0-1_input.txt";

    // If a file name is given on the command line, use that instead
    if (argc > 1) {
        filename = argv[1];
    }

    // Try to load the maze
    if (!maze.loadFromFile(filename)) {
        return 1; // quit if file not found
    }

    // Print the maze as it was read from the file
    cout << "Original maze:\n";
    maze.printMaze();

    // Attempt to solve the maze
    if (maze.solve()) {
        cout << "\nSolved maze:\n";
        maze.printMaze();
    } else {
        cout << "\nNo path found.\n";
    }

    return 0;
}




