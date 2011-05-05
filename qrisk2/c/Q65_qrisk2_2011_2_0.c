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
 * XML source: Q65_qrisk2_2011_2_0.xml
 * STATA dta time stamp: 9 Jan 2011 22:05
 * C file create date: Thu May  5 10:09:22 BST 2011
 */

#include <math.h>
#include <string.h>
#include <irisk/Q65_qrisk2_2011_2_0.h>
#include <irisk/util.h>

static double cvd_female_raw(
int age,int b_AF,int b_ra,int b_renal,int b_treatedhyp,int b_type2,double bmi,int ethrisk,int fh_cvd,double rati,double sbp,int smoke_cat,int surv,double town
)
{
	double survivor[16] = {
		0,
		0.998361468315125,
		0.996678650379181,
		0.994997859001160,
		0.993098974227905,
		0.991098940372467,
		0.989080786705017,
		0.986959576606750,
		0.984819591045380,
		0.982504785060883,
		0.980139017105103,
		0.977676749229431,
		0.975248038768768,
		0.972871840000153,
		0.970530509948730,
		0.968057155609131
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		0.2701997485015847400000000,
		0.5849925816222197900000000,
		0.2928293437254873600000000,
		0.0457169598790452620000000,
		-0.0941087619983587700000000,
		-0.5515362108414120200000000,
		-0.3276371733521620800000000,
		-0.1332541744745928700000000
	};
	double Ismoke[5] = {
		0,
		0.2327702810549802900000000,
		0.4875584615635800100000000,
		0.6277834520129398400000000,
		0.7659309359835262400000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,.5);
	double age_2 = pow(dage,2);
	double dbmi = bmi;
	dbmi=dbmi/10;
	double bmi_1 = pow(dbmi,.5);

	/* Centring the continuous variables */

	age_1 = age_1 - 2.212557792663574;
	age_2 = age_2 - 23.965053558349609;
	bmi_1 = bmi_1 - 1.605302810668945;
	rati = rati - 3.710259437561035;
	sbp = sbp - 129.842712402343750;
	town = town - -0.301369071006775;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];
	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += age_1 * 5.3451763070030678000000000;
	a += age_2 * -0.0141269980665285430000000;
	a += bmi_1 * 0.4265163581739610500000000;
	a += rati * 0.1426273862880608500000000;
	a += sbp * 0.0116526450551129520000000;
	a += town * 0.0596311153363571910000000;

	/* Sum from boolean values */

	a += b_AF * 1.2229035784229223000000000;
	a += b_ra * 0.3270074608538595700000000;
	a += b_renal * 0.7820359629541151500000000;
	a += b_treatedhyp * 0.5481734836311560300000000;
	a += b_type2 * 0.8590918982324876600000000;
	a += fh_cvd * 0.6438314617246578800000000;

	/* Sum from interaction terms */

	a += age_1 * (smoke_cat==1) * 0.5715389084782670500000000;
	a += age_1 * (smoke_cat==2) * -0.5974287351563502000000000;
	a += age_1 * (smoke_cat==3) * -1.2334443621176749000000000;
	a += age_1 * (smoke_cat==4) * -1.7283153973048535000000000;
	a += age_1 * b_AF * -3.8277394672781142000000000;
	a += age_1 * b_renal * -2.9025720400215884000000000;
	a += age_1 * b_treatedhyp * -1.9524720689086561000000000;
	a += age_1 * b_type2 * -1.6599035893675749000000000;
	a += age_1 * bmi_1 * -4.2607595722174354000000000;
	a += age_1 * fh_cvd * -0.0843592219007630460000000;
	a += age_1 * sbp * -0.0187441144599378300000000;
	a += age_1 * town * 0.0158368450820470140000000;
	a += age_2 * (smoke_cat==1) * -0.0121908132876918270000000;
	a += age_2 * (smoke_cat==2) * 0.0045599556763008383000000;
	a += age_2 * (smoke_cat==3) * 0.0127355214979385580000000;
	a += age_2 * (smoke_cat==4) * 0.0183719223512536080000000;
	a += age_2 * b_AF * 0.0411383240996853960000000;
	a += age_2 * b_renal * 0.0357111956715128740000000;
	a += age_2 * b_treatedhyp * 0.0200535596241913360000000;
	a += age_2 * b_type2 * 0.0163787650971418050000000;
	a += age_2 * bmi_1 * 0.0553349091629203870000000;
	a += age_2 * fh_cvd * -0.0100707528328853530000000;
	a += age_2 * sbp * 0.0000486558504939835630000;
	a += age_2 * town * -0.0019506535670581145000000;

	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int cvd_female_validation(
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

double cvd_female(
int age,int b_AF,int b_ra,int b_renal,int b_treatedhyp,int b_type2,double bmi,int ethrisk,int fh_cvd,double rati,double sbp,int smoke_cat,int surv,double town,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = cvd_female_validation(age,b_AF,b_ra,b_renal,b_treatedhyp,b_type2,bmi,ethrisk,fh_cvd,rati,sbp,smoke_cat,surv,town,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return cvd_female_raw(age,b_AF,b_ra,b_renal,b_treatedhyp,b_type2,bmi,ethrisk,fh_cvd,rati,sbp,smoke_cat,surv,town);
}
