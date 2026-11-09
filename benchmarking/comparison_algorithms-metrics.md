# comparison_algorithms metrics

## Raw results

| Run | Naive result | Naive time (s) | Single-pass result | Single-pass time (s) |
|---|---|---|---|---|
| 1 | 625025000 | 1.375813 | 25000 | 0.000044 |
| 2 | 625025000 | 1.337405 | 25000 | 0.000065 |
| 3 | 625025000 | 1.378661 | 25000 | 0.000077 |

## Averages

- Naive average: 1.363960 seconds
- Single-pass average: 0.000062 seconds

## Relative difference

The naive implementation is ~22,000 times slower than the single-pass implementation.

## Observations

- The naive version uses nested loops (about n^2 / 2 operations), while the single-pass version uses one loop (n operations).
- Naive times were stable (about 3% variation). Single-pass times varied more in relative terms because they are very small and close to the resolution of clock().
- The two implementations do not return the same result: the naive version counts the same values many times (625025000), while the single-pass version returns the correct count (25000).
