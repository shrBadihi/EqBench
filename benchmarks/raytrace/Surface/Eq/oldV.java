package benchmarks.raytrace.surface.Eq;
import java.util.*;
class Sphere {
    Surface surface;
    Vector3D center;
    float radius;
    float radSqr;
    public Sphere(Surface s, Vector3D c, float r) {
        surface = s;
        center = c;
        radius = r;
        radSqr = r*r;
    }
    public boolean intersect(Sphere s) {
        float dx = center.x - s.center.x;
        float dy = center.y - s.center.y;
        float dz = center.z - s.center.z;
        float t = radSqr - dx*dx - dy*dy - dz*dz;
        if (t < 0)
            return false;
        t = (float) Math.sqrt(t);
        if (t < 0)
            return false;
        return true;
    }
}
class Surface {
    public float ir, ig, ib;        
    public float ka, kd, ks, ns;    
    public float kt, kr, nt;
    private static final float TINY = 0.001f;
    private static final float I255 = 0.00392156f;  
    public Surface(float rval, float gval, float bval, float a, float d, float s, float n, float r, float t, float index) {
        ir = rval; ig = gval; ib = bval;
        ka = a; kd = d; ks = s; ns = n;
        kr = r*I255; kt = t; nt = index;
    }
}
class Light {
    public static final int AMBIENT = 0;
    public static final int DIRECTIONAL = 1;
    public static final int POINT = 2;
    public int lightType;
    public Vector3D lvec;                          
    public float ir, ig, ib;       
    public Light(int type, Vector3D v, float r, float g, float b) {
        lightType = type;
        ir = r;
        ig = g;
        ib = b;
        if (type != AMBIENT) {
            lvec = v;
            if (type == DIRECTIONAL) {
                lvec.normalize();
            }
        }
    }
}
class Vector3D {
  public float x, y, z;
  public Vector3D(float x, float y, float z) {
      this.x = x; this.y = y; this.z = z;
  }
  public Vector3D(Vector3D v) {
      x = v.x;
      y = v.y;
      z = v.z;
  }
  public final void normalize( ) {
      float t = x*x + y*y + z*z;
      if (t != 0 && t != 1) t = (float) (1 / Math.sqrt(t));
      x *= t;
      y *= t;
      z *= t;
  }
}