#####################################################################
# This is makefile for watertank sub project under wBRLCAD project. # 
#                                                                   # 
# Written By: Harmanpreet Singh                                     # 
#####################################################################

# main function file
mainFunction = watertank.cpp

# main function object file
mainFunctionObj = watertank.o

# file containing all definitions of functions and 
#variables.
definitions = definitions.cc

# definitions object file
definitionsObj = definitions.o

# file containing all declarations of functions and 
# variables.
declarations = declarations.h 

# main executable file of watertank project
main = watertank

# input file of watertank project
inputFile = inputForm/values

# name of compiler
compiler = g++

# all flags to be used during compilation
compilationFlags = -c

# Place output in a file.  This applies regardless to 
# whatever sort of output is being produced, whether it 
# be an executable file, an object file etc.
outputRedirectFlag = -o 

# defining targets and sources.

# calling the targets specified in the list below.
all: execute

# compiling file containing definitions
$(definitionsObj): $(definitions) $(declarations)
	$(compiler) $(compilationFlags) $(definitions)

# compiling file containing main function
$(mainFunctionObj): $(mainFunction) $(declarations)
	$(compiler) $(compilationFlags) $(mainFunction)

# linking object files
$(main): $(definitionsObj) $(mainFunctionObj) 
	$(compiler) $(outputRedirectFlag) $(main) $(definitionsObj) \
	$(mainFunctionObj)

execute: $(main)	
	./$(main) < $(inputFile)
	sh columnPlacer.sh > /dev/null 2>&1
	./render.sh > /dev/null 2>&1
	shotwell wtrt.png 
	@echo "$(Please wait while we process the inputs...)"
clean: 
	rm *.o *.g columnPlacer.sh wtrt* $(main)

