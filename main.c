#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

static inline int rdtsc_diff() {
    uint64_t ret, ret2;
    unsigned a, d;
    __asm__ volatile("rdtsc" : "=a" (a), "=d" (d));
    ret  = ((unsigned long long)a) | (((unsigned long long)d) << 32);
    __asm__ volatile("rdtsc" : "=a" (a), "=d" (d));
    ret2 = ((unsigned long long)a) | (((unsigned long long)d) << 32);
    fprintf(stdout, "(%llu - %llu) ", ret, ret2);
    return ret2 - ret;
}

int main(void) {
    int i, avg = 0, sub;
    for (i = 0; i < 10; i++) {
        sub = rdtsc_diff();
        fprintf(stdout, "rdtsc difference: %d\n", sub);
        avg = avg + sub;
        sleep(1);
    }
    fprintf(stdout, "difference average is: %d\n", (avg / 10));
    getchar();
    return 0;
}