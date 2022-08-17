target: main

SRC_DIR=src
SRC_FILE=best_json.c

LIB_DIR=lib
LIB_A=libjson.a
LIB_SO=libjson.so

INCLUDE_DIR=include
INCLUDE_FILE=*.h


main:
	@echo make
	# gcc -g -c $(SRC_DIR)/$(SRC_FILE) -o $(SRC_DIR)/$(LIB_A)
	gcc -g -fPIC -shared $(SRC_DIR)/$(SRC_FILE) -o $(SRC_DIR)/$(LIB_SO)


install:
	@echo install
	rm -rf $(LIB_DIR) && mkdir $(LIB_DIR)
	# mv $(SRC_DIR)/$(LIB_A) $(LIB_DIR)
	mv $(SRC_DIR)/$(LIB_SO) $(LIB_DIR)
	mkdir -p $(INCLUDE_DIR) && cp -f $(SRC_DIR)/$(INCLUDE_FILE) $(INCLUDE_DIR)

clean:
	@echo clean
	rm -f $(SRC_DIR)/*.a
	rm -f $(SRC_DIR)/*.so
	rm -rf $(LIB_DIR)/*
	rm -f $(INCLUDE_DIR)/$(INCLUDE_FILE)
