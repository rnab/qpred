/* 
 * Copyright 2011 ClinRisk Ltd.
 * 
 * This file is part of QCancer(Gastro-oesophageal) (http://qcancer.org/gastro-oesophageal, http://svn.clinrisk.co.uk/opensource/qcancer/gastro-oesophageal).
 * 
 * QCancer(Gastro-oesophageal) is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QCancer(Gastro-oesophageal) is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QCancer(Gastro-oesophageal).  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qcancer/gastro-oesophageal, faithfully implements QCancer(Gastro-oesophageal).
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qcancer/gastro-oesophageal.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q64_oesgastric_stcox_event_29_1.xml
 * STATA dta time stamp: 18 May 2011 12:50
 * C file create date: Thu  3 Nov 2011 11:49:24 GMT
 */

#include <stdio.h>
#include <stdlib.h>
#include <clinrisk/Q64_oesgastric_stcox_event_29_1.h>

static double score[3];
static char errorBuf[1024];
static int error;

void usage(void) {
	printf(" * Copyright 2011 ClinRisk Ltd.\n");
	printf(" * \n");
	printf(" * This is part of QCancer(Gastro-oesophageal) (http://qcancer.org/gastro-oesophageal, http://svn.clinrisk.co.uk/opensource/qcancer/gastro-oesophageal).\n");
	printf(" * \n");
	printf(" * QCancer(Gastro-oesophageal) is free software: you can redistribute it and/or modify\n");
	printf(" * it under the terms of the GNU Lesser General Public License as published by\n");
	printf(" * the Free Software Foundation, either version 3 of the License, or\n");
	printf(" * (at your option) any later version.\n");
	printf(" * \n");
	printf(" * QCancer(Gastro-oesophageal) is distributed in the hope that it will be useful,\n");
	printf(" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
	printf(" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
	printf(" * GNU Lesser General Public License for more details.\n");
	printf(" * \n");
	printf(" * You should have received a copy of the GNU Lesser General Public License\n");
	printf(" * along with QCancer(Gastro-oesophageal).  If not, see <http://www.gnu.org/licenses/>.\n");
	printf(" * \n");
	printf(" * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qcancer/gastro-oesophageal, faithfully implements QCancer(Gastro-oesophageal).\n");
	printf(" * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.\n");
	printf(" * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.\n");
	printf(" * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qcancer/gastro-oesophageal.\n");
	printf(" * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.\n");
	printf(" *\n");
	printf(" * This file has been auto-generated.\n");
	printf(" * XML source: Q64_oesgastric_stcox_event_29_1.xml\n");
	printf(" * STATA dta time stamp: 18 May 2011 12:50\n");
	printf(" * C file create date: Thu  3 Nov 2011 11:49:24 GMT\n");
	printf(" *\n");
	printf("Usage:\n");
	printf("  Q64_oesgastric_stcox_event_29_1_commandLine age c_hb new_abdopain new_appetiteloss new_dysphagia new_gibleed new_weightloss smoke_cat surv\n");
}

int main (int argc, char *argv[]) {
	if (argc!=10) {
		usage();
		exit(1);
	}

	int age = atoi(argv[1]);
	int c_hb = atoi(argv[2]);
	int new_abdopain = atoi(argv[3]);
	int new_appetiteloss = atoi(argv[4]);
	int new_dysphagia = atoi(argv[5]);
	int new_gibleed = atoi(argv[6]);
	int new_weightloss = atoi(argv[7]);
	int smoke_cat = atoi(argv[8]);
	int surv = atoi(argv[9]);

	double score = oesgastric_male(age,c_hb,new_abdopain,new_appetiteloss,new_dysphagia,new_gibleed,new_weightloss,smoke_cat,surv,&error,errorBuf,sizeof(errorBuf));
	if (error) {
		printf("%s", errorBuf);
		exit(1);
	}
	printf("%f\n", score);
}
