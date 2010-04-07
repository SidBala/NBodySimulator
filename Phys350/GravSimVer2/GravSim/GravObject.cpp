#include "stdafx.h"
#include "GravObject.h"
#include <math.h>
#include "SOIL\SOIL.h"
#include "CImg.h"

extern CTextureLoader* TexLoad;

CVec3::CVec3(void)
{
	x=y=z=0;										//	Initialize to 0
}

CVec3::CVec3 (const CVec3 & temp)
{
	x = temp.x;
	y = temp.y;
	z = temp.z;
}

CVec3::CVec3(float nx,float ny,float nz)
{
	x = nx;											//	Constructor with individual float values
	y = ny;
	z = nz;
}

CVec3::~CVec3(void)									//	Nothing to do here. No dynamic memory
{
}

float CVec3::Norm()									//	Returns the 2-Norm of the vector
{
	return (float) sqrt(x*x + y*y + z*z);
}

float CVec3::NormSq()
{
	return (float)(x*x + y*y + z*z);
}

CVec3 & CVec3::operator=(const CVec3 &v)						// Assignment Operator
{
	if (this != &v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}
	return *this;
}



CVec3 operator+(const CVec3 &v1, const CVec3 &v2)
{
	
	float x,y,z;
	x = v1.x + v2.x;
	y = v1.y + v2.y;
	z = v1.z + v2.z;
	return CVec3 (x,y,z);
}

CVec3 operator-(const CVec3 &v1, const CVec3 &v2)
{
	float x,y,z;
	x = v1.x - v2.x;
	y = v1.y - v2.y;
	z = v1.z - v2.z;
	return CVec3 (x,y,z);
}

CVec3 operator*(const CVec3 &v, const float f)
{
	float x,y,z;
	x = v.x * f;
	y = v.y * f;
	z = v.z * f;
	return CVec3 (x,y,z);
}

CVec3 operator*(const float f, const CVec3 &v)
{
	float x,y,z;
	x = v.x * f;
	y = v.y * f;
	z = v.z * f;
	return CVec3 (x,y,z);
}

CVec3 operator/(const CVec3 &v, const float f)
{
	float x,y,z;
	x = v.x / f;
	y = v.y / f;
	z = v.z / f;
	return CVec3 (x,y,z);
}


CGravObject::CGravObject(void)
{

}

CGravObject::CGravObject(std::string Name , CVec3 Pi, CVec3 Vi, float Mass, float Radius,int TrailLength)
{
	strName = Name;
	v3Pf = Pi;
	v3Vf = Vi;
	fMass = Mass;
	fRadius = Radius;
	fRotvPl = 0;
	fRotvCl = 0;
	iTrailLength = TrailLength;


	fRotPl = 0;
	fRotCl = 0;
	HasTexture = false;
	HasCloud = false;
}


CGravObject::CGravObject(std::string Name , CVec3 Pi, CVec3 Vi, float Mass, float Radius,float fRot, std::string PlanetTexture,int TrailLength)	//	Planet Texture
{
	strName = Name;
	v3Pf = Pi;
	v3Vf = Vi;
	fMass = Mass;
	fRadius = Radius;
	fRotvPl = fRot;
	fRotvCl = 0;
	
	iTrailLength = TrailLength;

	fRotPl = 0;
	fRotCl = 0;
	Texture = PlanetTexture;
	HasTexture = true;
	HasCloud = false;
}
CGravObject::CGravObject(std::string Name , CVec3 Pi, CVec3 Vi, float Mass, float Radius,float fRotp, float fRotc, std::string PlanetTexture, std::string CloudTexture,int TrailLength)	//	Planet + Cloud Texture
{
	strName = Name;
	v3Pf = Pi;
	v3Vf = Vi;
	fMass = Mass;
	fRadius = Radius;
	fRotvPl = fRotp;
	fRotvCl = fRotc;

	iTrailLength = TrailLength;

	fRotPl = 0;
	fRotCl = 0;
	Texture = PlanetTexture;
	Cloud = CloudTexture;
	HasTexture = true;
	HasCloud = true;
}

CGravObject::~CGravObject(void)
{

}

void CGravObject::DrawObject(void)
{
	glColor4f(1,1,1,1);
	
	glDisable(GL_TEXTURE_CUBE_MAP);
	
	if(HasTexture)
	{
		glPushMatrix();
		glTranslatef(v3Pf.x,v3Pf.y,v3Pf.z);
		glRotatef(fRotPl,0,1.0f,0);
		TexLoad->BindTexture(Texture);

		renderSphere(fRadius,50);

		TexLoad->UnBindTexture();
		glPopMatrix();
	}

	if(HasCloud)
	{
		glPushMatrix();
		glTranslatef(v3Pf.x,v3Pf.y,v3Pf.z);
		glRotatef(fRotCl,0,1.0f,0);
		TexLoad->BindTexture(Cloud);

		renderSphere(fRadius*1.08,50);

		TexLoad->UnBindTexture();
		glPopMatrix();
	}


	//Draw Trails Now
	std::vector<CVec3>::iterator i;
	std::vector<CVec3>::iterator j;

	if(Trails.size() > 2)
	{
		for(i =Trails.begin(); i != Trails.end()-1; i++)
		{
			j=(i+1);
			
			glBegin(GL_LINES);
			glColor3f(0,1,1); glVertex3f(i->x,i->y,i->z); glVertex3f(j->x,j->y,j->z);
			glEnd();
		}

	}



}


//	Code to render a sphere with proper texture coordinates
void CGravObject::renderSphere(float r, int p)
{
    const float PI     = 3.14159265358979f;
    const float TWOPI  = 6.28318530717958f;
    const float PIDIV2 = 1.57079632679489f;

    float theta1 = 0.0;
    float theta2 = 0.0;
    float theta3 = 0.0;

    float ex = 0.0f;
    float ey = 0.0f;
    float ez = 0.0f;

    float px = 0.0f;
    float py = 0.0f;
    float pz = 0.0f;

    // Disallow a negative number for radius.
    if( r < 0 )
        r = -r;

    // Disallow a negative number for precision.
    if( p < 0 )
        p = -p;

    // If the sphere is too small, just render a OpenGL point instead.
    if( p < 4 || r <= 0 ) 
    {
        glBegin( GL_POINTS );
        glVertex3f( 0,0,0 );
        glEnd();
        return;
    }

    for( int i = 0; i < p/2; ++i )
    {
        theta1 = i * TWOPI / p - PIDIV2;
        theta2 = (i + 1) * TWOPI / p - PIDIV2;

        glBegin( GL_TRIANGLE_STRIP );
        {
            for( int j = 0; j <= p; ++j )
            {
                theta3 = j * TWOPI / p;

                ex = cosf(theta2) * cosf(theta3);
                ey = sinf(theta2);
                ez = cosf(theta2) * sinf(theta3);
                px =  r * ex;
                py =  r * ey;
                pz =  r * ez;

                glNormal3f( ex, ey, ez );
                glTexCoord2f( ((float)j/(float)p) , (float)(2*(i+1))/(float)p );
                glVertex3f( px, py, pz );

                ex = cosf(theta1) * cosf(theta3);
                ey = sinf(theta1);
                ez = cosf(theta1) * sinf(theta3);
                px =  r * ex;
                py =  r * ey;
                pz =  r * ez;

                glNormal3f( ex, ey, ez );
                glTexCoord2f( ((float)j/(float)p), (float)(2*i)/(float)p );
                glVertex3f( px, py, pz );
            }
        }
        glEnd();
    }
}