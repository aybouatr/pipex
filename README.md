-----------------------------------------------------------------> PIPEX <-----------------------------------------------------------------------------------                                                                                                                    

1. open ---> : Opens a file to read from, write to, or both. It returns a file descriptor that you can use to access the file.
2. _______ . Example: open("file.txt", O_RDONLY);
3. close ---> : Closes an open file descriptor, freeing up the system resources associated with it
4. _______ . Example: close(fd);
5. 
1. open

    Definition: Opens a file to read from, write to, or both. It returns a file descriptor that you can use to access the file.
    Example: open("file.txt", O_RDONLY);

2. close

    Definition: Closes an open file descriptor, freeing up the system resources associated with it.
    Example: close(fd);

3. read

    Definition: Reads data from a file descriptor into a buffer.
    Example: read(fd, buffer, size);

4. write

    Definition: Writes data from a buffer to a file descriptor.
    Example: write(fd, buffer, size);

5. malloc

    Definition: Allocates a block of memory of a specified size and returns a pointer to it. It is used to dynamically allocate memory in C.
    Example: char *ptr = malloc(100);

6. free

    Definition: Frees a previously allocated block of memory (using malloc or calloc) to make it available for reuse.
    Example: free(ptr);

7. perror

    Definition: Prints a description of the last error that occurred in the program (using errno).
    Example: perror("Error message");

8. strerror

    Definition: Returns a pointer to a string that describes the error code stored in errno.
    Example: printf("%s\n", strerror(errno));

9. access

    Definition: Checks whether a file exists and whether the calling process has permission to read, write, or execute it.
    Example: access("file.txt", F_OK);

10. dup

    Definition: Duplicates an existing file descriptor and returns a new one. This new descriptor refers to the same file or resource.
    Example: int new_fd = dup(fd);

11. dup2

    Definition: Similar to dup(), but you can specify the exact number for the new file descriptor.
    Example: dup2(fd, new_fd);

12. execve

    Definition: Replaces the current process with a new program. It loads a program into the current process’s memory.
    Example: execve("/bin/ls", args, env);

13. exit

    Definition: Terminates the current process and returns a status code to the parent process.
    Example: exit(0);

14. fork

    Definition: Creates a new child process that is a copy of the parent process. It returns 0 to the child and the child’s process ID to the parent.
    Example: pid_t pid = fork();

15. pipe

    Definition: Creates a pair of file descriptors that can be used for inter-process communication (IPC). One file descriptor is for reading, the other for writing.
    Example: pipe(fd);

16. unlink

    Definition: Removes a file from the filesystem. It deletes the file, but the file is not actually removed until all processes stop using it.
    Example: unlink("file.txt");

17. wait

    Definition: Makes the parent process wait for any of its child processes to finish. It returns the process ID of the terminated child.
    Example: wait(NULL);

18. waitpid

    Definition: Similar to wait(), but allows the parent to wait for a specific child process to terminate by providing the child’s process ID.
    Example: waitpid(pid, &status, 0);
