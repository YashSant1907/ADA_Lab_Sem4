# =====================================
# Week-3 ADA Lab Codes
# Algorithm Design and Analysis
# =====================================
import matplotlib.pyplot as plt
import math

# Input sizes and observed times
sizes = [1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000]
times = [0, 831.3, 738.5, 1456.8, 4768.7, 5662.4, 8511.2, 10676.3, 14486.7, 16865]

# Calculate constant using largest value
factor = times[-1] / (sizes[-1] * math.log2(sizes[-1]))

# Expected O(n log n) values
expected = []
for n in sizes:
    expected.append(factor * n * math.log2(n))

# Plot graph
plt.plot(sizes, times, 'o-', label='Observed Time')
plt.plot(sizes, expected, 'x--', label='Expected O(n log n)')

plt.xlabel('Input Size (n)')
plt.ylabel('Time (microseconds)')
plt.title('Time Complexity of Quick Sort')

plt.xticks(sizes)
plt.legend()
plt.grid()

plt.show()