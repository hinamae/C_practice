CC				= gcc
CFLAGS		=
DEST			= 
LDFLAGS		=
LIBS				= 
OBJS          = test.o bclink.o escape.o
PROGRAM       = ktest

all:	$(PROGRAM)

$(PROGRAM):	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)

clean:	
	rm -f *.o 

install:	$(PROGRAM)
		install -s $(PROGRAM) $(DEST)
