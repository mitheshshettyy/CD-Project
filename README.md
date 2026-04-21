# 🔍 Lex & Yacc Based GCD Parser

## 📌 Project Overview

This project demonstrates the implementation of a parser using **Lex and Yacc** to compute the **Greatest Common Divisor (GCD)** of given inputs.

It showcases fundamental concepts of:

* Compiler Design
* Lexical Analysis
* Syntax Parsing

---

## ⚙️ Technologies Used

* C Programming
* Lex (Flex)
* Yacc (Bison)
* GCC Compiler

---

## 📂 Project Structure

```
CD-Project/
│── gcd.l        # Lex file (tokenizer)
│── gcd.y        # Yacc file (parser)
│── table.c      # Supporting C code
│── grammar.txt  # Grammar rules
│── input.txt    # Sample input
│── README.md    # Project documentation
```

---

## 🚀 How to Run

### 1️⃣ Compile the Lex file

```
lex gcd.l
```

### 2️⃣ Compile the Yacc file

```
yacc -d gcd.y
```

### 3️⃣ Compile using GCC

```
gcc lex.yy.c y.tab.c -o gcd
```

### 4️⃣ Run the program

```
./gcd < input.txt
```

---

## 🧠 Working

* Lex analyzes input and generates tokens
* Yacc parses tokens using grammar rules
* The program computes the **GCD** based on parsed input

---
