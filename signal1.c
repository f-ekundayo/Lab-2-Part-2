/* signal1.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static volatile sig_atomic_t alarm_fired = 0;

void handler(int signum) {
  printf("Hello World!\n");
  alarm_fired = 1;
}

int main(void) {
  signal(SIGALRM, handler);
  alarm(5);

  while (!alarm_fired) {
    /* busy wait */
  }

  printf("Turing was right!\n");
  return 0;
}
