default:
	g++ -O3 *.cpp -o OrganicSim
	./OrganicSim

debug:
	g++ -Og *.cpp -o OrganicSim
	./OrganicSim -d

clean:
	rm -rf build/
	rm -f OrganicSim
