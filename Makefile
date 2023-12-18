CC = g++

OBJECTS := *.o
TARGETS = src/prismRender/*.cpp src/prismObject/*.cpp src/prismIO/*.cpp src/prismText/*.cpp src/prismLoader/*.cpp
OUTPUT = build/libPrism.a
SDLINCLUDE = lib/SDL2/include
PRISMINCLUDE = include

Prism: $(OBJECTS)
	if [ ! -d "build" ]; then mkdir build; fi
	ar rcs $(OUTPUT) $(OBJECTS)
	@echo -e "\033[0;32mProject built successfully!\033[0m"

$(OBJECTS): $(TARGETS)
	$(CC) -c $(TARGETS) -I$(SDLINCLUDE) -I$(PRISMINCLUDE)

clean:
	rm *.o