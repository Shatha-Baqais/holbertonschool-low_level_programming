:set past# Green Efficiency Analysis

## Measurement Methodology

All programs were compiled in the same GitHub Codespace with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long` and executed in that same environment, so every measurement shares the same hardware and software conditions. Execution time was measured with `clock()` from `<time.h>`: the difference between two `clock()` calls was divided by `CLOCKS_PER_SEC` to convert processor ticks into seconds. Each program was run three consecutive times, and averages were computed from those three runs.

For `instrumentation_lab.c`, one timestamp was taken before the first phase, one between each pair of consecutive phases, and one after the last phase. Because consecutive phases share a boundary, there are no gaps: BUILD_DATA, PROCESS and REDUCE add up to TOTAL. All printing happens after the last timestamp, so output does not affect the measured time.

## Observed Performance Differences

The baseline loop (100,000,000 iterations) was run three times; all three outputs are recorded verbatim in `baseline_loop-metrics.md`. Runs 2 and 3 took 0.129311 and 0.103696 seconds. These values are close but not identical, which shows normal timing variability even for a deterministic program.

In `comparison_algorithms.c`, the naive algorithm took 1.375813, 1.337405 and 1.378661 seconds (average 1.363960 s), while the single-pass algorithm took 0.000044, 0.000065 and 0.000077 seconds (average 0.000062 s). The naive version was therefore about 22,000 times slower. This matches the structure of the code: the naive version uses nested loops and performs about 1.25 billion checks for 50,000 elements, while the single-pass version performs 50,000. The two functions also returned different results (625025000 versus 25000), because the naive version counts the same elements many times.

In `instrumentation_lab.c`, the average TOTAL was 0.000504 seconds. BUILD_DATA averaged 0.000215 s (about 43%), PROCESS 0.000201 s (about 40%) and REDUCE 0.000088 s (about 17%). Building and processing the dataset dominated the runtime, while the final reduction was the cheapest phase.

## Relation Between Runtime and Energy Consumption

These experiments did not measure power in watts. Runtime is used as a proxy: a program that keeps the CPU busy for longer generally consumes more energy. Under this assumption, the naive algorithm kept the CPU busy for about 1.36 seconds to do work that the single-pass algorithm completed in about 0.00006 seconds. If such a function ran millions of times on a server, the extra CPU time, and therefore the extra energy, would grow accordingly.

## Limitations of the Experiment

- Energy was not measured directly; runtime is only an approximation of energy use.
- Only three runs were recorded per program, which is a small sample.
- The single-pass and instrumentation timings are in the range of tens of microseconds, close to the practical resolution of `clock()`, so their relative variation is large (single-pass ranged from 0.000044 to 0.000077 s).
- The Codespace is a shared virtual machine, so background activity may have influenced individual runs.
- Results come from one environment and may differ on other hardware.

## Practical Engineering Takeaway

The largest difference in these measurements came from the choice of algorithm, not from small details: replacing a nested-loop approach with a single pass reduced runtime by about four orders of magnitude. Measuring before optimizing also matters: the instrumentation showed that BUILD_DATA and PROCESS dominate, so they would be the first candidates to examine. Choosing efficient algorithms and verifying their behavior with measurements is a practical way to reduce CPU time, and with it, energy consumption.e
