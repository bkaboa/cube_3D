#ifndef INCLUDE_H
# define INCLUDE_H

/*
 *
 *********************************		OS_MACRO
 *
 */

# if defined (__APPLE__)
	# include "../mlx/mlx.h"
# elif defined(__linux__)
	# include "../mlx_linux/mlx.h"
#endif

/*
 *
 *********************************		INCLUDE
 *
 */

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <math.h>
# include <stddef.h>
# include "stdbool.h"
# include "define.h"

#endif
