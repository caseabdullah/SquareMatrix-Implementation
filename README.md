# 🔢 Square Matrix Class Using Matrix Class | C++

### 📌 About the Project

This project implements a **Square Matrix Class (SMatrix) using an existing Matrix Class** in C++, applying Object-Oriented Programming (OOP) concepts, particularly composition and code reusability.

The `SMatrix` class acts as a wrapper around the existing `Matrix` class, providing functionality specifically designed for square matrices.

Instead of specifying rows and columns separately, a square matrix is created using a single order parameter (N × N).

The project reuses existing Matrix operations and extends them to support square matrix-specific functionality without duplicating the original implementation.

### 🛠️ Technologies & Concepts

- **Language:** C++
- **OOP Concepts:**
  - Classes and Objects
  - Encapsulation
  - Composition (Has-A Relationship)
  - Wrapper Class
  - Code Reusability
  - Constructor Overloading
  - Copy Constructor
  - Constructor Delegation
  - Destructors
  - Const Correctness

### ⚙️ Implemented Features

**1. Square Matrix Management**

- Create square matrices using a single order parameter (N × N).
- Access and modify matrix elements.
- Display square matrix elements.
- Convert an existing square `Matrix` into an `SMatrix`.
- Extract square submatrices using slicing.

**2. Basic Matrix Operations**

- **Addition:** Adds two square matrices.
- **Subtraction:** Subtracts one square matrix from another.
- **Multiplication:** Performs square matrix multiplication.
- **Transpose:** Calculates the transpose of a square matrix.

**3. Matrix Analysis & Properties**

- **Trace:** Calculates the sum of the main diagonal elements.
- **Anti-Trace:** Calculates the sum of the secondary diagonal elements.
- **Symmetry Checking:** Checks whether a matrix is symmetric or skew-symmetric.
- **Equality Checking:** Compares two square matrices.
- **Identity Checking:** Determines whether a matrix is an identity matrix.
- **Triangular Checking:** Checks lower, upper, and general triangular matrices.
- **Minor:** Extracts the minor of a specified element.
- **Slice:** Extracts a submatrix while maintaining square matrix dimensions.

**4. Code Reusability**

- **Matrix Reuse:** Utilizes the existing `Matrix` class functionality.
- **Wrapper Class:** Provides a simplified interface specifically for square matrices.
- **Composition:** Maintains a `Matrix` object as a private data member.
- **No Duplication:** Reuses existing Matrix operations instead of implementing them again.
- **Validation:** Ensures that converted and sliced matrices satisfy square matrix requirements.

### 🧠 Key Learning Outcomes

- Understanding composition through a Matrix object inside the SMatrix class.
- Implementing wrapper classes in C++.
- Reusing existing class functionality without modifying its implementation.
- Understanding constructor delegation and copy construction.
- Applying encapsulation and const correctness.
- Implementing matrix operations through composition.
- Practicing object-oriented design and code reusability.

### 👨‍💻 Developed By

**Abdullah**  
Software Engineering Student  
Punjab University – FCIT

**Code. Learn. Build. Repeat.** 🚀