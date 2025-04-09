savedcmd_/home/xppgx1/module_test/hello.mod := printf '%s\n'   hello.o | awk '!x[$$0]++ { print("/home/xppgx1/module_test/"$$0) }' > /home/xppgx1/module_test/hello.mod
