import sys
import subprocess
# Usage: arguments-from-file.py <argument-file> <tool> <module> [<extra-arg1> ... <extra-argN>]
# The module name is not used by the command, but including it in the arguments
# improves visibility when investigating errors (because cmake reports this command)
if len(sys.argv) < 2:
    print("[ERROR] Supply output file then tool")
    sys.exit(1)
with open(sys.argv[1], "r") as file_handle:
    args = sys.argv[3:] + [line.strip() for line in file_handle.readlines()]
    sys.exit(subprocess.run(args, stdout=file_handle).returncode)
