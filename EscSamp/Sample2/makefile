CC				= gcc
CFLAGS		=
DEST			= 
LDFLAGS		=
LIBS				= 
OBJS          = c_game.o realkey.o escape.o
PROGRAM       = sample

all:	$(PROGRAM)

$(PROGRAM):	$(OBJS)
		$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) $(LIBS) -o $(PROGRAM)

clean:	
	rm -f *.o 

install:	$(PROGRAM)
		install -s $(PROGRAM) $(DEST)
