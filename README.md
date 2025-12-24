<link rel="stylesheet" href="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/devicon.min.css">

# `linear-regression-using-c`

A minimal, lightweight implementation of simple linear regression using `C`, built from scratch using only the `C` standard library.

---

## 🐙 About

`linear-regression-using-c` is a minimal, terminal-based implementation written in `C` for performing simple linear regression and basic statistical analysis on numerical datasets.

It computes `mean`, `variance`, `covariance`, `correlation coefficient`, `regression equations` and some other statistical parameters with proper precision `(1e-4)`, edge cases, and `NaN` values.

---

## 🛸 Features

- 📈 Computes `mean`, `variance`, `standard deviation`

- 📉 Computes `Covariance` and `Pearson Correlation Coefficient`

- 📊 Performs simple linear regression

- 〰️ Regression of `[y on x]` and `[x on y]`

- ℞ Predicts values using regression equations

- ⚠️ Handles edge cases (`NaN`, `zero variance`, `invalid inputs`)

- ↑ Focus on numerical precision and floating-point safety

- Displays the `Regression Equations` and computed `Statistical Parameters` in a formatted tabular manner

---

## 🏗️ Tools & Tech Used

<p align="left">
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/c/c-original.svg" width="60" alt="C++" /><img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/gcc/gcc-original.svg" width="60" alt="gcc" />
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/bash/bash-original.svg" width="60" alt="Bash" />
<img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/vscode/vscode-original.svg" width="60" alt="VS Code" /><img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/git/git-original.svg" width="60" alt="Git" /><img src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/github/github-original.svg" width="60" alt="GitHub" /></p>

---

## ⚙️ Project Requirements

- `C` Compiler

  - `gcc` (`C99` or later recommended)
  - `clang` (`C99` compatible)

- Build Tools

  - `make`

- Libraries

  - Standard `C` Library only (`stdio.h`, `stdlib.h`, `math.h`, etc.)
  - No third-party dependencies

- Terminal
  - ANSI-compatible terminal (for I/O and colored CLI output)

---

## 🛠️ Project Setup

### 1. Navigate To The Directory Where You Want To Clone The Project Repository (example: `Desktop`)

```bash
cd ~/Desktop
```

### 2. Clone the Project Repository

```bash
git clone https://github.com/manakcodes/linear-regression-using-c.git
```

### 3. Navigate To The Project Repository

```bash
cd path-to/linear-regression-using-c/
```

### 4. Run the following command (to build the project)

```bash
make
```

### 5. Run the following command (to run the project)

```bash
make ./Main
```

### 6. After Using The Project Run The Following Command (to clean build artifacts)

```bash
make clean
```

---

## 🧪 To run the Tests run the following command

```
make test
```

```
./Test
```

---

## 🌲 Project Tree

```
..
├── linreg.h
├── Main.c
├── Makefile
├── README.md    <- you are here :)
├── src
│   ├── core.h
│   ├── io.h
│   └── utility.h
└── Test.c

2 directories, 8 files
```

---

## 🪪 LICENSE

This project is licensed under [MIT License](https://github.com/manakcodes/linear-regression-using-c/blob/f15df6c99088e55cec20b675505d6670d3b827e6/LICENSE).

---
