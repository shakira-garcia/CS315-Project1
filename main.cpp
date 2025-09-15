#include "Maze.h"
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    Maze maze;

    // Default filename
    string filename = "maze0-1_input.txt";

    // If user provides a command-line argument, use that instead
    if (argc > 1) {
        filename = argv[1];
    }

    // Load the maze from the file
    if (!maze.loadFromFile(filename)) {
        return 1; // quit if file not found
    }

    cout << "Original maze:\n";
    maze.printMaze();

    if (maze.solve()) {
        cout << "\nSolved maze:\n";
        maze.printMaze();
    } else {
        cout << "\nNo path found.\n";
    }

    return 0;
}




