/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
 * Copyright (C) 2020 Stanislav
 * 
 * lsp1 is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * lsp1 is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <unistd.h>
int getopt(int argc, char *const argv[], const char *optstring);
extern char *optarg;
extern int optindm,  opterr, optopt; 


int main(int argc, char *argv[])
{
	int oc;
	char *b_opt_arg;
	while((oc = getopt(argc, argv, "ab:")) != -1) {
		switch(oc) {
		case 'a':
                printf("Parsing options a\n");
				break;
		case 'b':
				b_opt_arg = optarg;
				break;
        case ':':
                break;
        case '?':
        default:
                return 0;
				
	    }
    }
}

