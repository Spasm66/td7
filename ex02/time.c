#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int seconds;
    int minutes;
    int hours;
}time;

bool    hms_to_spm(int h, int m, int s, int *res)
{
    if (!(h <= 23 && m <= 59 && s <= 59))
        return (false);
    *res = h * 3600 + m * 60 + s;
    return (true);
}

time    spm_to_hms(int spm)
{
    return ((time){(spm % 3600) % 60, (spm % 3600) / 60, spm / 3600});
}

time  time_plane_travel(time d, time a)
{
    int     spm_d;
    int     spm_a;

    hms_to_spm(d.hours, d.minutes, d.seconds, &spm_d);
    hms_to_spm(a.hours, a.minutes, a.seconds, &spm_a);
    return (spm_to_hms(spm_a - spm_d));
}

int main(void)
{
    time t_departure;
    time t_arrival;
    time t_duration;

    t_departure = (time){21, 30, 16};
    t_arrival = (time){11, 45, 17};
    t_duration = time_plane_travel(t_departure, t_arrival);
    printf("%d\t%d\t%d\n", t_duration.hours, t_duration.minutes, t_duration.seconds);
}