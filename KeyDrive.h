using namespace std;

class Drive
{	
	public:
		SDL_Event event;
		
		//QUIT EVENT
		void EventQuit(bool *run)
		{
			while(SDL_PollEvent(&event))
			{
				if(event.type==SDL_QUIT)
				{
					*run=false;
				}
				if ((&event) -> key.keysym.sym == SDLK_ESCAPE)
				{
					*run=false;
				}	
			}
		}
		//MOVED SAKUYA
			void SDL_PumpEvents(float *xrf, float *yrf, float *zrf, float *stepx, float *stepy,float *stepz)
			{
				const Uint8 *state = SDL_GetKeyboardState(NULL);
				if ( state[SDL_SCANCODE_UP] && *stepy<=4.88)
				{
					*stepy+=0.08;
					cout<<"x: "<<*stepx<<" y: "<<*stepy<<endl;
				}
				if ( state[SDL_SCANCODE_DOWN] && *stepy>=-4.88)
				{
					*stepy-=0.08;
					cout<<"x: "<<*stepx<<" y: "<<*stepy<<endl;
				}
				if ( state[SDL_SCANCODE_LEFT] && *stepx>=-7)
				{
					*stepx-=0.08;
					cout<<"x: "<<*stepx<<" y: "<<*stepy<<endl;
				}
				if ( state[SDL_SCANCODE_RIGHT] && *stepx<=7)
				{
					*stepx+=0.08;
					cout<<"x: "<<*stepx<<" y: "<<*stepy<<endl;
				}
				if ( state[SDL_SCANCODE_END] )
				{
					*stepz+=0.08;
					cout<<"x: "<<*stepx<<" y: "<<*stepy<<endl;
				}
				if ( state[SDL_SCANCODE_HOME] )
				{
					*stepz-=0.08;
					cout<<"x: "<<*stepx<<" y: "<<*stepy<<endl;
				}
				//rotate
				if ( state[SDL_SCANCODE_KP_8] )
				{
					*xrf-=0.5;
					cout<<"x: "<<*stepx<<" y: "<<*stepy<<endl;
				}
				if ( state[SDL_SCANCODE_KP_5] )
				{
					*xrf+=0.5;
					cout<<"x: "<<*stepx<<" y: "<<*stepy<<endl;
				}
				if ( state[SDL_SCANCODE_KP_4] )
				{
					*yrf-=0.5;
					cout<<"x: "<<*stepx<<" y: "<<*stepy<<endl;
				}
				if ( state[SDL_SCANCODE_KP_6] )
				{
					*yrf+=0.5;
					cout<<"x: "<<*stepx<<" y: "<<*stepy<<endl;
				}
					if ( state[SDL_SCANCODE_KP_7] )
				{
					*zrf-=0.5;
					cout<<"x: "<<*stepx<<" y: "<<*stepy<<endl;
				}
				if ( state[SDL_SCANCODE_KP_9] )
				{
					*zrf+=0.5;
					cout<<"x: "<<*stepx<<" y: "<<*stepy<<endl;
				}
			}
		//END MOVED SAKUYA
		
};
