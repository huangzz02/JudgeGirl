#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Data {
    char lastname[80];
    char firstname[80];
    char ID[80];
    int salary;
    int age;
};

bool check_condition(struct Data *data, char *condition) {
    char field[80], op[3], value[80];
    if (sscanf(condition, "%s %s %s", field, op, value) != 3) return 0;

    if (strcmp(field, "lastname") == 0 || strcmp(field, "firstname") == 0 || strcmp(field, "ID") == 0) {
        char *data_val;
        if (strcmp(field, "lastname") == 0) data_val = data->lastname;
        else if (strcmp(field, "firstname") == 0) data_val = data->firstname;
        else data_val = data->ID;

        if (strcmp(op, "==") == 0) return strcmp(data_val, value) == 0;
        else if (strcmp(op, "!=") == 0) return strcmp(data_val, value) != 0;
    }
    else if (strcmp(field, "salary") == 0 || strcmp(field, "age") == 0) {
        int val = atoi(value);
        int data_val = (strcmp(field, "salary") == 0) ? data->salary : data->age;

        if (strcmp(op, ">") == 0) return data_val > val;
        if (strcmp(op, "<") == 0) return data_val < val;
        if (strcmp(op, "==") == 0) return data_val == val;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    struct Data arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%s %s %s %d %d", arr[i].lastname, arr[i].firstname, arr[i].ID, &arr[i].salary, &arr[i].age);
    }

    int requst;
    scanf("%d", &requst);
    getchar(); // Clear newline character

    // example input : select lastname firstname ID where salary > 50000
    char input[200];
    while (requst--) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        char *select_ptr = strstr(input, "select");
        char *where_ptr = strstr(input, "where");
        /*
            select lastname firstname ID where salary > 50000
            ^                            ^
            select_ptr                   where_ptr
        */

        char select_field[100];
        int select_len = where_ptr - (select_ptr + 7);
        strncpy(select_field, select_ptr + 7, select_len);
        select_field[select_len] = '\0';
        /*
            select_field = "lastname firstname ID"
            select_len = 21 (length of select_field)
        */

        char condition[200];
        strcpy(condition, where_ptr + 6);
        /*
            condition = "salary > 50000"
        */

        char *fields[20];
        int field_count = 0;
        char *token = strtok(select_field, " ");
        while (token && field_count < 20) {
            fields[field_count++] = token;
            token = strtok(NULL, " ");
        }
        /*
            fields = ["lastname", "firstname", "ID"]
            field_count = 3

            Note: 
                char *token = strtok(select_field, " "); -> "lastname/0firstname ID", token = "lastname"
                char *token = strtok(NULL, " ");         -> "firstname/0ID"         , token = "firstname"
                char *token = strtok(NULL, " ");         -> "ID"                    , token = "ID"
        */

        for (int i = 0; i < n; i++) {
            if (check_condition(&arr[i], condition)) {
                for (int j = 0; j < field_count; j++) {
                    if (strcmp(fields[j], "lastname") == 0) printf("%s", arr[i].lastname);
                    else if (strcmp(fields[j], "firstname") == 0) printf("%s", arr[i].firstname);
                    else if (strcmp(fields[j], "ID") == 0) printf("%s", arr[i].ID);
                    else if (strcmp(fields[j], "salary") == 0) printf("%d", arr[i].salary);
                    else if (strcmp(fields[j], "age") == 0) printf("%d", arr[i].age);

                    if (j < field_count - 1) printf(" ");
                }
                printf("\n");
            }
        }
    }

    return 0;
}