# Compiler and flags
CXX := g++

ifeq ($(g),true)
    CXXFLAGS += -g
endif

# Get the number from the make command (e.g., make 1)
TARGET := $(firstword $(MAKECMDGOALS))

# Find the matching source file
SRC := $(wildcard $(TARGET).*.cpp)

# Avoid confusing Make with numbered targets
.PHONY: all clean $(TARGET)

# Default rule — show usage
all:
	@echo "Usage: make <number>"
	@echo "Example: make 1 (compiles 1.*.cpp -> ./1)"

# Compile rule
$(TARGET):
	@if [ -z "$(SRC)" ]; then \
		echo "❌ Error: No source file found matching '$(TARGET).*.cpp'"; \
		exit 1; \
	fi
	@echo "🔧 Compiling: $(SRC) -> $(TARGET)"
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	@echo "✅ Done! Run it with ./$(TARGET)"

# Clean rule
clean:
	@echo "🧹 Cleaning executables..."
	rm [0-9]

# Prevent 'make clean' etc. from being interpreted as file names
%:
	@true

