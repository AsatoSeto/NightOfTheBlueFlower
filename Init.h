using namespace std;
class SDL_GL_INIT
{	
	public:
				
		SDL_Window *win;
				
		void initializ(int width, int height)
		{
			//Init 
			if (SDL_Init(SDL_INIT_EVERYTHING)!=0)
			{
				cout<<"Error: "<<SDL_GetError()<<endl;
			}
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
			SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
			SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,6);
			SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,5);
			
			win = SDL_CreateWindow("Test OpenGL", 100,100, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
			
			SDL_GLContext glcontext = SDL_GL_CreateContext(win);
			
			if (win==NULL)
			{
				exit(1);
			}	
						
			//init OpenGL
			glClearColor(0.0f,0.0f,0.0f,1.0f); //black background
			glClearDepth(1.0);
			glDepthFunc(GL_LESS);
			glEnable(GL_DEPTH_TEST);//test глубины
			glShadeModel(GL_SMOOTH);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(60.0f,(float)width/(float)height, 0.1f, 100.0f);//трехмерная перспектива
			glMatrixMode(GL_MODELVIEW);//3d
		}
};
