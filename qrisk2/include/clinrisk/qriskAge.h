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
 * The initial version of this file, to be found at http://svn.clinrisk.co.uk/qrisk2, faithfully implements QRISK2-2012.
 * We have released this code under the GNU Lesser General Public License to enable others to implement the algorithm faithfully.
 * However, the nature of the GNU Lesser General Public License is such that we cannot prevent, for example, someone altering the coefficients.
 * We stress, therefore, that it is the responsibility of the end user to check that the source that they receive produces the same results as the original code posted at http://svn.clinrisk.co.uk/qrisk2.
 * Inaccurate implementations of risk scores can lead to wrong patients being given the wrong treatment.
 * 
 */

double referenceValuesGet_score(int sex, int age, int ethrisk); 
int referenceValuesSize_of_array(void);
char * referenceValuesVersion(void);
int qriskAge(int sex, int ethrisk, double score);
int maxAge;
int minAge;
