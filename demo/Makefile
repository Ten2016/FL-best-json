target: main

INC_DIR=../include
LIB_DIR=../lib
LIB_LD=-ljson


main:
	@echo make
	gcc -g \
	-I$(INC_DIR) \
	-L$(LIB_DIR) \
	$(LIB_LD) \
	json_dump.c -o json_dump


clean:
	@echo clean
	rm -f json_dump
