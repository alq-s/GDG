# GDG (Generic Dataset Generator) v0.1

> **NOTE:** GDG v0.1 is a pre-release. Expect bugs and issues. This is **not** considered a production-ready tool yet.

---

## Overview

GDG (Generic Dataset Generator) is an open-source C library designed to **automatically generate datasets**. It can produce datasets containing thousands to millions of values in a matter of milliseconds to seconds.  

GDG v0.1 is written entirely in C and aims to simplify the process of creating structured datasets, whether numeric, categorical, or custom-defined, without requiring manual data entry.

---

## Features

- Generate numeric datasets in **columnar format** with customizable formulas.  
- Generate **categorical datasets** with labeled values.  
- Minimal dependencies: only requires `<stdio.h>`.  
- Can be integrated into user programs for **dynamic dataset generation**.  
- Flexible enough to be used creatively for **live dashboards or ASCII-based visualizations**.  
- Users can define their own custom **generate functions** to extend GDG functionality.

---

## Installation (Linux)

Clone the repository and run the installer:

```bash
git clone https://github.com/alq-s/GDG.git
cd GDG
./install.sh
```

## Usage

```c
generate_column
```

Generates a numeric dataset in column format.

**Parameters:**

- start (int): Starting value of the independent variable.
- end (int): Ending value.
- steps (int): Increment step between values.
- formula (double (*)(double)): Pointer to a function that computes the dependent value.
- first_type (char): Label for the first column.
- second_type (char): Label for the second column.

**Example:**

```c
#include <gdg.h>

double formula(double x) {
    return x * 10;
}

int main() {
    generate_column(0, 100, 5, &formula, 'I', 'N');
    return 0;
}
```
**Output:**

```bash
 I      N
0.0000 0.0000
5.0000 50.0000
10.0000 100.0000
...
100.0000 1000.0000
```
---
```c
generate_categorical
```

Generates a **categorical dataset**. Each row represents a category and its numeric value.

**Parameters:**

- categories (char[]): Array of single-character labels (e.g., 'A', 'B', 'C').
- counts (int[]): Array of integers corresponding to each category.
- num_categories (int): Number of categories in the dataset.

**Example:**

```c
#include <gdg.h>

int main() {
    char teams[3] = {'U', 'B', 'R'};
    int scores[3] = {25, 6, 20};

    generate_categorical(teams, scores, 3);
    return 0;
}
```

**Output:**

```bash
U: █████████████████████
B: ██████
R: █████████████
```

***GDG is open-source. Feel free to report bugs, suggest features, or submit pull requests on the GitHub repository:***

