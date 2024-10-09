#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "../../lex.yy.c"
#include "./tokens.h"

#define MAX_LINE_LEN 1000
#define MAX_FILE_LEN 10000
#define MAX_FILES 1000

extern FILE *output_file;

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
    // sorting the file names.
    qsort(filenames, file_count, sizeof(char *), compare);
    FILE* logfile = fopen("logs", "w");
    for (int i = 0; i < file_count; i++) {
        FILE *inp;
        char inp_contents[MAX_FILE_LEN];
        char line[MAX_LINE_LEN];
        memset(inp_contents, 0, sizeof(inp_contents));
        memset(line, 0, sizeof(line));

        char inp_name[300];
        char out_name[300];
        sprintf(inp_name, "input/%s", filenames[i]);
        inp = fopen(inp_name, "r");

        if (!inp) {
            printf("%s : \033[1;31mCan't open\033[0m %s\n", filenames[i], inp_name);
            goto end;
        }

        char expected_out_name[300];
        sprintf(expected_out_name, "expected/%s", filenames[i]);

        // reinitializing variables in lex file.
        yylineno = 1;
        while (fgets(line, sizeof(line), inp) != NULL) {
            strcat(inp_contents, line);
        }

        yy_scan_string(inp_contents);
        FILE *expected_out = fopen(expected_out_name, "r");
        // If expected out file doesn't exist, then Syntax error is expected.
        if (!expected_out) {
            int token;
            while((token = yylex()) != 0) {
                // printf("Token: %d", token);
                if (token == YYEOF) {
                    break;
                }

                if(token == YYerror){
                    printf("%s : \033[1;32mTest Passed\n\033[0m", filenames[i]);
                    fprintf(logfile, "%s : Test Passed\n", filenames[i]);
                    break;
                }
            }
            if(token != YYerror){
                printf("%s : \033[1;31mTest Failed\n\033[0m", filenames[i]);
                fprintf(logfile, "%s : Test Failed\n", filenames[i]);

            }    
            continue;
        }

        

        int token;
        while ((token = yylex()) != 0) {
            // printf("Token: %d, Name=%s\n", token, yytname[token-258]); // Print tokens for debugging
            if (token == YYEOF) {
                break;
            }

            char line2[MAX_LINE_LEN];
            int line_num = 1;
            char *out2 = fgets(line2, sizeof(line2), expected_out);

            if(out2 == NULL) {
                printf("%s : \033[1;31mTest Failed\033[0m at line : %d\n", filenames[i], line_num);
                fprintf(logfile, "%s : Test Failed\n", filenames[i]);
                goto end;
            }
            int tok = token - 258;
            int len = strlen(out2);
            if(out2[len - 1] == '\n') {
                out2[len - 1] = '\0';
            }
            printf("Line %d, Token: %s, Expected: %s\n", yylineno, yytname[tok], line2);

            if(strcmp(yytname[tok], line2) != 0) {
                printf("%s : \033[1;31mTest Failed\033[0m at line : %d\n", filenames[i], line_num);
                printf("\033[1;34mGot\n\033[0m : %s\033[1;34mExpected\n\033[0m : %s\n", yytname[tok], line2);
                fprintf(logfile, "%s : Test Failed\n", filenames[i]);
                goto end;
            }

            line_num++;
        }
        printf("%s : \033[1;32mTest Passed\n\033[0m", filenames[i]);
        fprintf(logfile, "%s : Test Passed\n", filenames[i]);

    end:
        if (inp)
            fclose(inp);
        if (expected_out)
            fclose(expected_out);
        free(filenames[i]);
    }

    return 0;
}
