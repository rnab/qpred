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

#include <math.h>
#include <string.h>
#include <irisk/Qmodel_type2_0.h>
#include <irisk/util.h>

static double type2_female_raw(
int age,int b_corticosteroids,int b_cvd,int b_treatedhyp,double bmi,int ethrisk,int fh_diab,int smok,int surv,double town
)
{
	double survivor[11] = {
		0,
		0.998805761337280,
		0.997608065605164,
		0.996346592903137,
		0.994937002658844,
		0.993355870246887,
		0.991551995277405,
		0.989812076091766,
		0.987842559814453,
		0.985680699348450,
		0.983291983604431
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		0.5365495202183693200000000,
		0.7662863026744053400000000,
		1.4039515607221962000000000,
		0.2343839843021357000000000,
		-0.2262477766307989200000000,
		-0.2175322459800286300000000,
		0.6734132892549344900000000,
		-0.1179038879534471800000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,0.5);
	double age_2 = pow(dage,3);
	double dbmi = bmi;
	dbmi=dbmi/10;
	double bmi_1 = dbmi;
	double bmi_2 = pow(dbmi,3);

	/* Centring the continuous variables */

	age_1 = age_1 - 2.115379810333252;
	age_2 = age_2 - 89.604545593261719;
	bmi_1 = bmi_1 - 2.544721126556397;
	bmi_2 = bmi_2 - 16.478612899780273;
	town = town - -0.194727867841721;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];

	/* Sum from continuous values */

	a += age_1 * 4.4315148030665714000000000;
	a += age_2 * -0.0050056071936287576000000;
	a += bmi_1 * 3.6188087575505850000000000;
	a += bmi_2 * -0.0687183179802360040000000;
	a += town * 0.0538824941503230280000000;

	/* Sum from boolean values */

	a += b_corticosteroids * 0.3451916093391816400000000;
	a += b_cvd * 0.3770777565260045000000000;
	a += b_treatedhyp * 0.5804768757915621500000000;
	a += fh_diab * 0.8578527544136007600000000;
	a += smok * 0.2371389363172849400000000;

	/* Sum from interaction terms */

	a += age_1 * bmi_1 * 1.0913755651596941000000000;
	a += age_1 * bmi_2 * -0.0585537471691784180000000;
	a += age_1 * fh_diab * -0.7980912138325359000000000;
	a += age_1 * smok * 0.4772464609454892300000000;
	a += age_2 * bmi_1 * -0.0063395585467211609000000;
	a += age_2 * bmi_2 * 0.0002014356224656779000000;
	a += age_2 * fh_diab * 0.0014901432937626897000000;
	a += age_2 * smok * -0.0010348515577357010000000;

	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int type2_female_validation(
int age,int b_corticosteroids,int b_cvd,int b_treatedhyp,double bmi,int ethrisk,int fh_diab,int smok,int surv,double town,char *errorBuf,int errorBufSize
)
{
	int ok=1;
	*errorBuf=0;
	if (!i_in_range(age,25,79)) {
		ok=0;
		strlcat(errorBuf,"error: age must be in range (25,79)\n",errorBufSize);
	}
	if (!is_boolean(b_corticosteroids)) {
		ok=0;
		strlcat(errorBuf,"error: b_corticosteroids must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_cvd)) {
		ok=0;
		strlcat(errorBuf,"error: b_cvd must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_treatedhyp)) {
		ok=0;
		strlcat(errorBuf,"error: b_treatedhyp must be in range (0,1)\n",errorBufSize);
	}
	if (!d_in_range(bmi,18,42)) {
		ok=0;
		strlcat(errorBuf,"error: bmi must be in range (18,42)\n",errorBufSize);
	}
	if (!i_in_range(ethrisk,1,9)) {
		ok=0;
		strlcat(errorBuf,"error: ethrisk must be in range (1,9)\n",errorBufSize);
	}
	if (!is_boolean(fh_diab)) {
		ok=0;
		strlcat(errorBuf,"error: fh_diab must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(smok)) {
		ok=0;
		strlcat(errorBuf,"error: smok must be in range (0,1)\n",errorBufSize);
	}
	if (!i_in_range(surv,1,10)) {
		ok=0;
		strlcat(errorBuf,"error: surv must be in range (1,10)\n",errorBufSize);
	}
	if (!d_in_range(town,-6,11)) {
		ok=0;
		strlcat(errorBuf,"error: town must be in range (-6,11)\n",errorBufSize);
	}
	return ok;
}

double type2_female(
int age,int b_corticosteroids,int b_cvd,int b_treatedhyp,double bmi,int ethrisk,int fh_diab,int smok,int surv,double town,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = type2_female_validation(age,b_corticosteroids,b_cvd,b_treatedhyp,bmi,ethrisk,fh_diab,smok,surv,town,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return type2_female_raw(age,b_corticosteroids,b_cvd,b_treatedhyp,bmi,ethrisk,fh_diab,smok,surv,town);
}
