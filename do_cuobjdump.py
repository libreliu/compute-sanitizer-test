import os

COMPUTE_SANITIZER = "compute-sanitizer.bat"
CU_OBJDUMP = "cuobjdump"
EXEC_SUFFIX = ".exe"
DYN_LIB_SUFFIX = ".dll"

def do_dump(name):
    res = [
        f"{CU_OBJDUMP} bin/Debug/{name}{EXEC_SUFFIX} > results/{name}.cuobjdump.log",
        f"{COMPUTE_SANITIZER} bin/Debug/{name}{EXEC_SUFFIX} > results/{name}.log",
    ]
    return res

def do_dump_dyn_lib(name):
    res = [
        f"{CU_OBJDUMP} bin/Debug/{name}{DYN_LIB_SUFFIX} > results/{name}.cuobjdump.log"
    ]
    return res


cmds = []
cmds += do_dump("memcheck")
cmds += do_dump("memcheck-g")
cmds += do_dump("memcheck-hybrid-g")
cmds += do_dump("memcheck-dynamic-hybrid-g")
cmds += do_dump_dyn_lib("memcheck-dynamic-hybrid-g-lib")

for cmd in cmds:
    print(f"> {cmd}")
    os.system(cmd)