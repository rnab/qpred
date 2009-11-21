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
 * XML source: Qmodel_fracture_1.xml
 * STATA dta time stamp: 2 Sep 2009 08:55
 * C file create date: Fri Nov 20 22:52:44 GMT 2009
 */

#include <math.h>
#include <string.h>
#include <irisk/Qmodel_fracture_1.h>
#include <irisk/util.h>

static double fracture_male_raw(
int age,int b_asthma,int b_corticosteroids,int b_cvd,int b_falls,int b_liver,int b_ra,int b_tca,int b_type2,double bmi,int close_alcohol_category,int smoke_cat,int surv
)
{
	double survivor[11] = {
		0,
		0.999109745025635,
		0.998294174671173,
		0.997431516647339,
		0.996533095836639,
		0.995475649833679,
		0.994286656379700,
		0.993052601814270,
		0.991576194763184,
		0.990026175975800,
		0.988354146480560
	};

	/* The conditional arrays */

	double Ialcohol[6] = {
		0,
		-0.0764274409049113260000000,
		-0.0462155929172333450000000,
		0.0499679400852804860000000,
		0.0942979015293679560000000,
		0.4800973469613324400000000
	};
	double Ismoke[5] = {
		0,
		-0.0187930753957115390000000,
		0.1184874343467856200000000,
		0.1850036097476660500000000,
		0.3050600434642619700000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = dage;
	double age_2 = pow(dage,2);
	double dbmi = bmi;
	dbmi=dbmi/10;
	double bmi_1 = pow(dbmi,-2);

	/* Centring the continuous variables */

	age_1 = age_1 - 4.889286041259766;
	age_2 = age_2 - 23.905118942260742;
	bmi_1 = bmi_1 - 0.378574401140213;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Ialcohol[close_alcohol_category];
	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += age_1 * -0.9219124810644523400000000;
	a += age_2 * 0.1225882002875540200000000;
	a += bmi_1 * 3.3176486948143649000000000;

	/* Sum from boolean values */

	a += b_asthma * 0.2498389884091865600000000;
	a += b_corticosteroids * 0.3792774124338336200000000;
	a += b_cvd * 0.2567801304967053900000000;
	a += b_falls * 0.8008286190106441700000000;
	a += b_liver * 1.0518090794718631000000000;
	a += b_ra * 0.3929149537553725500000000;
	a += b_tca * 0.3058617487532246900000000;
	a += b_type2 * 0.1831755749438354900000000;

	/* Sum from interaction terms */


	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int fracture_male_validation(
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

double fracture_male(
int age,int b_asthma,int b_corticosteroids,int b_cvd,int b_falls,int b_liver,int b_ra,int b_tca,int b_type2,double bmi,int close_alcohol_category,int smoke_cat,int surv,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = fracture_male_validation(age,b_asthma,b_corticosteroids,b_cvd,b_falls,b_liver,b_ra,b_tca,b_type2,bmi,close_alcohol_category,smoke_cat,surv,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return fracture_male_raw(age,b_asthma,b_corticosteroids,b_cvd,b_falls,b_liver,b_ra,b_tca,b_type2,bmi,close_alcohol_category,smoke_cat,surv);
}
