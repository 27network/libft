# libft-neo [![kiroussa's 42 Libft Score](https://badge42.coday.fr/api/v2/clqhi717m065501p4hai37lsg/project/3383637)](https://projects.intra.42.fr/projects/42cursus-libft/projects_users/3383637)

42's standard library recode, by `kiroussa`.

**Note**: This project is a personal extension to the original libft project. Please look into the
[flattened branch](https://github.com/27network/libft/tree/flattened) to see the original libft.

## Building

You can simply run the GNU `make` command-line utility to build the project:
```sh
# the -j flag makes use of multiple CPU threads, allowing for faster build times

make -j$(nproc)
```

You can then find both a static and dynamically linked library in the `build/output` folder.

**Warning**: Don't try to call `make re` with the -j flag, it *will* break stuff (and no I'm not fixing it).

## Documentation

The documentation uses [doxygen](https://www.doxygen.nl/) as a builder, after installing it, you can
just run `doxygen` in your terminal to build the documentation:
```bash
cd /path/to/your/libft

# Call doxygen to build the documentation
doxygen
```

The documentation will be created in `docs/output/html` (or `docs/output/man` for manpages).
