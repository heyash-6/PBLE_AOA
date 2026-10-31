# Smart Delivery Planning – Fractional Knapsack

A menu-driven C program implementing the **Fractional Knapsack Problem using the Greedy Algorithm** to maximize the total value of packages within a vehicle's limited carrying capacity.

This project is developed as part of the **Analysis of Algorithms (AOA) – Problem-Based Learning Experiment (PBLE)**.

## Problem Statement

A delivery company has a vehicle with a fixed carrying capacity and several packages, each having a specific weight and value. The objective is to maximize the total value of packages carried without exceeding the vehicle's capacity.

The Fractional Knapsack algorithm allows selecting complete packages as well as fractions of packages whenever required.

## Objectives

- Understand and implement the Greedy Method.
- Calculate the Value-to-Weight ratio of each package.
- Sort packages in decreasing order of their ratios.
- Select complete packages whenever possible.
- Select fractions of packages when necessary.
- Calculate the maximum achievable value.
- Analyze the time complexity of the algorithm.

## Algorithm Used

**Fractional Knapsack – Greedy Algorithm**

1. Accept the number of packages, their values, weights, and vehicle capacity.
2. Calculate the Value-to-Weight ratio of each package.

   `Ratio = Package Value / Package Weight`

3. Sort packages in decreasing order of their ratios.
4. Select the package with the highest ratio first.
5. Select complete packages whenever they fit.
6. If a package cannot fit completely, select the fraction that fits into the remaining capacity.
7. Calculate and display the maximum value and total weight used.

## Features

- Menu-driven interface.
- Enter and display package details.
- Calculate Value-to-Weight ratios.
- Sort packages based on their ratios.
- Find maximum achievable value.
- Display selected packages and their fractions.
- Display total weight used and maximum value.
- Handle invalid menu choices.

## Technologies Used

- **Language:** C
- **Compiler:** GCC
- **IDE:** Visual Studio Code
- **Concepts:** Greedy Algorithm, Fractional Knapsack, Bubble Sort, Arrays, Structures and Functions.

## Menu Options

| Option | Description |
|:---:|---|
| 1 | Enter Package Details |
| 2 | Display Package Details |
| 3 | Calculate Value/Weight Ratio |
| 4 | Sort Packages by Ratio |
| 5 | Find Maximum Value |
| 6 | Display Selected Packages |
| 7 | Exit |

## How to Run

### Prerequisites

- GCC Compiler
- Visual Studio Code (or any C-compatible IDE)

### Execution Steps

**1. Clone the repository**

```bash
git clone <your-repository-url>
```

**2. Navigate to the project folder**

```bash
cd <project-folder>
```

**3. Compile the program**

```bash
gcc pble.c -o pble.exe
```

**4. Run the executable (Windows)**

```powershell
.\pble.exe
```

## Sample Test Case

**Input:**

| Package | Value | Weight |
|:---:|---:|---:|
| 1 | 40 | 5 |
| 2 | 30 | 10 |
| 3 | 50 | 5 |
| 4 | 20 | 4 |

**Vehicle Capacity:** 15

**Sorted Package Order:** 3 → 1 → 4 → 2

**Output:**

| Package | Weight Selected | Value Obtained |
|:---:|---:|---:|
| 3 | 5 | 50 |
| 1 | 5 | 40 |
| 4 | 4 | 20 |
| 2 | 1 | 3 |

**Maximum Value Obtained:** 113

**Total Weight Used:** 15

## Time Complexity Analysis

| Operation | Time Complexity |
|---|---|
| Calculate Ratios | O(n) |
| Sort Packages using Bubble Sort | O(n²) |
| Select Packages | O(n) |
| **Overall Time Complexity** | **O(n²)** |

**Space Complexity:** O(n), for storing package details and selection results.

The overall time complexity is O(n²) because Bubble Sort dominates the execution time.

## AOA Concepts Covered

- Greedy Method
- Fractional Knapsack Problem
- Ratio-Based Selection
- Bubble Sort
- Time Complexity Analysis
- Space Complexity Analysis

## Conclusion

The Fractional Knapsack problem was successfully implemented using the Greedy Algorithm in C. The program selects packages based on their Value-to-Weight ratios and maximizes the total value without exceeding the vehicle's carrying capacity.

This experiment demonstrates the practical application of the Greedy Method in resource allocation and delivery planning.

---

**Subject:** Analysis of Algorithms (AOA)  
**Experiment:** Problem-Based Learning Experiment (PBLE)  
**Topic:** Smart Delivery Planning – Fractional Knapsack
