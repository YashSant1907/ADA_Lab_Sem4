# =====================================
# Week-4 ADA Lab Codes
# Algorithm Design and Analysis
# =====================================
import matplotlib.pyplot as plt

# Matrix sizes and observed times
sizes = [2, 4, 8, 16, 32, 64]
times = [0, 0, 1567.6, 1304.1, 8857.5, 65525.2]

# Use largest value for stable constant
factor = times[-1] / (sizes[-1] ** 3)

# Expected O(n^3)
expected = []
for n in sizes:
    expected.append(factor * (n ** 3))

# Plot graph
plt.plot(sizes, times, 'o-', label='Observed Time')
plt.plot(sizes, expected, 'x--', label='Expected O(n³)')

plt.xlabel("Matrix Size (n x n)")
plt.ylabel("Time (microseconds)")
plt.title("Time Complexity of Matrix Multiplication")

plt.legend()
plt.grid()

plt.show()