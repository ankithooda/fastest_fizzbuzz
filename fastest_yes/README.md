# Fastest Yes

## `yes` - Outputs a continous stream of character `y`

`yes | pv -a > /dev/null` [8.8 GiB/s]

The above command consists of two userland programs - `yes` and `pv`

Now, consider the following command which only consists of one userland program `pv`.

`pv -a < /dev/zero > /dev/null` [21.7 GiB/s]

### Without using splice

`pv` provides an option `-C` which disallows the use of `splice` syscall.  

`yes | pv -a -C > /dev/null`

Throughput - 3.87 GiB/s

`pv -a -C < /dev/zero > /dev/null`

Throughput - 21.7 GiB/s

Conclusion: 

`pv` is indeed using splice in the first because the throughput becomes half if you instruct it not to use splice.

### Now we will analyze each of the above command in `strace` to understand what is going on more deeply.



`strace yes | pv -a -S -s 1073741824 > /dev/null`





