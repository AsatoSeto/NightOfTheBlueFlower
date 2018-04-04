#include <iostream> 
#include <SDL.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include "Init.h"
#include "KeyDrive.h"
#include "Models.h"

using namespace std;
const int width = 800;
const int height = 600;	

int countFrame=0;
	
int main(int argc, char *argv[])
{
	SDL_GL_INIT initsdl;
	initsdl.initializ(width, height);
	
	Drive keyevent;
	float stepx=0;
	float stepy=0;
	float stepz=-7;
	float xrf=0,yrf=0,zrf=0;
	bool run=true;
	while(run)
	{
		//quit
		keyevent.EventQuit(&run);
		//moved gg
		keyevent.SDL_PumpEvents(&xrf,&yrf,&zrf,&stepx,&stepy,&stepz);
		//rotate variable
	//	xrf-=0.5;
	//	yrf-=0.5;
	//	zrf-=0.5;
		//draw models
		Models model;
		model.drawCube(xrf,yrf,zrf,stepx,stepy,stepz);
		//count Frame
		countFrame++;
		cout<<countFrame<<endl;	
		glFlush();
		SDL_GL_SwapWindow(initsdl.win);	
	}
	SDL_DestroyWindow(initsdl.win);
	SDL_Quit();
	return 0;	
}
