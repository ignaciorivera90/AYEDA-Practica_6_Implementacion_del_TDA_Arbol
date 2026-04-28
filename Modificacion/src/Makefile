CXX = g++
CXXFLAGS = -std=c++23 -Wall -I../include

# ========= PROGRAMA PRINCIPAL =========
SRC = main.cc functions.cc nif.cc
OBJ = $(SRC:.cc=.o)
EXECUTABLE = p06_arboles

# ========= TEST =========
TEST_SRC = ../test/test_unitario.cc nif.cc
TEST_EXEC = test_unitario

# ========= BUILD =========
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ========= TEST =========
test:
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o $(TEST_EXEC)

# ========= CLEAN =========
.PHONY: clean test
clean:
	rm -f $(OBJ) $(EXECUTABLE) $(TEST_EXEC)