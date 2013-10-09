#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include <gtk/gtk.h>


struct Parametre
{
	const char* fonction;
	int mu;
	int j;
	int l;
	int N;
	int k;
	float deb_periode;
	float fin_periode;
} P;
