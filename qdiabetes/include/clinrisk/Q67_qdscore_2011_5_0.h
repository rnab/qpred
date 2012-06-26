/* 
 * Copyright 2011 ClinRisk Ltd.
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
 * XML source: Q67_qdscore_2011_5_0.xml
 * STATA dta time stamp: 9 May 2011 11:01
 * Header file create date: Wed 22 Jun 2011 10:48:53 BST
 */

double type2_female(
int age,int b_corticosteroids,int b_cvd,int b_treatedhyp,double bmi,int ethrisk,int fh_diab,int smoke_cat,int surv,double town,int *error,char *errorBuf,int errorBufSize
);
