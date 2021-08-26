CC=g++
TARGET=autocmp
SRC=run.cpp src/autocmp.cpp

run:$(TARGET)
	$(TARGET)

$(TARGET):$(SRC)
	$(CC) $(SRC) -o $(TARGET)