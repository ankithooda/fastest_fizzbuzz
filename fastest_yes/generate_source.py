import sys
from string import Template

bytes_to_send = int(sys.argv[1])
bytes = 'y\\n' * bytes_to_send

source_code = """
#include <stdio.h>
#include <unistd.h>

int main() {{
    while(1) {{
        write(1, "{}", {});
    }}
    return 0;
}}
""".format(bytes, bytes_to_send)

print(source_code)