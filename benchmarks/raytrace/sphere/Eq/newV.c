#include <stdio.h>
#include <math.h>
#include <stdbool.h>
typedef struct Vector3DClass {
    float x, y, z;
}Vector3D;
typedef struct LightClass {
    const int AMBIENT;
    const int DIRECTIONAL;
    const int POINT ;
    int lightType;
    Vector3D lvec;                          
    float ir, ig, ib; 
}Light;
typedef struct SurfaceClass {
    float ir, ig, ib;  
    float ka, kd, ks, ns;
    float kt, kr, nt;
}Surface;
typedef struct SphereClass {
    Surface surface;
    Vector3D center;
    float radius;
    float radSqr;
}Sphere;
const float TINY = 0.001f;
const float I255 = 0.00392156f;
Vector3D Vector3DConstructor(float x, float y, float z) {
      Vector3D obj;
      obj.x = x; obj.y = y; obj.z = z;
      return obj;
}
Vector3D Vector3DConstructor2(Vector3D v) {
    Vector3D obj;
    obj.x = v.x;
    obj.y = v.y;
    obj.z = v.z;
    return obj;
}
Vector3D normalize(Vector3D v){
  float t = v.x*v.x + v.y*v.y + v.z*v.z;
  if (t != 0 && t != 1) 
    t = (float) (1 / sqrt(t));
  v.x *= t;
  v.y *= t;
  v.z *= t;
  return Vector3DConstructor(v.x, v.y, v.z);
}
Light LightConstructor(int type, Vector3D v, float r, float g, float b) {
      Light obj;
      obj.lightType = type;
      obj.ir = r;
      obj.ig = g;
      obj.ib = b;
      if (type != obj.AMBIENT) {
            obj.lvec = v;
          if (type == obj.DIRECTIONAL) {
                obj.lvec = normalize(obj.lvec);
            }
      }
      return obj;
}
Surface SurfaceConstructor(float rval, float gval, float bval, float a, float d, float s, float n, float r, float t, float index){
      Surface obj;
      obj.ir = rval; obj.ig = gval; obj.ib = bval;
      obj.ka = a; obj.kd = d; obj.ks = s; obj.ns = n;
      obj.kr = r*I255; obj.kt = t; obj.nt = index;
      return obj;
}
Sphere SphereConstructor(Surface s, Vector3D c, float r) {
		  Sphere obj;
	    obj.surface = s;
	    obj.center = c;
	    obj.radius = r;
      float temp = r*r;//change
      obj.radSqr = temp;//change
		  return obj;
}
bool intersect(Sphere s, Sphere d) {
  float dx = s.center.x - d.center.x;
  float dy = s.center.y - d.center.y;
  float dz = s.center.z - d.center.z;
  float t = s.radSqr - dx*dx - dy*dy - dz*dz;
  if (t < 0)
    return false;
  t =(float) sqrt(t);
  if (t < 0)
    return false;
  return true;
}