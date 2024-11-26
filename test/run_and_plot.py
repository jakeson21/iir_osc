#!/usr/bin/env python3
import numpy as np
import matplotlib.pyplot as plt
import subprocess


command = ["../build/tone_gen", "48000"]
result = subprocess.run(command, capture_output=True, text=True)
output = result.stdout.strip()
lines = output.splitlines()
words = output.split()

# print(output)
# print(lines)
data = np.genfromtxt(lines)
print(data.shape)
plt.plot(data.real)
plt.grid(True)
plt.show()
