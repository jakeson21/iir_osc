#!/usr/bin/env python3
import numpy as np
import pyaudio
import subprocess
import sys
import time
import wave


CHUNK = 1024

command = ["../build/tone_gen", "-r", "48000", "-f", "100", "-n", "1920000"]
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

print(x_y.shape)

data16 = (x_y * 0.8 * 32767).astype(dtype=np.int16)
data16 = data16.flatten('C')

print(data16.shape)

# Instantiate PyAudio and initialize PortAudio system resources (1)
p = pyaudio.PyAudio()

# Open stream (2)
stream = p.open(format=2,
                channels=2,
                rate=48000,
                output=True)


stream.write(data16)

time.sleep(0.1)

# Close the stream (5)
stream.close()

# Release PortAudio system resources (6)
p.terminate()
