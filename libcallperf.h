/* LIBCALLPERF
   Copyright 2018 Patrick Pelissier
	
   The LIBCALLPERF Library is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation; either version 3 of the License, or (at your
   option) any later version.
 	
   The LIBCALLPERF Library is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public
   License for more details.
 	
   You should have received a copy of the GNU Lesser General Public License
   along with the LIBCALLPERF Library; see the file COPYING.LESSER.  If not, see
   http://www.gnu.org/licenses/ or write to the Free Software Foundation, Inc.,
   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA. */

#ifndef __LIBCALLPERF_H
#define __LIBCALLPERF_H

#include <stdio.h>

struct libcallperf_report_s;

extern int libcallperf_start(char *what);
extern struct libcallperf_report_s *libcallperf_stop(void);
extern double libcallperf_get (const struct libcallperf_report_s *report, const char name[]);
extern void libcallperf_print (FILE *stream, const struct libcallperf_report_s *report);
extern void libcallperf_free (struct libcallperf_report_s *report);

#endif
