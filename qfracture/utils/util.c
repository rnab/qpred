/* 
 * Copyright 2009 ClinRisk Ltd.
 * 
 * This file is part of QFracture (http://qfracture.org).
 * 
 * QFracture is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QFracture is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QFracture.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * This file has been auto-generated.
 * XML source: Qmodel_fracture_0.xml
 * STATA dta time stamp: 2 Sep 2009 08:55
 * C file create date: Fri Nov 20 22:39:59 GMT 2009
 */

#include <string.h>
#include <irisk/util.h>

int is_boolean(int b) {
	int result=0;
	if (b==1 || b==0) {
		result = 1;
	}
	return result;
}

int d_in_range(double x, double min, double max) {
	return !(x<min || x>max);
}

int i_in_range(int x, int min, int max) {
	return !(x<min || x>max);
}

void strlcat(char *dst, char *src, int n) {
        if (strlen(src) + 1 > n - strlen(dst))
                strcpy(dst, "errorBuf has been truncated");
        (void)strncat(dst, src, n - strlen(dst) - 1);
}
