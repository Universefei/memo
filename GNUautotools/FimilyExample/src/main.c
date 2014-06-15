#include <stdio.h>
#include "wife.h"
#include "daughter.h"

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

int main() {
				printf("These are my girls/n");
				daughter_say();
				wife_say();
				return 0;
}

