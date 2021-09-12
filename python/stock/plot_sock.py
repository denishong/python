import matplotlib.pyplot as plt
import csv

x = []
y = []

with open('aa.txt','r') as csvfile:
    plots = csv.reader(csvfile, delimiter=' ')
    for row in plots:
#        x.append((row[0]))
        y.append((row[1]))

type(y)
		
#ymin = min(int(y))
#ymax = max(int(y))
#plt.ylim(20000, 100)
plt.plot(y, label='Loaded from file!')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Interesting Graph\nCheck it out')
plt.legend()
plt.show()
