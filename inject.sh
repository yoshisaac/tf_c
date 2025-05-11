#!/bin/bash

LIB_PATH=$(pwd)/tf_c.so
PROCID=$(pgrep tf_linux64 | head -n 1)

unload() {
    echo -e "\nUnloading library with handle $LIB_HANDLE"
    
    RC=$(gdb -n --batch -ex "attach $PROCID" \
             -ex "call ((int (*) (void *)) dlclose)((void *) $LIB_HANDLE)" \
             -ex "call ((char * (*) (void)) dlerror)()" \
             -ex "detach" 2> /dev/null | grep -oP '\$2 = 0x\K[0-9a-f]+')
    
    if [[ "$RC" == "0" ]]; then
        echo "Library unloaded successfully"
    else
        echo "Failed to unload library"
    fi
}

trap unload SIGINT

LIB_HANDLE=$(sudo gdb -n --batch -ex "attach $PROCID" \
                  -ex "call ((void * (*) (const char*, int)) dlopen)(\"$LIB_PATH\", 1)" \
                  -ex "detach" 2> /dev/null | grep -oP '\$1 = \(void \*\) \K0x[0-9a-f]+')

if [ -z "$LIB_HANDLE" ]; then
    echo "Failed to load library"
    exit 1
fi

echo "Library loaded successfully at $LIB_HANDLE. Use Ctrl+C to unload."

# Logs are printed to STDERR, watch load logs via `cat /proc/$(pidof tf_linux64)/fd/2` from another terminal
cat /proc/$(pidof tf_linux64)/fd/2
