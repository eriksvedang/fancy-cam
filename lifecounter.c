#include <stdio.h>
#include <stdlib.h>

const char *save_file_name = "life.txt";

void set_life(int new_life) {
    FILE *f = fopen(save_file_name, "w");
    fprintf(f, "%d\n", new_life);
    fclose(f);
}

int get_life() {
    FILE *f = fopen(save_file_name, "r");
    int life = 0;
    fscanf(f, "%d", &life);
    fclose(f);
    return life;
}

void change_life(int change) {
    int new_life = get_life() + change;
    set_life(new_life);
}

void print_life() {
    system("clear");
    printf("Life: %d\n", get_life());
}

int main() {
    system ("/bin/stty raw");
    set_life(20);
    print_life();
    char c;
    while((c=getchar()) != 'q') {
        if(c == ',') {
            change_life(-1);
        }
        else if(c == '.') {
            change_life(1);
        }
        else if(c == 'r') {
            set_life(20);
        }
        print_life();
    }
    system ("/bin/stty cooked");
}
