# Smart Brain Project

## Description
This project is a modular simulation of an “artificial brain,” built in C++ using object-oriented programming (OOP) and the STL (Standard Template Library).  
The goal is to demonstrate the use of classes, inheritance, polymorphism, smart pointers, and data structures for organizing and processing information.

The brain is divided into several **functional centers** (e.g., logic, math, memory, speech, fun), each implemented as a separate class that extends a common interface.  
All these centers are managed by a central class called `Brain`.

---

## Architecture
- **Brain**  
  - The main component that coordinates all centers.  
  - Uses a map (`std::unordered_map`) to associate each center with a text identifier (e.g., `"logic"`, `"math"`).  
  - Receives input from the user and redirects it to the appropriate center.

- **Center (abstract interface)**  
  - Defines a common interface for all centers (`process`, `getName`).  
  - Enables polymorphism and easy extensibility.

- **LogicCenter**  
  - Processes logical expressions.  
  - Uses a **binary tree** (`LogicNode`) data structure to represent logical expressions.  
  - Relies on smart pointers (`std::shared_ptr`) for automatic memory management.  

- **MathCenter**  
  - Performs basic mathematical calculations.  
  - Uses **string streams** (`std::istringstream`) for parsing expressions.

- **MemoryCenter**  
  - Stores and retrieves information.  
  - Implements a **vector (`std::vector<std::string>`)** to hold user-provided data.

- **SpeechCenter**  
  - Generates text based on “say” commands.  
  - Uses simple input and output (`std::cout`).

- **FunCenter**  
  - Generates entertaining activities (jokes, fun messages).  

---

## Data Structures and Concepts Used
- **`std::map<std::string, std::shared_ptr<BaseCenter>>`**  
  - Associates the name of a center with the corresponding object.  
  - Allows fast access to centers by a text key.  

- **`std::vector<std::string>`**  
  - Used in `MemoryCenter` to store memorized information.  

- **`std::shared_ptr`**  
  - Provides automatic lifetime management of dynamically allocated objects.  
  - Prevents memory leaks and removes the need for manual `delete`.
    
- **`std::stack<int>` and `std::stack<char>`**  
  - Used in `MathCenter` to correctly handle operator precedence and expression evaluation.
    
- **Binary tree (`LogicNode`)**  
  - Represents logical expressions as interconnected nodes.  
  - Allows recursive evaluation of expressions like `AND`, `OR`, `NOT`.  

- **OOP (inheritance and polymorphism)**  
  - All centers inherit from `BaseCenter`.  
  - Polymorphism allows calling the `process` method regardless of the specific center type.




