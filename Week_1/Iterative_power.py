# =====================================
# Week-1 ADA Lab Codes
# Algorithm Design and Analysis
# =====================================
import matplotlib.pyplot as plt

# Input exponents and observed times
exponents = [100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000]
times = [0.1977, 1.6159, 2.2045, 5.3444, 7.4811, 10.4615, 12.9536, 16.444, 18.5913, 21.0028]

# Estimate constant for linear growth
constant = times[-1] / exponents[-1]

# Expected O(n) values
expected = []
for n in exponents:
    expected.append(constant * n)

# Plot graph
plt.plot(exponents, times, 'o-', label='Observed Time')
plt.plot(exponents, expected, 'x--', label='Expected O(n)')

plt.xlabel('Exponent (n)')
plt.ylabel('Time (microseconds)')
plt.title('Time Complexity of Iterative Power Function')

plt.xticks(exponents)
plt.legend()
plt.grid()

plt.show()