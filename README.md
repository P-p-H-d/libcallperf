# libcallperf
Library for using the linux 'perf stat' command within an isolated portion of a program 

# Usage:

## int libcallperf\_start(char *what)

Start a measure with the perf stat command.
'what' is an extra parameter for the perf command, or NULL if none special.
It returns 0 in case of success.


## struct libcallperf\_report\_s *libcallperf\_stop(void)

Stop the measure and returns a measure report.
Or NULL in case of failure.


## double libcallperf\_get (const struct libcallperf\_report\_s *report, const char name[])

Get the value associated to the name 'name' in the report
and return it. Return NAN if the name is not present in the report.


## void libcallperf\_print (FILE *stream, const struct libcallperf\_report\_s *report)

Print all the report on the given stream.

## void libcallperf\_free (struct libcallperf\_report\_s *report);

Free the report.


# Example

 See test.c
 
# Limitation:

* Not precise enought for small measure.
* Not for production.

