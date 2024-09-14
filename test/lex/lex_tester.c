#include <stdio.h>
#include <dirent.h>
#include "../../lex.yy.c"
#define MAX_LINE_LEN 1000
#define MAX_FILE_LEN 10000
extern FILE *output_file;

int main()
{

    DIR *dir;
    struct dirent *ent;
    const char *inputDir = "input"; // Directory name
    if ((dir = opendir(inputDir)) != NULL)
    {
        while ((ent = readdir(dir)) != NULL)
        {
            FILE *inp;
            char inp_contents[MAX_FILE_LEN];
            char line[MAX_LINE_LEN];
            memset(inp_contents, 0, sizeof(inp_contents));
            memset(line, 0, sizeof(line));
            if (ent->d_name[0] == '.' || ent->d_name == "..")
                continue;
            char inp_name[300];
            char out_name[300];
            strcpy(inp_name, ent->d_name);
            strcpy(out_name, ent->d_name);
            sprintf(inp_name, "input/%s", ent->d_name);
            sprintf(out_name, "output/%s", ent->d_name);

            inp = fopen(inp_name, "r");
            output_file = fopen(out_name, "w");
            if (!inp)
            {
                printf("%s : \033[1;31mCan't open\033[0m %s\n", ent->d_name,inp_name);
                goto end;
            }
            if (!output_file)
            {
                printf("%s : \033[1;31mCan't open\033[0m %s\n", ent->d_name,out_name);
                goto end;
            }
            char expected_out_name[300];
            sprintf(expected_out_name, "expected/%s", ent->d_name);

            FILE *expected_out = fopen(expected_out_name, "r");
            if (!expected_out)
            {
                printf("%s : \033[1;31mCan't open\033[0m %s\n", ent->d_name,expected_out_name);
                goto end;
            }

            while (fgets(line, sizeof(line), inp) != NULL)
            {
                strcat(inp_contents, line);
            }
            // if ((strcmp(inp_name, "input/24.txt"))==0)
                // printf("%s", inp_contents);

            yy_scan_string(inp_contents);
            while (yylex() != 0)
                ;

            // fclose(inp);
            fclose(output_file);

            output_file = fopen(out_name, "r");

            char line2[MAX_LINE_LEN];
            int line_num = 1;
            char *out1 = fgets(line, sizeof(line), output_file);
            char *out2 = fgets(line2, sizeof(line2), expected_out);
            while (out1 != NULL || out2 != NULL)
            {
                char *line_temp = line;
                char *line2_temp = line2;
                while (*line_temp != '\0' || *line_temp != '\0')
                {
                    if ((*line_temp == '\0' || *line_temp == '\0') || (*line_temp != *line2_temp))
                    {
                        printf("%s : \033[1;31mTest Failed\033[0m at line : %d char number : %d\n", ent->d_name, line_num, (int)(line_temp - line + 1));
                        printf("\033[1;34mGot\n\033[0m : %s\033[1;34mExpected\n\033[0m : %s", line_temp, line2_temp);
                        goto end;
                    }
                    line_temp++;
                    line2_temp++;
                }
                line_num++;
                out1 = fgets(line, sizeof(line), output_file);
                out2 = fgets(line2, sizeof(line2), expected_out);
            }
            printf("%s : \033[1;32mTest Passed\n\033[0m", ent->d_name);
        end:
            if (inp)
                fclose(inp);
            if (output_file)
                fclose(output_file);
            if (expected_out)
                fclose(expected_out);
            // break;
        }
        closedir(dir);
    }
    return 0;
}