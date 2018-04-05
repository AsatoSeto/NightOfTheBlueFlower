using namespace std;
class Models
{
	public:
	void drawCube(float xrf,float yrf,float zrf, float stepx, float stepy, float stepz)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glLoadIdentity();
		glTranslatef(stepx, stepy, stepz);

		glRotatef(xrf, 1.0f, 0.0f, 0.0f);
		glRotatef(yrf, 0.0f, 1.0f, 0.0f);
		glRotatef(zrf, 0.0f, 0.0f, 1.0f);

		glBegin(GL_TRIANGLES);
		
		glEnd();
	}
};
