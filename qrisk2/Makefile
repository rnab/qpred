# 
# Copyright 2011 ClinRisk Ltd.
# 
# This file is part of QRISK2-2011 (http://qrisk.org).
# 
# QRISK2-2011 is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# QRISK2-2011 is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public License
# along with QRISK2-2011.  If not, see <http://www.gnu.org/licenses/>.
# 
# The initial version of this file, to be found at http://qrisk.org, faithfully implements QRISK2-2011.
# We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.  However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone randomly permuting the coefficients. 
# We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://qrisk.org.
# Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
#

CMDLINE_SRC=$(wildcard commandLine/*.c)
CMDLINE_OBJS = $(CMDLINE_SRC:.c=.o)
EXECUTABLES = $(CMDLINE_SRC:.c=)

LIB_SRC=$(wildcard c/*.c) utils/util.c
LIB_OBJ = $(LIB_SRC:.c=.o)
LIB_OUT = lib/libirisk.a

INCLUDES = -I include

# C++ compiler flags (-g -O2 -Wall)
#CCFLAGS = -g
CCFLAGS = 

# compiler
CC = gcc

# library paths
LIBS = -Llib -lirisk -lm

# compile flags
#LDFLAGS = -g
LDFLAGS = 

.SUFFIXES: .c

default: dep $(LIB_OUT)

executables: $(EXECUTABLES)
	cp $(EXECUTABLES) executables

$(EXECUTABLES): $(LIB_OUT)

.c:
	$(CC) $(INCLUDES) $(LDFLAGS) $< -o $@ $(LIBS)

.c.o:
	$(CC) $(INCLUDES) $(CCFLAGS) -c $< -o $@

$(LIB_OUT): $(LIB_OBJ)
	ar rcs $(LIB_OUT) $(LIB_OBJ)

depend: dep

dep:
	makedepend -- $(CFLAGS) -- -I /usr/include/linux $(INCLUDES) $(LIB_SRC)

clean:
	rm -f $(LIB_OBJ) $(LIB_OUT) Makefile.bak
	rm -f $(CMDLINE_OBJ) $(CMDLINE_PROGS) 
	rm -f executables/*

veryClean: clean
	rm -f c/*.c include/irisk/*.h commandLine/*
	cp utils/util.h include/irisk

# DO NOT DELETE

