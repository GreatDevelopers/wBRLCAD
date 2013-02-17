#include<iostream>
#include<iomanip>
#include<math.h>
#include<fstream>
#include<stdlib.h>
#include<sstream>
#include<vector>
using namespace std;

class waterTank
{
/** Will be used for column name incremental suffix */
int i;

/** counter for height in cylinderGenerator */
int k;

/** suffix of stirrup object names */
int stirrupSuffix;

/** Diameter of water tank base */
int foundationDiameter;

/** Initial angle in degrees */
int angleDeg;

/** Number of columns */
double colNo;

/** Maximum angle */
int maxAngle;

/** Increment in angle in degrees */
int  angleStepDeg;

/** Name of mged database file */
string databaseName;

/** Radius of columns */
int colDiameter;

/** rotation angle to rotate braces */
double rotationAngle;	

/** x coordinate, y coordinate, z coordinate
* initial angle in radians, increment in angle 
* in radians, maximum value of angle */
double xCord, yCord, zCord, angleRad, angleStepRad, maxRange;

/**
 * x1, y1: storing x and y coordinates of 1st column
 * x2, y2: storing x and y coordinates of 2st column
 * length, width and height of each brace.
 */
double x1, y1, x2, y2, braceLength, braceWidth, braceDepth;

/**
 * diameter, radius and height of water holding tank,
 * top & bottom thickness of its walls 
 */
double cylinderDiameter;
double cylinderRadius;
double cylinderHeight;	
double cylinderThicknessTop;	
double cylinderThicknessBottom;

/** x, y and z coordinates of vertex of rings */
double verX;
double verY;
double verZ;

/** x and y height vectors of rings. 
 * Its third vertex, z will be used to decide position */
double heightVecX;
double heightVecY;

/** height and width of top beam ring */
double topRingBeamDepth;
double topRingBeamWidth;

/** height and width of middle beam ring */
double middleRingBeamDepth;
double middleRingBeamWidth;

/** height and width of bottom beam ring */
double bottomRingBeamDepth;
double bottomRingBeamWidth;

/** height and width of foundation beam ring */
double foundationBeamDepth;
double foundationBeamWidth;

/** distance from ground to bottomBeamRing */
double stagingHeight;

/** distance between ground and lower of lowest brace */
double braceClearHeight;

double topRingBeamPosition;
double middleRingBeamPosition;
double bottomRingBeamPosition;
double waterContainerPosition;
double bottomRingBeamColumnPosition;

double footingDepth;
double foundationProjectionInner;
double footingDepthInner;
double foundationProjectionOuter;
double footingDepthOuter;
double footingThicknessInnerEdge;
double footingHorizontalInner;
double innerCornerRemoverHeight;
double footingThicknessOuterEdge;
double footingHorizontalOuter;
double outerCornerRemoverHeight;

double topDomeThickness;
double topDomeRise;
double topDomeInnerRadius;
double topDomeOuterRadius;
double topDomePosition;

double bottomDomeThickness;
double bottomDomeRise;
double bottomDomeInnerRadius;
double bottomDomeOuterRadius;
double bottomDomePosition;
double bottomRingInnerRadius;

double conicalDomeHeight;
double conicalDomeThickness;
double conicalDomePosition;

/** height of each segment of column above ground */
double aboveGroundColHeight;	

/** width of foundation column below ground */
double foundationColumnWidth;

/** width of plinth column above ground */
double plinthColumnWidth;

double extraCoverInEarth;

double columnPosition;

/** used in cylinderGenerator() */
double columnHeight[3];
double columnDiameter[3];

double braceNumber;
double braceCounter;

double outerCoverWidth;
double steelBarDiameter;

int steelBarNo;
double reinforcementRadius;	

string objectName[100];
int nameCounter; 

int masterCounter;
int columnTypes;	

stringstream concatenator;
stringstream s;
stringstream object;
double lowerPortionHeight;
double upperPortionHeight;
double middlePortionHeight;
double lowerPortionStarting;
double middlePortionStarting;
double upperPortionStarting;   
double lowerPortionEnding;
double middlePortionEnding;
double upperPortionEnding;	
double totalColumnHeight;
double columnHeightPartitioner;
double stirrupRadius;
double stirrupWidth;
double stirrupDistance;
double stirrupSmallerDistance;
double stirrupGreaterDistance;

double cuttingBoxLengthWidth;
double cuttingBoxHeight;

vector<string> mgedCmd;
vector<string> masterColumn;
vector<string> mgedObjectName;
int mgedObjectNo;

int cmdCounter;
int cpId;

ofstream oFile;

string shellScript;

/** used to create beam rings for different set of values */
static int id;	

public:

/** constructer */
waterTank();
void stepCalculator();
void degreeToRadian();
void braceColumnArrangement();
double braceLengthCalculator();
void ringGenerator();
void waterContainer();
void domeGenerator();
void conicalDomeGenerator();
void cylinderGenerator();
void columnReinforcement();
void coordinatesGenerator();
void waterTankCrossSection();
void stirrupCopier(double);
void sphere(string sphereName, double sphereRadius, double sphereCenterXCord = 0, double sphereCenterYCord = 0, double sphereCenterZCord = 0);
void draw(string);
void cp(string, string);
void sed(string);
void translate(double x = 0, double y = 0, double z = 0);
void fileWriter(int);
void vectorWriter();
void attachSuffix(int);
void accept();
};
