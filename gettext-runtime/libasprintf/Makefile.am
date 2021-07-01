## Makefile for the gettext-runtime/libasprintf subdirectory of GNU gettext
## Copyright (C) 2002-2007, 2009-2011, 2013, 2016, 2018-2019, 2021 Free Software Foundation, Inc.
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation; either version 2.1 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU Lesser General Public License for more details.
##
## You should have received a copy of the GNU Lesser General Public License
## along with this program.  If not, see <https://www.gnu.org/licenses/>.

## Process this file with automake to produce Makefile.in.

AUTOMAKE_OPTIONS = 1.5 gnu no-dependencies
ACLOCAL_AMFLAGS = -I ../../m4 -I ../m4 -I gnulib-m4

SUBDIRS = gnulib-lib

EXTRA_DIST =
BUILT_SOURCES =
MOSTLYCLEANFILES =

RM = rm -f


AM_CPPFLAGS = -Ignulib-lib -I$(srcdir)/gnulib-lib

DEFS = -DIN_LIBASPRINTF @DEFS@

if WOE32
# On mingw, disable the declarations of *printf functions as aliases to the
# corresponding __mingw_*printf functions, because
# - these functions are useless for i18n purposes (not POSIX/XSI compliant),
# - they pull in a dependency to the libgcc_s_sjlj DLL (through the symbols
#   __udivdi3, __umoddi3).
DEFS += -D__USE_MINGW_ANSI_STDIO=0
endif


# Library include file.

include_HEADERS = autosprintf.h

all-local $(libasprintf_la_OBJECTS): autosprintf.h
autosprintf.h: autosprintf.in.h
	cp $(srcdir)/autosprintf.in.h autosprintf.h
MOSTLYCLEANFILES += autosprintf.h
EXTRA_DIST += autosprintf.in.h

dist-hook:
	rm -f $(distdir)/autosprintf.h


# Library code.

lib_LTLIBRARIES = libasprintf.la

noinst_LTLIBRARIES =

libasprintf_la_SOURCES = \
  lib-asprintf.h lib-asprintf.c \
  autosprintf.h autosprintf.cc

# Sources used only on platforms lacking vasprintf().
lib_asprintf_EXTRASOURCES = \
  asnprintf.c \
  vasprintf.h vasprintf.c asprintf.c
lib-asprintf.lo: $(lib_asprintf_EXTRASOURCES)
EXTRA_DIST += $(lib_asprintf_EXTRASOURCES)


# Limit the set of exported symbols, on those platforms where libtool supports it.
# Currently this excludes the symbols from gnulib modules, that we have mapped
# to symbols prefixed with 'libasprintf_' through config.h.
LIBASPRINTF_EXPORTED_SYMBOLS_REGEX = '^[^l]|^l[^i]|^li[^b]|^lib[^a]|^liba[^s]|^libas[^p]|^libasp[^r]|^libaspr[^i]|^libaspri[^n]|^libasprin[^t]|^libasprint[^f]|^libasprintf[^_]'


# Version information according to Woe32 conventions.
EXTRA_DIST += libasprintf.rc
if WOE32
WOE32_LIBADD = libasprintf.res.lo
# This rule is executed only on Woe32 systems.
# Use $(RC) with libtool, $(WINDRES) when not using libtool.
# The following sed expressions come from the windres-options script. They are
# inlined here, so that they can be written in a Makefile without requiring a
# temporary file. They must contain literal newlines rather than semicolons,
# so that they work with the sed-3.02 that is shipped with MSYS.
libasprintf.res.lo: $(srcdir)/libasprintf.rc
	nlinit=`echo 'nl="'; echo '"'`; eval "$$nlinit"; \
	sed_extract_major='/^[0-9]/{'$${nl}'s/^\([0-9]*\).*/\1/p'$${nl}q$${nl}'}'$${nl}'c\'$${nl}0$${nl}q; \
	sed_extract_minor='/^[0-9][0-9]*[.][0-9]/{'$${nl}'s/^[0-9]*[.]\([0-9]*\).*/\1/p'$${nl}q$${nl}'}'$${nl}'c\'$${nl}0$${nl}q; \
	sed_extract_subminor='/^[0-9][0-9]*[.][0-9][0-9]*[.][0-9]/{'$${nl}'s/^[0-9]*[.][0-9]*[.]\([0-9]*\).*/\1/p'$${nl}q$${nl}'}'$${nl}'c\'$${nl}0$${nl}q; \
	$(LIBTOOL) --tag=RC $(AM_LIBTOOLFLAGS) $(LIBTOOLFLAGS) --mode=compile $(RC) \
	  "-DPACKAGE_VERSION_STRING=\\\"$(VERSION)\\\"" \
	  "-DPACKAGE_VERSION_MAJOR="`echo '$(VERSION)' | sed -n -e "$$sed_extract_major"` \
	  "-DPACKAGE_VERSION_MINOR="`echo '$(VERSION)' | sed -n -e "$$sed_extract_minor"` \
	  "-DPACKAGE_VERSION_SUBMINOR="`echo '$(VERSION)' | sed -n -e "$$sed_extract_subminor"` \
	  -i $(srcdir)/libasprintf.rc -o libasprintf.res.lo --output-format=coff
MOSTLYCLEANFILES += libasprintf.res.lo
else
WOE32_LIBADD =
endif
libasprintf_la_LIBADD       = $(WOE32_LIBADD)
libasprintf_la_DEPENDENCIES = $(WOE32_LIBADD)

# How to build libasprintf.
# With libtool 1.5.14, on some platforms, like BeOS, "libtool --tag=CXX" fails
# to create a shared library, however "libtool --tag=CC" succeeds.
libasprintf_la_LDFLAGS = @LTNOUNDEF@ -export-symbols-regex $(LIBASPRINTF_EXPORTED_SYMBOLS_REGEX)
libasprintf.la: $(libasprintf_la_OBJECTS) $(libasprintf_la_DEPENDENCIES) gnulib-lib/libgnu.la
	$(AM_V_GEN)$(CXXLINK) -rpath $(libdir) $(libasprintf_la_LDFLAGS) $(libasprintf_la_OBJECTS) $(libasprintf_la_LIBADD) gnulib-lib/libgnu.la $(LIBS) || \
	$(LINK) -rpath $(libdir) $(libasprintf_la_LDFLAGS) $(libasprintf_la_OBJECTS) $(libasprintf_la_LIBADD) gnulib-lib/libgnu.la $(LIBS)


# Allow users to use "gnulib-tool --update".
EXTRA_DIST += gnulib-m4/gnulib-cache.m4


# Clean up after Solaris cc.
clean-local:
	rm -rf SunWS_cache

# Windows support.

EXTRA_DIST += INSTALL.windows
