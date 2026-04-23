import matplotlib.pyplot as plt

# Input data
degrees = [100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000]
observed_time = [0.3446, 1.7232, 3.8283, 7.6612, 11.2686, 16.0727, 19.5734, 23.149, 27.1224, 30.074]

# Calculate proportional constant for O(n)
constant = observed_time[-1] / degrees[-1]

# Expected linear time values
expected_time = []
for d in degrees:
    expected_time.append(constant * d)

# Plot graph
plt.plot(degrees, observed_time, 'o-', label='Observed Time')
plt.plot(degrees, expected_time, 'x--', label='Expected O(n)')

plt.xlabel('Polynomial Degree')
plt.ylabel('Time (microseconds)')
plt.title("Time Complexity of Horner's Method")

plt.legend()
plt.grid()

plt.show()