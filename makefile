default:
	g++ -Og *.cpp -o OrganicSim
	./OrganicSim

clean:
	rm -rf build/
	rm -f OrganicSim
