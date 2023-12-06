CXX = g++
BIN_DIR = bin

# Specify the target file as a command-line argument
src = $(SRC_DIR)
file = $(TARGET_FILE)

# Generate the corresponding object file and executable
target = $(BIN_DIR)/$(basename $(file))

all: $(BIN_DIR) $(target)

$(target): $(SRC_DIR)/$(TARGET_FILE)
	$(CXX) $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean
