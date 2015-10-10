wBRLCAD
=======

Extending power of BRLCAD through web.

BRL-CAD is a powerful cross-platform Open Source solid modeling system based on the concept of Constructive Solid Geometry (CSG) that includes interactive 3D solid geometry editing, high-performance ray-tracing support for rendering and geometric analysis and ton of other features. For more information, please visit: http://brlcad.org/d/about

wBRLCAD is aimed at extending the capability of BRLCAD from desktop to web in the fields of Civil, Mechanical and other general use. 

Basically, this project has three main branches (other than github branches). These are Civil, Mechanical and General. These three branches contain further independent projects that provide ease of use to end user. 

Currently, Civil branch has following projects:

Watertank

##Requirement-:

1. g++

2. apache2

3. BRLCAD


##Installation -:

1. configure apache2 to run cgi.

2. Add this to /etc/apache2/sites-available/000-default.conf file

	<FilesMatch script$>
	    SetHandler cgi-script
	</FilesMatch>

3. Put this folder in cgi-bin.

4. $cd /path/to/folder/watertank
	
5.	$make  

6. Run follwing url in browser-:
	
	http://localhost/path/to/folder/watertank/waterTankForm/onform.html 	
	
