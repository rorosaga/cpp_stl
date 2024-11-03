import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import numpy as np

data1 = np.loadtxt("word_freqs.txt", dtype=str)
ranks1 = data1[:, 0].astype(int)
frequencies1 = data1[:, 1].astype(int)

data2 = np.loadtxt("word_freqs2.txt", dtype=str)
ranks2 = data2[:, 0].astype(int)
frequencies2 = data2[:, 1].astype(int)

plt.figure()

plt.loglog(ranks1, frequencies1, marker='o', linestyle='None', label='Dataset 1 (word_freqs.txt)')
plt.loglog(ranks2, frequencies2, marker='x', linestyle='None', label='Dataset 2 (word_freqs2.txt)', color='orange')

plt.xlabel('Rank')
plt.ylabel('Frequency')
plt.title('Word Frequency Distribution')
plt.grid(True)

plt.legend()

plt.savefig('word_freqs_comparison.png')
