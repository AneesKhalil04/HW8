# HW8
Name: Anees Khalil

Affiliation: University of Maryland, Baltimore County (UMBC)

Course: CMSC 313 — Computer Organization and Assembly Language

Date: 4/19/25
This project was made by Anees Khalil for CMSC 313 at UMBC during Spring 2025. The goal was to build a small matrix library in both C and C++ that could do basic math like adding matrices, multiplying by a number, transposing, and multiplying two matrices together. The code is set up to solve the equation:
D = A + (3 × B) × Cᵗ

There are a few files included. MatrixLibrary.cpp is the main C++ file that holds the Matrix class and main(). Matrix.h is the header file for the class. On the C side, there’s matrix_lib.c which has all the functions and main(), and matrix.h which has the function declarations. There’s also a Makefile so it’s easy to compile and run everything with just a couple commands.

To build the programs, just run make. You can run the C++ version with make run_cpp and the C version with make run_c. To clean up the compiled files, just use make clean.

To test everything, we used some preset values in the matrices and printed the result after running the equation. All the operations are separated into functions or class methods, so you could swap out the values or change the size of the matrices if needed. The code is written so it's easy to read, and ready for testing however needed.

The snippet of the code being ran and tested is attached in this README and in the reprository.
<img width="316" alt="image" src="https://github.com/user-attachments/assets/3753c69c-934f-40a4-9208-ada13a873d9d" />

