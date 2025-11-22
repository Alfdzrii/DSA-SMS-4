# Copilot Instructions for DSA Codebase

## Overview
This codebase contains C++ implementations of core data structures and algorithms, organized by topic and week. It is structured for educational purposes, with each file or folder typically representing a distinct concept or assignment.

## Directory Structure
- **Root Level**: Contains standalone C++ files for various data structures (e.g., `circularQ.cpp`, `LeafCounting.cpp`, `CPQueue.cpp`).
- **weekX/**: Weekly folders (e.g., `week 2/`, `week 3/`, etc.) contain topic-specific exercises and assignments.
- **tree/**: Contains binary search tree implementations (`BST.cpp`).
- **kak denzel/**: Contains multiple linked list and stack implementations, including subfolders for array and linked list stacks.
- **assignment/**: Contains assignment-specific files.

## Build & Run Workflow
- **Build**: Use the VS Code build task `C/C++: g++.exe build active file` to compile the currently open C++ file. This uses MSYS2's g++ and outputs a `.exe` in the same directory as the source.
  - Example: Open `week3/Structure.cpp` and run the build task to produce `Structure.exe`.
- **Run**: Execute the resulting `.exe` directly in the terminal. No unified build system; each file is built and run independently.

## Patterns & Conventions
- **File Naming**: Filenames reflect the data structure or algorithm implemented (e.g., `queue.cpp`, `stack.cpp`, `BST.cpp`).
- **No Main Entry Point**: Each file is self-contained with its own `main()` function for testing/demo purposes.
- **Minimal External Dependencies**: All code is standard C++ with no third-party libraries.
- **No Automated Tests**: Validation is manual via running the compiled executables.
- **Windows/MSYS2 Pathing**: Build tasks use Windows-style paths and MSYS2 toolchain, even on Linux. Adjust if porting.

## Examples
- To build and run a stack implementation:
  1. Open `week 4/stack.cpp` in VS Code.
  2. Run the build task to generate `stack.exe`.
  3. Run `./week 4/stack.exe` in the terminal.
- To explore a binary search tree:
  1. Open `tree/BST.cpp`.
  2. Build and run as above.

## Tips for AI Agents
- When adding new data structure files, follow the naming and folder conventions.
- Keep each implementation self-contained with its own `main()` for demonstration.
- Reference existing files for typical function signatures and usage patterns.
- Avoid introducing external dependencies unless absolutely necessary.
- Document any new patterns or workflows in this file for future agents.

---
_Last updated: November 22, 2025_
