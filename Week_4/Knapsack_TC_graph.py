# =====================================
# Week-4 ADA Lab Codes
# Algorithm Design and Analysis
# =====================================
import matplotlib.pyplot as plt
import math

# Input sizes
sizes = [100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000]

# Observed times
by_weight = [1019.9, 1551.2, 6865.3, 17964.5, 31944.6, 52606.6, 74641.7, 102909, 131566, 150000]
by_profit = [200.2, 1642.9, 7104.2, 16207.2, 30429.8, 47425.8, 66510.1, 101416, 133867, 160000]
by_ratio  = [1093.4, 3904.3, 13032.3, 25469.9, 51622.5, 78452.5, 120468, 159567, 219495, 250000]

# Better constant using average of last values
avg_last = (by_weight[-1] + by_profit[-1] + by_ratio[-1]) / 3
factor = avg_last / (sizes[-1] * math.log2(sizes[-1]))

# Expected O(n log n)
expected = []
for n in sizes:
    expected.append(factor * n * math.log2(n))

# Plot
plt.plot(sizes, by_weight, 'o-', label='By Weight')
plt.plot(sizes, by_profit, 's-', label='By Profit')
plt.plot(sizes, by_ratio, '^-', label='By Ratio')

plt.plot(sizes, expected, 'k--', label='Expected O(n log n)')

plt.xlabel("Input Size (n)")
plt.ylabel("Time (microseconds)")
plt.title("Time Complexity of Fractional Knapsack")

plt.xticks(sizes)
plt.legend()
plt.grid()

plt.show()