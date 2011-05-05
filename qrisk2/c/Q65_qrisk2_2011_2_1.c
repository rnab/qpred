/* 
 * Copyright 2011 ClinRisk Ltd.
 * 
 * This file is part of QRISK2-2011 (http://qrisk.org, http://svn.clinrisk.co.uk/opensource/qrisk2).
 * 
 * QRISK2-2011 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QRISK2-2011 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QRISK2-2011.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/opensource/qrisk2, faithfully implements QRISK2-2011.
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/opensource/qrisk2.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q65_qrisk2_2011_2_1.xml
 * STATA dta time stamp: 9 Jan 2011 22:05
 * C file create date: Thu May  5 10:09:34 BST 2011
 */

#include <math.h>
#include <string.h>
#include <irisk/Q65_qrisk2_2011_2_1.h>
#include <irisk/util.h>

static double cvd_male_raw(
int age,int b_AF,int b_ra,int b_renal,int b_treatedhyp,int b_type2,double bmi,int ethrisk,int fh_cvd,double rati,double sbp,int smoke_cat,int surv,double town
)
{
	double survivor[16] = {
		0,
		0.997251808643341,
		0.994411587715149,
		0.991577506065369,
		0.988431155681610,
		0.985084950923920,
		0.981717884540558,
		0.978166103363037,
		0.974576294422150,
		0.970824301242828,
		0.966860234737396,
		0.962876856327057,
		0.958815157413483,
		0.954597651958466,
		0.950800955295563,
		0.946760058403015
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		0.2951201722226509100000000,
		0.5774536084141955700000000,
		0.5856789051039356100000000,
		0.1557364124244510200000000,
		-0.4239684807026608000000000,
		-0.5298535279109863900000000,
		-0.3409560555106792600000000,
		-0.2547523360677878000000000
	};
	double Ismoke[5] = {
		0,
		0.2682688391611277600000000,
		0.5042185439341627700000000,
		0.6186559642078698400000000,
		0.7584809371310703400000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,-2);
	double age_2 = pow(dage,-2)*log(dage);
	double dbmi = bmi;
	dbmi=dbmi/10;
	double bmi_1 = log(dbmi);

	/* Centring the continuous variables */

	age_1 = age_1 - 0.044995188713074;
	age_2 = age_2 - 0.069769531488419;
	bmi_1 = bmi_1 - 0.967867195606232;
	rati = rati - 4.458122253417969;
	sbp = sbp - 133.248199462890620;
	town = town - -0.164980158209801;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];
	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += age_1 * 47.4409231432571520000000000;
	a += age_2 * -103.9694778548133500000000000;
	a += bmi_1 * 0.4454212658879678200000000;
	a += rati * 0.1531415988987079000000000;
	a += sbp * 0.0086481101655897820000000;
	a += town * 0.0326616854962242380000000;

	/* Sum from boolean values */

	a += b_AF * 0.6724975345708518200000000;
	a += b_ra * 0.2844675803629553900000000;
	a += b_renal * 0.7934428384714343800000000;
	a += b_treatedhyp * 0.5501928673194242900000000;
	a += b_type2 * 0.8102736062476685300000000;
	a += fh_cvd * 0.7509625254916093600000000;

	/* Sum from interaction terms */

	a += age_1 * (smoke_cat==1) * -1.8114868938741493000000000;
	a += age_1 * (smoke_cat==2) * -14.0178925355489450000000000;
	a += age_1 * (smoke_cat==3) * -12.2971507354086000000000000;
	a += age_1 * (smoke_cat==4) * -9.5995358645940403000000000;
	a += age_1 * b_AF * -29.9229283009898380000000000;
	a += age_1 * b_renal * -55.5547457814475080000000000;
	a += age_1 * b_treatedhyp * 31.0186452463243260000000000;
	a += age_1 * b_type2 * -19.8796087944702440000000000;
	a += age_1 * bmi_1 * 16.3437082809787420000000000;
	a += age_1 * fh_cvd * -26.3175914239316240000000000;
	a += age_1 * sbp * -0.2288663778369489900000000;
	a += age_1 * town * -2.8512030583797006000000000;
	a += age_2 * (smoke_cat==1) * 6.3639267384563913000000000;
	a += age_2 * (smoke_cat==2) * 19.3756175012057240000000000;
	a += age_2 * (smoke_cat==3) * 18.8415645049194790000000000;
	a += age_2 * (smoke_cat==4) * 19.7059409243283880000000000;
	a += age_2 * b_AF * 31.1557572626584510000000000;
	a += age_2 * b_renal * 59.0028081909139600000000000;
	a += age_2 * b_treatedhyp * -14.6191239386960210000000000;
	a += age_2 * b_type2 * 29.2015783029565630000000000;
	a += age_2 * bmi_1 * -2.9965983324865419000000000;
	a += age_2 * fh_cvd * 35.6829323968598970000000000;
	a += age_2 * sbp * 0.3647340147196024300000000;
	a += age_2 * town * 3.3173634478389573000000000;

	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int cvd_male_validation(
int age,int b_AF,int b_ra,int b_renal,int b_treatedhyp,int b_type2,double bmi,int ethrisk,int fh_cvd,double rati,double sbp,int smoke_cat,int surv,double town,char *errorBuf,int errorBufSize
)
{
	int ok=1;
	*errorBuf=0;
	if (!i_in_range(age,30,84)) {
		ok=0;
		strlcat(errorBuf,"error: age must be in range (30,84)\n",errorBufSize);
	}
	if (!is_boolean(b_AF)) {
		ok=0;
		strlcat(errorBuf,"error: b_AF must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_ra)) {
		ok=0;
		strlcat(errorBuf,"error: b_ra must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_renal)) {
		ok=0;
		strlcat(errorBuf,"error: b_renal must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_treatedhyp)) {
		ok=0;
		strlcat(errorBuf,"error: b_treatedhyp must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_type2)) {
		ok=0;
		strlcat(errorBuf,"error: b_type2 must be in range (0,1)\n",errorBufSize);
	}
	if (!d_in_range(bmi,20,40)) {
		ok=0;
		strlcat(errorBuf,"error: bmi must be in range (20,40)\n",errorBufSize);
	}
	if (!i_in_range(ethrisk,1,9)) {
		ok=0;
		strlcat(errorBuf,"error: ethrisk must be in range (1,9)\n",errorBufSize);
	}
	if (!is_boolean(fh_cvd)) {
		ok=0;
		strlcat(errorBuf,"error: fh_cvd must be in range (0,1)\n",errorBufSize);
	}
	if (!d_in_range(rati,1,12)) {
		ok=0;
		strlcat(errorBuf,"error: rati must be in range (1,12)\n",errorBufSize);
	}
	if (!d_in_range(sbp,70,210)) {
		ok=0;
		strlcat(errorBuf,"error: sbp must be in range (70,210)\n",errorBufSize);
	}
	if (!i_in_range(smoke_cat,0,4)) {
		ok=0;
		strlcat(errorBuf,"error: smoke_cat must be in range (0,4)\n",errorBufSize);
	}
	if (!i_in_range(surv,1,10)) {
		ok=0;
		strlcat(errorBuf,"error: surv must be in range (1,10)\n",errorBufSize);
	}
	if (!d_in_range(town,-7,11)) {
		ok=0;
		strlcat(errorBuf,"error: town must be in range (-7,11)\n",errorBufSize);
	}
	return ok;
}

double cvd_male(
int age,int b_AF,int b_ra,int b_renal,int b_treatedhyp,int b_type2,double bmi,int ethrisk,int fh_cvd,double rati,double sbp,int smoke_cat,int surv,double town,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = cvd_male_validation(age,b_AF,b_ra,b_renal,b_treatedhyp,b_type2,bmi,ethrisk,fh_cvd,rati,sbp,smoke_cat,surv,town,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return cvd_male_raw(age,b_AF,b_ra,b_renal,b_treatedhyp,b_type2,bmi,ethrisk,fh_cvd,rati,sbp,smoke_cat,surv,town);
}
