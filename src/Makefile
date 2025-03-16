CFLAGS=-g



all: tokenizer



tokenizer.o: tokenizer.h

history.o: history.h tokenizer.h

uimain.o:  tokenizer.h history.h



tokenizer: tokenizer.h history.h uimain.o

	cc -o $@ $^ $(CFLAGS)

clean:

	rm -f *.o *.c~ *.h~ *~ *.c# src

run:

	./tokenizer
