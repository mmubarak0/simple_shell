# 0x16. C - Simple Shell
## The Gates of Shell”, by @spencerhcheng, featuring @julienbarbier42

#### issues:

- to continue with the cd(), we need to create _setenv.
- There is lot of memory leaks in this shell.
	- 9 bytes in 2 blocks are still reachable in loss record 1 of 3
   		`by 0x10A634: _tokenize (_token.c:41)
   		by 0x109F94: process (process.c:33)
   		by 0x109B84: main (main.c:24)`
	- 32 bytes in 1 blocks are still reachable in loss record 2 of 3
		`by 0x10A53F: _tokenize (_token.c:22)
		by 0x109F94: process (process.c:33)
		by 0x109B84: main (main.c:24)`
#### TODO
- impelemnt:
	- eval.c `exec file commands`
	- _setenv.c `change an enviroment variable`
	- modify print_strings() to accept `%s`
