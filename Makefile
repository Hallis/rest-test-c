#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# define the C compiler to use
CC = gcc

# define any compile-time flags
CFLAGS = -Wall -Werror -Wmissing-prototypes -Werror=unused-but-set-variable

# define the executable file 
PROG = resttest

# define any directories containing header files other than /usr/include
# libcurl:   /D/Program/msys64/usr/include
# libjson-c: /D/Program/msys64/ucrt64/include
INCLUDES = -I/D/Program/msys64/usr/include

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
# libcurl:   /D/Program/msys64/usr/lib
# libjson-c: /D/Program/msys64/ucrt64/lib
LFLAGS = -L/D/Program/msys64/usr/lib

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
#LIBS = -lcurl -ljson
LIBS = -ljson-c

# define the C source files
#SRCS = main.c
SRCS = jsonarraytest.c

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.c=.o)


#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#
.PHONY: depend clean

all:	$(PROG)
	@echo Simple compiler named $(PROG) has been compiled

#$(MAIN): $(OBJS) 
#	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)
$(PROG): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $@ $(LFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ *.exe $(PROG)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
