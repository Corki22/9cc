CFLAGS=-Wall
SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o)

9cc: $(OBJS)
	$(CC) -o 9cc $(OBJS) $(LDFLAGS)

$(OBJS): head9cc.h

test: 9cc
		./test.sh

clean:
		rm -f 9cc *.o *~ tmp*
