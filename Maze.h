//
// Created by Shakira Garcia on 9/14/2025.
//

#ifndef CS_315_PROJECT_1_MAZE_H
#define CS_315_PROJECT_1_MAZE_H

#include <vector>
#include <string>
#include <iostream>

// Struct for representing a cell in the maze
struct Cell {
    int row;
    int col;
};

class Maze {
private:
    std::vector<std::vector<int>> grid;
    Cell start{-1, -1};
    Cell target{-1, -1};

public:
    // Load maze from file
    bool loadFromFile(const std::string& filename);

    // Print the maze to console
    void printMaze() const;

    // Getters for start and target
    Cell getStart() const { return start; }
    Cell getTarget() const { return target; }

    // Solve the maze using stack-based backtracking
    bool solve();
};


#endif //CS_315_PROJECT_1_MAZE_H
