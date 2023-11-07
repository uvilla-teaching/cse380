import matplotlib as mpl                                               
import numpy as np

# Different modes
# By default, you can "show()" the figure which gives you an interactive window
# and it will save a .png when you call savefig().
# PDF produces a .pdf file, but show() doesn't work.
#mpl.use("PDF")

# Must set backend before bring in pyplot
import matplotlib.pyplot as plot

data = np.loadtxt( "x.dat", skiprows=2 )

size = data.size

f = 1.0
x = np.linspace(0.0, 1.0, 200,endpoint=True)
x0 = np.linspace(0.0, 1.0, size,endpoint=True)

y = -1.0*f*x*x/2.0 + f*x/2

plot.plot(x,y,"k-")
plot.plot(x0,data[:],"b-")

plot.show()
