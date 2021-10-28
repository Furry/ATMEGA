# from matplotlib import pyplot as plt;
# import numpy as np;

# # Import the CSV file named 'ADC Sensor Values'
# data = np.genfromtxt('ADC Sensor Values - Sheet1.csv', delimiter=',')
# # Remove the first headers
# data = data[1:,:]

# # Create a new figure, with the y axis labeled 'ADC Value' and the x axis labeled 'Distance'
# fig = plt.figure()
# ax = fig.add_subplot(111)
# ax.set_ylabel('ADC Value')
# ax.set_xlabel('Distance')

# for elem in data:
#     # Plot the data
#     ax.plot(elem[0], elem[1], 'ro')
# #END

# plt.show()

# Write the equation '188e^-4.78E-03x' in python.
import math

x = 99
y = 1.88 * math.e ** (-4.78e-3 * x)
print(y)