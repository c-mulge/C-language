#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// #include <sys/wait.h>

#define MAX_CMD_LEN 1024
#define MAX_ARG_COUNT 100

// Function to print the first n lines of a file
void print_first_n_lines(char *filename, int n)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    char line[MAX_CMD_LEN];
    int count = 0;
    while (fgets(line, sizeof(line), file) != NULL && count < n)
    {
        printf("%s", line);
        count++;
    }

    fclose(file);
}

// Function to print all lines of a file
void print_all_lines(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    char line[MAX_CMD_LEN];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    fclose(file);
}

// Function to handle the custom command "typeline"
void handle_typeline(char *args[])
{
    if (args[1] == NULL || args[2] == NULL)
    {
        printf("Usage: typeline +n filename or typeline -a filename\n");
        return;
    }

    if (args[1][0] == '+')
    {
        // +n option to print first n lines
        int n = atoi(args[1] + 1);
        print_first_n_lines(args[2], n);
    }
    else if (strcmp(args[1], "-a") == 0)
    {
        // -a option to print all lines
        print_all_lines(args[2]);
    }
    else
    {
        printf("Invalid typeline option\n");
    }
}

int main()
{
    char cmd[MAX_CMD_LEN];     // Command input buffer
    char *args[MAX_ARG_COUNT]; // Array to hold arguments
    char *token;               // For tokenizing input
    pid_t pid;                 // Process ID for fork()

    while (1)
    {
        printf("myshell$ ");            // Command prompt
        fgets(cmd, sizeof(cmd), stdin); // Read input from user

        // Remove newline character from input
        if ((token = strchr(cmd, '\n')) != NULL)
        {
            *token = '\0';
        }

        // Tokenize the input command
        int i = 0;
        token = strtok(cmd, " ");
        while (token != NULL)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL; // Null-terminate the argument list

        // If command is "exit", break the loop and exit the shell
        if (args[0] == NULL)
        {
            continue; // Empty command
        }

        if (strcmp(args[0], "exit") == 0)
        {
            break;
        }

        // Handle the custom command "typeline"
        if (strcmp(args[0], "typeline") == 0)
        {
            handle_typeline(args);
            continue; // Skip to the next iteration without forking
        }

        // Fork a child process to execute other commands
        pid = fork();
        if (pid < 0)
        {
            perror("Fork failed");
            exit(1);
        }

        if (pid == 0)
        {
            // Child process: Execute the command
            if (execvp(args[0], args) < 0)
            {
                perror("Error executing command");
            }
            exit(1); // Exit the child process
        }
        else
        {
            // Parent process: Wait for the child to finish
            wait(NULL);
        }
    }

    return 0;
}
