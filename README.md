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
### Same Image Explained More

The following images explain the steps of simulating Unix pipe functionality in the Pipex project. Each image represents a different part of the process or simulation.

1. **First Image: `dup()` - File Descriptor Duplication**  
   This image shows how the `dup()` system call is used to duplicate file descriptors in the Unix process. It's a critical part of redirecting input/output streams in the Pipex project.

   ![dup() - File Descriptor Duplication](https://media.discordapp.net/attachments/1330877911925919774/1336285066049097771/dup.png?ex=67a33ff2&is=67a1ee72&hm=3cbd6f17a742bef4968d8a77d627dc75456b07f136c7b034ffc16f69fd89b980&=&format=webp&quality=lossless)

2. **Second Image: Pipe with Multiple Commands**  
   This image demonstrates how multiple commands are piped together in the Pipex simulation. Each command takes the output from the previous command as its input.

   ![Multiple Commands Pipe](https://media.discordapp.net/attachments/1330877911925919774/1336285066346762311/pipe3.png?ex=67a33ff2&is=67a1ee72&hm=57b1ed4f83f0a78315064506580e26705bc7b59ce53b56006de32eddf2c89ed1&=&format=webp&quality=lossless)

3. **Third Image: Simple Forking**  
   The forking process is visualized in this diagram. It shows how a process is forked to create a new child process that will run the given commands.

   ![Simple Forking](https://media.discordapp.net/attachments/1330877911925919774/1336285066866724934/simple_fork.png?ex=67a33ff2&is=67a1ee72&hm=1a3ecd9a9bd93222aa9889c914698bd6b62e4eddebb3d6c483a942ff3862408e&=&format=webp&quality=lossless&width=866&height=565)

4. **Fourth Image: Pipe with Two Commands**  
   This image visualizes a pipe that connects two processes, showing how the output of the first command is passed as input to the second command.

   ![Pipe with Two Commands](https://media.discordapp.net/attachments/1330877911925919774/1336285066611134548/pipe_with_two-2.png?ex=67a33ff2&is=67a1ee72&hm=3cfe3e4187f2c31f5479255d3a35a9aeb747a8a5f727355e3958908f01c23940&=&format=webp&quality=lossless)
