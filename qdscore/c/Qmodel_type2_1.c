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
 * XML source: Qmodel_type2_1.xml
 * STATA dta time stamp: 2 Sep 2009 08:55
 * C file create date: Mon Jun 14 10:39:39 BST 2010
 */

#include <math.h>
#include <string.h>
#include <irisk/Qmodel_type2_1.h>
#include <irisk/util.h>

static double type2_male_raw(
int age,int b_corticosteroids,int b_cvd,int b_treatedhyp,double bmi,int ethrisk,int fh_diab,int smok,int surv,double town
)
{
	double survivor[11] = {
		0,
		0.998265564441681,
		0.996459126472473,
		0.994545221328735,
		0.992372393608093,
		0.989888370037079,
		0.987229585647583,
		0.984477102756500,
		0.981423079967499,
		0.978139400482178,
		0.974618017673492
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		0.6570127848928590800000000,
		0.9313077095099755500000000,
		1.5110638424815201000000000,
		0.6386475488204873500000000,
		-0.0457606683245606950000000,
		0.5277792532857636900000000,
		0.3461723062004857800000000,
		0.1816253608765281400000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = log(dage);
	double age_2 = pow(dage,3);
	double dbmi = bmi;
	dbmi=dbmi/10;
	double bmi_1 = pow(dbmi,2);
	double bmi_2 = pow(dbmi,3);

	/* Centring the continuous variables */

	age_1 = age_1 - 1.481503963470459;
	age_2 = age_2 - 85.158302307128906;
	bmi_1 = bmi_1 - 6.793983936309815;
	bmi_2 = bmi_2 - 17.708702087402344;
	town = town - -0.116421662271023;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];

	/* Sum from continuous values */

	a += age_1 * 4.6602861083783393000000000;
	a += age_2 * -0.0041910642479371044000000;
	a += bmi_1 * 1.1530981937722629000000000;
	a += bmi_2 * -0.1842768413859622900000000;
	a += town * 0.0374907921747831690000000;

	/* Sum from boolean values */

	a += b_corticosteroids * 0.2300178029690344300000000;
	a += b_cvd * 0.4053830216731730800000000;
	a += b_treatedhyp * 0.5372956311124768000000000;
	a += fh_diab * 1.0024885672432731000000000;
	a += smok * 0.2219810439747176000000000;

	/* Sum from interaction terms */

	a += age_1 * bmi_1 * 0.6622761776879641000000000;
	a += age_1 * bmi_2 * -0.1758962488748286000000000;
	a += age_1 * fh_diab * -1.1340986109024660000000000;
	a += age_1 * smok * 0.2673074975973938100000000;
	a += age_2 * bmi_1 * -0.0015091976327686514000000;
	a += age_2 * bmi_2 * 0.0003113315912160423000000;
	a += age_2 * fh_diab * 0.0015387250276902814000000;
	a += age_2 * smok * -0.0008827362626436393300000;

	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int type2_male_validation(
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

double type2_male(
int age,int b_corticosteroids,int b_cvd,int b_treatedhyp,double bmi,int ethrisk,int fh_diab,int smok,int surv,double town,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = type2_male_validation(age,b_corticosteroids,b_cvd,b_treatedhyp,bmi,ethrisk,fh_diab,smok,surv,town,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return type2_male_raw(age,b_corticosteroids,b_cvd,b_treatedhyp,bmi,ethrisk,fh_diab,smok,surv,town);
}
