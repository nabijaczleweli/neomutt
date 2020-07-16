/**
 * @file
 * Shared constants/structs that are private to libpattern
 *
 * @authors
 * Copyright (C) 2020 Richard Russon <rich@flatcap.org>
 *
 * @copyright
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MUTT_PATTERN_PRIVATE_H
#define MUTT_PATTERN_PRIVATE_H

#include "config.h"
#include <stdbool.h>

/**
 * enum PatternEat - Function to process pattern arguments
 *
 * Values for PatternFlags.eat_arg
 */
enum PatternEat
{
  EAT_NONE,          ///< No arguments required
  EAT_REGEX,         ///< Process a regex
  EAT_DATE,          ///< Process a date (range)
  EAT_RANGE,         ///< Process a number (range)
  EAT_MESSAGE_RANGE, ///< Process a message number (range)
  EAT_QUERY,         ///< Process a query string
};

/**
 * struct PatternFlags - Mapping between user character and internal constant
 */
struct PatternFlags
{
  int tag;   ///< Character used to represent this operation, e.g. 'A' for '~A'
  int op;    ///< Operation to perform, e.g. #MUTT_PAT_SCORE
  int flags; ///< Pattern flags, e.g. #MUTT_PC_FULL_MSG

  enum PatternEat eat_arg;
  char *desc;
};

extern const struct PatternFlags Flags[];

extern char *C_ExternalSearchCommand;
extern char *C_PatternFormat;
extern bool  C_ThoroughSearch;

#endif /* MUTT_PATTERN_PRIVATE_H */
