/* 
 * Copyright 2010 ClinRisk Ltd.
 * 
 * This file is part of QRISK2-2010 (http://qrisk.org).
 * 
 * QRISK2-2010 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QRISK2-2010 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QRISK2-2010.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://qrisk.org, faithfully implements QRISK2-2010.
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone randomly permuting the coefficients.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://qrisk.org.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 *
 * This file has been auto-generated.
 * XML source: Q54_general_xml_74_cvd_0.xml
 * STATA dta time stamp: 26 Feb 2010 13:37
 * C file create date: Fri Apr 16 11:10:40 BST 2010
 */

#include <stdio.h>
#include <stdlib.h>
#include <irisk/Q54_general_xml_74_cvd_0.h>

static double score[11];
static char errorBuf[1024];
static int error;

void usage(void) {
	printf(" * Copyright 2010 ClinRisk Ltd.\n");
	printf(" * \n");
	printf(" * This is part of QRISK2-2010 (http://qrisk.org).\n");
	printf(" * \n");
	printf(" * QRISK2-2010 is free software: you can redistribute it and/or modify\n");
	printf(" * it under the terms of the GNU Lesser General Public License as published by\n");
	printf(" * the Free Software Foundation, either version 3 of the License, or\n");
	printf(" * (at your option) any later version.\n");
	printf(" * \n");
	printf(" * QRISK2-2010 is distributed in the hope that it will be useful,\n");
	printf(" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
	printf(" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
	printf(" * GNU Lesser General Public License for more details.\n");
	printf(" * \n");
	printf(" * You should have received a copy of the GNU Lesser General Public License\n");
	printf(" * along with QRISK2-2010.  If not, see <http://www.gnu.org/licenses/>.\n");
	printf(" * \n");
	printf(" * This file has been auto-generated.\n");
	printf(" * XML source: Q54_general_xml_74_cvd_0.xml\n");
	printf(" * STATA dta time stamp: 26 Feb 2010 13:37\n");
	printf(" * C file create date: Fri Apr 16 11:10:40 BST 2010\n");
	printf(" *\n");
	printf("Usage:\n");
	printf("  Q54_general_xml_74_cvd_0_commandLine age b_AF b_ra b_renal b_treatedhyp b_type2 bmi ethrisk fh_cvd rati sbp smok surv town\n");
}

int main (int argc, char *argv[]) {
	if (argc!=15) {
		usage();
		exit(1);
	}

	int age = atoi(argv[1]);
	int b_AF = atoi(argv[2]);
	int b_ra = atoi(argv[3]);
	int b_renal = atoi(argv[4]);
	int b_treatedhyp = atoi(argv[5]);
	int b_type2 = atoi(argv[6]);
	double bmi = atof(argv[7]);
	int ethrisk = atoi(argv[8]);
	int fh_cvd = atoi(argv[9]);
	double rati = atof(argv[10]);
	double sbp = atof(argv[11]);
	int smok = atoi(argv[12]);
	int surv = atoi(argv[13]);
	double town = atof(argv[14]);

	double score = cvd_female(age,b_AF,b_ra,b_renal,b_treatedhyp,b_type2,bmi,ethrisk,fh_cvd,rati,sbp,smok,surv,town,&error,errorBuf,sizeof(errorBuf));
	if (error) {
		printf("%s", errorBuf);
		exit(1);
	}
	printf("%f\n", score);
}
