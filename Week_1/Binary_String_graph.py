import matplotlib.pyplot as plt

# Input sizes and observed execution time
sizes = [5, 8, 10, 12, 14, 16, 18, 20, 21, 23]
times = [0, 0, 0, 0, 0, 251.9, 1619.2, 5507.8, 10561.9, 44161.5]

# Calculate constant for exponential growth
constant = times[-1] / (2 ** sizes[-1])

# Expected O(2^n) values
expected = []
for n in sizes:
    expected.append(constant * (2 ** n))

# Plot graph
plt.plot(sizes, times, 'o-', label='Observed Time')
plt.plot(sizes, expected, 'x--', label='Expected O(2^n)')

plt.xlabel('Input Size (n)')
plt.ylabel('Time (microseconds)')
plt.title('Time Complexity of Binary String Generation')

plt.xticks(sizes)
plt.legend()
plt.grid()

plt.show()