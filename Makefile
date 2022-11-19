CC := g++
SRCDIR := src
OBJDIR := bin/objs
BINDIR := bin
SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/*.cpp,$(OBJDIR)/*.o,$(SRCS))

all: run

$(BINDIR)/lgf.exe: $(OBJS)
	$(CC) $^ -o $@

$(OBJDIR)/*.o: $(SRCDIR)/*.cpp
	$(CC) -c -o $@ $<

run: $(BINDIR)/lgf.exe $(OBJDIR)/*.o
	./$(BINDIR)/lgf.exe	
