/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

static volatile sig_atomic_t ticks = 0;
static time_t start_time = 0;

void alarm_handler(int signum) {
  ++ticks;
  alarm(1);
}

void sigint_handler(int signum) {
  time_t end_time = time(NULL);
  time_t elapsed = (end_time >= start_time) ? (end_time - start_time) : 0;

  printf("\nTotal elapsed time: %ld seconds\n", (long)elapsed);
  printf("Number of alarms (seconds counted): %d\n", (int)ticks);
  exit(0);
}

int main(void) {
  start_time = time(NULL);

  signal(SIGALRM, alarm_handler);
  signal(SIGINT, sigint_handler);

  alarm(1);

  for (;;) {
    pause();  // wait for signals
  }
}
