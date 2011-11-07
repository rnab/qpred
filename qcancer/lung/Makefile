#
# Copyright 2011 ClinRisk Ltd. 
# 
# QCancer(Lung)-2011 is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# QCancer(Lung)-2011 is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public License
# along with QCancer(Lung)-2011  If not, see <http://www.gnu.org/licenses/>.
# 
# The initial version of this file, to be found at http://qrisk.org/lifetime, faithfully implements QCancer(Lung)-2011.
# We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.  However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone randomly permuting the coefficients. 
# We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://qcancer.org/lung.
# Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
#

INCLUDES = 

# C++ compiler flags (-g -O2 -Wall)
CCFLAGS = -std=c99 -g

# compiler
CC = gcc

# library paths
LIBS = -lm

# compile flags
LDFLAGS = 

SOURCES = $(wildcard *.c)

.SUFFIXES: .c

default: depend executables

executables: Q64_lungcancer_stcox_26_0_commandLine Q64_lungcancer_stcox_26_1_commandLine 

Q64_lungcancer_stcox_26_0_commandLine: Q64_lungcancer_stcox_26_0_commandLine.o Q64_lungcancer_stcox_event_26_0.o Q64_lungcancer_stcox_death_26_0.o lifetimeRisk.o util.o

Q64_lungcancer_stcox_26_1_commandLine: Q64_lungcancer_stcox_26_1_commandLine.o Q64_lungcancer_stcox_event_26_1.o Q64_lungcancer_stcox_death_26_1.o lifetimeRisk.o util.o


.c:
	$(CC) $(INCLUDES) $(LDFLAGS) $< -o $@ $(LIBS)

.c.o:
	$(CC) $(INCLUDES) $(CCFLAGS) -c $< -o $@

depend:
	makedepend -- $(CFLAGS) -- $(INCLUDES) $(SOURCES)

clean:
	rm -f *.o *commandLine *.bak

# DO NOT DELETE
