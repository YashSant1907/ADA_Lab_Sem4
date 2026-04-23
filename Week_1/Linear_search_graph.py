import matplotlib.pyplot as plt

# Input sizes and observed times
sizes = [100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000]
times = [0.0000, 0.3837, 0.6784, 1.1595, 1.9368, 2.299, 3.1201, 3.4446, 4.0446, 4.6457]

# Estimate constant for O(n)
factor = times[-1] / sizes[-1]

# Expected linear growth
expected = []
for s in sizes:
    expected.append(factor * s)

# Plotting
plt.plot(sizes, times, 'o-', label='Observed Time')
plt.plot(sizes, expected, 'x--', label='Expected O(n)')

plt.xlabel('Input Size (n)')
plt.ylabel('Time (microseconds)')
plt.title('Time Complexity of Linear Search')

plt.legend()
plt.grid()

plt.show()