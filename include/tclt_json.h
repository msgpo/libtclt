/*
 * Copyright (c) 2012 Florent Tribouilloy <florent.tribouilloy AT epitech DOT net>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef TCLT_JSON_H_
# define TCLT_JSON_H_

#include <stddef.h>

# ifdef __cplusplus
extern "C" {
# endif
	
struct s_string
{
	char* buf;
	size_t len;
};

typedef struct s_string string;

enum element_type
{
    NOTHING,
    NULL_ELE,
    BOOL,
    INT,
    DOUBLE,
    NUMBER,
    STRING,
    MAP_KEY,
    START_MAP,
    END_MAP,
    START_ARRAY,
    END_ARRAY
};

struct s_elements
{
    struct s_elements* next;
    enum element_type type;
    union {
        int boolean;
        long long integer;
        double floating;
        char *buf;
    } u_value;
};

typedef struct s_elements elements;

elements *tclt_parse(const char*, size_t);

# ifdef __cplusplus
}
# endif

#endif
