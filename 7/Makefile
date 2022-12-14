CC=gcc
CFLAGS=
EXE = run

#should make it so it includes all .c files
SOURCES = main.c loop.c stack_functions.c tree_functions.c
#create from SOURCES; deal with later
OBJECTS = $(SOURCES:%.c=%.o)
#source/object without suffix
WITHOUT = $(SOURCES:%.c=%.)
#make so includes all .h files
HEADERS = constants.h loop.h stack_functions.h  structures.h tree_functions.h


#need to improve so doesn't compile everything each time 
${EXE}: ${SOURCES} ${HEADERS}
	${CC} -o ${EXE} ${SOURCES}



clean: 
	-rm -f $(EXE)      # Remove the executable file
	-rm -f $(OBJECTS)  # Remove the object files
