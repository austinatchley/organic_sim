default:
	mkdir -p build
	g++ -std=c++17 -O3 src/*.cpp -o build/OrganicSim
	./build/OrganicSim

debug:
	mkdir -p build
	g++ -std=c++17 -Og src/*.cpp -o build/OrganicSim
	./build/OrganicSim -d

format:
	clang-format -i src/*.cpp src/*.h 

clean:
	rm -rf build/
	rm -f OrganicSim
