# libft-neo [![kiroussa's 42 Libft Score](https://badge42.coday.fr/api/v2/clqhi717m065501p4hai37lsg/project/3383637)](https://projects.intra.42.fr/projects/42cursus-libft/projects_users/3383637)

42's C standard library recode, by `kiroussa`.

**Note**: This project is a personal extension to the original libft project. Please look into the
[flattened branch](https://codeberg.org/27/libft/src/branch/flattened) to see the submitted project. 

## Building

You can simply run the GNU `make` command-line utility to build the project:
```sh
# the -j flag makes use of multiple CPU threads, allowing for faster build times

make -j$(nproc)
```

You can then find both a dynamically linked library in the `build/output` folder, which is also symlinked as `libft.so` in the project's root directory.

**Warning**: Don't try to call `make re` with the -j flag, it *will* break stuff (and no I'm not fixing it).

## Documentation

The documentation uses [doxygen](https://www.doxygen.nl/) as a builder, after installing it, you can
just run `doxygen` in your terminal to build the documentation:
```bash
cd /path/to/libft

# Call doxygen to build the documentation
doxygen
```

The documentation will be created in `docs/output/html` (or `docs/output/man` for manpages).
