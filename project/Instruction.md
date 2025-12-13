## Инструкция

Чтобы собрать это приложение, выполните:

```console
$ gcc main.c optSort.s -Wall -Wextra -Wpedantic -O2 -o main
```

optSort.c был скомпилирован в optSort.s с помощью:

```console
$ gcc optSort.c -S -O2 -Wall -Wextra -Wpedantic -o optSort.s
```