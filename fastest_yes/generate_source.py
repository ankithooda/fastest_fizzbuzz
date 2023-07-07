import sys
from string import Template

bytes_to_send = int(sys.argv[1])
bytes = "y\n"*bytes_to_send

source_code = "#include <stdio.h>\n#include <unistd.h>\nint main() " + '{' + 
"""
    // int i = 0; 
    // Bytes to write is 4096/4096
    while(1) """ + '{' +
""" 
        // i++;
        write(1, {}, {})
""".format(bytes, bytes_to_send) + '} return 0; }';

print(source_code)