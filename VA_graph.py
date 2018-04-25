import numpy as np
import matplotlib.pyplot as plt

a= np.loadtxt("advection.txt")

x = a[:,0]
y = a [:,1]


    

plt.plot(x,y)
plt.xlabel("")
plt.ylabel("")
plt.savefig("grafica.png")
