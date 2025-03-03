SRC := src
OBJ := obj

TARGET := Hall

CXX := g++
INCLUDES := -Iinclude
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic $(INCLUDES)
DEPFLAGS = -MQ $@ -MP -MM -MF $(@:.o=.d)
LDFLAGS := -lm

SRCFILES := $(wildcard $(SRC)/*.cpp)
OBJFILES := $(patsubst $(SRC)/%.cpp,$(OBJ)/%.o,$(SRCFILES))
DEPFILES := $(OBJFILES:.o=.d)

$(shell mkdir -p $(OBJ))

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) $(LDFLAGS) -o $@ $^

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CXX) $(INCLUDES) $(DEPFLAGS) $<
	$(CXX) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(OBJ)

.PHONY: distclean
distclean: clean
	rm -f $(TARGET)

-include $(DEPFILES)
