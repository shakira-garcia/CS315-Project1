#include "Maze.h"
#include <fstream>
#include <stack>

// --------------------------------------------------
// Load maze from file into a 2D vector
// --------------------------------------------------
bool Maze::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return false;
    }

    grid.clear();   // make sure the grid is empty before loading
    std::string line;

    // Read the maze file line by line
    while (std::getline(inFile, line)) {
        std::vector<int> row;
        // Go through each character in the line
        for (char c : line) {
            if (c == '0' || c == '1') {
                row.push_back(c - '0'); // convert character '0' or '1' to integer 0 or 1
            }
        }
        if (!row.empty()) {
            grid.push_back(row); // add the row to the maze
        }
    }

    inFile.close();

    // Find the entrance (start) and exit (target)
    // These will be the two open cells (0's) on the border
    start = {-1, -1};
    target = {-1, -1};
    int rows = grid.size();
    int cols = grid[0].size();

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            // check if this is a border cell and it's open (0)
            if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) && grid[r][c] == 0) {
                if (start.row == -1) {
                    start = {r, c}; // first open border cell is the start
                } else {
                    target = {r, c}; // second open border cell is the target
                }
            }
        }
    }

    return true;
}

// --------------------------------------------------
// Print the maze to the console
// --------------------------------------------------
void Maze::printMaze() const {
    for (const auto& row : grid) {
        for (int cell : row) {
            if (cell == 2) {
                std::cout << " "; // mark solution path with blank space
            } else {
                std::cout << cell; // otherwise print 0 or 1
            }
        }
        std::cout << std::endl;
    }
}

// --------------------------------------------------
// Solve the maze using stack-based backtracking
// --------------------------------------------------
bool Maze::solve() {
    if (start.row == -1 || target.row == -1) {
        std::cerr << "Maze does not have valid start/target.\n";
        return false;
    }

    int rows = grid.size();
    int cols = grid[0].size();

    // Keep track of whether each cell has been visited
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    // Stack to keep track of our path
    std::stack<Cell> st;
    st.push(start);
    visited[start.row][start.col] = true;

    // Parent array: remembers where we came from, so we can reconstruct the path later
    std::vector<std::vector<Cell>> parent(rows, std::vector<Cell>(cols, {-1, -1}));

    // Arrays to represent the 4 possible moves (up, right, down, left)
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    while (!st.empty()) {
        Cell current = st.top();
        st.pop();

        // Check if we have reached the exit
        if (current.row == target.row && current.col == target.col) {
            // Backtrack from target to start, marking the path
            Cell p = target;
            while (!(p.row == start.row && p.col == start.col)) {
                grid[p.row][p.col] = 2; // mark this cell as part of the solution path
                p = parent[p.row][p.col]; // move to parent cell
            }
            grid[start.row][start.col] = 2; // mark the start cell
            return true; // solved!
        }

        // Explore all 4 neighbors (up, right, down, left)
        for (int i = 0; i < 4; i++) {
            int nr = current.row + dr[i]; // new row
            int nc = current.col + dc[i]; // new column

            // Check if the neighbor is inside the maze, is open (0), and not visited yet
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
                grid[nr][nc] == 0 && !visited[nr][nc])
            {
                visited[nr][nc] = true;      // mark as visited
                parent[nr][nc] = current;    // remember where we came from
                st.push({nr, nc});           // push neighbor to stack for later exploration
            }
        }
    }

    return false; // no path found
}


