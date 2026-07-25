# OS-TEP

> Implementing the concepts from **Operating Systems: Three Easy Pieces (OSTEP)** from first principles using C.

## Overview

This repository documents my journey through **Operating Systems: Three Easy Pieces (OSTEP)** by building simplified versions of the core mechanisms used in modern operating systems.
The objective is **not** to build a production operating system or a Linux clone. Instead, each implementation focuses on understanding *why* operating systems work the way they do by recreating individual concepts from scratch.
Every topic is implemented independently, documented thoroughly, and accompanied by notes explaining the design decisions, limitations, and connections to real-world operating systems.

---

## Goals

- Understand operating systems beyond textbook definitions.
- Learn systems programming using C.
- Implement core operating system mechanisms from scratch.
- Build intuition for how Linux and other modern operating systems work internally.
- Document the learning process for future reference.

---

---

# Learning Roadmap

## Part I — Virtualization

- [ ] Process API
- [ ] Process Control Block (PCB)
- [ ] Context Switching
- [ ] CPU Scheduling
- [ ] Process Address Space
- [ ] Segmentation
- [ ] Paging
- [ ] Multi-Level Page Tables
- [ ] Translation Lookaside Buffer (TLB)
- [ ] Swapping
- [ ] Virtual Memory Simulator

---

## Part II — Concurrency

- [ ] Threads
- [ ] Thread API
- [ ] Mutexes
- [ ] Spinlocks
- [ ] Semaphores
- [ ] Condition Variables
- [ ] Producer–Consumer Problem
- [ ] Readers–Writers Problem
- [ ] Dining Philosophers
- [ ] Deadlocks
- [ ] Lock-Free Programming

---

## Part III — Persistence

- [ ] Disk Abstraction
- [ ] File System Layout
- [ ] Inodes
- [ ] Directory Structure
- [ ] Free Space Management
- [ ] File Allocation
- [ ] Journaling
- [ ] Crash Recovery
- [ ] Log Structured File Systems
- [ ] RAID

---

# Project Philosophy

Each implementation aims to answer four questions:

1. What problem exists?
2. Why is this mechanism needed?
3. How does the implementation work?
4. How do real operating systems solve the same problem?

---

# Technologies

- **Language:** C (C17)
- **Compiler:** GCC / Clang
- **Platform:** Linux
- **Debugger:** GDB
- **Memory Analysis:** Valgrind
- **Build System:** Make

---


# Learning Resources

- Operating Systems: Three Easy Pieces
- Linux Manual Pages
- POSIX Documentation
- The Linux Programming Interface

---
