TARGET	=	program
CXX	= g++
RM=del -f
CPPFLAGS	= 


default: $(TARGET)
all: clean default

OBJECTS	= $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h)

%.o: %.cpp $(HEADERS)
		$(CXX) $(CPPFLAGS) -c $< -o $@


$(TARGET): $(OBJECTS)
		$(CXX) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
		$(RM) *.o
		$(RM) $(TARGET).exe