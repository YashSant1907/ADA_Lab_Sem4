import matplotlib.pyplot as plt

# Input sizes and observed times
sizes = [500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000]
times = [325.8, 841.8, 3328.3, 4985.8, 10637.4, 17329.4, 17700.9, 25945, 36059.9]

# Calculate proportional constant using last value
factor = times[-1] / (sizes[-1] ** 2)

# Expected O(n^2) values
expected = []
for n in sizes:
    expected.append(factor * (n ** 2))

# Plot graph
plt.plot(sizes, times, 'o-', label='Observed Time')
plt.plot(sizes, expected, 'x--', label='Expected O(n²)')

plt.xlabel('Input Size (n)')
plt.ylabel('Time (microseconds)')
plt.title('Time Complexity of Insertion Sort (Average Case)')

plt.xticks(sizes)
plt.legend()
plt.grid()

plt.show()