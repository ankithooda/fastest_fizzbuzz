# Fastest Yes

## `yes` - Outputs a continous stream of character `y`

`yes | pv > /dev/null`

Throughput - 8.8 GiB/s

The above command consists of two userland programs - `yes` and `pv`

Now, consider the following command

`pv < /dev/zero > /dev/null`

Throughput - 21.7 GiB/s







