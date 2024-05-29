# COMPILE CONFIGURE
CFLAGS = -Wall -Wextra $(LINK_DIRS)
CC := g++
EXECUTE_FILE := main

MODULES := Controller Model 
SRCDIR = $(foreach module,$(MODULES),$(module)/src)
INCDIR := View/src $(foreach module,$(MODULES),$(module)/inc)
OBJDIR := Build

LINK_DIRS = $(foreach dir, $(INCDIR), -I$(dir))
SRCS := $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.cpp))
OBJS := $(OBJDIR)/main.o $(patsubst %.cpp,./$(OBJDIR)/%.o,$(notdir $(SRCS)))

vpath %.cpp $(SRCDIR)

$(OBJDIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# $(OBJDIR)/main.o : main.cpp
# 	$(CC) $(CFLAGS) -c $< -o $(OBJDIR)/$@

build: $(OBJS)
	$(CC) $(OBJS) -o $(OBJDIR)/$(EXECUTE_FILE)

.PHONY: run
run:
	./$(OBJDIR)/$(EXECUTE_FILE)

.PHONY: clean
clean:
	rm -f $(OBJDIR)/*.o ./$(OBJDIR)/$(EXECUTE_FILE)

print-%:
	@echo $($*)