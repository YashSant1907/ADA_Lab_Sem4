# =====================================
# Week-1 ADA Lab Codes
# Algorithm Design and Analysis
# =====================================
import matplotlib.pyplot as plt

# Input sizes and observed execution times
sizes = [1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000]
times = [1.8111, 10.0077, 20.3784, 45.5015, 60.9216, 83.2699, 102.262, 117.997, 141.985, 162.923]

# Estimate proportional constant for linear growth
factor = times[-1] / sizes[-1]

# Expected O(n) values
expected = []
for n in sizes:
    expected.append(factor * n)

# Plot graph
plt.plot(sizes, times, 'o-', label='Observed Time')
plt.plot(sizes, expected, 'x--', label='Expected O(n)')

plt.xlabel('Array Size (n)')
plt.ylabel('Time (microseconds)')
plt.title('Time Complexity of Array Sum')

plt.xticks(sizes)
plt.legend()
plt.grid()

plt.show()