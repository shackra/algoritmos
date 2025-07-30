ext := if os_family() == "windows" { ".exe" } else { "" }

[private]
default:
	@just --list

[private]
build:
	mkdir -p build
	cmake -B build -DCMAKE_BUILD_TYPE=Debug
	cmake --build build --config Debug

run PROGRAM: build
	./build/{{PROGRAM}}{{ext}}

list:
	@echo "· programas disponibles ·"
	@echo "binary_search"
	@echo "bubble_sort"
	@echo "two_crystal_balls"
	@echo "queue"
