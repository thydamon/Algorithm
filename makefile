# 2.6.35-22-generic
CXX=g++
C_FLAGS+=-g -Wall -DDEBUG
LIB_FLAGS=-pthread
OBJ=Sort
TARGET=$(OBJ)
all:$(TARGET)
$(OBJ):$(OBJ).o
	$(CXX) -o $@ $^ $(C_FLAGS) $(LIB_FLAGS)
.cpp.o:
	$(CXX) -c -o $*.o $(C_FLAGS) $(LIB_FLAGS) $*.cpp

.PHONY:clean
clean:
	rm -f *.o
	rm -f $(TARGET)

