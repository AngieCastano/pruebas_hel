# Lite Shell

Lite Shell is a simple command interpreter that provides basic functions for interacting with the OS, pipes handling is not provided but Lite shell handles memory management for preventing memory leaks, Lite shell is not meant to be a replacement of BASH, SH or another well-supported shell since lite shell is developed for basic understanding of shell functions

## Getting started

* Lite Shell works on Unix-like systems but Linux distros are prefered

* Lite Shell is not distributed by any homebrew then for installing you must clone the repository and copy liteshell to /bin

Inside the repository execute:

```bash
cp liteshell /bin
```

## Usage

### Invocation

* in non interactive mode from SH:

```bash
SH> echo "input" | liteshell
SH> "input"
```

* In interactive mode:

```bash
SH> liteshell
lsh> echo "input"
lsh> "input"
```

* Going out interactive mode

```bash
lsh> exit
SH>
```

## Road Map

* --

## Contributing
Pull requests and reporting issues are always welcome, make a pull request for contacting us :)

## License

Educational purposes, content is not licensed and it does not have technical support
