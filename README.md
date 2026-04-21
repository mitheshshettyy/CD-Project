# 🔧 Lex & YACC Based GCD Parser

## 📌 Project Overview

This project implements a **GCD (Greatest Common Divisor) computation system** using **Lex and YACC**.
It parses a simplified C-like syntax and computes the GCD of two numbers using the **Euclidean Algorithm**.

---

## 🎯 Objectives

* Design a grammar for a structured programming language subset
* Implement lexical analysis using **Lex**
* Perform syntax analysis using **YACC**
* Generate and display a **Parsing Table**
* Compute GCD using parsed input

---

## 🧠 Technologies Used

* C Programming
* Lex (Flex)
* YACC (Bison)
* Ubuntu / Linux Terminal

---

## 📂 Project Structure

```
CD-Project/
├── lex.l                  # Lex file (token definitions)
├── yacc.y                 # YACC file (grammar rules)
├── table.c                # Parsing table generator
├── parsing_table.txt      # Output parsing table
├── input.txt              # Sample input
├── README.md              # Project documentation
├── yacc.output            # YACC state details (optional)
```

---

## ⚙️ How to Run

### 1️⃣ Compile Lex and YACC

```bash
lex lex.l
yacc -d yacc.y
gcc lex.yy.c y.tab.c -o parser
```

### 2️⃣ Run Parser

```bash
./parser < input.txt
```

### 3️⃣ Generate Parsing Table

```bash
gcc table.c -o table
./table > parsing_table.txt
```

---

## 📊 Parsing Table

* The parsing table consists of:

  * **ACTION** (shift, reduce, accept)
  * **GOTO** (state transitions)
* A simplified version is included in `parsing_table.txt`

---
