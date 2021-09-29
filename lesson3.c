/*
 * main.c
 * 
 * Copyright 2021 Rezvov_OA <Rezvov_OA@OLEG>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <math.h>

int main(void)
{
	float R;
	printf("Please enter radius R: ");
	scanf("%F", &R);
	float L = 2*M_PI*R;
	float A = M_PI*R*R;
	double V = 4/3.f*M_PI*R*R*R;		
	
	printf("Calculated length of circle: %.2f\n", L);
	printf("Calculated area of circle: %.2f\n", A);
	printf("Calculated volume of circle: %.3f\n", V);
	return 0;
}

