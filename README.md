# Pipex

**42 Project**: Pipex - A simulation of the Unix pipe functionality to enable communication between processes.

## Project Overview

The **Pipex** project consists of building a program that simulates the behavior of the `pipe` system call in Unix-like systems. The objective is to create a pipeline of commands, where the output of one command is passed as the input to the next, much like how the Unix shell handles pipes (`|`).

The project focuses on:
- **Forking processes**: Understanding how to create new processes.
- **Redirection**: Redirecting the output and input of processes.
- **Pipes**: Implementing inter-process communication using pipes.
- **Error handling**: Managing edge cases and errors efficiently.

## Features

- **Simulate Unix Pipe**: Use `pipe`, `fork`, and `dup2` to simulate inter-process communication.
- **Handle Multiple Commands**: Handle any number of commands passed via the command line.
- **Error Handling**: Gracefully handle errors like invalid arguments, missing files, or failed system calls.
- **Supports Redirection**: Handle standard input/output redirection for each process.

### Example Usage:

##### usage
    $ ./pipex infile "command1" "command2" outfile


