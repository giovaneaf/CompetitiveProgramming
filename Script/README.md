# runtests.sh explanation
This script run test cases automatically for you. (Tested on Ubuntu 16.04 LTS)
# Requirements
Test cases with input and output files with same name and different extensions at the same folder
An executable to run the tests
# Example
If I have an executable in the current folder B and my test cases at the location described below then the 
command below will run:
./runtest.sh ~/swerc_testcases/blurredpictures/data/secret/ ./B
# Optional arguments
You can insert optional positional arguments for input file extension and output file extension without the dot.
For example if you have .in input files and .out output files then you can run the following command:
./runtest.sh ~/swerc_testcases/blurredpictures/data/secret/ ./B in out
If no extension is given the standard is .in (input) and .ans (output) extensions.
# Help
There is a help command but i don't think this will help, if you want you can run the following command:
./runtest.sh -h or ./runtest.sh --help