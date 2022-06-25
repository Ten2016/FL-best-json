target: main

SRC_DIR=src
SRC_FILE=best_json.c

INCLUDE_FILE=best_json.h

DST_LIB_A=libjson.a
DST_LIB_SO=libjson.so

main:
	@echo make
	gcc -g -c $(SRC_DIR)/$(SRC_FILE) -o $(SRC_DIR)/$(DST_LIB_A)
	gcc -g -fPIC -shared $(SRC_DIR)/$(SRC_FILE) -o $(SRC_DIR)/$(DST_LIB_SO)


install:
	mv -Force $(SRC_DIR)/$(DST_LIB_A) lib
	mv -Force $(SRC_DIR)/$(DST_LIB_SO) lib
	cp -Force $(SRC_DIR)/INCLUDE_FILE include

clean:
	@echo clean
	rm -f src/*.a
	rm -f src/*.so
	rm -f lib/*
