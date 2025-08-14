#include <stdio.h>

int main() {
    char name[20];
    int age;

    printf("Enter name and age: ");
    if (scanf("%19s %d", name, &age) != 2) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Name: %s, Age: %d\n", name, age);
    return 0;
}
