import matplotlib.pyplot as plt
import numpy as np

# Execution times in seconds (replace with real measurements)
methods = ['Scalar', 'NEON', 'OpenMP', 'GPU']
times = [1.0, 0.25, 0.15, 0.05]  # Example values; replace with real

# Speedup plot
plt.figure(figsize=(8,5))
plt.bar(methods, [1/t for t in times], color='skyblue')
plt.ylabel('Speedup')
plt.title('DLP Performance Comparison')
plt.savefig('Outputs/graphs/speedup_comparison.png')
plt.close()

# Energy vs Performance plot (example)
energy = [100, 80, 60, 50]  # hypothetical energy consumption
plt.figure(figsize=(8,5))
plt.scatter(times, energy, c='red')
for i, txt in enumerate(methods):
    plt.annotate(txt, (times[i], energy[i]))
plt.xlabel('Execution Time (s)')
plt.ylabel('Energy Consumption (J)')
plt.title('Energy vs Performance')
plt.savefig('Outputs/graphs/energy_performance_tradeoff.png')
plt.close()

print("Graphs generated in Outputs/graphs/")
