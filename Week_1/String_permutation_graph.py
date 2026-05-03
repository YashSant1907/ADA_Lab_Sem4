# =====================================
# Week-1 ADA Lab Codes
# Algorithm Design and Analysis
# =====================================
import matplotlib.pyplot as plt
import math

# Input sizes and observed times
sizes = [3, 4, 5, 6, 7, 8, 9, 10]
times = [0, 0, 0, 0, 0, 803.1, 5713.3, 55094.4]

# Calculate scaling factor for factorial growth
factor = times[-1] / math.factorial(sizes[-1])

# Expected O(n!) values
expected = []
for n in sizes:
    expected.append(factor * math.factorial(n))

# Plot graph
plt.plot(sizes, times, 'o-', label='Observed Time')
plt.plot(sizes, expected, 'x--', label='Expected O(n!)')

plt.xlabel('Input Size (n)')
plt.ylabel('Time (microseconds)')
plt.title('Time Complexity of String Permutations')

plt.xticks(sizes)
plt.legend()
plt.grid()

plt.show()