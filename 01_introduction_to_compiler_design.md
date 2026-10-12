
# Lesson 01: Introduction to Compiler Design

**Subject:** Compiler Design
**Phase:** Compiler Design Fundamentals
**Lesson:** 01
**Level:** Beginner

---

## Learning Objectives

After completing this lesson, students will be able to:

- Define Programming Language and Compiler.
- Explain why a Compiler is needed.
- Differentiate between Source Code, Object Code, and Executable Code.
- Describe the basic compilation process.
- Distinguish between Compiler, Interpreter, and Assembler.
- Define Compiler Design.
- Identify the basic categories of programming errors.

---

## 1. Introduction

A computer program is a set of instructions that tells a computer
what tasks to perform.

Programmers usually write programs using high-level programming
languages such as C, C++, Java, and others.

However, a processor executes instructions defined by its
Instruction Set Architecture (ISA). High-level source code
normally needs to be translated or processed before execution.

A Compiler is one of the important tools used for this purpose.

### Example

```c
#include <stdio.h>

int main(void) {
    printf("Hello, World!");
    return 0;
}
```

This is a C program that prints:

```text
Hello, World!
```

A typical C compiler toolchain translates the program into
code suitable for the target platform.

---

## 2. Programming Language

A Programming Language is a formal language used to express
instructions, computations, and data-processing operations.

### 2.1 High-Level Language

High-level languages provide abstractions that make programming
easier for humans.

Example:

```c
int a = 10;
int b = 20;
int sum = a + b;
```

### 2.2 Assembly Language

Assembly Language represents processor instructions using
human-readable mnemonics.

Illustrative example:

```asm
ADD R1, R2, R3
```

The exact instruction syntax depends on the processor architecture.

### 2.3 Machine Language

Machine Language consists of instructions encoded according to
a processor's Instruction Set Architecture.

Machine instructions are commonly represented using binary digits,
but their bit patterns have specific meanings and encodings.

---

## 3. What Is a Compiler?

**Definition:**

A Compiler is system software that translates a program written
in a source language into an equivalent program in a target
language, while detecting and reporting errors where applicable.

### Basic Translation Model

```text
Source Program
      |
      v
   Compiler
      |
      v
Target Program
```

The target may be machine code, assembly code, or an intermediate
representation, depending on the compiler and its configuration.

### Why Is a Compiler Needed?

1. To translate source programs into target code.
2. To detect and report many programming errors.
3. To optimize code when appropriate.
4. To generate code for a target architecture.
5. To support the implementation of programming languages.

---

## 4. Real-Life Analogy: A Translator

Imagine that a person writes instructions in Bengali, but the
recipient understands only Japanese.

A translator converts the instructions into a language that
the recipient understands.

| Real-Life Concept | Compiler Design Concept |
|---|---|
| Original Bengali instructions | Source Code |
| Translator | Compiler |
| Translated instructions | Target Code |
| Language rules | Syntax and Semantics |

**Key Idea:** A Compiler translates a program from one language
into another according to defined language rules.

Note that a programming language compiler follows formal
translation rules, unlike a human translator who may interpret
natural language more flexibly.

---

## 5. Basic Compilation Process

Consider this C statement:

```c
int result = 10 + 20 * 3;
```

A compiler commonly performs several kinds of analysis and
transformation.

### 5.1 Lexical Analysis

The source characters are grouped into tokens.

Example tokens:

```text
int
result
=
10
+
20
*
3
;
```

### 5.2 Syntax Analysis

The compiler checks whether the tokens follow the grammar
of the programming language.

Operator precedence is also important when constructing the
expression's structure.

### 5.3 Semantic Analysis

The compiler checks semantic rules, including declarations,
types, and other language-specific constraints.

### 5.4 Intermediate Code Generation

The compiler may transform the program into an intermediate
representation (IR).

### 5.5 Code Optimization

The compiler may apply transformations intended to improve
execution time, code size, or other relevant properties.

### 5.6 Target Code Generation

The compiler generates code suitable for the target platform.

### Simplified Pipeline

```text
Source Code
    |
    v
Lexical Analysis
    |
    v
Syntax Analysis
    |
    v
Semantic Analysis
    |
    v
Intermediate Code Generation
    |
    v
Code Optimization
    |
    v
Target Code Generation
```

Real compilers may organize, combine, or repeat some of these
activities. Supporting data structures and error-handling
mechanisms are also important.

---

## 6. Operator Precedence Example

Consider:

```c
int result = 10 + 20 * 3;
```

Multiplication has higher precedence than addition.

Therefore:

```text
10 + 20 * 3
= 10 + (20 * 3)
= 10 + 60
= 70
```

The resulting value is:

```text
result = 70
```

This example demonstrates why a compiler must correctly analyze
the structure of expressions.

---

## 7. Source Code, Object Code, and Executable Code

### 7.1 Source Code

The original program written by a programmer.

Example:

```text
main.c
```

### 7.2 Object Code

Object code contains machine instructions and related information
in an object-file format. Object files often contain relocatable
code and unresolved external references.

Examples:

```text
main.o
main.obj
```

### 7.3 Executable Code

An executable is a program file prepared for execution under
the target platform's rules.

Example on Windows:

```text
app.exe
```

### Typical C Build Process

```text
main.c
   |
   v
Preprocessing
   |
   v
Compilation
   |
   v
Assembly
   |
   v
Object File
   |
   v
Linking
   |
   v
Executable
   |
   v
Execution
```

The exact process depends on the toolchain. A compiler driver
may coordinate several of these stages automatically.

---

## 8. Compiler vs. Interpreter vs. Assembler

### 8.1 Compiler

A Compiler translates a source program into a target program.

Example: GCC can compile C source code into object files or
an executable through its toolchain.

### 8.2 Interpreter

An Interpreter executes a program by processing its instructions
or an intermediate representation during execution.

Example: CPython commonly compiles Python source into bytecode
and executes that bytecode using its runtime interpreter.

### 8.3 Assembler

An Assembler translates assembly-language instructions into
machine code or object code for a target architecture.

### Comparison Table

| Feature | Compiler | Interpreter | Assembler |
|---|---|---|---|
| Main purpose | Translate source programs | Execute programs | Translate assembly |
| Input | Source language | Program or representation | Assembly language |
| Output/Result | Target code | Program execution | Machine/object code |
| Example | GCC | CPython runtime | NASM |

**Important:** Modern language implementations may combine
compilation and interpretation. The distinction is not simply
that a compiler always processes the whole program while an
interpreter always processes one line at a time.

---

## 9. What Is Compiler Design?

**Exam-Ready Definition:**

Compiler Design is the study of the principles, algorithms, and
techniques used to design and implement compilers that translate
source programs into equivalent target programs while handling
errors and, where appropriate, optimizing generated code.

### Major Areas of Compiler Design

1. Lexical Analysis
2. Syntax Analysis
3. Semantic Analysis
4. Intermediate Code Generation
5. Code Optimization
6. Target Code Generation
7. Symbol Table Management
8. Error Detection and Recovery
9. Runtime Environment

### Why Study Compiler Design?

- To understand how programming languages are implemented.
- To understand the structure and processing of source programs.
- To learn formal grammars and parsing algorithms.
- To understand code generation and optimization.
- To develop tools such as compilers, interpreters, and analyzers.

---

## 10. Basic Categories of Errors

### 10.1 Lexical Error

An error caused by input that cannot be recognized as a valid
token according to the language's lexical rules.

### 10.2 Syntax Error

An error caused by a token sequence that violates the grammar.

Example:

```c
int x = ;
```

### 10.3 Semantic Error

An error involving the meaning of a program or a violation
of semantic rules, such as an invalid type operation.

### 10.4 Runtime Error

An error that occurs during program execution.

Example: An operation attempts to divide by zero.

Not every runtime error can be detected by a compiler before
the program executes.

---

## 11. Important Terms

| Term | Meaning |
|---|---|
| Programming Language | A language used to express computer programs |
| Compiler | Software that translates source programs |
| Source Code | Original program written by a programmer |
| Target Code | Code produced by a translation process |
| Machine Language | Instructions encoded for a processor ISA |
| Assembly Language | Human-readable representation of machine instructions |
| Object File | A file containing object code and related information |
| Executable | A program file prepared for execution |
| Interpreter | Software that processes and executes a program |
| Assembler | Software that translates assembly instructions |
| Compiler Design | The study of compiler construction principles and techniques |

---

## 12. Quick Revision

- A Compiler translates a source program into a target program.
- Processors execute instructions defined by their ISA.
- High-level programs commonly require translation before execution.
- Source code is the original program.
- Object files commonly contain relocatable machine code and metadata.
- Linking combines object files and required libraries or components.
- Lexical Analysis identifies tokens.
- Syntax Analysis checks grammatical structure.
- Semantic Analysis checks language-specific semantic rules.
- Optimization attempts to improve selected code properties.
- Target Code Generation produces code for the target platform.
- Compiler Design studies how compilers are designed and implemented.

---

## 13. Practice Questions

### Short Questions

1. What is a Compiler?
2. Why is a Compiler needed?
3. Define Compiler Design.
4. What is Source Code?
5. What is Machine Language?
6. What is an Assembler?
7. What is an Interpreter?
8. What is the purpose of Code Optimization?

### Descriptive Questions

1. Explain the basic compilation process with a diagram.
2. Differentiate between Compiler, Interpreter, and Assembler.
3. Explain the difference between Source Code, Object Code,
   and Executable Code.
4. Describe the major activities performed by a compiler.
5. Explain the role of Compiler Design in programming language
   implementation.

### Problem-Solving Practice

For the following expression, determine the final value
according to normal arithmetic precedence:

```c
int result = 5 + 4 * 2;
```

Also identify the operators and operands.

---

## 14. Self-Assessment Checklist

After studying this lesson, verify that you can:

- [ ] Define a Compiler in your own words.
- [ ] Explain why source code requires translation.
- [ ] Distinguish between high-level, assembly, and machine language.
- [ ] Explain the basic compilation pipeline.
- [ ] Differentiate Compiler, Interpreter, and Assembler.
- [ ] Distinguish Source Code, Object Code, and Executable Code.
- [ ] Explain the purpose of Compiler Design.
- [ ] Solve a simple expression using operator precedence.

---

## Conclusion

Compiler Design explains how source programs are analyzed,
translated, and transformed into target representations.

This lesson introduced the fundamental concepts required to
understand the internal structure of a compiler.

In the next lesson, we will study Compiler, Interpreter,
and Assembler in greater detail, including their execution
models, advantages, limitations, and examples.
