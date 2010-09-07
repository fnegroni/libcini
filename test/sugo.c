#include <stdio.h> // for fprintf
#include <stdlib.h> // for abort and exit
#include <argp.h> // for argp*

static const int EXIT_ARGS = 1;

const char *argp_program_version = "0.1";
const char *argp_program_bug_address = "<f.e.negroni@gmail.com>";
error_t argp_err_exit_status;
const char *const NONPOSITIONAL_ARGS_DOC = "TEST...";
const char *const PROGRAM_DOC = "sugo -- a test framework for system routines.";

unsigned int verbosity_level = 1;
size_t count;

static error_t
program_options_parser(int key, char *arg, struct argp_state *state)
{
	if ('v' == key) {
		++verbosity_level;
		fprintf(stderr, "Verbosity level now %u.\n", verbosity_level);
	} else if ('q' == key) {
		verbosity_level = 0;
		fprintf(stderr, "Verbosity level now %u.\n", verbosity_level);
	} else if (ARGP_KEY_ARG == key) {
		++count;
		fprintf(stderr, "Adding %s to list.\n", arg);
	} else if (ARGP_KEY_END == key) {
		if (!count) {
			argp_error(state, "no tests specified.");
		}
	} else {
		return ARGP_ERR_UNKNOWN;
	}

	return 0;
}

int
main(int argc, char **argv)
{
	argp_err_exit_status = EXIT_ARGS;

	struct argp_option program_options[] = {
		{"verbose", 'v', 0, 0, "Make logging more verbose."},
		{"quiet", 'q', 0, 0, "Turn logging off completely."},
		{0}
	};

	struct argp program_parser = {
		program_options,
		program_options_parser,
		NONPOSITIONAL_ARGS_DOC,

		PROGRAM_DOC
	};

	error_t err = argp_parse(&program_parser, argc, argv, 0, 0, 0);
	if (err) {
		if (EINVAL == err) {
			exit(EXIT_ARGS);
		}
		abort();
	}
	return 0;
}
