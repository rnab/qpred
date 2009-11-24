Welcome to QFracture (http://qfracture.org)
-------------------------------------------

Copyright 2009 ClinRisk Ltd.

This file is part of QFracture (http://qfracture.org).

QFracture is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

QFracture is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with QFracture.  If not, see <http://www.gnu.org/licenses/>.

----

Please note:

  The QFracture algorithms are also available from ClinRisk Ltd. under a commercial licence.
  This is for suppliers who do not want to release any code under the open source licence.  
  With the commercial licence, suppliers can either use the open source code and base their code on that, or use our .NET software development kit.  
  Closed source implementations need to undergo an accreditation process with ClinRisk Ltd., to ensure that their published software implements QFracture accurately.

  Use of the QFracture trademark is linked to using the latest version of the QFracture algorithm.  We expect that the algorithm will be updated annually, re-fitted to the latest version of the QResearch database.

  Support contracts are available from ClinRisk Ltd., both for the open source route, and also for those who wish to go a closed source route.

----

To compile QFracture on a UNIX-like system, type
 make
 make executables
to create the command line executables.

Please check http://qfracture.org for our latest sources.
The intention is to update the QFracture algorithms annually.  

This is the initial 2009, released on the day of publication of the BMJ QFracture paper, 20/11/2009, and has STATA dta time stamp: 2 Sep 2009 08:55.

There are a few patients where the risk of hip fracture calculated with the algorithm appears to exceed the overall estimated fracture risk. 
This situation affects less than 0.5% of the population and is found in the most  elderly patients with multiple risk  factors. 
Since the hip fracture algorithm has the better performance, we have substituted this value for the overall fracture risk value for those patients to avoid any under-estimation in risk. 
There are less data available for modelling at the extremes of age and this is the most likely explanation for why the models appear less stable at the extremes.
