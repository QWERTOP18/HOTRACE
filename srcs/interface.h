/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yui <yui@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 23:02:15 by yui               #+#    #+#             */
/*   Updated: 2025/06/28 00:47:13 by yui              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
#define INTERFACE_H
#include "utils.h"


typedef enum e_state
{
    STORE,
    SEARCH,
    EXIT
} t_state;


/*
** Parse a line of input from the specified file descriptor.
** Returns a newly allocated string containing the parsed line,
** or NULL on failure.
*/
char *parse(int fd);

/*
** Create a new context for storing key-value pairs.
** Returns a pointer to the new context, or NULL on failure.
*/
void* new_ctx();

/*
** Free the context created by new_ctx.
*/
void free_ctx(void *ctx);

/*
** Store a key-value pair in the database.
** Returns -1 if fatal error, 0 on success.
*/
int store(const char *key, const char *value, void *ctx);

/* Search for a key in the database.
** Returns -1 if fatal error, 0 whether the key is found or not.,
*/
int search(const char *key, void *ctx);



/**
** Debug function to log the current state of the context.
*/
void debug_log(void *ctx);

#endif
