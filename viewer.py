import numpy as np
import matplotlib.pyplot as plt

a = "1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-255-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-255-255-255-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-255-255-255-255-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-255-255-255-255-255-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-255-1-255-255-255-1-1-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-255-255-1-1-1-1-1-1-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-1-255-1-1-1-1-1-1-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-1-1-1-1-1-1-1-1-1-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-1-1-1-1-1-1-1-1-1-1-255-255-255-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-1-1-1-1-1-1-1-1-1-1-255-255-255-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-1-1-1-1-1-1-1-1-1-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-1-1-1-1-1-1-1-1-1-255-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-1-1-1-1-1-1-1-255-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-1-1-1-1-1-1-255-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-255-255-255-255-255-255-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-255-255-255-255-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-255-255-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1"
a = [int(i) for i in a.split("-")]



b = "1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-128-255-255-255-128-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-128-255-255-255-255-255-128-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-128-255-255-255-255-255-255-255-128-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-128-255-255-255-255-255-255-255-255-255-128-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-255-255-255-255-255-255-255-128-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-255-255-255-255-255-255-255-255-128-1-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-255-255-255-255-255-255-255-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-255-255-128-191-223-112-56-155-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-128-255-255-255-255-255-255-128-191-96-1-1-1-255-255-255-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-1-1-1-1-1-1-1-1-1-255-255-255-1-1-1-1-1-1-1-1-1-1-1-128-255-255-128-1-1-1-1-1-1-1-1-1-1-255-255-255-1-1-1-1-1-1-1-1-1-1-128-255-255-255-128-1-1-1-1-1-1-1-1-1-1-255-255-255-1-1-1-1-1-1-1-1-1-1-128-255-255-255-128-1-1-1-1-1-1-1-1-1-255-255-255-128-1-1-1-1-1-1-1-1-1-1-128-255-255-255-1-1-1-1-1-1-1-1-1-255-255-255-255-128-1-1-1-1-1-1-1-1-1-1-128-255-255-255-1-1-1-1-1-1-1-128-255-255-255-255-128-1-1-1-1-1-1-1-1-1-1-1-128-255-255-255-1-1-1-1-1-1-128-255-255-255-255-128-1-1-1-1-1-1-1-1-1-1-1-1-128-255-255-255-255-255-255-255-255-255-255-255-255-255-128-1-1-1-1-1-1-1-1-1-1-1-1-1-1-255-255-255-255-255-255-255-255-255-255-255-128-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-128-255-255-255-255-255-255-255-255-128-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-128-255-255-255-255-255-128-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1"
b = [int(i) for i in b.split('-')]


width = 28
height = 28

fig, (ax1, ax2) = plt.subplots(1, 2)

ax1.imshow(np.array(a).reshape(width, height), cmap='gray')
ax1.set_title('a')

ax2.imshow(np.array(b).reshape(width, height), cmap='gray')
ax2.set_title('b')

plt.show()
