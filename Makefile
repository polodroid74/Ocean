PROG = vect
SOURCES = Dvector.cpp vect.cpp
OBJETS = $(SOURCES:.cpp=.o)
CXX = clang++
CXXFLAGS = -Wall -g

$(PROG) : $(OBJETS)
	$(CXX) $(CXXFLAGS) -o $(PROG) $(OBJETS) $(LDFLAGS)

.cpp.o :
	$(CXX) $(CXXFLAGS) $< -o $@
