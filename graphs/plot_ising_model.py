import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
data = pd.read_csv('../data/ising_data.csv')

# Plot the magnetism over steps
plt.figure(figsize=(10, 5))
plt.plot(data['Step'], data['Magnetism'], label='Magnetism', color='blue')
plt.xlabel('Step')
plt.ylabel('Magnetism')
plt.title('Magnetism over Steps')
plt.legend()
plt.grid(True)
plt.savefig('magnetism_over_steps.png')  # Save the plot as an image
plt.show()

# Plot the temperature over steps
plt.figure(figsize=(10, 5))
plt.plot(data['Step'], data['Temperature'], label='Temperature', color='orange')
plt.xlabel('Step')
plt.ylabel('Temperature (kT)')
plt.title('Temperature over Steps')
plt.legend()
plt.grid(True)
plt.savefig('temperature_over_steps.png')  # Save the plot as an image
plt.show()
