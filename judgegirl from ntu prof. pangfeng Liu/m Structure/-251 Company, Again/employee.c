#include "employee.h"

int relation(Employee *employee1, Employee *employee2) {
    // Check if employee1 is a subordinate of employee2 (employee1 < employee2)
    Employee *current = employee1;
    int is_sub = 0;
    while (current->boss != current) {
        if (current == employee2) {
            is_sub = 1;
            break;
        }
        current = current->boss;
    }
    if (current == employee2) {
        is_sub = 1;
    }
    if (is_sub) {
        return 1;
    }

    // Check if employee1 is a supervisor of employee2 (employee1 > employee2)
    current = employee2;
    int is_super = 0;
    while (current->boss != current) {
        if (current == employee1) {
            is_super = 1;
            break;
        }
        current = current->boss;
    }
    if (current == employee1) {
        is_super = 1;
    }
    if (is_super) {
        return 2;
    }

    // find the root (topmost boss) of employee1
    current = employee1;
    while (current->boss != current) {
        current = current->boss;
    }
    Employee *root1 = current;

    // find the root (topmost boss) of employee2
    current = employee2;
    while (current->boss != current) {
        current = current->boss;
    }
    Employee *root2 = current;

    // If the roots are the same, then they are colleagues (same boss)
    if (root1 == root2) {
        return 3;
    }

    // Otherwise unrelated
    return 4;
}

/*
    Note: 
        Changed the sample code on Judge Girl from
           "int relation(Employee employee1, Employee employee2);"
        to "int relation(Employee *employee1, Employee *employee2);"

        The parameters should be pointers to allow traversal of the employee hierarchy.
*/