#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "../../lex.yy.c"
// #include "../../y.tab.c"
#define MAX_LINE_LEN 1000
#define MAX_FILE_LEN 10000
#define MAX_FILES 1000

extern FILE *output_file;

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    DIR *dir;
    struct dirent *ent;
    const char *inputDir = "input"; // dir name
    char *filenames[MAX_FILES];
    int file_count = 0;

    // Read all filenames into an array
    if ((dir = opendir(inputDir)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_name[0] == '.') // Skip hidden files and directories
                continue;
            filenames[file_count] = strdup(ent->d_name); // Copy the filename
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

    // Sort filenames in lexicographic order
    qsort(filenames, file_count, sizeof(char *), compare);

    // Process each file in sorted order
    for (int i = 0; i < file_count; i++) {
        FILE *inp;
        char inp_contents[MAX_FILE_LEN];
        char line[MAX_LINE_LEN];
        memset(inp_contents, 0, sizeof(inp_contents));
        memset(line, 0, sizeof(line));

        char inp_name[300];
        char out_name[300];
        sprintf(inp_name, "input/%s", filenames[i]);
        sprintf(out_name, "output/%s", filenames[i]);
        inp = fopen(inp_name, "r");
        output_file = fopen(out_name, "w");
        if (!inp) {
            printf("%s : \033[1;31mCan't open\033[0m %s\n", filenames[i], inp_name);
            goto end;
        }
        if (!output_file) {
            printf("%s : \033[1;31mCan't open\033[0m %s\n", filenames[i], out_name);
            goto end;
        }
        char expected_out_name[300];
        sprintf(expected_out_name, "expected/%s", filenames[i]);

        FILE *expected_out = fopen(expected_out_name, "r");
        if (!expected_out) {
            printf("%s : \033[1;31mCan't open\033[0m %s\n", filenames[i], expected_out_name);
            goto end;
        }

        while (fgets(line, sizeof(line), inp) != NULL) {
            strcat(inp_contents, line);
        }
        yylineno = 1;
        yy_scan_string(inp_contents);
        while (yylex() != 0)
            ;

        fclose(output_file);

        output_file = fopen(out_name, "r");

        char line2[MAX_LINE_LEN];
        int line_num = 1;
        char *out1 = fgets(line, sizeof(line), output_file);
        char *out2 = fgets(line2, sizeof(line2), expected_out);
        while (out1 != NULL || out2 != NULL) {
            char *line_temp = line;
            char *line2_temp = line2;
            while (*line_temp != '\0' || *line2_temp != '\0') {
                if ((*line_temp == '\0' || *line2_temp == '\0') || (*line_temp != *line2_temp)) {
                    printf("%s : \033[1;31mTest Failed\033[0m at line : %d char number : %d\n", filenames[i], line_num, (int)(line_temp - line + 1));
                    printf("\033[1;34mGot\n\033[0m : %s\033[1;34mExpected\n\033[0m : %s\n", line, line2);
                    goto end;
                }
                line_temp++;
                line2_temp++;
            }
            line_num++;
            out1 = fgets(line, sizeof(line), output_file);
            out2 = fgets(line2, sizeof(line2), expected_out);
        }
        printf("%s : \033[1;32mTest Passed\n\033[0m", filenames[i]);
    end:
        if (inp)
            fclose(inp);
        if (output_file)
            fclose(output_file);
        if (expected_out)
            fclose(expected_out);
        free(filenames[i]); // Free the allocated memory for the filename
    }

    return 0;
}
