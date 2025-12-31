#include <stdio.h>

inline void fastscan(int* number) {
    *number = 0;
    register int c = getchar_unlocked();
    for (; c >= '0'; c = getchar_unlocked())
        *number = *number * 10 + c - '0';
}

inline void fastprint(int number) {
    char buffer[16];
    register int i = -1;
    do {
        buffer[++i] = (number % 10) + '0';
        number /= 10;
    } while (number);
    while (i >= 0)
        putchar_unlocked(buffer[i--]);
    putchar_unlocked('\n');
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

inline int diff(int a, int b) {
    int tmp = b - a;
    return tmp < 0? -tmp : tmp;
}

inline int time(int a, int b, int s) {
    return diff(a, b) * s;
}

int main() {
    int curr, target, lift, t_stairs, t_lift;
    fastscan(&curr);
    fastscan(&target);
    fastscan(&lift);
    fastscan(&t_stairs);
    fastscan(&t_lift);
    while (curr != 0 || target != 0 || lift != 0 || t_stairs != 0 ||
           t_lift != 0) {
        // Initial solution is taking the stairs
        int res = time(curr, target, t_stairs);
        if (t_stairs <= t_lift || res == 0) goto end;
        if (lift == curr) {
            // If we start at the lift and the lift is faster, there is no
            // reason to not take it
            res = time(curr, target, t_lift);
        } else if ((lift - curr < 0) != (target - curr < 0)) {
            // If we are between the target and the lift, we have 2 options:
            // just using the stairs, or wait for the lift. If we take the lift,
            // the final time will be the time needed for the lift to reach the
            // target, so moving while we wait won't change the result. Thus, we
            // can wait for it at the initial floor and guarantee we will be
            // able to take it without the lift having to wait
            res = min(res, time(lift, target, t_lift));
        } else {
            // The lift and target are in the same direction. Either just use
            // the stairs, go to the lift through the stairs and take the lift
            // there, or wait for the lift at the initial position. Any other
            // choice can't result in a lower time, since if it's beneficial to
            // get closer to the lift through the stairs for a single floor it
            // will be beneficial for all floors until the floor where the lift
            // is at.
            res = min(
                res,
                min(
                    time(curr, lift, t_stairs) + time(lift, target, t_lift),
                    time(curr, lift, t_lift) + time(curr, target, t_lift)
                )
            );
        }
    end:
        fastprint(res);
        fastscan(&curr);
        fastscan(&target);
        fastscan(&lift);
        fastscan(&t_stairs);
        fastscan(&t_lift);
    }
    return 0;
}
