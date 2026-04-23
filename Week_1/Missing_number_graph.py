import matplotlib.pyplot as plt

# Input sizes and execution times
sizes = [1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000]
times = [0.9168, 4.0997, 9.0822, 19.2284, 32.7541, 38.8241, 50.0533, 57.3787, 66.883, 77.608]

# Calculate proportional constant
factor = times[-1] / sizes[-1]

# Expected linear growth
expected = []
for s in sizes:
    expected.append(factor * s)

# Plot graph
plt.plot(sizes, times, 'o-', label='Observed Time')
plt.plot(sizes, expected, 'x--', label='Expected O(n)')

plt.xlabel('Input Size')
plt.ylabel('Time (microseconds)')
plt.title('Time Complexity of Missing Number Detection')

plt.legend()
plt.grid()

plt.show()