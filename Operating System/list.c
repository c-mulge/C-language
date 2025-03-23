//list

//list f dir_name
//list n dir_name
//list i dir_name

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <dirent.h>
#include <unistd.h>

void list(const char *dn, char op) {
    DIR *dp = opendir(dn);
    struct dirent *entry;
    int dc = 0, fc = 0;
    if (!dp) {
        printf("Dir %s not found.\n", dn);
        return;
    }

    while ((entry = readdir(dp))) {
        if (op == 'f' && entry->d_type == DT_REG)
            printf("%s\n", entry->d_name);
        else if (op == 'n') {
            if (entry->d_type == DT_DIR) dc++;
            if (entry->d_type == DT_REG) fc++;
        } else if (op == 'i' && entry->d_type == DT_REG)
            printf("%s\t%lu\n", entry->d_name, entry->d_ino);
    }

    if (op == 'n') printf("%d Dir(s)\t%d File(s)\n", dc, fc);
    closedir(dp);
}

int main() {
    char buff[80], *tok[5];

    while (1) {
        printf("myshell$ ");
        fgets(buff, sizeof(buff), stdin);

        int n = 0;
        tok[n] = strtok(buff, " \n");
        while (tok[n] && n < 4) tok[++n] = strtok(NULL, " \n");

        if (!tok[0]) continue;
        if (strcmp(tok[0], "list") == 0 && tok[1] && tok[2])
            list(tok[2], tok[1][0]);
        else if (fork() == 0) {
            execvp(tok[0], tok);
            perror("Execution failed");
            exit(1);
        } else
            wait(NULL);
    }
}
