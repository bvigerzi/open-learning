#include <stdio.h>
#include <unistd.h>
void (*m)();
void f() {
    printf("child is running m = %p\n", m);
}
int main() {
    m = f; // assign function pointer to function f
    if (fork() == 0) {
        printf("child has started\n");
        int i;
        for (i = 0; i < 15; i++) {
            sleep(1);
            (*m)();
        }
    } else {
        printf("parent has started\n");
        sleep (5);
        printf("parent is running; let's write to m = %p\n", m);
        m = 0;
        printf("parent tries to invoke m = %p\n", m);
        (*m)();
        printf("parent is still alive\n"); // parent should crash before printing this, but child fork will keep going
    }
}