# BSTW_Algorithm
Implementation of the Bentley, Sleator, Tarjan and Wei compression algorithm

##How to use
- Edit the file 'file.txt' containing the data you wish to encode
- compile the program via 'make run'
- Launch it via './bstw' (the program takes no other argument)

##Output example
if the input is 'WABBAWABBA', then the terminal output will be

ENCODING STATES :
1W
1W2A
1W2A3B
1W2A3B1
1W2A3B12
1W2A3B123
1W2A3B1232
1W2A3B12323
1W2A3B123231
1W2A3B1232312

DECODING STATES :
W
WA
WAB
WABB
WABBA
WABBAW
WABBAWA
WABBAWAB
WABBAWABB
WABBAWABBA
