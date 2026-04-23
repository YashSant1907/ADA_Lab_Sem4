import matplotlib.pyplot as plt
import math

# Input data
sizes = [1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000]
times = [0, 938.8, 1327.3, 4669.6, 5260.7, 8079.5, 9791, 9944.8, 11624.5, 16046.1]

# Better constant (use largest value)
factor = times[-1] / (sizes[-1] * math.log2(sizes[-1]))

# Expected values
expected = []
for n in sizes:
    expected.append(factor * n * math.log2(n))

# Plot
plt.plot(sizes, times, 'o-', label='Observed Time')
plt.plot(sizes, expected, 'x--', label='Expected O(n log n)')

plt.xlabel("Input Size (n)")
plt.ylabel("Time (microseconds)")
plt.title("Merge Sort - Time Complexity")

plt.xticks(sizes)
plt.legend()
plt.grid()

plt.show() 