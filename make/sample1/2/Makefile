.PHONY: all clean

TARGET = test main
all : $(TARGET)

main :  
	cd ./main_src; make
	cp ./main_src/main ./

test : 
	cd io; make
	cp ./io/test ./

clean:
	rm $(TARGET)
	rm ./main_src/*.o ./main_src/main 
	rm ./io/*.o ./io/test 
