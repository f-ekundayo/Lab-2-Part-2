/* signal2.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static volatile sig_atomic_t alarm_fired = 0;

void handler(int signum) {
  printf("Hello World!\n");
  alarm_fired = 1;
  alarm(5);
}

int main(void) {
  signal(SIGALRM, handler);
  alarm(5);

  for (;;) {
    while (!alarm_fired) {
      /* busy wait */
    }
    printf("Turing was right!\n");
    alarm_fired = 0;
  }
}
