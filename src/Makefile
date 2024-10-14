CXX=g++
RM=rm -f

TARGET := knn

.PHONY: all knn clean distclean

all: knn

knn: main.cc
	$(CXX) -std=c++11 main.cc -o knn

distclean:
	$(RM) knn
