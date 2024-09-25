#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "../../y.tab.h" 

#define MAX_FILE_LEN 10000
#define MAX_FILES 1000

extern FILE *yyin;
extern int yyparse();
extern int yylineno;

int extract_file_num(const char *filename) {
    int num = 0;
    for (int i = 0; filename[i] != '\0'; i++) {
        if (filename[i] >= '0' && filename[i] <= '9') {
            num = num * 10 + (filename[i] - '0');
        }
    }
    return num;
}

int compare(const void *a, const void *b) {
    int num1 = extract_file_num(*(const char **)a);
    int num2 = extract_file_num(*(const char **)b);
    return num1 - num2;
}

int main() {
    DIR *dir;
    struct dirent *ent;
    const char *inputDir = "input";
    char *filenames[MAX_FILES];
    int file_count = 0;
    
    // Open input directory and read all file names
    if ((dir = opendir(inputDir)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_name[0] == '.')
                continue;
            filenames[file_count] = strdup(ent->d_name);
            file_count++;
            if (file_count >= MAX_FILES) {
                printf("Too many files in directory.\n");
                return 1;
            }
        }
        closedir(dir);
    } else {
        perror("opendir");
        return 1;
    }

    // Sort the file names.
    qsort(filenames, file_count, sizeof(char *), compare);

    // Log file to record test results
    FILE *logfile = fopen("logs", "w");
    if (!logfile) {
        perror("fopen");
        return 1;
    }

    for (int i = 0; i < file_count; i++) {
        FILE *inp;
        char inp_name[300];
        sprintf(inp_name, "input/%s", filenames[i]);
        inp = fopen(inp_name, "r");

        if (!inp) {
            printf("%s : \033[1;31mCan't open\033[0m %s\n", filenames[i], inp_name);
            fprintf(logfile, "%s : Can't open %s\n", filenames[i], inp_name);
            free(filenames[i]);
            continue;
        }

        // Set yyin for Yacc to read from this file
        yyin = inp;
        yylineno = 1;  // Reset line number

        // Parse the file using Yacc parser
        int result = yyparse();
        
        if (result == 0) {
            // Parsing was successful
            printf("%s : \033[1;32mTest Passed (Parsed successfully)\033[0m\n", filenames[i]);
            fprintf(logfile, "%s : Test Passed (Parsed successfully)\n", filenames[i]);
        } else {
            // Parsing failed (syntax error)
            printf("%s : \033[1;31mTest Failed (Syntax Error)\033[0m\n", filenames[i]);
            fprintf(logfile, "%s : Test Failed (Syntax Error)\n", filenames[i]);
        }

        fclose(inp);
        free(filenames[i]);
    }

    fclose(logfile);
    return 0;
}
