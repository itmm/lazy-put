# `lazy-put`

Command line tool to copy the contents of standard input into a file
specified at the command line. The tool accepts only a single file path as
an argument (apart from the required `--help`).

The tool uses the `lazy-write` library for writing, so the file is only
modified, if its contents changes.

`cmake` is used for building this small tool in C++17. The program itself is
written using [https://github.com/itmm/md-patcher](md-patcher). This tool is
used to extract the source code from the Markdown files.

# Detailed Design

The `main` function first parses the command line.

Then it processes the standard input line by line and puts it into the
specified file.

The implementation can be found at [lazy-put.md](./lazy-put.md).
