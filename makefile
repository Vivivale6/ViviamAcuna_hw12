grafica.png: advection.txt VA_graph.py
	python VA_graph.py
advection.txt: eje12
	./eje12 > advection.txt
eje12: VA_advection.cpp
	c++ VA_advection.cpp -o eje12
