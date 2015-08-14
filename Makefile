CC=g++

LFLAGS=-lncurses
CFLAGS=-Wall -Wextra

IDIR=include
SDIR=src
ODIR=obj

DEPS=$(wildcard $(IDIR)/*.h)
SRCS=$(wildcard $(SDIR)/*.cpp)
OBJS=$(SRCS:$(SDIR)/%.cpp=$(ODIR)/%.o)

PROG=dfs

all: $(PROG)

$(PROG): $(OBJS) 
	$(CC) $(LFLAGS) $(CFLAGS) $(OBJS) -o $(PROG)

$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CC) $(CFLAGS) -I$(IDIR) -c -o $@ $<

clean:
	rm -rf $(ODIR)/*.o $(PROG)
