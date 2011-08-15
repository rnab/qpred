/* 
 * Copyright 2011 ClinRisk Ltd.
 * 
 * This file is part of QThrombosis (http://qthrombosis.org, http://svn.clinrisk.co.uk/opensource/qthrombosis).
 * 
 * QThrombosis is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QThrombosis is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QThrombosis.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Additional terms
 * 
 * The following disclaimer must be displayed alongside any risk score generated by this code.
 *   The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qthrombosis, faithfully implements QThrombosis.
 *   We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 *   However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.
 *   We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qthrombosis.
 *   Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q66_vte_xml_20_vte_0.xml
 * STATA dta time stamp: 20 Mar 2011 13:10
 * This file was created on: Mon 15 Aug 2011 18:50:57 BST
 */

#include <math.h>
#include <string.h>
#include <clinrisk/Q66_vte_xml_20_vte_0.h>
#include <clinrisk/utils.h>

static double vte_female_raw(
int age,int antipsychotics_current,int b_CCF,int b_anycancer,int b_copd,int b_ibd,int b_renal,int b_varicosevein,double bmi,int cop_current,int hrt_current,int smoke_cat,int surv,int tamoxifen_current,int z1_admit
)
{
	double survivor[6] = {
		0,
		0.999376356601715,
		0.998682796955109,
		0.997944533824921,
		0.997253477573395,
		0.996520936489105
	};

	/* The conditional arrays */

	double Ismoke[5] = {
		0,
		0.0717169370978090050000000,
		0.1987553072293612200000000,
		0.1547104796226689000000000,
		0.2917149160411480800000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,-.5);
	double age_2 = log(dage);
	double dbmi = bmi;
	dbmi=dbmi/10;
	double bmi_1 = pow(dbmi,-2);
	double bmi_2 = pow(dbmi,-2)*log(dbmi);

	/* Centring the continuous variables */

	age_1 = age_1 - 0.453635036945343;
	age_2 = age_2 - 1.580924510955811;
	bmi_1 = bmi_1 - 0.146638035774231;
	bmi_2 = bmi_2 - 0.140756979584694;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += age_1 * 42.9579705434332200000000000;
	a += age_2 * 12.0763782716993160000000000;
	a += bmi_1 * 2.3287900114265345000000000;
	a += bmi_2 * -18.7665353784352680000000000;

	/* Sum from boolean values */

	a += antipsychotics_current * 0.4358492347548906200000000;
	a += b_CCF * 0.3337927703207742600000000;
	a += b_anycancer * 0.6147066422203549800000000;
	a += b_copd * 0.3470345998249598800000000;
	a += b_ibd * 0.3686700220353901200000000;
	a += b_renal * 0.4725846604440773800000000;
	a += b_varicosevein * 0.3381458875841721900000000;
	a += cop_current * 0.2868799951458520500000000;
	a += hrt_current * 0.1858755355720995700000000;
	a += tamoxifen_current * 0.3900993288187091200000000;
	a += z1_admit * 0.6232360746877910800000000;

	/* Sum from interaction terms */


	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int vte_female_validation(
int age,int antipsychotics_current,int b_CCF,int b_anycancer,int b_copd,int b_ibd,int b_renal,int b_varicosevein,double bmi,int cop_current,int hrt_current,int smoke_cat,int surv,int tamoxifen_current,int z1_admit,char *errorBuf,int errorBufSize
)
{
	int ok=1;
	*errorBuf=0;
	if (!i_in_range(age,25,84)) {
		ok=0;
		strlcat(errorBuf,"error: age must be in range (25,84)\n",errorBufSize);
	}
	if (!is_boolean(antipsychotics_current)) {
		ok=0;
		strlcat(errorBuf,"error: antipsychotics_current must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_CCF)) {
		ok=0;
		strlcat(errorBuf,"error: b_CCF must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_anycancer)) {
		ok=0;
		strlcat(errorBuf,"error: b_anycancer must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_copd)) {
		ok=0;
		strlcat(errorBuf,"error: b_copd must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_ibd)) {
		ok=0;
		strlcat(errorBuf,"error: b_ibd must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_renal)) {
		ok=0;
		strlcat(errorBuf,"error: b_renal must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_varicosevein)) {
		ok=0;
		strlcat(errorBuf,"error: b_varicosevein must be in range (0,1)\n",errorBufSize);
	}
	if (!d_in_range(bmi,20,40)) {
		ok=0;
		strlcat(errorBuf,"error: bmi must be in range (20,40)\n",errorBufSize);
	}
	if (!is_boolean(cop_current)) {
		ok=0;
		strlcat(errorBuf,"error: cop_current must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(hrt_current)) {
		ok=0;
		strlcat(errorBuf,"error: hrt_current must be in range (0,1)\n",errorBufSize);
	}
	if (!i_in_range(smoke_cat,0,4)) {
		ok=0;
		strlcat(errorBuf,"error: smoke_cat must be in range (0,4)\n",errorBufSize);
	}
	if (!i_in_range(surv,1,15)) {
		ok=0;
		strlcat(errorBuf,"error: surv must be in range (1,15)\n",errorBufSize);
	}
	if (!is_boolean(tamoxifen_current)) {
		ok=0;
		strlcat(errorBuf,"error: tamoxifen_current must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(z1_admit)) {
		ok=0;
		strlcat(errorBuf,"error: z1_admit must be in range (0,1)\n",errorBufSize);
	}
	return ok;
}

double vte_female(
int age,int antipsychotics_current,int b_CCF,int b_anycancer,int b_copd,int b_ibd,int b_renal,int b_varicosevein,double bmi,int cop_current,int hrt_current,int smoke_cat,int surv,int tamoxifen_current,int z1_admit,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = vte_female_validation(age,antipsychotics_current,b_CCF,b_anycancer,b_copd,b_ibd,b_renal,b_varicosevein,bmi,cop_current,hrt_current,smoke_cat,surv,tamoxifen_current,z1_admit,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return vte_female_raw(age,antipsychotics_current,b_CCF,b_anycancer,b_copd,b_ibd,b_renal,b_varicosevein,bmi,cop_current,hrt_current,smoke_cat,surv,tamoxifen_current,z1_admit);
}
