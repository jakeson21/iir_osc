#!/usr/bin/env python3
import numpy as np
import matplotlib.pyplot as plt
import subprocess


command = ["../build/tone_gen", "-r", "48000", "-f", "7", "-n", "4801000", "-N", "9600"]
result = subprocess.run(command, capture_output=True, text=True)
output = result.stdout.strip()
lines = output.splitlines()
words = output.split()

print(words)

if words[1] == '4':
    data = np.fromfile(words[0], dtype=np.float32)
elif words[1] == '8':
    data = np.fromfile(words[0], dtype=np.double)
else:
    print("ERROR")

x_y = data.reshape(int(data.size/2),2)

print(x_y.shape, np.abs(data.max()))
plt.plot(x_y[-9600:, :])
plt.grid(True)
plt.show()
