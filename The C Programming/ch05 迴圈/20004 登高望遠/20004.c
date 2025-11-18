#include <stdio.h>
#include <math.h>

int main() {
    int height = 5, floor;
    double vision, obstacle, distance;
    scanf("%lf %d %lf %lf", &vision, &floor, &obstacle, &distance);

    double current_height = floor * height;
    int count_climbs = 0;

    while (current_height <= obstacle) {
        current_height += height;
        count_climbs++;
    }

    while (1) {
        if (current_height > vision) {
            printf("unable\n");
            break;
        }

        // x : x + distance = obstacle : current_height
        double x = distance * obstacle / (current_height - obstacle);
        double temp_vision = sqrt((distance + x) * (distance + x) + current_height * current_height);

        if (temp_vision > vision) {
            current_height += height;
            count_climbs++;
        } else {
            printf("%d\n", count_climbs);
            break;
        }
    }

    return 0;
}

/*
    Another solution using mathematical calculations?
     _
    |_|\
    |_| \
    |_|  \
    |_|   \
    |_|    \
    |_|     \
    |_|      \
    |_|       \
    |_|        \
    |_|         \
    |_|          \
    |_|           \
    |_|            \--> vision
    |_|             \
    |_|              \
    |_|               \
    |_|                \
    |_|                _\
    |_|               |_|\
    |_|               |_|--> obstacle
    |_|               |_|  \
    |_|_______________|_|___\
              |           |
              |           L--> x
              L--> distance
        
    x : x + distance = obstacle : exact_height
    ?   ?    known      known          ?

    Uses vision to find x:
        (vision * (x / (distance+x)))^2 = obstacle^2 + x^2

        let vision = a
            distance = b
            obstacle = c
        (a * (x / (b+x)))^2 = c^2 + x^2

        After organizing, we got:
            x^4 + 2b*x^3 + (b^2 + c^2 - a^2)*x^2 + 2bc^2*x + (b^2)(c^2) = 0

    And because the method for solving a quartic equation is too complicated, it cannot be done this way here.
*/