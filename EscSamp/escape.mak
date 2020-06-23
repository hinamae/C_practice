CC				= gcc
CFLAGS		=
DEST			= 
LDFLAGS		=
LIBS				= 
OBJS          = escapeFull.o etest.o
PROGRAM       = etest

all:	$(PROGRAM)

$(PROGRAM):	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)

clean:	
	rm -f *.o 

install:	$(PROGRAM)
		install -s $(PROGRAM) $(DEST)
