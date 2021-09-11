with open('sfl_push_forward.txt') as f:
    lines = f.readlines()
    x = [int(line.split()[0]) for line in lines]
    y = [int(line.split()[1]) for line in lines]

x = x[::100]
y = y[::100]

print(x)

import matplotlib.pyplot as plt
plt.title("subforwardlist push_forward")
plt.plot(x, y, 'b')
#plt.show()
plt.savefig("sfl_push_forward.png")
