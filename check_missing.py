#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fenc=utf-8

import os
import sys

makefile = open("Makefile", "r")
makefile_lines = makefile.readlines()
makefile.close()

src_files = []
src_files_line_index = -1
src_files_end_index = -1
for i in range(len(makefile_lines)):
    if makefile_lines[i].startswith("SRC_FILES"):
        src_files_line_index = i
    if src_files_line_index != -1 and "\\" not in makefile_lines[i]:
        src_files_end_index = i
        break
for i in range(src_files_line_index, src_files_end_index + 1):
    src_files.append(makefile_lines[i].strip("\\\n").replace("SRC_FILES", "").replace("=", "").strip())

src_files = ["src/" + file.strip() for file in src_files]

missing_files = []
for file in src_files:
    if not os.path.exists(file):
        missing_files.append(file)

# Check if files in the filesystem hierarchy are missing from the makefile
files_in_hierarchy = []
for root, dirs, files in os.walk("src"):
    for file in files:
        if file.endswith(".c") or file.endswith(".h"):
            files_in_hierarchy.append(os.path.join(root, file))

missing_files_in_hierarchy = []
for file in files_in_hierarchy:
    if file not in src_files:
        missing_files_in_hierarchy.append(file)

missing_files = sorted(missing_files)
missing_files_in_hierarchy = sorted(missing_files_in_hierarchy)

# Print the results
if len(missing_files) == 0:
    print("No missing files in the filesystem")
else:
    print("Missing files in the filesystem:")
    for file in missing_files:
        print(file)

if len(missing_files_in_hierarchy) == 0:
    print("No missing files in the Makefile")
else:
    print("Missing files in the Makefile")
    for file in missing_files_in_hierarchy:
        print(file)

if len(missing_files) != 0 or len(missing_files_in_hierarchy) != 0:
    sys.exit(1)

sys.exit(0)
