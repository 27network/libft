# libft-neo

42's standard library recode, by `kiroussa`.

## Building

**Note**: This project is a personal extension to the original libft project. Please look into the
[flattened branch](https://github.com/27network/libft/tree/flattened) to see the original libft.

You can simply run the GNU `make` command-line utility to build the project:
```sh
# the -j flag makes use of multiple CPU threads, allowing for faster build times

make -j$(nproc)
```

**Warning**: Don't try to call `make re` with the -j flag, it *will* break stuff (and no I'm not fixing it).

You can find both a static and dynamically linked library in the `build/output` folder.
