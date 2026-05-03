# =====================================
# Week-1 ADA Lab Codes
# Algorithm Design and Analysis
# =====================================
import matplotlib.pyplot as plt

# Number of disks and observed execution times
disks = [5, 8, 10, 12, 14, 16, 18, 20, 22, 24]
times = [0, 0, 0, 0, 0, 260.5, 992, 4507.4, 16561.6, 66009.2]

# Estimate constant for exponential growth
factor = times[-1] / (2 ** disks[-1])

# Expected O(2^n) values
expected = []
for n in disks:
    expected.append(factor * (2 ** n))

# Plot graph
plt.plot(disks, times, 'o-', label='Observed Time')
plt.plot(disks, expected, 'x--', label='Expected O(2^n)')

plt.xlabel('Number of Disks (n)')
plt.ylabel('Time (microseconds)')
plt.title('Time Complexity of Tower of Hanoi')

plt.xticks(disks)
plt.legend()
plt.grid()

plt.show()