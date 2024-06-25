CC = clang++
BUILD_DIR = build/bin
SOURCE_DIR = src
.PHONY: all clean clear


server :
	$(CC)$(cflags) $(SOURCE_DIR)/server/server.cpp -o $(BUILD_DIR)/server
	./$(BUILD_DIR)/server
	
