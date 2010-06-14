/* 
 * Copyright 2010 ClinRisk Ltd.
 * 
 * This file is part of QDScore (http://qdscore.org, http://svn.clinrisk.co.uk/opensource/qdscore).
 * 
 * QDScore is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QDScore is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QDScore.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qdscore, faithfully implements QDScore.
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qdscore.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Qmodel_type2_0.xml
 * STATA dta time stamp: 2 Sep 2009 08:55
 * C file create date: Mon Jun 14 10:39:28 BST 2010
 */

#include <stdio.h>
#include <stdlib.h>
#include <irisk/Qmodel_type2_0.h>

static double score[11];
static char errorBuf[1024];
static int error;

void usage(void) {
	printf(" * Copyright 2010 ClinRisk Ltd.\n");
	printf(" * \n");
	printf(" * This is part of QDScore (http://qdscore.org, http://svn.clinrisk.co.uk/opensource/qdscore).\n");
	printf(" * \n");
	printf(" * QDScore is free software: you can redistribute it and/or modify\n");
	printf(" * it under the terms of the GNU Lesser General Public License as published by\n");
	printf(" * the Free Software Foundation, either version 3 of the License, or\n");
	printf(" * (at your option) any later version.\n");
	printf(" * \n");
	printf(" * QDScore is distributed in the hope that it will be useful,\n");
	printf(" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
	printf(" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
	printf(" * GNU Lesser General Public License for more details.\n");
	printf(" * \n");
	printf(" * You should have received a copy of the GNU Lesser General Public License\n");
	printf(" * along with QDScore.  If not, see <http://www.gnu.org/licenses/>.\n");
	printf(" * \n");
	printf(" * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qdscore, faithfully implements QDScore.\n");
	printf(" * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.\n");
	printf(" * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.\n");
	printf(" * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qdscore.\n");
	printf(" * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.\n");
	printf(" *\n");
	printf(" * This file has been auto-generated.\n");
	printf(" * XML source: Qmodel_type2_0.xml\n");
	printf(" * STATA dta time stamp: 2 Sep 2009 08:55\n");
	printf(" * C file create date: Mon Jun 14 10:39:28 BST 2010\n");
	printf(" *\n");
	printf("Usage:\n");
	printf("  Qmodel_type2_0_commandLine age b_corticosteroids b_cvd b_treatedhyp bmi ethrisk fh_diab smok surv town\n");
}

int main (int argc, char *argv[]) {
	if (argc!=11) {
		usage();
		exit(1);
	}

	int age = atoi(argv[1]);
	int b_corticosteroids = atoi(argv[2]);
	int b_cvd = atoi(argv[3]);
	int b_treatedhyp = atoi(argv[4]);
	double bmi = atof(argv[5]);
	int ethrisk = atoi(argv[6]);
	int fh_diab = atoi(argv[7]);
	int smok = atoi(argv[8]);
	int surv = atoi(argv[9]);
	double town = atof(argv[10]);

	double score = type2_female(age,b_corticosteroids,b_cvd,b_treatedhyp,bmi,ethrisk,fh_diab,smok,surv,town,&error,errorBuf,sizeof(errorBuf));
	if (error) {
		printf("%s", errorBuf);
		exit(1);
	}
	printf("%f\n", score);
}
