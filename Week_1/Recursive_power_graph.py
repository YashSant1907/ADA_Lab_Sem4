import matplotlib.pyplot as plt
import math

# Input values and observed times
exponents = [100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000]
times = [0.12, 0.18, 0.22, 0.27, 0.30, 0.33, 0.36, 0.38, 0.41, 0.43]

# Estimate constant for log growth
factor = times[-1] / math.log2(exponents[-1])

# Expected O(log n) values
expected = []
for n in exponents:
    expected.append(factor * math.log2(n))

# Plot graph
plt.plot(exponents, times, 'o-', label='Observed Time')
plt.plot(exponents, expected, 'x--', label='Expected O(log n)')

plt.xlabel('Exponent (n)')
plt.ylabel('Time (microseconds)')
plt.title('Time Complexity of Recursive Power Function')

plt.legend()
plt.grid()

plt.show()