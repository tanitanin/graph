#pragma once

#include <sys/time.h>
#include <sys/resource.h>


class Timer {
  private:
    rusage usage;
    timeval ut1, ut2;
    timeval st1, st2;
  public:
    Timer();
    ~Timer();

    void start();
    void stop();

    double utime();
    double stime();
};

