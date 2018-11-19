all: *.pdf

*.txt: ODE.cpp PDE.cpp
	g++ ODE.cpp -o proyectil
	g++ PDE.cpp -o calcita
	./proyectil
	./calcita

*.pdf: *.txt Plots_hw4.py
	python Plots_hw4.py
	rm *.txt
	