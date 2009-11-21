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
 * XML source: Qmodel_fracture_1.xml
 * STATA dta time stamp: 2 Sep 2009 08:55
 * C file create date: Fri Nov 20 22:52:44 GMT 2009
 */

#include <stdio.h>
#include <stdlib.h>
#include <irisk/Qmodel_fracture_1.h>

static double score[11];
static char errorBuf[1024];
static int error;

void usage(void) {
	printf(" * Copyright 2009 ClinRisk Ltd.\n");
	printf(" * \n");
	printf(" * This is part of QFracture (http://qfracture.org).\n");
	printf(" * \n");
	printf(" * QFracture is free software: you can redistribute it and/or modify\n");
	printf(" * it under the terms of the GNU Lesser General Public License as published by\n");
	printf(" * the Free Software Foundation, either version 3 of the License, or\n");
	printf(" * (at your option) any later version.\n");
	printf(" * \n");
	printf(" * QFracture is distributed in the hope that it will be useful,\n");
	printf(" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
	printf(" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
	printf(" * GNU Lesser General Public License for more details.\n");
	printf(" * \n");
	printf(" * You should have received a copy of the GNU Lesser General Public License\n");
	printf(" * along with QFracture.  If not, see <http://www.gnu.org/licenses/>.\n");
	printf(" * \n");
	printf(" * This file has been auto-generated.\n");
	printf(" * XML source: Qmodel_fracture_1.xml\n");
	printf(" * STATA dta time stamp: 2 Sep 2009 08:55\n");
	printf(" * C file create date: Fri Nov 20 22:52:44 GMT 2009\n");
	printf(" *\n");
	printf("Usage:\n");
	printf("  Qmodel_fracture_1_commandLine age b_asthma b_corticosteroids b_cvd b_falls b_liver b_ra b_tca b_type2 bmi close_alcohol_category smoke_cat surv\n");
}

int main (int argc, char *argv[]) {
	if (argc!=14) {
		usage();
		exit(1);
	}

	int age = atoi(argv[1]);
	int b_asthma = atoi(argv[2]);
	int b_corticosteroids = atoi(argv[3]);
	int b_cvd = atoi(argv[4]);
	int b_falls = atoi(argv[5]);
	int b_liver = atoi(argv[6]);
	int b_ra = atoi(argv[7]);
	int b_tca = atoi(argv[8]);
	int b_type2 = atoi(argv[9]);
	double bmi = atof(argv[10]);
	int close_alcohol_category = atoi(argv[11]);
	int smoke_cat = atoi(argv[12]);
	int surv = atoi(argv[13]);

	double score = fracture_male(age,b_asthma,b_corticosteroids,b_cvd,b_falls,b_liver,b_ra,b_tca,b_type2,bmi,close_alcohol_category,smoke_cat,surv,&error,errorBuf,sizeof(errorBuf));
	if (error) {
		printf("%s", errorBuf);
		exit(1);
	}
	printf("%f\n", score);
}
