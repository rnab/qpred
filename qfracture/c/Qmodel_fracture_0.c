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
 * XML source: Qmodel_fracture_0.xml
 * STATA dta time stamp: 2 Sep 2009 08:55
 * C file create date: Fri Nov 20 22:52:36 GMT 2009
 */

#include <math.h>
#include <string.h>
#include <irisk/Qmodel_fracture_0.h>
#include <irisk/util.h>

static double fracture_female_raw(
int age,int b_asthma,int b_corticosteroids,int b_cvd,int b_endocrine,int b_falls,int b_liver,int b_malabsorption,int b_menopausalsymptoms,int b_ra,int b_tca,int b_type2,double bmi,int close_alcohol_category,int fh_osteoporosis,int hrt_classify,int smoke_cat,int surv
)
{
	double survivor[11] = {
		0,
		0.999080657958984,
		0.998103082180023,
		0.997029721736908,
		0.995813012123108,
		0.994470179080963,
		0.993021965026855,
		0.991343677043915,
		0.989629805088043,
		0.987689733505249,
		0.985766530036926
	};

	/* The conditional arrays */

	double Ialcohol[6] = {
		0,
		-0.0015342444146155703000000,
		0.0202998829881848200000000,
		0.0270109777978433560000000,
		0.3904199623583949900000000,
		0.6960912808109172000000000
	};
	double Ihrt[14] = {
		0,
		-0.1085999151494391700000000,
		-0.1059570787675646600000000,
		-0.2855453273396474400000000,
		-0.2723086435138115100000000,
		-0.0861660332225285260000000,
		-0.0657901464962380860000000,
		0.1323698420086327800000000,
		-0.2094520847099630200000000,
		0.2154748718637425900000000,
		0.0299465951950255020000000,
		0,
		-0.1278535363457821200000000,
		-0.0823984848587913240000000
	};
	double Ismoke[5] = {
		0,
		0.0210993664817644140000000,
		0.0402380949029234260000000,
		0.1042268143129933000000000,
		0.1882003649002871300000000
	};

	/* Applying the fractional polynomial transforms */
	/* (which includes scaling)                      */

	double dage = age;
	dage=dage/10;
	double age_1 = pow(dage,-1);
	double age_2 = pow(dage,-1)*log(dage);
	double dbmi = bmi;
	dbmi=dbmi/10;
	double bmi_1 = pow(dbmi,-1);

	/* Centring the continuous variables */

	age_1 = age_1 - 0.196857452392578;
	age_2 = age_2 - 0.319947570562363;
	bmi_1 = bmi_1 - 0.385591715574265;

	/* Start of Sum */
	double a=0;

	/* The conditional sums */

	a += Ialcohol[close_alcohol_category];
	a += Ihrt[hrt_classify];
	a += Ismoke[smoke_cat];

	/* Sum from continuous values */

	a += age_1 * 4.1258537545712093000000000;
	a += age_2 * -39.1980071031613590000000000;
	a += bmi_1 * 2.9324140498583149000000000;

	/* Sum from boolean values */

	a += b_asthma * 0.2540161318210931700000000;
	a += b_corticosteroids * 0.1564853455644983600000000;
	a += b_cvd * 0.1564529413303961900000000;
	a += b_endocrine * 0.1085547161760247000000000;
	a += b_falls * 0.5987537045436228700000000;
	a += b_liver * 0.5826327338078524100000000;
	a += b_malabsorption * 0.2094076997680918700000000;
	a += b_menopausalsymptoms * 0.1396743935623578100000000;
	a += b_ra * 0.2663728763961483200000000;
	a += b_tca * 0.2703264525090124900000000;
	a += b_type2 * 0.2254547635539113100000000;
	a += fh_osteoporosis * 0.5785059281875142300000000;

	/* Sum from interaction terms */


	/* Calculate the score itself */
	double score = 100.0 * (1 - pow(survivor[surv], exp(a)) );
	return score;
}

static int fracture_female_validation(
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

double fracture_female(
int age,int b_asthma,int b_corticosteroids,int b_cvd,int b_endocrine,int b_falls,int b_liver,int b_malabsorption,int b_menopausalsymptoms,int b_ra,int b_tca,int b_type2,double bmi,int close_alcohol_category,int fh_osteoporosis,int hrt_classify,int smoke_cat,int surv,int *error,char *errorBuf,int errorBufSize
)
{
	*error = 0;	int ok = fracture_female_validation(age,b_asthma,b_corticosteroids,b_cvd,b_endocrine,b_falls,b_liver,b_malabsorption,b_menopausalsymptoms,b_ra,b_tca,b_type2,bmi,close_alcohol_category,fh_osteoporosis,hrt_classify,smoke_cat,surv,errorBuf,errorBufSize);
	if(!ok) { 
		*error = 1;
		return 0.0;
	}
	return fracture_female_raw(age,b_asthma,b_corticosteroids,b_cvd,b_endocrine,b_falls,b_liver,b_malabsorption,b_menopausalsymptoms,b_ra,b_tca,b_type2,bmi,close_alcohol_category,fh_osteoporosis,hrt_classify,smoke_cat,surv);
}
