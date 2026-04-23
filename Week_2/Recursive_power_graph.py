import matplotlib.pyplot as plt
import math

# Input sizes and observed times
sizes = [1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000]
times = [0.03, 0.045, 0.05, 0.055, 0.058, 0.060, 0.062, 0.064, 0.066, 0.068]

# Calculate proportional constant using last value
factor = times[-1] / math.log2(sizes[-1])

# Expected O(log n) values
expected = []
for n in sizes:
    expected.append(factor * math.log2(n))

# Plot graph
plt.plot(sizes, times, 'o-', label='Observed Time')
plt.plot(sizes, expected, 'x--', label='Expected O(log n)')

plt.xlabel('Input Size (n)')
plt.ylabel('Time (microseconds)')
plt.title('Time Complexity of Recursive Power Function')

plt.xticks(sizes)
plt.legend()
plt.grid()

plt.show()