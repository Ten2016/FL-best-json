target: main

SRC_DIR=src

SRC_FILE=best_json.c
DST_LIB=libjson.so

main:
	@echo make
	gcc -fPIC -shared $(SRC_DIR)/$(SRC_FILE) -o $(SRC_DIR)/$(DST_LIB)


install:
	@echo mv 'so' to lib
	mv src/*.so lib


clean:
	@echo clean
	rm -f src/*.so
	rm -f lib/*.so
