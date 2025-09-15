# CS315-Project1
# Project 1 – Maze Solver

---

## 👩‍💻 Student Information
- **Name:** Shakira Garcia  
- **Student ID:** 008218438  
- **Repository Link:** [GitHub Repo](<insert-your-repo-link-here>)  

---

## 🤝 Collaboration & Sources
This project is my own work.  

I did, however, reference outside resources and received assistance:  
- **Online references:**  
  - [Code Review: Maze Maker Style and Efficiency](https://codereview.stackexchange.com/questions/265710/general-coding-style-and-efficiency-of-a-maze-maker/265726)  
    - I used this resource to understand general coding style, naming conventions, and efficiency considerations for maze-related projects. It helped me check that my design (using a `Maze` class and stack-based solving) followed good coding practices.  
  - [YouTube: Maze Solving Explanation](https://www.youtube.com/watch?v=Y37-gB83HKE)  
    - This video gave me a visual explanation of how stack-based backtracking works in mazes. It reinforced the concept of pushing new cells onto the stack and popping (backtracking) when hitting dead ends.  
  - [GeeksforGeeks: Command-Line Arguments in C++](https://www.geeksforgeeks.org/cpp/command-line-arguments-in-cpp/)  
    - While testing on the Blue server, I needed to be able to accept input files through the command line (ex:, `./a.out maze0-1_input.txt`). This tutorial explained how command-line arguments work in C++, which allowed me to adjust testing so I could pass new maze files without hardcoding filenames.  

- **AI tools:** I used ChatGPT to help with writing explanatory comments. I reviewed and edited all my comments to make sure they matched my understanding and the course guidelines.

---

## ⚙️ Implementation Details
The program is written in C++ and solves a maze using an **iterative, stack-based backtracking algorithm**.

- **Data Structures:**
  - `std::vector<std::vector<int>>` – to store the maze as a 2D grid of integers (`1` = wall, `0` = path).  
  - `struct Cell { int row; int col; };` – to represent maze coordinates.  
  - `std::stack<Cell>` – to store the current path as the algorithm explores and backtracks.  

- **Algorithm:**
  1. Load the maze from a text file into a 2D vector.  
  2. Detect the start and target cells (the two open border cells).  
  3. Use a stack-based backtracking algorithm:
     - Push the start cell onto the stack.  
     - At each step, try to move up, down, left, or right to an unvisited open cell.  
     - Mark visited cells as part of the path.  
     - If no moves are available, pop (backtrack) until another unexplored option exists.  
  4. If the target is reached, mark the path in the grid. If not, report that no solution exists.  

- **Output:**  
  - The original maze is printed first (with 0’s and 1’s).  
  - The solved maze is printed again, with the solution path shown as blank spaces (` `).  

---

## ✅ Testing & Status

### What Works
- Maze file loads correctly from `maze0-1_input.txt`.  
- The program correctly identifies the entrance (start) and exit (target) cells.  
- The original maze is printed exactly as it appears in the file.  
- The solver finds a valid path from start to target using stack-based backtracking.  
- The solved maze is reprinted with the path marked as spaces (` `).  
- The program correctly handles edge cases:
  - If the file cannot be opened, an error message is printed and the program exits.  
  - If no solution exists in a maze, the program prints “No path found.”  

### What Does Not Work
- The program does not currently handle mazes with more than one possible solution; it simply follows the first path it finds.  
- The program does not support colored output or marking the path with special symbols (these were optional).  

### How to Test
1. Place `maze0-1_input.txt` in the project root directory (same location as `CMakeLists.txt`).  

#### Option 1: Run in CLion
- Build and run the project.  
- If no arguments are provided, the program will automatically use `maze0-1_input.txt`.  
- The program will print the original maze followed by the solved maze.  

#### Option 2: Run on Blue (command-line arguments)
- Compile the program:
