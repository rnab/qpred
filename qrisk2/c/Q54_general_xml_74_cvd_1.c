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
 * XML source: Q54_general_xml_74_cvd_1.xml
 * STATA dta time stamp: 26 Feb 2010 13:37
 * C file create date: Fri Apr 16 11:10:47 BST 2010
 */

#include <math.h>
#include <string.h>
#include <irisk/Q54_general_xml_74_cvd_1.h>
#include <irisk/util.h>

static double cvd_male_raw(
int age,int b_AF,int b_ra,int b_renal,int b_treatedhyp,int b_type2,double bmi,int ethrisk,int fh_cvd,double rati,double sbp,int smok,int surv,double town
)
{
	double survivor[11] = {
		0,
		0.996804893016815,
		0.993515729904175,
		0.990212798118591,
		0.986552238464355,
		0.982661902904511,
		0.978698372840881,
		0.974610328674316,
		0.970230817794800,
		0.965753257274628,
		0.960994482040405
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		0.2779752967919788000000000,
		0.5765004110580710400000000,
		0.5814077511040650600000000,
		0.1791872902489883600000000,
		-0.4221753793631450900000000,
		-0.4294724547697814600000000,
		-0.3422833639030458100000000,
		-0.1831750651231736600000000
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

	age_1 = age_1 - 0.044204741716385;
	age_2 = age_2 - 0.068935595452785;
	bmi_1 = bmi_1 - 0.969249010086060;
	rati = rati - 4.465841770172119;
	sbp = sbp - 133.504226684570310;
	town = town - -0.378447085618973;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];

	/* Sum from continuous values */

	a += age_1 * 47.5567007765739190000000000;
	a += age_2 * -103.3233043649436200000000000;
	a += bmi_1 * 0.5335148965200203800000000;
	a += rati * 0.1530659541619358300000000;
	a += sbp * 0.0087951128720684373000000;
	a += town * 0.0398289717203854990000000;

	/* Sum from boolean values */

	a += b_AF * 0.7617063943234410100000000;
	a += b_ra * 0.2926699271756058600000000;
	a += b_renal * 0.7512246657155928800000000;
	a += b_treatedhyp * 0.5328761241531457800000000;
	a += b_type2 * 0.7724817361793342400000000;
	a += fh_cvd * 0.7664701293062744500000000;
	a += smok * 0.5112117199010407500000000;

	/* Sum from interaction terms */

	a += age_1 * b_AF * -37.4004639192136420000000000;
	a += age_1 * b_renal * -34.2740173199030590000000000;
	a += age_1 * b_treatedhyp * 22.9840801365443460000000000;
	a += age_1 * b_type2 * -10.8985852230277320000000000;
	a += age_1 * bmi_1 * 3.6097891321720086000000000;
	a += age_1 * fh_cvd * -29.0539075479693810000000000;
	a += age_1 * sbp * -0.2692375419328578700000000;
	a += age_1 * smok * -18.7673791276518750000000000;
	a += age_1 * town * -3.0008901896869080000000000;
	a += age_2 * b_AF * 40.5731587723394540000000000;
	a += age_2 * b_renal * 40.4295952394319330000000000;
	a += age_2 * b_treatedhyp * -8.5579552130877037000000000;
	a += age_2 * b_type2 * 20.7197083925717610000000000;
	a += age_2 * bmi_1 * 9.5522673534361058000000000;
	a += age_2 * fh_cvd * 37.7077731667262480000000000;
	a += age_2 * sbp * 0.4204767650148031300000000;
	a += age_2 * smok * 26.2551762223034440000000000;
	a += age_2 * town * 3.5665931312301318000000000;

	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int cvd_male_validation(
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

double cvd_male(
int age,int b_AF,int b_ra,int b_renal,int b_treatedhyp,int b_type2,double bmi,int ethrisk,int fh_cvd,double rati,double sbp,int smok,int surv,double town,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = cvd_male_validation(age,b_AF,b_ra,b_renal,b_treatedhyp,b_type2,bmi,ethrisk,fh_cvd,rati,sbp,smok,surv,town,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return cvd_male_raw(age,b_AF,b_ra,b_renal,b_treatedhyp,b_type2,bmi,ethrisk,fh_cvd,rati,sbp,smok,surv,town);
}
