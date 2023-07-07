fizz_simple:
	gcc fizz.c -o ./bin/fizz_simple
	./bin/fizz_simple

fizz_branchless:
	gcc fizz_branchless.c -o ./bin/fizz_branchless
	./bin/fizz_branchless | pv > /dev/null

trace_print_buff:
	gcc buffer_experiments/print_buff.c	-o ./bin/print_buff
	strace ./bin/print_buff

print_buff:
	gcc buffer_experiments/print_buff.c	-o ./bin/print_buff
	./bin/print_buff

yes_trace:
	gcc yes.c -o ./bin/yes
	strace ./bin/yes > /dev/null