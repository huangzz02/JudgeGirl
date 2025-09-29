#ifndef EMPLOYEE_H
#define EMPLOYEE_H
 
typedef struct employee {
  char first_name[32];
  char last_name[32];
  struct employee *boss;
} Employee;

int relation(Employee *employee1, Employee *employee2);
#endif

/*
    Note:
        The sample code on Judge Girl is:
            #ifndef EMPLOYEE_H
            #define EMPLOYEE_H
            
            typedef struct employee {
            char first_name[32];
            char last_name[32];
            struct employee boss;
            } Employee;
            
            int relation(Employee employee1, Employee employee2);
            #endif

        But the above code has a problem that struct employee contains an instance of itself, which leads to infinite size.
        Therefore, I modified "struct employee boss;"
                           to "struct employee *boss;"
        to use a pointer instead.

        And the function signature is also changed from
               "int relation(Employee employee1, Employee employee2);"
            to "int relation(Employee *employee1, Employee *employee2);
*/