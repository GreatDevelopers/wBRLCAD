#include"declarations.h"
/** initilization of static variable */
//int id = 1;
int main()
{
	ofstream oFile;
	system("rm columnPlacer.sh"); 
	waterTank rcc;
	rcc.degreeToRadian();
	rcc.cylinderGenerator();
	rcc.columnReinforcement();
        rcc.braceColumnArrangement();
	rcc.ringGenerator();
	rcc.ringGenerator();
	rcc.ringGenerator();
	rcc.ringGenerator();
	rcc.ringGenerator();
	rcc.ringGenerator();
	rcc.ringGenerator();
	rcc.waterContainer();
	rcc.domeGenerator();
	rcc.conicalDomeGenerator();
	rcc.waterTankCrossSection();
	rcc.combination();
	oFile.open("columnPlacer.sh", ios::out | ios::app);
	oFile<<"EOF\n";
	oFile.close();
        return(0);
}
