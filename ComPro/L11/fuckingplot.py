#%%

import matplotlib.pyplot as plt 
import numpy as np 
import pandas as pd 

temp =  [28,32,25,35,30]
hun =   [50,65,34,90,75]
rain =  [10,25,0,50,16]

# fuck = list(zip(temp,hun,rain))


# x = np.array( list(range(-2,3)))
# y = np.array( list( i**3 - 2*i - 1 for i in range(-2,3)))
# plt.plot(x,y)
# plt.grid(True)
# #plt.legend(True)
# plt.show()

# x = np.arange(0,6,0.1)

plt.scatter(temp,hun, c= rain)
plt.grid(True )
plt.xlabel('Temperature(C)')
plt.ylabel('Hunmidity ( % ) ')
cbar = plt.colorbar()
cbar.ax.set_title('Rainfall (mm)')
plt.set_cmap("jet")
plt.show()





# df  = pd.DataFrame(data = fuck , columns = [ 'Temp','Human','Rain'])
# df.plot()
# plt.show()

# plt.plot(hun, rain, 'ro')
# #plt.axis(temp)
# plt.show()