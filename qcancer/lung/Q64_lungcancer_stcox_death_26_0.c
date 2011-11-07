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
 * XML source: Q64_lungcancer_stcox_death_26_0.xml
 * STATA dta time stamp: 6 Mar 2011 16:20
 * C file create date: Thu  3 Nov 2011 12:33:27 GMT
 */

#include <math.h>
#include <string.h>
#include "Q64_lungcancer_stcox_death_26_0.h"
#include "util.h"

static double Q64_lungcancer_stcox_death_26_0_death_raw(
int b_anycancer,int b_copd,double bmi,int c_hb,int new_appetiteloss,int new_haemoptysis,int new_weightloss,int s1_cough,int smoke_cat,double town
)
{
	double survivor[0] = {
		
	};

	/* The conditional arrays */

	double Ismoke[5] = {
		0,
		0.0991535966916315260000000,
		0.5041221498472959800000000,
		0.6388807298376285600000000,
		0.8141192177518841200000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dbmi = bmi;
	dbmi=dbmi/10;
	double bmi_1 = pow(dbmi,-2);
	double bmi_2 = log(dbmi);

	/* Centring the continuous variables */

	bmi_1 = bmi_1 - 0.151612251996994;
	bmi_2 = bmi_2 - 0.943214476108551;
	town = town - -0.384868830442429;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += bmi_1 * 6.0195328776318373000000000;
	a += bmi_2 * 1.6586250198686909000000000;
	a += town * 0.0232353243418833390000000;

	/* Sum from boolean values */

	a += b_anycancer * 0.9812996874651234200000000;
	a += b_copd * 0.5557091088221426400000000;
	a += c_hb * 1.1091198574656296000000000;
	a += new_appetiteloss * 1.1227847543922216000000000;
	a += new_haemoptysis * 0.5807276467677539000000000;
	a += new_weightloss * 0.6925522575751975600000000;
	a += s1_cough * 0.2545535989580614600000000;

	/* Sum from interaction terms */


	/* Return a */
	return a;
}

static int Q64_lungcancer_stcox_death_26_0_death_validation(
int b_anycancer,int b_copd,double bmi,int c_hb,int new_appetiteloss,int new_haemoptysis,int new_weightloss,int s1_cough,int smoke_cat,double town,char *errorBuf,int errorBufSize
)
{
	int ok=1;
	*errorBuf=0;
	if (!is_boolean(b_anycancer)) {
		ok=0;
		strlcat(errorBuf,"error: b_anycancer must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_copd)) {
		ok=0;
		strlcat(errorBuf,"error: b_copd must be in range (0,1)\n",errorBufSize);
	}
	if (!d_in_range(bmi,20,40)) {
		ok=0;
		strlcat(errorBuf,"error: bmi must be in range (20,40)\n",errorBufSize);
	}
	if (!is_boolean(c_hb)) {
		ok=0;
		strlcat(errorBuf,"error: c_hb must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(new_appetiteloss)) {
		ok=0;
		strlcat(errorBuf,"error: new_appetiteloss must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(new_haemoptysis)) {
		ok=0;
		strlcat(errorBuf,"error: new_haemoptysis must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(new_weightloss)) {
		ok=0;
		strlcat(errorBuf,"error: new_weightloss must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(s1_cough)) {
		ok=0;
		strlcat(errorBuf,"error: s1_cough must be in range (0,1)\n",errorBufSize);
	}
	if (!i_in_range(smoke_cat,0,4)) {
		ok=0;
		strlcat(errorBuf,"error: smoke_cat must be in range (0,4)\n",errorBufSize);
	}
	if (!d_in_range(town,-7,11)) {
		ok=0;
		strlcat(errorBuf,"error: town must be in range (-7,11)\n",errorBufSize);
	}
	return ok;
}

double Q64_lungcancer_stcox_death_26_0_death(
int b_anycancer,int b_copd,double bmi,int c_hb,int new_appetiteloss,int new_haemoptysis,int new_weightloss,int s1_cough,int smoke_cat,double town,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = Q64_lungcancer_stcox_death_26_0_death_validation(b_anycancer,b_copd,bmi,c_hb,new_appetiteloss,new_haemoptysis,new_weightloss,s1_cough,smoke_cat,town,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return Q64_lungcancer_stcox_death_26_0_death_raw(b_anycancer,b_copd,bmi,c_hb,new_appetiteloss,new_haemoptysis,new_weightloss,s1_cough,smoke_cat,town);
}