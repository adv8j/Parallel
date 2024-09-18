#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_TOKENS 256

void trim_whitespace(char *str) {
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
}

int main() {
    FILE *file = fopen("../../y.tab.h", "r");
    FILE *output_file = fopen("./tokens.h", "w");
    if (!file) {
        perror("Unable to open y.tab.h");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char tokens[MAX_TOKENS][MAX_LINE_LENGTH];
    int token_count = 0;
    int inside_enum = 0;

    while (fgets(line, sizeof(line), file)) {
        trim_whitespace(line);

        // Detect the start of enum yytokentype
        if (strstr(line, "enum yytokentype")) {
            inside_enum = 1;
            continue;
        }

        // Detect the end of the enum
        if (inside_enum && strstr(line, "}")) {
            inside_enum = 0;
            break;
        }

        // process token lines
        if (inside_enum) {
            char *token_start = line;
            while (*token_start && isspace((unsigned char)*token_start)) token_start++; 

            // Copy the token name until the '=' character
            char *equals_sign = strchr(token_start, '=');
            if (equals_sign) {
                size_t token_len = equals_sign - token_start;
                strncpy(tokens[token_count], token_start, token_len);
                tokens[token_count][token_len] = '\0';  // Null terminate the token string
                token_count++;
            }
        }
    }

    fclose(file);

    // Generate the yytname array
    // fprintf(output_file, "#include \"tokens.h\"\n\n");
    fprintf(output_file, "const char *yytname[] = {\n");
    int cnt = 0;
    for (int i = 0; i < token_count; i++) {
        if(strstr(tokens[i], "YY")) {
            continue;
        }
        int len = strlen(tokens[i]);
        if (tokens[i][len - 1] == ' ') {
            tokens[i][len - 1] = '\0';
        }
        fprintf(output_file, "    \"%s\",\n", tokens[i]);
        cnt++;
    }
    fprintf(output_file, "};\n\n");
    fprintf(output_file, "const int yyntokens = %d;\n", cnt);


    return 0;
}
