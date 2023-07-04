fizz_simple:
	gcc fizz.c -o ./bin/fizz_simple
	./bin/fizz_simple

fizz_branchless:
	gcc fizz_branchless.c -o ./bin/fizz_branchless
	./bin/fizz_branchless | pv > /dev/null
