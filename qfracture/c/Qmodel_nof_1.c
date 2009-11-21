/* 
 * Copyright 2009 ClinRisk Ltd.
 * 
 * This file is part of QFracture (http://qfracture.org).
 * 
 * QFracture is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * QFracture is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with QFracture.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * This file has been auto-generated.
 * XML source: Qmodel_nof_1.xml
 * STATA dta time stamp: 2 Sep 2009 08:55
 * C file create date: Fri Nov 20 22:53:03 GMT 2009
 */

#include <math.h>
#include <string.h>
#include <irisk/Qmodel_nof_1.h>
#include <irisk/util.h>

static double nof_male_raw(
int age,int b_asthma,int b_corticosteroids,int b_cvd,int b_falls,int b_liver,int b_ra,int b_tca,int b_type2,double bmi,int close_alcohol_category,int smoke_cat,int surv
)
{
	double survivor[11] = {
		0,
		0.999943733215332,
		0.999888420104980,
		0.999834001064301,
		0.999763071537018,
		0.999681532382965,
		0.999581456184387,
		0.999472856521606,
		0.999337852001190,
		0.999172449111938,
		0.998986899852753
	};

	/* The conditional arrays */

	double Ialcohol[6] = {
		0,
		-0.2435542275802839700000000,
		-0.2582824768722000200000000,
		-0.2140105589971362200000000,
		-0.1960432651398792700000000,
		0.5326592137352713600000000
	};
	double Ismoke[5] = {
		0,
		-0.0095332534029691149000000,
		0.1910497043706918000000000,
		0.3838314671177485100000000,
		0.5280726070551861100000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,2);
	double dbmi = bmi;
	dbmi=dbmi/10;
	double bmi_1 = log(dbmi);
	double bmi_2 = pow(log(dbmi),2);

	/* Centring the continuous variables */

	age_1 = age_1 - 23.896591186523438;
	bmi_1 = bmi_1 - 0.971441388130188;
	bmi_2 = bmi_2 - 0.943698406219482;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Ialcohol[close_alcohol_category];
	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += age_1 * 0.0867780027517282140000000;
	a += bmi_1 * -4.4340555004447415000000000;
	a += bmi_2 * 1.2253306754421784000000000;

	/* Sum from boolean values */

	a += b_asthma * 0.2701947894980922200000000;
	a += b_corticosteroids * 0.1974652764865817400000000;
	a += b_cvd * 0.2181123677565810500000000;
	a += b_falls * 0.9778204435253035100000000;
	a += b_liver * 1.0843065761076021000000000;
	a += b_ra * 0.5935109255442482200000000;
	a += b_tca * 0.5127361167342250300000000;
	a += b_type2 * 0.3225752421332743800000000;

	/* Sum from interaction terms */


	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int nof_male_validation(
int age,int b_asthma,int b_corticosteroids,int b_cvd,int b_falls,int b_liver,int b_ra,int b_tca,int b_type2,double bmi,int close_alcohol_category,int smoke_cat,int surv,char *errorBuf,int errorBufSize
)
{
	int ok=1;
	*errorBuf=0;
	if (!i_in_range(age,30,84)) {
		ok=0;
		strlcat(errorBuf,"error: age must be in range (30,84)\n",errorBufSize);
	}
	if (!is_boolean(b_asthma)) {
		ok=0;
		strlcat(errorBuf,"error: b_asthma must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_corticosteroids)) {
		ok=0;
		strlcat(errorBuf,"error: b_corticosteroids must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_cvd)) {
		ok=0;
		strlcat(errorBuf,"error: b_cvd must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_falls)) {
		ok=0;
		strlcat(errorBuf,"error: b_falls must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_liver)) {
		ok=0;
		strlcat(errorBuf,"error: b_liver must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_ra)) {
		ok=0;
		strlcat(errorBuf,"error: b_ra must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_tca)) {
		ok=0;
		strlcat(errorBuf,"error: b_tca must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_type2)) {
		ok=0;
		strlcat(errorBuf,"error: b_type2 must be in range (0,1)\n",errorBufSize);
	}
	if (!d_in_range(bmi,18,42)) {
		ok=0;
		strlcat(errorBuf,"error: bmi must be in range (18,42)\n",errorBufSize);
	}
	if (!i_in_range(close_alcohol_category,0,5)) {
		ok=0;
		strlcat(errorBuf,"error: close_alcohol_category must be in range (0,5)\n",errorBufSize);
	}
	if (!i_in_range(smoke_cat,0,4)) {
		ok=0;
		strlcat(errorBuf,"error: smoke_cat must be in range (0,4)\n",errorBufSize);
	}
	if (!i_in_range(surv,1,10)) {
		ok=0;
		strlcat(errorBuf,"error: surv must be in range (1,10)\n",errorBufSize);
	}
	return ok;
}

double nof_male(
int age,int b_asthma,int b_corticosteroids,int b_cvd,int b_falls,int b_liver,int b_ra,int b_tca,int b_type2,double bmi,int close_alcohol_category,int smoke_cat,int surv,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = nof_male_validation(age,b_asthma,b_corticosteroids,b_cvd,b_falls,b_liver,b_ra,b_tca,b_type2,bmi,close_alcohol_category,smoke_cat,surv,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return nof_male_raw(age,b_asthma,b_corticosteroids,b_cvd,b_falls,b_liver,b_ra,b_tca,b_type2,bmi,close_alcohol_category,smoke_cat,surv);
}
