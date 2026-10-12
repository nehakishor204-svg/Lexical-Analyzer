# C Lexical Analyzer

## 📌 Project Overview

A **Lexical Analyzer implemented in C** that reads a C source file character by character, identifies lexemes, classifies tokens, and detects selected lexical errors.

The project demonstrates file handling, character processing, string manipulation, token classification, and error handling in C programming.

## ✨ Features

- **Keyword and Identifier Recognition** — Identifies C keywords and identifiers.
- **Constant Recognition** — Handles integer, decimal, hexadecimal, and scientific-notation numbers supported by the implementation.
- **Operator Recognition** — Recognizes single-character and supported multi-character operators.
- **String and Character Recognition** — Identifies string literals and character constants, including supported escape sequences.
- **Preprocessor Recognition** — Identifies preprocessor directives such as `#include` and `#define`.
- **Comment Handling** — Skips single-line (`//`) and multi-line (`/* ... */`) comments.
- **Special Character Recognition** — Identifies symbols such as `;`, `,`, `()`, `{}`, and `[]`.
- **Lexical Error Detection** — Reports selected invalid numbers, invalid character constants, unterminated strings, unterminated character constants, and unsupported characters.
- **Line Number Tracking** — Reports the source line associated with each token or error.
- **Formatted Output** — Displays recognized tokens in an aligned table.

## 🛠️ Technologies Used

- C Programming Language
- Standard C Library
- GCC Compiler
- Linux / WSL
- Visual Studio Code

## 📂 Project Structure

```text
Lexical_Analyzer/
├── main.c       # Main program and control flow
├── file.c       # File opening, reading, and closing
├── file.h       # File-handling declarations
├── lexer.c      # Lexical analysis and error detection
├── lexer.h      # Lexer function declaration
├── token.c      # Token classification and printing
├── token.h      # Token types and Token structure
├── test.c       # C source file used as lexer input
└── README.md    # Project documentation
```

## ⚙️ Compilation

Clone the repository and navigate to the project directory.

```bash
git clone https://github.com/nehakishor204-svg/Lexical-Analyzer.git
cd Lexical-Analyzer
```

Compile the lexer using GCC:

```bash
gcc -Wall -Wextra main.c file.c lexer.c token.c -o lexer
```

## ▶️ Execution

Run the compiled program:

```bash
./lexer
```

The program reads the configured input file, `test.c`, and displays the recognized tokens and lexical errors.

**Note:** `test.c` is the input source file being analyzed. Do not include it in the lexer compilation command because it may contain its own `main()` function.

## 📊 Sample Output

```text
LINE   TOKEN TYPE         LEXEME
------------------------------------------------------
1      PREPROCESSOR       #include <stdio.h>
3      KEYWORD            int
3      IDENTIFIER         main
3      SPECIAL_CHAR       (
3      SPECIAL_CHAR       )
4      SPECIAL_CHAR       {
7      KEYWORD            int
7      IDENTIFIER         count
7      OPERATOR           =
7      CONSTANT           123
7      SPECIAL_CHAR       ;
```

The output includes line numbers, token types, and their corresponding lexemes. Invalid input produces lexical error messages.

## 🧪 Testing

The test input covers:

- Keywords and identifiers
- Numeric constants
- Operators and special characters
- Strings and character constants
- Escape sequences
- Preprocessor directives
- Single-line and multi-line comments
- Invalid numeric formats
- Invalid character constants
- Unterminated strings and character constants
- Line number tracking

## 🎯 Learning Outcomes

- Understanding the role of lexical analysis in a compiler.
- Processing source code character by character.
- Distinguishing lexemes and token categories.
- Working with file handling and string operations in C.
- Implementing basic lexical error detection.
- Organizing a C project using source and header files.

## 🚀 Future Improvements

- Expand support for C numeric formats and operators.
- Improve handling of escape sequences and malformed literals.
- Add token storage and symbol-table support.
- Integrate a syntax analyzer as a separate module.

## 👩‍💻 Author

**Neha Kishor**

Developed as a C programming project to explore lexical analysis and compiler fundamentals.
