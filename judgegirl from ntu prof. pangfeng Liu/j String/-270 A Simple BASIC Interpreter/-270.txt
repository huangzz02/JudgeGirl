#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    bool is_GOTO;
    int GOTO_num;

    bool is_IF;
    char IF_var1[8];
    char IF_op[3];
    char IF_var2[8];
    int IF_num;

    bool is_EXP;
    char EXP_ans[8];
    char EXP_var1[8];
    char EXP_op;
    char EXP_var2[8];

    bool is_PRINT;
    char PRINT_var[8];

    bool is_STOP;
} instructions;

void parse_instruction(char *line, instructions *data, int length, char variable[100][8], int value[100]) {
    if (strncmp(line, "GOTO", 4) == 0) {
        data[length].is_GOTO = true;
        data[length].is_IF = false;
        data[length].is_EXP = false;
        data[length].is_PRINT = false;
        data[length].is_STOP = false;

        data[length].GOTO_num = atoi(line + 5);
    }
    else if (strncmp(line, "IF", 2) == 0) {
        data[length].is_GOTO = false;
        data[length].is_IF = true;
        data[length].is_EXP = false;
        data[length].is_PRINT = false;
        data[length].is_STOP = false;

        char var1[8], op[3], var2[8]; // op may be >= or <=
        int num;
        sscanf(line, "IF %s %s %s GOTO %d", var1, op, var2, &num);

        strcpy(data[length].IF_var1, var1);
        strcpy(data[length].IF_op, op);
        strcpy(data[length].IF_var2, var2);
        data[length].IF_num = num;
    }
    else if (strchr(line, '=') != NULL) {
        data[length].is_GOTO = false;
        data[length].is_IF = false;
        data[length].is_EXP = true;
        data[length].is_PRINT = false;
        data[length].is_STOP = false;

        char var[8], var1[8], op, var2[8];
        sscanf(line, "%s = %s %c %s", var, var1, &op, var2);

        strcpy(data[length].EXP_ans, var);
        strcpy(data[length].EXP_var1, var1);
        data[length].EXP_op = op;
        strcpy(data[length].EXP_var2, var2);
    }
    else if (strncmp(line, "PRINT", 5) == 0) {
        data[length].is_GOTO = false;
        data[length].is_IF = false;
        data[length].is_EXP = false;
        data[length].is_PRINT = true;
        data[length].is_STOP = false;

        char var[8];
        sscanf(line, "PRINT %s", var);

        strcpy(data[length].PRINT_var, var);
    }
    else if (strcmp(line, "STOP") == 0) {
        data[length].is_GOTO = false;
        data[length].is_IF = false;
        data[length].is_EXP = false;
        data[length].is_PRINT = false;
        data[length].is_STOP = true;
    }
}

void execute_program(instructions *data, int length, char variable[100][8], int value[100], int index) {
    int pc = 0;
    int execution_count = 0;

    while (pc < length) {
        if (execution_count > 1000000) {
            break;
        }

        if (data[pc].is_GOTO) {
            pc = data[pc].GOTO_num - 1;
        }
        else if (data[pc].is_IF) {
            int var1_val , var2_val;
            for (int i = 0; i < index; i++) {
                if (strcmp(variable[i], data[pc].IF_var1) == 0) {
                    var1_val = value[i];
                    break;
                }
            }
            for (int i = 0; i < index; i++) {
                if (strcmp(variable[i], data[pc].IF_var2) == 0) {
                    var2_val = value[i];
                    break;
                }
            }
            
            bool condition_GOTO = false;
            if (strcmp(data[pc].IF_op, "==") == 0) {
                condition_GOTO = (var1_val == var2_val);
            } else if (strcmp(data[pc].IF_op, "!=") == 0) {
                condition_GOTO = (var1_val != var2_val);
            } else if (strcmp(data[pc].IF_op, ">") == 0) {
                condition_GOTO = (var1_val > var2_val);
            } else if (strcmp(data[pc].IF_op, "<") == 0) {
                condition_GOTO = (var1_val < var2_val);
            } else if (strcmp(data[pc].IF_op, ">=") == 0) {
                condition_GOTO = (var1_val >= var2_val);
            } else if (strcmp(data[pc].IF_op, "<=") == 0) {
                condition_GOTO = (var1_val <= var2_val);
            }

            if (condition_GOTO) {
                pc = data[pc].IF_num - 1;
            } else {
                pc++;
            }
        }
        else if (data[pc].is_EXP) {
            int var1_val , var2_val;
            for (int i = 0; i < index; i++) {
                if (strcmp(variable[i], data[pc].EXP_var1) == 0) {
                    var1_val = value[i];
                    break;
                }
            }
            for (int i = 0; i < index; i++) {
                if (strcmp(variable[i], data[pc].EXP_var2) == 0) {
                    var2_val = value[i];
                    break;
                }
            }

            int result;
            switch (data[pc].EXP_op) {
                case '+': result = var1_val + var2_val; break;
                case '-': result = var1_val - var2_val; break;
                case '*': result = var1_val * var2_val; break;
                case '/': result = var1_val / var2_val; break;
                case '%': result = var1_val % var2_val; break;
            }

            for (int i = 0; i < index; i++) {
                if (strcmp(variable[i], data[pc].EXP_ans) == 0) {
                    value[i] = result;
                    break;
                }
            }

            pc++;
        }
        else if (data[pc].is_PRINT) {
            for (int i = 0; i < index; i++) {
                if (strcmp(variable[i], data[pc].PRINT_var) == 0) {
                    printf("%d\n", value[i]);
                    break;
                }
            }

            pc++;
        }
        else if (data[pc].is_STOP) {
            break;
        }

        execution_count++;
    }
}

int main() {
    char variable[100][8];
    int value[100];

    int index = 0;
    char line_0[10000];
    fgets(line_0, sizeof(line_0), stdin);

    if (strncmp(line_0, "END", 3) == 0) { // when there is no input (easy to be overlooked!!!)
        return 0;
    }

    char *token = strtok(line_0, " ");
    while (token != NULL) {
        if (strcmp(token, "END") == 0) {
            break;
        }

        strcpy(variable[index], token);

        token = strtok(NULL, " "); // '='

        token = strtok(NULL, " ");
        value[index] = atoi(token);

        index++;
        token = strtok(NULL, " \n"); // ' ' or '\n'
    }
    
    instructions data[1000];
    int length = 0;

    char line[100];
    while (fgets(line, sizeof(line), stdin) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        parse_instruction(line, data, length, variable, value);
        length++;
    }

    execute_program(data, length, variable, value, index);

    return 0;
}