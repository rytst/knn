CXX=g++
RM=rm -f

TARGET := knn

.PHONY: all knn clean distclean

all: knn

knn: %.o
	$(CXX) -std=c++11 main.cc -o knn

%.o: %.cc %.hh
	$(CXX) -std=c++11 

clean:
	$(RM) *.o

distclean:
	$(RM) knn

-include $(DEPS)
