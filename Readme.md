# NNP - No New Privileges

`NO_NEW_Privileges` is a new linux mechanism to make sure a program or any child thereof can not gain any new privileges.

This sample program is based on http://www.outflux.net/blog/archives/2012/03/26/keeping-your-process-unprivileged/ from Kees Cook.

# COMPILE

```shell
gcc -Wall -O2 nnp.c -o nnp
```

# EXAMPLES

```shell
% nnp ping localhost     
ping: icmp open socket: Operation not permitted.

% nnp mtr localhost       
mtr: unable to get raw sockets.
```
