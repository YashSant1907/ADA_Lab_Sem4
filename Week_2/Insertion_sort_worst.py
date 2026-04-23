import matplotlib.pyplot as plt

# Input sizes and observed times
sizes = [100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000]
times = [0, 0, 0, 3299.8, 5056.1, 8698.2, 13026.9, 18439.3, 24996.1, 36044.3]

# Use larger value for better approximation
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
plt.title('Time Complexity of Insertion Sort (Worst Case)')

plt.xticks(sizes)
plt.legend()
plt.grid()

plt.show()