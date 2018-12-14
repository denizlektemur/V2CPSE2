src = $(wildcard *.cpp)
headers = $(wildcard *.hpp)

FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lstdc++

applicationName = application

$(applicationName): $(src) $(headers)
	g++ -o $@ $^ $(FLAGS)

build: $(applicationName)

run: build
	./$(applicationName)

.PHONY: clean
clean:
	rm -f $(obj) $(applicationName)