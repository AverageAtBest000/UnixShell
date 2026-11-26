# UnixShell

![Language](https://img.shields.io/badge/language-C-blue)
![Standard](https://img.shields.io/badge/standard-gnu23-informational)
![Build](https://img.shields.io/badge/build-CMake-064F8C?logo=cmake)
![Platform](https://img.shields.io/badge/platform-Linux-lightgrey?logo=linux)
![License](https://img.shields.io/badge/license-GPL--3.0-green)

A minimal Unix shell written in C (`gnu23`), built on POSIX APIs.

## Features
- **Raw-mode input**: the terminal is put into non-canonical mode via `termios` (`ICANON`, `ECHO` and `ISIG` disabled), and input is read and echoed one byte at a time.
- **Command execution**: commands run in a child process via `fork()` & `execvp()`, and the parent waits with `waitpid()`.
- **Built-ins**: `cd` No argument changes to `$HOME`.
- **Tab completion**: completes file paths in the current directory by longest prefix match.
- **Signal handling**: `Ctrl+C` clears the current line, while child processes keep the default `SIGINT` behavior. `Ctrl+D` exits the shell.

## Project Structure
```
src/
├── main.c          # REPL loop, terminal setup/teardown
├── lexer.c         # tokenizer
├── parser.c        # parser
├── executor.c      # fork/exec/wait
├── builtins.c      # built-in commands
└── input/
    ├── input.c     # raw byte reader, key dispatch
    ├── handlers.c  # backspace, tab, Ctrl+C, Ctrl+D
    └── completion.c # file path completion
```

## Dependencies
- `clang`
- `cmake` (≥ 3.16)
- [libds-c](https://github.com/Villy-P/libds-c), fetched automatically through CMake `FetchContent`

On Arch:
```bash
sudo pacman -S clang cmake
```
Modify according to your distribution.

## Building
```bash
git clone https://github.com/AverageAtBest000/shell
cd shell
make
./shell
```

Alternatively, build entirely with CMake:
```bash
cmake -S . -B build
cmake --build build
./build/shell
```

## Roadmap
- [ ] Recursive tab completion (paths more than one directory deep)
- [ ] Pipes (`|`)
- [ ] Command chaining: `;`, `&&`, `||`
- [ ] Variable expansion: `$VAR`, `$?`
- [ ] `~` expansion, single quotes, and backslash escapes
- [ ] Stderr redirection: `2>`, `2>&1`
- [ ] Glob expansion (`*.c`)

## License
This project is licensed under the GPL-3.0. See [LICENSE](LICENSE) for details.
