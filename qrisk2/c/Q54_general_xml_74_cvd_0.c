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

#include <math.h>
#include <string.h>
#include <irisk/Q54_general_xml_74_cvd_0.h>
#include <irisk/util.h>

static double cvd_female_raw(
int age,int b_AF,int b_ra,int b_renal,int b_treatedhyp,int b_type2,double bmi,int ethrisk,int fh_cvd,double rati,double sbp,int smok,int surv,double town
)
{
	double survivor[11] = {
		0,
		0.998114824295044,
		0.996216416358948,
		0.994249880313873,
		0.992084741592407,
		0.989799082279205,
		0.987466812133789,
		0.985021889209747,
		0.982500910758972,
		0.979762673377991,
		0.976909220218658
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		0.2314131808945855400000000,
		0.5519883366016252700000000,
		0.2323000705245862600000000,
		-0.0206078534593695790000000,
		-0.1919087928434186600000000,
		-0.5490173303645657900000000,
		-0.3655366650516778100000000,
		-0.1479965485050352400000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,0.5);
	double age_2 = pow(dage,2);
	double dbmi = bmi;
	dbmi=dbmi/10;
	double bmi_1 = pow(dbmi,.5);

	/* Centring the continuous variables */

	age_1 = age_1 - 2.223060607910156;
	age_2 = age_2 - 24.423343658447266;
	bmi_1 = bmi_1 - 1.605616688728333;
	rati = rati - 3.708191633224487;
	sbp = sbp - 130.317565917968750;
	town = town - -0.491603106260300;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];

	/* Sum from continuous values */

	a += age_1 * 5.4946569028018830000000000;
	a += age_2 * -0.0174668752070062070000000;
	a += bmi_1 * 0.4577335077497408600000000;
	a += rati * 0.1410450563981926500000000;
	a += sbp * 0.0116248169649082290000000;
	a += town * 0.0687444309936767610000000;

	/* Sum from boolean values */

	a += b_AF * 1.2045781589148943000000000;
	a += b_ra * 0.3539229412626246400000000;
	a += b_renal * 0.7797113289342096900000000;
	a += b_treatedhyp * 0.5032055488537238200000000;
	a += b_type2 * 0.9284628145154381100000000;
	a += fh_cvd * 0.6458727284810530400000000;
	a += smok * 0.5408334311058870000000000;

	/* Sum from interaction terms */

	a += age_1 * b_AF * -3.7725023228828656000000000;
	a += age_1 * b_renal * -2.8764440583762769000000000;
	a += age_1 * b_treatedhyp * -1.9625326145279900000000000;
	a += age_1 * b_type2 * -2.1503182006956956000000000;
	a += age_1 * bmi_1 * -3.7354107145604645000000000;
	a += age_1 * fh_cvd * -0.0781205405555043250000000;
	a += age_1 * sbp * -0.0202779543525558710000000;
	a += age_1 * smok * -1.0998391447666569000000000;
	a += age_1 * town * -0.0165985689442654240000000;
	a += age_2 * b_AF * 0.0402572312578888810000000;
	a += age_2 * b_renal * 0.0358643392697075220000000;
	a += age_2 * b_treatedhyp * 0.0214992753812953650000000;
	a += age_2 * b_type2 * 0.0224481791197297110000000;
	a += age_2 * bmi_1 * 0.0464041846965939570000000;
	a += age_2 * fh_cvd * -0.0103771094147538030000000;
	a += age_2 * sbp * 0.0000545297405855030650000;
	a += age_2 * smok * 0.0090021836269921617000000;
	a += age_2 * town * -0.0016682978627580989000000;

	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int cvd_female_validation(
int age,int b_AF,int b_ra,int b_renal,int b_treatedhyp,int b_type2,double bmi,int ethrisk,int fh_cvd,double rati,double sbp,int smok,int surv,double town,char *errorBuf,int errorBufSize
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
	if (!is_boolean(smok)) {
		ok=0;
		strlcat(errorBuf,"error: smok must be in range (0,1)\n",errorBufSize);
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
int age,int b_AF,int b_ra,int b_renal,int b_treatedhyp,int b_type2,double bmi,int ethrisk,int fh_cvd,double rati,double sbp,int smok,int surv,double town,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = cvd_female_validation(age,b_AF,b_ra,b_renal,b_treatedhyp,b_type2,bmi,ethrisk,fh_cvd,rati,sbp,smok,surv,town,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return cvd_female_raw(age,b_AF,b_ra,b_renal,b_treatedhyp,b_type2,bmi,ethrisk,fh_cvd,rati,sbp,smok,surv,town);
}
