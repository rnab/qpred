/* 
 * Copyright 2011 ClinRisk Ltd.
 * 
 * This file is part of QCancer(Lung)-2011 (http://qcancer.org/lung).
 * 
 * QCancer(Lung)-2011 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QCancer(Lung)-2011 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QCancer(Lung)-2011.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://qcancer.org/lung, faithfully implements QCancer(Lung)-2011.
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.  
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone randomly permuting the coefficients. 
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://qcancer.org/lung.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 *
 * This file has been auto-generated.
 * XML source: Q64_lungcancer_stcox_event_26_0.xml
 * STATA dta time stamp: 6 Mar 2011 16:20
 * C file create date: Thu  3 Nov 2011 12:33:45 GMT
 */

#include <stdio.h>
#include <stdlib.h>
#include "Q64_lungcancer_stcox_event_26_0.h"
#include "Q64_lungcancer_stcox_death_26_0.h"
#include "lifetimeRisk.h"

static double score[0];
static char errorBuf[1024];
static int error;

void usage(void) {
	printf(" * Copyright 2011 ClinRisk Ltd.\n");
	printf(" * \n");
	printf(" * This file is part of QCancer(Lung)-2011 (http://qcancer.org/lung).\n");
	printf(" * \n");
	printf(" * QCancer(Lung)-2011 is free software: you can redistribute it and/or modify\n");
	printf(" * it under the terms of the GNU Lesser General Public License as published by\n");
	printf(" * the Free Software Foundation, either version 3 of the License, or\n");
	printf(" * (at your option) any later version.\n");
	printf(" * \n");
	printf(" * QCancer(Lung)-2011 is distributed in the hope that it will be useful,\n");
	printf(" * but WITHOUT ANY WARRANTY; without even the implied warranty of\n");
	printf(" * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n");
	printf(" * GNU Lesser General Public License for more details.\n");
	printf(" * \n");
	printf(" * You should have received a copy of the GNU Lesser General Public License\n");
	printf(" * along with QCancer(Lung)-2011.  If not, see <http://www.gnu.org/licenses/>.\n");
	printf(" * \n");
	printf(" * The initial version of this file, to be found at http://qcancer.org/lung, faithfully implements QCancer(Lung)-2011.\n");
	printf(" * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.  \n");
	printf(" * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone randomly permuting the coefficients. \n");
	printf(" * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://qcancer.org/lung.\n");
	printf(" * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.\n");
	printf(" *\n");
	printf(" * This file has been auto-generated.\n");
	printf(" * XML source: Q64_lungcancer_stcox_event_26_0.xml\n");
	printf(" * STATA dta time stamp: 6 Mar 2011 16:20\n");
	printf(" * C file create date: Thu  3 Nov 2011 12:33:45 GMT\n");
	printf(" *\n");
	printf("Usage:\n");
	printf("  Q64_lungcancer_stcox_26_0_commandLine b_anycancer b_copd bmi c_hb new_appetiteloss new_haemoptysis new_weightloss s1_cough smoke_cat town age noOfFollowupYears\n");
}

int main (int argc, char *argv[]) {
        if (!(argc==13)) {
                usage();
                exit(1);
        }

	int b_anycancer = atoi(argv[1]);
	int b_copd = atoi(argv[2]);
	double bmi = atof(argv[3]);
	int c_hb = atoi(argv[4]);
	int new_appetiteloss = atoi(argv[5]);
	int new_haemoptysis = atoi(argv[6]);
	int new_weightloss = atoi(argv[7]);
	int s1_cough = atoi(argv[8]);
	int smoke_cat = atoi(argv[9]);
	double town = atof(argv[10]);
	int age = atoi(argv[11]);
	int noOfFollowupYears = atoi(argv[12]);


        lifetimeRiskInit("Q64_lungcancer_stcox_time_26_0");

	double a_event = Q64_lungcancer_stcox_event_26_0_event(b_anycancer,b_copd,bmi,c_hb,new_appetiteloss,new_haemoptysis,new_weightloss,s1_cough,smoke_cat,town,&error,errorBuf,sizeof(errorBuf));
	if (error) {
		printf("%s", errorBuf);
		exit(1);
	}
	double a_death = Q64_lungcancer_stcox_death_26_0_death(b_anycancer,b_copd,bmi,c_hb,new_appetiteloss,new_haemoptysis,new_weightloss,s1_cough,smoke_cat,town,&error,errorBuf,sizeof(errorBuf));
	if (error) {
		printf("%s", errorBuf);
		exit(1);
	}

        double result[2];

	lifetimeRisk(age, a_event, a_death, noOfFollowupYears, &result[0]);
         
        printf("%d-year : %f, lifetime: %f\n", noOfFollowupYears, result[0] * 100, result[1] * 100);
        // printf("%f, %f\n", result[0] * 100, result[1] * 100);

        lifetimeRiskClose();
}
