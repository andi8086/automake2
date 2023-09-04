# How to start with autotools

Requirements: Makefile.am, configure.ac

```
aclocal
autoconf
automake --add-missing
```

# Configuration

```
./configure
```

# Make a distribution package

```
make dist-xz
```

# Compile

```
make
```

# Cleaning

```
make clean     # Removes all built files produced by make
make dist-clean # also removes generated Makefile and more
```

# User should not ...

... run `autoreconf`, nor have autotools installed.
We should ship with `./configure` in place.




