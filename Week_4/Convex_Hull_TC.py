import matplotlib.pyplot as plt
import math

# Input sizes and observed times
sizes = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
times = [6.8248, 182.183, 963.147, 2997.1, 7320.97, 15676.4, 28283, 47839.9, 78598.9, 120557]

# Use larger value for stable constant
factor = times[-1] / (sizes[-1] ** 4)

# Expected O(n^4)
expected = []
for n in sizes:
    expected.append(factor * (n ** 4))

# Plot
plt.plot(sizes, times, 'o-', label='Observed Time')
plt.plot(sizes, expected, 'x--', label='Expected O(n⁴)')

plt.xlabel('Number of Points (n)')
plt.ylabel('Time (microseconds)')
plt.title('Time Complexity of Convex Hull (Brute Force)')

plt.legend()
plt.grid()

plt.show()