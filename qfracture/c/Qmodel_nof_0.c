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
 * XML source: Qmodel_nof_0.xml
 * STATA dta time stamp: 2 Sep 2009 08:55
 * C file create date: Fri Nov 20 22:52:56 GMT 2009
 */

#include <math.h>
#include <string.h>
#include <irisk/Qmodel_nof_0.h>
#include <irisk/util.h>

static double nof_female_raw(
int age,int b_asthma,int b_corticosteroids,int b_cvd,int b_endocrine,int b_falls,int b_liver,int b_malabsorption,int b_menopausalsymptoms,int b_ra,int b_tca,int b_type2,double bmi,int close_alcohol_category,int fh_osteoporosis,int hrt_classify,int smoke_cat,int surv
)
{
	double survivor[11] = {
		0,
		0.999901890754700,
		0.999804556369781,
		0.999695241451263,
		0.999577820301056,
		0.999432742595673,
		0.999266982078552,
		0.999067306518555,
		0.998853743076324,
		0.998617410659790,
		0.998342514038086
	};

	/* The conditional arrays */

	double Ialcohol[6] = {
		0,
		-0.1272222098947520800000000,
		-0.1352819239197220200000000,
		-0.0510266904848880040000000,
		0.3426624372575582400000000,
		0.8096672226954656500000000
	};
	double Ihrt[14] = {
		0,
		-0.2275073688666170400000000,
		-0.1354734181150799300000000,
		-0.4323144416635494300000000,
		-0.2207530933594222800000000,
		-0.0766314770410703310000000,
		-0.2191061971428427400000000,
		0.0019099184305622998000000,
		-0.0932886265174169280000000,
		0.1122692875790380900000000,
		-0.1736314894612923900000000,
		0,
		-0.1958562970264298200000000,
		-0.4756574573194372000000000
	};
	double Ismoke[5] = {
		0,
		0.0399392520037666830000000,
		0.1640997105002404100000000,
		0.2804763676661344900000000,
		0.4387473026461515800000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,3);
	double age_2 = pow(dage,3)*log(dage);
	double dbmi = bmi;
	dbmi=dbmi/10;
	double bmi_1 = pow(dbmi,-2);

	/* Centring the continuous variables */

	age_1 = age_1 - 132.450866699218750;
	age_2 = age_2 - 215.727661132812500;
	bmi_1 = bmi_1 - 0.148729562759399;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Ialcohol[close_alcohol_category];
	a += Ihrt[hrt_classify];
	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += age_1 * 0.0664527772546618520000000;
	a += age_2 * -0.0253868349666359210000000;
	a += bmi_1 * 5.1369781819440377000000000;

	/* Sum from boolean values */

	a += b_asthma * 0.2789085205155984500000000;
	a += b_corticosteroids * 0.1612852780510756800000000;
	a += b_cvd * 0.1529014034280595800000000;
	a += b_endocrine * 0.1705587864007732100000000;
	a += b_falls * 0.7072235511703520700000000;
	a += b_liver * 0.5030545791676919200000000;
	a += b_malabsorption * 0.0969998721241282500000000;
	a += b_menopausalsymptoms * 0.1205852327982601500000000;
	a += b_ra * 0.5762719083422049900000000;
	a += b_tca * 0.2913674504005155400000000;
	a += b_type2 * 0.5106376415323860000000000;
	a += fh_osteoporosis * 0.0559527659338745420000000;

	/* Sum from interaction terms */


	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int nof_female_validation(
int age,int b_asthma,int b_corticosteroids,int b_cvd,int b_endocrine,int b_falls,int b_liver,int b_malabsorption,int b_menopausalsymptoms,int b_ra,int b_tca,int b_type2,double bmi,int close_alcohol_category,int fh_osteoporosis,int hrt_classify,int smoke_cat,int surv,char *errorBuf,int errorBufSize
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
	if (!is_boolean(b_endocrine)) {
		ok=0;
		strlcat(errorBuf,"error: b_endocrine must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_falls)) {
		ok=0;
		strlcat(errorBuf,"error: b_falls must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_liver)) {
		ok=0;
		strlcat(errorBuf,"error: b_liver must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_malabsorption)) {
		ok=0;
		strlcat(errorBuf,"error: b_malabsorption must be in range (0,1)\n",errorBufSize);
	}
	if (!is_boolean(b_menopausalsymptoms)) {
		ok=0;
		strlcat(errorBuf,"error: b_menopausalsymptoms must be in range (0,1)\n",errorBufSize);
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
	if (!is_boolean(fh_osteoporosis)) {
		ok=0;
		strlcat(errorBuf,"error: fh_osteoporosis must be in range (0,1)\n",errorBufSize);
	}
	if (!i_in_range(hrt_classify,0,13)) {
		ok=0;
		strlcat(errorBuf,"error: hrt_classify must be in range (0,13)\n",errorBufSize);
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

double nof_female(
int age,int b_asthma,int b_corticosteroids,int b_cvd,int b_endocrine,int b_falls,int b_liver,int b_malabsorption,int b_menopausalsymptoms,int b_ra,int b_tca,int b_type2,double bmi,int close_alcohol_category,int fh_osteoporosis,int hrt_classify,int smoke_cat,int surv,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = nof_female_validation(age,b_asthma,b_corticosteroids,b_cvd,b_endocrine,b_falls,b_liver,b_malabsorption,b_menopausalsymptoms,b_ra,b_tca,b_type2,bmi,close_alcohol_category,fh_osteoporosis,hrt_classify,smoke_cat,surv,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return nof_female_raw(age,b_asthma,b_corticosteroids,b_cvd,b_endocrine,b_falls,b_liver,b_malabsorption,b_menopausalsymptoms,b_ra,b_tca,b_type2,bmi,close_alcohol_category,fh_osteoporosis,hrt_classify,smoke_cat,surv);
}
