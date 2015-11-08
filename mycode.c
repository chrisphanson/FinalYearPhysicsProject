#include <stdio.h>
#include<time.h>
#include <math.h>


struct Particle
{
	int pos[3];//[x,y,z] cordinates
};

struct StrctSubBox
{
	int pos[3];//[x,y,z] cordinates of bottem left corner
	struct Particle ListOfParticles[1000];//needs to be large enough for all particles?
	long particleListCurr; //point to current top EMPTY space in list of particles
	long lookUpTbl[26];//array of ajacent boxes, referenced by their number
	long lookUpListCurr;
};


main()
{
	printf("Hello World.\n");
	int Np,boxSize,rC,boxLen;//varibles controlling how simulation should be set up
	long Nb;
	long i,j,x,y,z;//for loop counter
	srand(42);//TODO : replace with better random function
	
	Np = 500; //Define initial number of particles in box.	
	rC = 100;//Define the maximum range at which two particles are gaurtneed to interact with each other.
		//Particles outside this range may not interact depending on their position within the sub-cubes
		//each sub-cube will have sides equal to this value	
	boxLen = 5;//Define number of sub-boxes along each axis
	Nb = pow(boxLen,3); //total number of sub-boxes
	// printf("Nb = %i \n",Nb);
	struct StrctSubBox SubBoxes[Nb];
	for (i=0;i<Nb;i++){//create lookup table of neigbouring cells		
		SubBoxes[i].particleListCurr = 0; //also set intial 
		SubBoxes[i].lookUpListCurr = 0;
	}
	
	
	//Setup lookup tables for every cell
	i=0;	
	for(z=0;z<boxLen;z++){//give every box cordinates
			for(y=0;y<boxLen;y++){
				for(x=0;x<boxLen;x++){
					SubBoxes[i].pos[1]=x;
					SubBoxes[i].pos[2]=y;
					SubBoxes[i].pos[3]=z;
					i++;
				}
	
			}
		}
	int xcurr,ycurr,zcurr,match;
	
	for(i=0;i<Nb;i++){
			xcurr = SubBoxes[i].pos[1];
			ycurr = SubBoxes[i].pos[2];
			zcurr = SubBoxes[i].pos[3];
			
			
			//TODO : write a function to search for ajacent boxes in array
	}
	//debugging to check lookup table is being assigned correctly
	long test;
	test = 7;
	printf(" for box %i, x = %i, y = %i, z = %i \n",test,SubBoxes[test].pos[1],SubBoxes[test].pos[2],SubBoxes[test].pos[3]);

	
		
	//Initial Set up of particles into sub-boxes
	long chosenSubBox;
	for (i=0;i<Np;i++){	//for each particle in simulation
		// printf("--------------\nIn particle pos assignment, i = %i \n",i);
		chosenSubBox = rand() % Nb; //chose a random sub-box to place particle in
		// printf("ChosenSubBox is = %i \n",chosenSubBox);
		// printf("top of list for chosen SubBox is  %i \n",SubBoxes[chosenSubBox].particleListCurr);
		SubBoxes[chosenSubBox].ListOfParticles[SubBoxes[chosenSubBox].particleListCurr].pos[1] = rand() % rC;//chose its x/y/z cordinates relative to bottom left of sub box
		SubBoxes[chosenSubBox].ListOfParticles[SubBoxes[chosenSubBox].particleListCurr].pos[2] = rand() % rC;
		SubBoxes[chosenSubBox].ListOfParticles[SubBoxes[chosenSubBox].particleListCurr].pos[3] = rand() % rC;		
		// printf("x pos is %i, ypos is %i, zpos is %i \n",SubBoxes[chosenSubBox].ListOfParticles[SubBoxes[chosenSubBox].particleListCurr].pos[1],SubBoxes[chosenSubBox].ListOfParticles[SubBoxes[chosenSubBox].particleListCurr].pos[2],SubBoxes[chosenSubBox].ListOfParticles[SubBoxes[chosenSubBox].particleListCurr].pos[3]);
		SubBoxes[chosenSubBox].particleListCurr = SubBoxes[chosenSubBox].particleListCurr +1;//increment sub-box list counter
	}
	printf("------------ end of placing particles \n");
}