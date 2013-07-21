#include "timer.h"

Timer::Timer() {
}
Timer::~Timer() {
}

void Timer::start() {
  getrusage(RUSAGE_SELF, &usage );
  ut1 = usage.ru_utime;
  st1 = usage.ru_stime;
}

void Timer::stop() {
  getrusage(RUSAGE_SELF, &usage );
  ut2 = usage.ru_utime;
  st2 = usage.ru_stime;
}

double Timer::utime() {
  return (ut2.tv_sec - ut1.tv_sec) + (ut2.tv_usec - ut1.tv_usec)*1.0E-6;
}

double Timer::stime() {
  return (st2.tv_sec - st1.tv_sec) + (st2.tv_usec - st1.tv_usec)*1.0E-6;
}
