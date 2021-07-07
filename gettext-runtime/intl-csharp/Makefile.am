## Makefile for the gettext-runtime/intl-csharp subdirectory of GNU gettext
## Copyright (C) 2003-2004, 2006, 2013, 2015, 2018 Free Software Foundation, Inc.
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <https://www.gnu.org/licenses/>.

## Process this file with automake to produce Makefile.in.

AUTOMAKE_OPTIONS = 1.2 gnits
EXTRA_DIST =
CLEANFILES =

RM = rm -f

CSHARPCOMP = $(SHELL) ../csharpcomp.sh
CSHARPCOMPFLAGS = @CSHARPCOMPFLAGS@


all-local: all-dll
install-data-local: install-dll
installdirs-local: installdirs-dll
uninstall-local: uninstall-dll


# Special rules for C# compilation.

all-dll: all-dll-@BUILDCSHARP@
all-dll-no:
all-dll-yes: GNU.Gettext.dll

GNU.Gettext.dll: intl.cs
	$(CSHARPCOMP) $(CSHARPCOMPFLAGS) -o $@ $(srcdir)/intl.cs

EXTRA_DIST += intl.cs

CLEANFILES += GNU.Gettext.dll GNU.Gettext.dll.mdb

install-dll: install-dll-@BUILDCSHARP@
install-dll-no:
	$(MKDIR_P) $(DESTDIR)$(libdir)
install-dll-yes: all-dll-yes
	$(MKDIR_P) $(DESTDIR)$(libdir)
	$(INSTALL_DATA) GNU.Gettext.dll $(DESTDIR)$(libdir)/GNU.Gettext.dll

installdirs-dll:
	$(MKDIR_P) $(DESTDIR)$(libdir)

uninstall-dll:
	$(RM) $(DESTDIR)$(libdir)/GNU.Gettext.dll

