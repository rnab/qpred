/* 
 * Copyright 2012 ClinRisk Ltd.
 * 
 * This file is part of QRISK2-2012 (http://qrisk.org, http://svn.clinrisk.co.uk/qrisk2).
 * 
 * QRISK2-2012 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QRISK2-2012 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QRISK2-2012.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Additional terms
 * 
 * The following disclaimer must be displayed alongside any risk score generated by this code.
 *   The initial version of this file, to be found at http://svn.clinrisk.co.uk/qrisk2, faithfully implements QRISK2-2012.
 *   We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 *   However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.
 *   We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/qrisk2.
 *   Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 * This file has been auto-generated.
 * XML source: Q68_qrisk2_2012_1_0.xml
 * STATA dta time stamp: 2 Jan 2012 23:10
 * This file was created on: Tue  3 Jan 2012 09:15:05 GMT
 */

#include <math.h>
#include <string.h>
#include <clinrisk/Q68_qrisk2_2012_1_0.h>
#include <clinrisk/utils.h>

static double cvd_female_raw(
int age,int b_AF,int b_ra,int b_renal,int b_treatedhyp,int b_type2,double bmi,int ethrisk,int fh_cvd,double rati,double sbp,int smoke_cat,int surv,double town
)
{
	double survivor[16] = {
		0,
		0.998272597789764,
		0.996482193470001,
		0.994584262371063,
		0.992607414722443,
		0.990407526493073,
		0.988208174705505,
		0.985817015171051,
		0.983284771442413,
		0.980540335178375,
		0.977537572383881,
		0.974311947822571,
		0.971061646938324,
		0.967655360698700,
		0.963695406913757,
		0.959843873977661
	};

	/* The conditional arrays */

	double Iethrisk[10] = {
		0,
		0,
		0.2163282093750823500000000,
		0.6904687508186858600000000,
		0.3422685053345692600000000,
		0.0731008288350808310000000,
		-0.0989396610852535660000000,
		-0.2352321178062382600000000,
		-0.2956316192158425800000000,
		-0.1010123741730201800000000
	};
	double Ismoke[5] = {
		0,
		0.2033232689326185900000000,
		0.4820416413827907100000000,
		0.6126017502669054400000000,
		0.7481362046722807000000000
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

	age_1 = age_1 - 2.214729070663452;
	age_2 = age_2 - 24.059265136718750;
	bmi_1 = bmi_1 - 1.606468081474304;
	rati = rati - 3.708646535873413;
	sbp = sbp - 129.990249633789060;
	town = town - -0.485970288515091;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Iethrisk[ethrisk];
	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += age_1 * 5.0327322737460403000000000;
	a += age_2 * -0.0108190285560098470000000;
	a += bmi_1 * 0.4723685118804857300000000;
	a += rati * 0.1325846978117864200000000;
	a += sbp * 0.0105865933893311400000000;
	a += town * 0.0597458366155125960000000;

	/* Sum from boolean values */

	a += b_AF * 1.3260722293533254000000000;
	a += b_ra * 0.3626145113296154700000000;
	a += b_renal * 0.7636191853466424200000000;
	a += b_treatedhyp * 0.5420886736363689200000000;
	a += b_type2 * 0.8939864249454413400000000;
	a += fh_cvd * 0.5997157809513348200000000;

	/* Sum from interaction terms */

	a += age_1 * (smoke_cat==1) * 0.1773773580667799300000000;
	a += age_1 * (smoke_cat==2) * -0.3277435393269309500000000;
	a += age_1 * (smoke_cat==3) * -1.1532771847454322000000000;
	a += age_1 * (smoke_cat==4) * -1.5396928677197224000000000;
	a += age_1 * b_AF * -4.6084283441445892000000000;
	a += age_1 * b_renal * -2.6400602815968979000000000;
	a += age_1 * b_treatedhyp * -2.2479789428920025000000000;
	a += age_1 * b_type2 * -1.8452128842162694000000000;
	a += age_1 * bmi_1 * -3.0850905786159868000000000;
	a += age_1 * fh_cvd * -0.2480779144692392100000000;
	a += age_1 * sbp * -0.0132453692890105240000000;
	a += age_1 * town * -0.0369396566313616930000000;
	a += age_2 * (smoke_cat==1) * -0.0051475082686792311000000;
	a += age_2 * (smoke_cat==2) * -0.0005319773104753907200000;
	a += age_2 * (smoke_cat==3) * 0.0105091708474237890000000;
	a += age_2 * (smoke_cat==4) * 0.0154782037050560930000000;
	a += age_2 * b_AF * 0.0507454178844450110000000;
	a += age_2 * b_renal * 0.0343259130322268740000000;
	a += age_2 * b_treatedhyp * 0.0257783591608558020000000;
	a += age_2 * b_type2 * 0.0179772109650001910000000;
	a += age_2 * bmi_1 * 0.0345004560510129770000000;
	a += age_2 * fh_cvd * -0.0062437412993034047000000;
	a += age_2 * sbp * -0.0000295094907709919760000;
	a += age_2 * town * -0.0010621576948374419000000;

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
