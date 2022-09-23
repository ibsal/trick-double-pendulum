#!/usr/bin/env python3
import matplotlib.pyplot as plt
import numpy as np


data = np.genfromtxt('../Modified_data/tableData',
                     delimiter='	',
                     skip_header=4,
                     skip_footer=1,
                     names=['t', 'x1', 'y1', 'x2', 'y2'],
                     dtype=(float, float)
                    )

curve1 = plt.plot(data['x1'], data['y1'], 'C1-')
curve2 = plt.plot(data['x2'], data['y2'], 'C2-')
plt.legend(('Mass1', 'Mass2'))
plt.title('Pendulum Position')
plt.xlabel('pos x (m)')
plt.ylabel('pos y (m)')
plt.grid(True)
plt.show()
