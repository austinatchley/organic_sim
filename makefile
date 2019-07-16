default:
	g++ -std=c++17 -O3 *.cpp -o OrganicSim
	./OrganicSim

debug:
	g++ -std=c++17 -Og *.cpp -o OrganicSim
	./OrganicSim -d

clean:
	rm -rf build/
	rm -f OrganicSim
