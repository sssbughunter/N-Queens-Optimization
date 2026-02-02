# N-Queens Heuristic Optimization (CSP)

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Status: Benchmarked](https://img.shields.io/badge/Status-Benchmarked-green.svg)]()

This repository explores **Constraint Satisfaction Problems (CSP)** through a high-performance, hybrid knight-based heuristic for the $N$-Queens problem. The goal is to optimize backtracking depth and pruning efficiency in NP-hard state spaces.

## 📊 Benchmarks
* **Performance:** 9,908 distinct solutions for $N=20$ in **2.94 seconds**.
* **Methodology:** Hybrid Knight-Based Domain Reduction.
* **Comparison:** Outperforms standard Dancing Links (DLX) implementations in specific domain-reduction scenarios.

## 🧠 Theoretical Approach
Traditional solvers rely on exhaustive search. This implementation utilizes a **Knight-Move Constraint** to preemptively reduce the domain of available cells, significantly pruning the search tree before the backtracking algorithm initiates. 

This research serves as a toy model for **Heuristic Convergence** and **State-Space Pruning** in autonomous agents.

## 📄 Publications
* *Research accepted for publication at IEEE ICCA.*
