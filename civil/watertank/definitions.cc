#include"declarations.h"

/** initilization of static variable */
int waterTank :: id = 1;

waterTank :: waterTank() {
cout.setf(ios :: fixed);

/** start of initilization of variables */
i = 0;
angleDeg = 0;
maxAngle = 360;
zCord = 0;
braceCounter = 0;
nameCounter = 0;
masterCounter = 0;
columnTypes = 3;
stirrupSuffix = 0;
cmdCounter = 0;
mgedObjectNo = 7;

/** starting of assumed values for rings */
verX = 0;
verY = 0;
verZ = 40000; //temporary value
heightVecX = 0;
heightVecY = 0;
/** end */
/** end of initilization of variables */

cpId = 0;

/** starting of input statements.
* taking input of names of master columns in an array */

ifstream iFile;
/** objectNames.txt file contains names of mged objects */
iFile.open("objectNames.txt");
for (k = 0; k < columnTypes; k++) {
    string arrayBuffer;
    iFile>>arrayBuffer;
    masterColumn.push_back(arrayBuffer);
//    cout<<masterColumn[k];
}

/** taking input of names of mged objects in an array */
for (k = 0; k < mgedObjectNo; k++) {
    string arrayBuffer;
    iFile>>arrayBuffer;
    mgedObjectName.push_back(arrayBuffer);
//    cout<<mgedObjectName[k]<<endl;
}
iFile.close();

/** taking input for depth of "foundation column" and "plinth" */
for (k = 0; k <= 1; k++) {
    cin>>columnHeight[k];
//    cout<<"height: "<<columnHeight[k]<<endl;
}   

/**  taking input for diameter of column above ground */
for (k = 2; k <= 2; k++) {
    cin>>columnDiameter[k];
//    cout<<"dia: "<<columnDiameter[k]<<endl;
}

cin>>foundationDiameter>>colNo;
cin>>databaseName>>colDiameter;
cin>>braceWidth>>braceDepth;

cin>>topRingBeamWidth>>topRingBeamDepth>>cylinderDiameter;
cin>>middleRingBeamWidth>>middleRingBeamDepth;

cin>>braceClearHeight>>cylinderThicknessTop;
cin>>cylinderThicknessBottom>>cylinderHeight;

cin>>bottomRingBeamWidth>>bottomRingBeamDepth;
cin>>foundationBeamWidth>>foundationBeamDepth;

cin>>footingDepth>>stagingHeight>>conicalDomeHeight;
cin>>foundationProjectionInner>>footingDepthInner;

cin>>foundationProjectionOuter>>footingDepthOuter;
cin>>footingThicknessInnerEdge>>footingHorizontalInner;

cin>>footingThicknessOuterEdge>>footingHorizontalOuter;
cin>>topDomeThickness>>topDomeRise;

cin>>bottomDomeThickness>>bottomDomeRise;
cin>>conicalDomeThickness>>braceNumber;

cin>>extraCoverInEarth;
cin>>outerCoverWidth>>steelBarDiameter;

cin>>steelBarNo>>stirrupWidth;
cin>>columnHeightPartitioner;

cin>>stirrupSmallerDistance>>stirrupGreaterDistance;
/** end of input statements */

/** starting of calculations of variable values */
rotationAngle = 180 / colNo;

cylinderRadius = cylinderDiameter / 2;
totalColumnHeight = stagingHeight + footingDepth - bottomRingBeamDepth;

/** starting of calculations for upper and bottom domes */
topDomeInnerRadius = ((cylinderRadius * cylinderRadius) / topDomeRise + topDomeRise) / 2;	
topDomeOuterRadius = topDomeInnerRadius + topDomeThickness;

/** used in calculation of inner and outer radii of bottom dome */
bottomRingInnerRadius = (foundationDiameter / 2) - (bottomRingBeamWidth / 2);

bottomDomeInnerRadius = ((bottomRingInnerRadius * bottomRingInnerRadius) / bottomDomeRise + bottomDomeRise) / 2;	
bottomDomeOuterRadius = bottomDomeInnerRadius + bottomDomeThickness;
/** end of upper and bottom some calculations */

/** height of object(s) that is used to remove inner and outer corner of footing */
innerCornerRemoverHeight = footingDepthInner - footingThicknessInnerEdge;
outerCornerRemoverHeight = footingDepthOuter - footingThicknessOuterEdge;

/** positions of various objects in the space */
bottomRingBeamPosition = footingDepth + stagingHeight - bottomRingBeamDepth;
conicalDomePosition = bottomRingBeamPosition + bottomRingBeamDepth;
middleRingBeamPosition = conicalDomePosition + conicalDomeHeight;
waterContainerPosition = middleRingBeamPosition + middleRingBeamDepth;
topRingBeamPosition = waterContainerPosition + cylinderHeight;
topDomePosition = topRingBeamPosition + topRingBeamDepth - topDomeOuterRadius + topDomeRise;	
bottomDomePosition = bottomRingBeamPosition + bottomRingBeamDepth - bottomDomeOuterRadius + bottomDomeRise;	

/** height of each segment of column above ground */
aboveGroundColHeight = (stagingHeight - bottomRingBeamDepth) / (braceNumber + 1);

/** initializing the variable for placement of first brace-column segment */
columnPosition = aboveGroundColHeight + footingDepth;

/** foundation column and plinth width */
foundationColumnWidth = colDiameter + extraCoverInEarth * 2;	
plinthColumnWidth =  colDiameter + extraCoverInEarth * 2;	
	
/** start of reinforcement calculations */
lowerPortionHeight = totalColumnHeight / columnHeightPartitioner;
upperPortionHeight = totalColumnHeight / columnHeightPartitioner;
middlePortionHeight = totalColumnHeight - upperPortionHeight - lowerPortionHeight;

lowerPortionStarting = zCord;
lowerPortionEnding = totalColumnHeight / columnHeightPartitioner;

middlePortionStarting = lowerPortionEnding;
middlePortionEnding =  lowerPortionEnding + middlePortionHeight;

upperPortionStarting =  middlePortionEnding;
upperPortionEnding = totalColumnHeight;

stirrupRadius = colDiameter / 2 - outerCoverWidth - stirrupWidth / 2;
reinforcementRadius = stirrupRadius - stirrupWidth / 2 - steelBarDiameter / 2;
/** end of reinforcement calculations */

/** length, width and height of cutting box. cutting box is used to cut the water tank into half */
cuttingBoxLengthWidth = cylinderDiameter + middleRingBeamWidth;
cuttingBoxHeight = topRingBeamPosition + topRingBeamDepth + topDomeRise;

/** end of calculations */

/** taking calculated value of height for columnBraceCombination */
columnHeight[2] = aboveGroundColHeight;

/** taking calculated value of width for foundationColumn */
columnDiameter[0] = foundationColumnWidth;

/** taking calculated value of width of plinth column */
columnDiameter[1] = plinthColumnWidth;
 
}

void waterTank :: stepCalculator() {
angleStepDeg = maxAngle / colNo;
        }

void waterTank :: degreeToRadian() {
        stepCalculator();

        /* converting angle from degrees into radians */
        angleRad = angleDeg * (M_PI / 180);

        /* converting increment angle from degrees to radians */
        angleStepRad = angleStepDeg * (M_PI / 180);

        /* converting maximum angle from degrees to radians */
        maxRange = maxAngle * (M_PI / 180);
        }


void waterTank :: coordinatesGenerator() {
	
	/** 
	 * using formulae, "x = r Sin (theta)" and "y = r Cos(theta)", 
         * calculating the value of x and y coordinates of vertices of RCCs 
	 */

        xCord = foundationDiameter / 2 * sin(angleRad);
        yCord = foundationDiameter / 2 * cos(angleRad);
        angleRad = angleRad + angleStepRad;
	}

void waterTank :: braceColumnArrangement() {
        degreeToRadian();

	/** setting the output of floating numbers from 
	 * scientific to normal form 
	 */
        cout.setf(ios :: fixed);
        oFile.setf(ios :: fixed);

	/** 
	 * opening file to write. "ios::out | ios::app" 
	 * part will help us to append the new content to 
	 * the current content of file. 
	 */	
	oFile.open("columnPlacer.sh", ios::out | ios::app);
		
	/** copying master column 002 for column brace segment*/
	oFile<<"cp col002 columnPart"<<"\n";

	/** 
	 * create a master brace at origin.
	 */
	oFile<<" in bracePart rpp "<<"0 "<<braceLengthCalculator();
	oFile<<" -"<<braceWidth/2<<" "<<braceWidth/2<<" 0 "<<braceDepth<<"\n";
	oFile<<"c braceColumnCombination.c bracePart u columnPart\n";
	oFile<<"draw braceColumnCombination.c"<<"\n";
	oFile<<"oed / braceColumnCombination.c/columnPart\n";
	oFile<<"rot 180 0 0"<<"\n";
        oFile<<"accept\n";


	
	/* while initial angle is less than maximum angle */
        while (i < colNo) {
	coordinatesGenerator();
       	/** 
	 * copying master column 000 for foundation column 
	 * and placing it to exact positions.		
 	 */
	oFile<<"cp stirrupSteelBarCol000.c foundationColumn"<<i<<"\n";
	oFile<<"draw foundationColumn"<<i<<"\n";
	oFile<<"oed / foundationColumn"<<i<<"/col000"<<"\n";
	oFile<<"translate "<<setprecision(3)<<xCord<<" "<<setprecision(3)<<yCord<<" 0"<<"\n";
	oFile<<"accept"<<"\n";
	/**
	 * saving names of objects in an array 
	 */
	objectNameCollector("foundationColumn",i);
	i++;
}
	oFile.close(); //temporarily written.
	/** resetting the counter */
	i = 0;

	while (i < colNo) {
	coordinatesGenerator();
	/** 
	 * copying master column 001 for plinth column 
	 * and placing it to exact positions.		
	*/

	cp(masterColumn[1], mgedObjectName[4]);
	attachSuffix(i);
//	oFile<<"cp col001 plinthColumn"<<i<<"\n";
	
	draw(mgedObjectName[4]);
	attachSuffix(i);
//	oFile<<"draw plinthColumn"<<i<<"\n";

	sed(mgedObjectName[4]);
	attachSuffix(i);
//	oFile<<"sed plinthColumn"<<i<<"\n";

	translate(xCord, yCord, footingDepth);
//	oFile<<"translate "<<setprecision(3)<<xCord<<" "<<setprecision(3)<<yCord<<" "<<footingDepth<<"\n";

	accept();
//	oFile<<"accept"<<"\n";
	
	/**
	 * saving names of objects in an array 
	 */
	objectNameCollector("plinthColumn",i);
	i++;
	}


	/** resetting the counter */	
	i = 0;
	while (i < colNo) {
	
	coordinatesGenerator();
	/** 
	 * copying master column 002 for column below bottom ring beam
	 * and placing it to exact positions.		
	 */

	cp(masterColumn[2], mgedObjectName[5]);
	attachSuffix(i);
//	oFile<<"cp col002 bottomRingBeamColumn"<<i<<"\n";

	draw(mgedObjectName[5]);
	attachSuffix(i);
//	oFile<<"draw bottomRingBeamColumn"<<i<<"\n";

	sed(mgedObjectName[5]);
	attachSuffix(i);
//	oFile<<"sed bottomRingBeamColumn"<<i<<"\n";
	
	translate(xCord, yCord, bottomRingBeamPosition - aboveGroundColHeight);	
//	oFile<<"translate "<<setprecision(3)<<xCord<<" "<<setprecision(3)<<yCord<<" "<<bottomRingBeamPosition - aboveGroundColHeight<<"\n";

	accept();
//	oFile<<"accept"<<"\n";
	
	/**
	 * saving names of objects in an array 
	 */
    objectNameCollector("bottomRingBeamColumn",i);
	i++;
}
//	cout<<"after bottomRing"<<cmdCounter<<endl;
	fileWriter(cmdCounter);
//	cout<<"after file writing"<<cmdCounter<<endl;


//        rotationAngle = rotationAngle + angleStepDeg;

        /* incementing the angle */
//        angleRad = angleRad + angleStepRad;

   i = 0;
oFile.open("columnPlacer.sh", ios::out | ios::app);
while (braceCounter < braceNumber) {

	int counter = 0;

	/* while initial angle is less than maximum angle */
        while (counter < colNo) {
	coordinatesGenerator();	
        /* using formulae, "x = r Sin (theta)" and "y = r Cos(theta)", 
        calculating the value of x and y coordinates of vertices of RCCs */
//        xCord = foundationDiameter / 2 * sin(angleRad);
//        yCord = foundationDiameter / 2 * cos(angleRad);

	/* setting the output of floating numbers from scientific to normal form */
        cout.setf(ios :: fixed);
        oFile.setf(ios :: fixed);

//	cout<<"columnPosition: "<<columnPosition<<endl;
//	cout<<"braceCounter: "<<braceCounter<<endl;
 
	oFile<<"\ncp braceColumnCombination.c braceColumnCombination.c"<<i<<"\n";
        oFile<<"draw braceColumnCombination.c"<<i<<"\n";
        oFile<<"oed / braceColumnCombination.c"<<i<<"/columnPart/"<<"\n";
       	oFile<<"rot 0 0 "<<rotationAngle<<"\n";
        oFile<<"translate "<<setprecision(3)<<xCord<<" "<<setprecision(3)<<yCord<<" "<<columnPosition<<"\n";
        oFile<<"accept\n";
	/**
	 * saving names of objects in an array 
	 */
	objectNameCollector("braceColumnCombination.c",i);
	i++;

	rotationAngle = rotationAngle + angleStepDeg;

        /* incementing the angle */
//        angleRad = angleRad + angleStepRad;

        counter++;
	}

	columnPosition = columnPosition + aboveGroundColHeight;
	braceCounter++;	
	}	
	
//	int f;
//	for (f = 0; f < 32; f++) {
//	cout<<"$$$"<<endl<<objectName[f]<<endl;
//	}

	/** removing master braceColumnCombination.c from database file */
	oFile<<"kill braceColumnCombination.c"<<"\n";

	/** closing the file */
	oFile.close();
	}

	/**
	 * Saving the vertices of 1st and 2nd column to 
	 * calculate the distance between them, which is 
	 * being further used as length of each brace.
	 */
	double waterTank :: braceLengthCalculator() 
	{
	
	while(i < 2)
	{
	coordinatesGenerator();
	/* using formulae, "x = r Sin (theta)" and "y = r Cos(theta)", 
        calculating the value of x and y coordinates of vertices of RCCs */
        
//	xCord = foundationDiameter / 2 * sin(angleRad);
//        yCord = foundationDiameter / 2 * cos(angleRad);

	/** vertex of first column */
	if(i == 0) 
	{
	x1 = xCord;
	y1 = yCord;
	}
	
	/** vertex of second column */
	if(i == 1)
	{
	x2 = xCord;
	y2 = yCord;
	}
	
	/* incementing the angle */
//        angleRad = angleRad + angleStepRad;
	
	i++;
	}
	
	/** resetting the variables */
	i = 0;
	angleRad = 0;
	
	/** calculating the length of brace using the concept of distance between two coordinate points */
	braceLength = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	cout<<endl<<braceLength<<endl;
	return braceLength;
	}

	void waterTank :: ringGenerator() 
	{
	oFile.open("columnPlacer.sh", ios::out | ios::app);
	double ringWidth, ringDepth, innerRingDiameter, outerRingRadius, innerRingRadius;

	/** creating top beam ring */
	if (id == 1)
	{
	ringWidth = topRingBeamWidth;
	ringDepth = topRingBeamDepth;
	innerRingRadius = cylinderRadius;
	verZ = topRingBeamPosition;
	}

	/** creating middle beam ring */
	if (id == 2)
	{
	ringWidth = middleRingBeamWidth;
	ringDepth = middleRingBeamDepth;
	innerRingRadius = cylinderRadius;
	verZ = middleRingBeamPosition;
	}

	/** creating bottom beam ring */
	if (id == 3)
	{
	ringWidth = bottomRingBeamWidth;
	ringDepth = bottomRingBeamDepth;
	innerRingRadius = bottomRingInnerRadius;
	verZ = bottomRingBeamPosition;
	}

	/** creating foundatiom beam ring */
	if (id == 4)
	{
	ringWidth = foundationBeamWidth;
	ringDepth = foundationBeamDepth;
	innerRingRadius = foundationDiameter / 2 - foundationBeamWidth / 2;
	verZ = 0;
	}

	/** creating inner side of foundation */	
	if (id == 5)
	{
	ringWidth = foundationProjectionInner;
	ringDepth = footingDepthInner;
	innerRingRadius = foundationDiameter / 2 - foundationBeamWidth / 2 - foundationProjectionInner; 
	verZ = 0;
	}
	
	/** creating outer side of foundation (upper part) */
	if (id == 6)
	{
	ringWidth = foundationProjectionOuter;
	ringDepth = footingDepthOuter - footingThicknessOuterEdge;
	innerRingRadius = foundationDiameter / 2 + foundationBeamWidth / 2; 
	verZ = footingThicknessOuterEdge;
	}
	
	/** creating outer side of foundation (lower part) */
	if (id == 7)
	{
	ringWidth = foundationProjectionOuter;
	ringDepth = footingThicknessOuterEdge;
	innerRingRadius = foundationDiameter / 2 + foundationBeamWidth / 2; 
	verZ = 0;
	}

	outerRingRadius = innerRingRadius + ringWidth;


	/** creating an object to remove inner corner of inner side of foundation */	
	if (id == 5)
	{
	oFile<<"in cornerRemover"<<id<<" trc "<<verX<<" "<<verY<<" "<<footingThicknessInnerEdge;
	oFile<<" "<<heightVecX<<" "<<heightVecY<<" "<<innerCornerRemoverHeight;
	oFile<<" "<<innerRingRadius<<" "<<outerRingRadius - footingHorizontalInner<<"\n";
	}

	/** creating an object to remove outer corner of outer side of foundation */	
	if (id == 6)
	{
	oFile<<"in cornerRemover"<<id<<" trc "<<verX<<" "<<verY<<" "<<footingThicknessOuterEdge;
	oFile<<" "<<heightVecX<<" "<<heightVecY<<" "<<outerCornerRemoverHeight;
	oFile<<" "<<outerRingRadius<<" "<<innerRingRadius + footingHorizontalOuter<<"\n";
	}
	
	/** printing the values of radius of all outer and inner rings */
//	cout<<"outer Ring: id: "<<id<<": "<<outerRingRadius<<endl;
//	cout<<"inner Ring: id: "<<id<<": "<<innerRingRadius<<endl;
	
	/** creating rings */
	oFile<<" in outerRing"<<id<<" rcc "<<verX<<" "<<verY<<" "<<verZ<<" "<<heightVecX<<" "<<heightVecY;
	oFile<<" "<<ringDepth<<" "<<outerRingRadius<<"\n";
	oFile<<" in innerRing"<<id<<" rcc "<<verX<<" "<<verY<<" "<<verZ<<" "<<heightVecX<<" "<<heightVecY;
	oFile<<" "<<ringDepth<<" "<<innerRingRadius<<"\n";

	/** subtracting innerRingX from outerRingX to create final ring */
	oFile<<"c ring"<<id<<" outerRing"<<id<<" - "<<"innerRing"<<id<<"\n";
	
	if (id != 5 & id != 6) {
	    objectNameCollector("ring", id);
	}
	/** removing the inner edge of foundationProjectionInner */
	if (id == 5)
	{
	oFile<<"c foundationInner"<<id<<" ring"<<id<<" - cornerRemover"<<id<<"\n";
	objectNameCollector("foundationInner", id);
	}

	/** removing the outer edge of foundationProjectionOuter */
	if (id == 6)
	{
	oFile<<"c foundationOuter"<<id<<" ring"<<id<<" + cornerRemover"<<id<<"\n";
	objectNameCollector("foundationOuter", id);
	}

	
oFile.close();

	id = id + 1;
	}

void waterTank :: waterContainer()
	{
	oFile.open("columnPlacer.sh", ios::out | ios::app);
	oFile<<"in innerWaterContainer rcc 0 0 0 0 0 "<<cylinderHeight<<" "<<cylinderRadius<<"\n";
	oFile<<"in outerWaterContainer trc 0 0 0 0 0 "<<cylinderHeight<<" "<<cylinderRadius + cylinderThicknessBottom;
	oFile<<" "<<cylinderRadius + cylinderThicknessTop<<"\n";
	oFile<<"c waterContainer.c outerWaterContainer - innerWaterContainer"<<"\n";
	oFile<<"draw waterContainer.c"<<"\n";
	oFile<<"oed / waterContainer.c/innerWaterContainer"<<"\n";
	oFile<<"translate 0 0 "<<waterContainerPosition<<"\n";
	oFile<<"accept"<<"\n";
	oFile.close();
	}

void waterTank :: domeGenerator() {

	/** top dome */
	oFile.open("columnPlacer.sh", ios::out | ios::app);

//        sphere(topInnerDome, topDomeInnerRadius);		
	oFile<<"in topInnerDome sph 0 0 0 "<<topDomeInnerRadius<<"\n";

//	sphere(topOuterDome, topDomeOuterRadius);
	oFile<<"in topOuterDome sph 0 0 0 "<<topDomeOuterRadius<<"\n";

	oFile<<"in topdomeExtraPartRemover rpp -"<<topDomeOuterRadius<<" ";
	oFile<<topDomeOuterRadius<<" -"<<topDomeOuterRadius<<" ";
	oFile<<topDomeOuterRadius<<" -"<<topDomeOuterRadius<<" ";
	oFile<<topDomeOuterRadius<<"\n";
	oFile<<"c topDome.c topOuterDome - topInnerDome"<<"\n";
	oFile<<"draw topDome.c\n";
	oFile<<"oed / topDome.c/topOuterDome"<<"\n";
	oFile<<"translate 0 0 1500"<<"\n";
	oFile<<"accept\n";
	oFile<<"c topDome1.c topDome.c - topdomeExtraPartRemover"<<"\n";
	oFile<<"draw topDome1.c\n";
	oFile<<"oed / topDome1.c/topDome.c/topOuterDome"<<"\n";
	oFile<<"translate 0 0 "<<topDomePosition<<"\n";
	oFile<<"accept"<<"\n";

	
	/** bottom Dome */
//	sphere(bottomInnerDome, bottomDomeInnerRadius);
	oFile<<"in bottomInnerDome sph 0 0 0 "<<bottomDomeInnerRadius<<"\n";

//	sphere(bottomOuterDome, bottomDomeOuterRadius);
	oFile<<"in bottomOuterDome sph 0 0 0 "<<bottomDomeOuterRadius<<"\n";

	oFile<<"in bottomdomeExtraPartRemover rpp -"<<topDomeOuterRadius<<" ";
	oFile<<bottomDomeOuterRadius<<" -"<<bottomDomeOuterRadius<<" ";
	oFile<<bottomDomeOuterRadius<<" -"<<bottomDomeOuterRadius<<" ";
	oFile<<bottomDomeOuterRadius<<"\n";
	oFile<<"c bottomDome.c bottomOuterDome - bottomInnerDome"<<"\n";
	oFile<<"draw bottomDome.c\n";
	oFile<<"oed / bottomDome.c/bottomOuterDome"<<"\n";
	oFile<<"translate 0 0 1500"<<"\n";
	oFile<<"accept\n";
	oFile<<"c bottomDome1.c bottomDome.c - bottomdomeExtraPartRemover"<<"\n";
	oFile<<"draw bottomDome1.c\n";
	oFile<<"oed / bottomDome1.c/bottomDome.c/bottomOuterDome"<<"\n";
	oFile<<"translate 0 0 "<<bottomDomePosition<<"\n";
	oFile<<"accept"<<"\n";
	oFile.close();
	}

void waterTank :: conicalDomeGenerator() {
	oFile.open("columnPlacer.sh", ios::out | ios::app);
	oFile<<"in innerConicalDome trc 0 0 0 0 0 "<<conicalDomeHeight<<" "<<bottomRingInnerRadius;
        oFile<<" "<<cylinderRadius<<"\n";
	oFile<<"in outerConicalDome trc 0 0 0 0 0 "<<conicalDomeHeight<<" "<<bottomRingInnerRadius + conicalDomeThickness; 
        oFile<<" "<<cylinderRadius + conicalDomeThickness<<"\n";
	oFile<<"c conicalDome.c outerConicalDome - innerConicalDome"<<"\n";
	oFile<<"draw conicalDome.c"<<"\n";
	oFile<<"oed / conicalDome.c/outerConicalDome"<<"\n";
	oFile<<"translate 0 0 "<<conicalDomePosition<<"\n";
	oFile<<"accept"<<"\n";
	oFile.close();
	}

void waterTank :: cylinderGenerator() {
	cout.setf(ios :: fixed);
        oFile.setf(ios :: fixed);
	
        oFile.open("columnPlacer.sh", ios::out | ios::app);
	oFile<<"#!/bin/bash\n";
        oFile<<"cat <<EOF | mged -c "<<databaseName<<"\n";

	for (k = 0; k < columnTypes; k++) {	
	    oFile<<"in "<<masterColumn[k]<<" rcc 0 0 0 0 0 "<<setprecision(3)<<columnHeight[k]<<" "<<columnDiameter[k]/2<<"\n";
//	    cout<<"height: "<<columnHeight[k]<<" column: "<<columnDiameter[k]<<endl;
	    }
	oFile.close();
        }
/**
 * This function creates steel bars along a circular path with centre at origin.
 * Later these are combined as a region. This region is further combined in a combination
 * with col002.
 */
void waterTank :: columnReinforcement() {
	cout.setf(ios :: fixed);
        oFile.setf(ios :: fixed);
	oFile.open("columnPlacer.sh", ios :: out | ios :: app);

	/** declaring string array of same size as that of no. of steel bars, so as to store their respective names. */
	string steelBarArray[steelBarNo];
	
	/** creating steel bars */
	int steelBarCounter;
	for (steelBarCounter = 0; steelBarCounter < steelBarNo; steelBarCounter++) {
	
        /* using formulae, "x = r Sin (theta)" and "y = r Cos(theta)", 
        calculating the value of x and y coordinates of vertices of RCCs */
        xCord = reinforcementRadius * sin(angleRad);
        yCord = reinforcementRadius * cos(angleRad);

	oFile<<"in steelBar"<<steelBarCounter<<" rcc "<<setprecision(3)<<xCord;
        oFile<<" "<<setprecision(3)<<yCord<<" "<<setprecision(3)<<zCord;
        oFile<<" 0 0 "<<totalColumnHeight<<" "<<steelBarDiameter / 2<<"\n";

	/**
	 * saving names of steel bar objects in an array 
	 */
	s<<" u steelBar"<<steelBarCounter;
	steelBarArray[steelBarCounter] = s.str();
	s.str(std :: string());

	/** incementing the angle */
        angleRad = angleRad + angleStepRad;
	}

	/** creating master stirrup */
	oFile<<"in stirrup tor 0 0 "<<zCord;
	oFile<<" 0 0 1 "<<stirrupRadius<<" "<<stirrupWidth / 2<<"\n";
	
	/** resetting the value of z coordinate to "0" */
	zCord = 0;
	
	/** copying master stirrup and placing along the column height */
	while (zCord < totalColumnHeight) {

	    /** placing stirrups in lower portion */
    	    if (zCord < lowerPortionEnding) {
                while (zCord < lowerPortionEnding) { 
         	    oFile<<"cp stirrup stirrup"<<stirrupSuffix<<"\n";
		    oFile<<"draw stirrup"<<stirrupSuffix<<"\n";
		    oFile<<"sed stirrup"<<stirrupSuffix<<"\n";
		    oFile<<"translate 0 0 "<<zCord<<"\n";
		    oFile<<"accept"<<"\n";
   		    zCord = zCord + stirrupSmallerDistance;
		    stirrupSuffix++;
		    }
    	    }
	    /** placing stirrups in middle portion */
	    else if (zCord < middlePortionEnding) {
        	while (zCord < middlePortionEnding) {
         	    oFile<<"cp stirrup stirrup"<<stirrupSuffix<<"\n";
		    oFile<<"draw stirrup"<<stirrupSuffix<<"\n";
		    oFile<<"sed stirrup"<<stirrupSuffix<<"\n";
		    oFile<<"translate 0 0 "<<zCord<<"\n";
		    oFile<<"accept"<<"\n";
         	    zCord = zCord + stirrupGreaterDistance;
        	    stirrupSuffix++;
		    }
    	    }
	    /** placing stirrups in upper portion */
	    else if (zCord <= totalColumnHeight) {
        	while (zCord <= totalColumnHeight) {
         	    oFile<<"cp stirrup stirrup"<<stirrupSuffix<<"\n";
		    oFile<<"draw stirrup"<<stirrupSuffix<<"\n";
		    oFile<<"sed stirrup"<<stirrupSuffix<<"\n";
		    oFile<<"translate 0 0 "<<zCord<<"\n";
		    oFile<<"accept"<<"\n";
            	    zCord = zCord + stirrupSmallerDistance;
        	    stirrupSuffix++;
		    }
    	    }
	}

	/** resetting the value of z coordinate again to "0" */
	zCord = 0;
	/** 
	 * since at this point, the variable "stirrupSuffix" has the value 
	 * = (total number of stirrups + 1)  */
	string stirrup[stirrupSuffix];
	int stirrupCounter;
	
	/**
	 * saving names of stirrup objects in an array 
	 */
	for (stirrupCounter = 0; stirrupCounter < stirrupSuffix; stirrupCounter++) {	
	s<<" u stirrup"<<stirrupCounter;
	stirrup[stirrupCounter] = s.str();
	s.str(std :: string());
	}	
        
	/** creating region of stirrups */
	oFile<<"r stirrup.r";
	for (stirrupCounter = 0; stirrupCounter < stirrupSuffix; stirrupCounter++) {
	oFile<<stirrup[stirrupCounter];
	}
	oFile<<endl;

	/** creating region of steel bars */
	oFile<<"r steelBar.r";
	for (steelBarCounter = 0; steelBarCounter < steelBarNo; steelBarCounter++) {
	oFile<<steelBarArray[steelBarCounter];
	}
	oFile<<endl;

	/** creating combination of regions of stirrups and steel bars */
	oFile<<"c stirrupSteelBarCombination.c stirrup.r u steelBar.r"<<"\n";


	/** creating region of steelBar combination and foundation columns. */	
	oFile<<"c stirrupSteelBarCol000.c stirrupSteelBarCombination.c u col000"<<"\n";
	oFile.close();
}

void waterTank :: waterTankCrossSection() {
    cout.setf(ios :: fixed);
    oFile.setf(ios :: fixed);
    oFile.open("columnPlacer.sh", ios::out | ios::app);
    oFile<<"in cuttingBox rpp -"<<cuttingBoxLengthWidth / 2;
    oFile<<" "<<cuttingBoxLengthWidth / 2<<" -";
    oFile<<cuttingBoxLengthWidth / 2<<" "<<cuttingBoxLengthWidth / 2;
    oFile<<" 0 "<<cuttingBoxHeight<<"\n";
    oFile<<"e cuttingBox"<<"\n";
    oFile<<"sed cuttingBox"<<"\n";
    oFile<<"tra "<<cuttingBoxLengthWidth / 2<<" 0 0"<<"\n";
    oFile<<"accept"<<"\n";
    oFile.close();
}

void waterTank :: stirrupCopier(double stirrupDistance) {

	/** setting the output of floating numbers from 
	 * scientific to normal form 
	 */
        cout.setf(ios :: fixed);
        oFile.setf(ios :: fixed);
cout<<"stirrup Copier"<<endl;
oFile<<"cp stirrup stirrup"<<stirrupSuffix<<"\n";
oFile<<"draw stirrup"<<stirrupSuffix<<"\n";
oFile<<"sed stirrup"<<stirrupSuffix<<"\n";
oFile<<"translate 0 0 "<<zCord<<"\n";
oFile<<"accept"<<"\n";
}


/** 
 * vector writer: common function 
 * that is being called by other functions
 * to write content in a vector, increment 
 * the cmdCounter and clear the contents of variable "object"
 * having type stringstream */
void waterTank :: vectorWriter() 
{
    mgedCmd.push_back(object.str());
    cmdCounter++;
    object.str(std::string());
}

/** function to write into file */
void waterTank :: fileWriter(int cmdCounter)
{
    int fileCounter;
    cout<<"fileWriter: "<<cmdCounter<<endl;
    oFile.open("columnPlacer.sh", ios::out | ios::app);
    for (fileCounter = 0; fileCounter < cmdCounter; fileCounter++) {
        oFile<<mgedCmd[fileCounter];
 //       cout<<mgedCmd[fileCounter]<<" -- "<<fileCounter<<endl;
    }
    cmdCounter = 0;
    oFile.close();
}

/** function for creating sphere using "in" command of mged */
void waterTank :: sphere(string sphereName, double sphereRadius, double sphereCenterXCord, double sphereCenterYCord, double sphereCenterZCord) {
object<<"in "<<sphereName<<" "<<sphereCenterXCord<<" "<<sphereCenterYCord<<" "<<sphereCenterZCord<<" "<<sphereRadius<<"\n";
vectorWriter();
}

/** function for mged "draw" command */
void waterTank :: draw(string objectName) {
object<<"\n"<<"draw "<<objectName;
vectorWriter();
}

void waterTank :: cp(string original, string copy) {
object<<"\n"<<"cp "<<original<<" "<<copy;
vectorWriter();
}

void waterTank :: attachSuffix(int suffix) {
object<<suffix;
vectorWriter();
}

void waterTank :: sed(string objectName) {
object<<"\n"<<"sed "<<objectName;
vectorWriter();
}

void waterTank :: translate(double x,  double y, double z) {
object.setf(ios :: fixed);
object<<"\n"<<"translate "<<setprecision(3)<<x<<" "<<setprecision(3)<<y<<" "<<setprecision(3)<<z;
vectorWriter();
}

void waterTank :: accept() {
object<<"\n"<<"accept";
vectorWriter();
}

void waterTank :: combination(){
	int combinationCounter;
	oFile.open("columnPlacer.sh", ios::out | ios::app);
	oFile<<"r watertank.r";
	for (combinationCounter = 0; combinationCounter < nameCounter;
		combinationCounter++){ 
			cout<<objectName[combinationCounter]<<" ";
			oFile<<" u "<<objectName[combinationCounter];
	}
	oFile<<" u waterContainer.c u topDome1.c u bottomDome1.c"; 
	oFile<<" u conicalDome.c\n";
	oFile.close();
}

void waterTank :: objectNameCollector(string name, double suffix){
	concatenator<<name<<suffix;
	objectName[nameCounter] = concatenator.str();
	concatenator.str(std :: string());
	nameCounter++;
	}
