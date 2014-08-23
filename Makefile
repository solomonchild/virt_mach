all:
	make -f Makefile.libsvm
	make -f Makefile.test
clean:
	rm -rf bin/
	rm -rf obj/
