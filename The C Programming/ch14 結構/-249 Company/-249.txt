#include <stdio.h>
#include <string.h>

struct employee {
  int id;
  char first_name[32];
  char last_name[32];
  int boss_id;
};

int main() {
    int data;
    scanf("%d", &data);
    struct employee relation[data];
    for (int i = 0; i < data; i++) {
        scanf("%d %s %s %d", 
              &relation[i].id, 
              relation[i].first_name, 
              relation[i].last_name, 
              &relation[i].boss_id);
    }

    int ask;
    scanf("%d", &ask);

    for (int i = 0; i < ask; i++) {
        char name1_first[32], name1_last[32];
        char name2_first[32], name2_last[32];
        scanf("%s %s %s %s", name1_first, name1_last, name2_first, name2_last);

        int id1 ,boss_id1, id2, boss_id2;
        for (int j = 0; j < data; j++) {
            if (strcmp(relation[j].first_name, name1_first) == 0 &&
                strcmp(relation[j].last_name, name1_last) == 0) {
                id1 = relation[j].id;
                boss_id1 = relation[j].boss_id;
            }
            if (strcmp(relation[j].first_name, name2_first) == 0 &&
                strcmp(relation[j].last_name, name2_last) == 0) {
                id2 = relation[j].id;
                boss_id2 = relation[j].boss_id;
            }
        }

        int case_end = 0;

        int end = 0;
        while(!end) {
            for (int j = 0; j < data; j++) {
                if (relation[j].id == boss_id1) {
                    if (relation[j].id == id2) {
                        printf("subordinate\n");
                        end = 1;
                        case_end = 1;
                    } else {
                        if (relation[j].boss_id == boss_id1) {
                            end = 1;
                        } else {
                            boss_id1 = relation[j].boss_id;
                        }
                    }
                    break;
                }
            }
        }
        if (case_end) continue;

        end = 0;
        while(!end) {
            for (int j = 0; j < data; j++) {
                if (relation[j].id == boss_id2) {
                    if (relation[j].id == id1) {
                        printf("supervisor\n");
                        end = 1;
                        case_end = 1;
                    } else {
                        if (relation[j].boss_id == boss_id2) {
                            end = 1;
                        } else {
                            boss_id2 = relation[j].boss_id;
                        }
                    }
                    break;
                }
            }
        }
        if (case_end) continue;

        if (boss_id1 == boss_id2) {
            printf("colleague\n");
        } else {
            printf("unrelated\n");
        }
    }
    return 0;
}