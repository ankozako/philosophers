# Philosophers

A solution to the dining philosophers problem in C, using POSIX threads and mutexes. Built as part of the 42 curriculum at 42 Belgium.

## The problem

N philosophers sit around a table with one fork between each pair of neighbours. To eat, a philosopher needs both forks next to them; after eating they sleep, then think, then try to eat again. If a philosopher goes longer than `time_to_die` milliseconds without starting a meal, they die and the simulation ends.

The challenge is to keep everyone alive with no deadlocks and no data races, while logging every state change with an accurate timestamp.

## Build and run

```bash
make
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [meals_per_philosopher]
```

All times are in milliseconds. The optional fifth argument ends the simulation once every philosopher has eaten that many times. All arguments must be positive integers.

```bash
./philo 5 800 200 200      # nobody should die; runs until interrupted
./philo 5 800 200 200 7    # stops once everyone has eaten 7 times
./philo 4 310 200 100      # a philosopher dies
./philo 1 800 200 200      # one fork only: the philosopher cannot eat and dies
```

Each log line has the format `<timestamp_ms> <philosopher_id> <action>`, for example `200 3 is eating`.

## How it works

### Threads

Each philosopher runs in its own thread, looping through think → take forks → eat → drop forks → sleep. The main thread acts as a monitor: every 0.5 ms it checks whether any philosopher has starved or whether everyone has eaten enough, and if so sets a shared stop flag that all threads watch.

### Shared state and mutexes

| Mutex | Protects |
|---|---|
| One per fork | The fork itself |
| One per philosopher (meal mutex) | Time of last meal and meal count, written by the philosopher and read by the monitor |
| Print mutex | Standard output, so log lines never interleave; also checks the stop flag so nothing is logged once the simulation has ended |
| Stop mutex | The simulation-end flag |

Shared data is only read or written through small getter and setter functions that lock the matching mutex, so there are no unprotected accesses.

### Avoiding deadlock

If every philosopher picks up their left fork first, they can all end up holding one fork and waiting forever for the other. To break that cycle, odd-numbered philosophers take their left fork first and even-numbered philosophers take their right fork first. Even philosophers also start 1 ms later, so the first round of odd philosophers can pick up their forks without contention.

### Precise timing

`usleep` can overshoot, which matters when deaths are judged to the millisecond. Instead of one long sleep, `prec_sleep` sleeps in 100 µs steps and checks the clock each time. This keeps eating and sleeping durations close to the requested values and lets threads exit promptly when the simulation stops.

### One philosopher

With a single philosopher there is only one fork. The philosopher takes it, waits until the monitor declares their death, then releases it and exits.
