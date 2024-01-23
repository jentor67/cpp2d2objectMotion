#include<stdio.h>
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<math.h>

using namespace std;

struct StellarObject
{
  string name;
  double mass;
  double x;
  double y;
  double u;
  double v;
}; 

class compute_values
{
  public:
    double pi = 3.1459, Gc = 6.674083E-11, moon_earth = 384399000; 


    double gravity_AB(StellarObject Objects[], int m, int n) 
    {
      double g, r;

      r = pow( ( pow( ( Objects[m].x - Objects[n].x ), 2) + pow( ( Objects[m].y - Objects[n].y ), 2)  ), 0.5 );
      g = Gc * Objects[n].mass /(pow(r,2));
      
      return(g);
    };
    
    double radius(double x1, double y1, double x2, double y2)
    {
      double r;
      r = pow( ( pow( ( x1 - x2 ), 2) + pow( ( y1 - y2 ), 2)  ), 0.5 );
     
      return(r);
    };


    void sumForces(StellarObject Objects[], int size, int p)
    {
      double g, gx, gy , r, x, y, u, v, dx, dy;
      int i;

      gx=0.0;
      gy=0.0;
      i = 0;
      while( i < size )
      {
        if( i != p )
        {
          g = gravity_AB(Objects, p, i);
          r = pow((pow((Objects[i].x - Objects[p].x),2) + pow((Objects[i].y - Objects[p].y),2 )), 0.5);
          dx = Objects[i].x - Objects[p].x;
          dy = Objects[i].y - Objects[p].y;
          gx = gx+g*dx/r;
          gy = gy+g*dy/r;
        }
        i++;
      }

      Objects[p].x = Objects[p].x + Objects[p].u;
      Objects[p].y = Objects[p].y + Objects[p].v;

      Objects[p].u = Objects[p].u + gx;
      Objects[p].v = Objects[p].v + gy;
    }

};

class read_file
{
 
  public:

    void readDataFile(StellarObject a[], int size){
      int i, j;
      string line, object1, value, token, delimiter=",", name1;
      double m1, x1, y1, u1, v1;
      ifstream in ("data2-8.txt", ios_base::in);
    
      i = 0;
      j = 0;
      while ( in.good() )
      {
        getline ( in, line); 
     
        size_t pos = 0; 
        j=0;
        while((pos = line.find(delimiter)) != string::npos){
          token = line.substr(0, pos); 
          line.erase(0, pos + delimiter.length());
          string::size_type sz;
          if( j == 0 ) a[i].name = token;
          if( j == 1 ) a[i].mass = stof(token,&sz);
          if( j == 2 ) a[i].x = stof(token,&sz);
          if( j == 3 ) a[i].y = stof(token,&sz);
          if( j == 4 ) a[i].u = stof(token,&sz);
          if( j == 5 ) a[i].v = stof(token,&sz);
         
          j++;
        } 
        i++;
      }

    } 

};


int main(void)
{
  int i, j, k, numberOfObjects=5, secondsLimit = 60000000;
  int dummy1, dummy2;
  double g, r, r1, r2, rmin, radiusLimit = 0.309938E8;
  compute_values computeValues; // computeValues is an object
  read_file readFile; //readFile is an object
  StellarObject StellarObjectArray[numberOfObjects];
  int size = sizeof(StellarObjectArray) / sizeof(StellarObjectArray[0]);

  readFile.readDataFile(StellarObjectArray, size);

  ofstream out;
  out.open ("/home/jmajor/temp/2d2Object_cpp_output2-8em.txt");
  
  i = 0;
  while( i < numberOfObjects )
  {
    cout << i << ' ' << StellarObjectArray[i].name << ' ' << StellarObjectArray[i].mass << ' ' 
    << StellarObjectArray[i].x << ' ' << StellarObjectArray[i].y << ' ' 
    << StellarObjectArray[i].u << ' ' << StellarObjectArray[i].v << ' ' 
    <<  '\n';
    cout << '\n';
    i++;
  }

  i=0;
  while( i <= secondsLimit )
  {
    j=0;
    r = computeValues.radius(StellarObjectArray[1].x, StellarObjectArray[1].y, 
       StellarObjectArray[4].x, StellarObjectArray[4].y);
    if( i % 100 == 0 && r < computeValues.moon_earth)
    { 
      r = computeValues.radius(StellarObjectArray[0].x, StellarObjectArray[0].y, 
         StellarObjectArray[1].x, StellarObjectArray[1].y);
      r1 = computeValues.radius(StellarObjectArray[0].x, StellarObjectArray[0].y, 
         StellarObjectArray[4].x, StellarObjectArray[4].y);
      r2 = computeValues.radius(StellarObjectArray[1].x, StellarObjectArray[1].y, 
         StellarObjectArray[4].x, StellarObjectArray[4].y);
      out << i << ' ' << StellarObjectArray[0].x << ' ' << StellarObjectArray[0].y << ' '
      << StellarObjectArray[1].x << ' ' << StellarObjectArray[1].y << ' '
      << StellarObjectArray[2].x << ' ' << StellarObjectArray[2].y << ' '
      << StellarObjectArray[3].x << ' ' << StellarObjectArray[3].y << ' ' 
      << StellarObjectArray[4].x << ' ' << StellarObjectArray[4].y << ' ' 
      << r << ' ' << r1 << ' ' << r2 << '\n';
    }
    while( j < numberOfObjects )
    {
      computeValues.sumForces(StellarObjectArray, numberOfObjects, j);
      j++;
    }
    //***Radius from xNeptune to Sun****
    r = computeValues.radius(StellarObjectArray[1].x, StellarObjectArray[1].y, 
         StellarObjectArray[4].x, StellarObjectArray[4].y);
    if( i == 0 ) rmin = r;
    if( r < rmin ) rmin = r;
    if( r < radiusLimit ) 
    {
      cout << "Collision " << r << ' ' << radiusLimit << ' ' << rmin << '\n';
      exit (EXIT_FAILURE);
    }
    g = computeValues.Gc * StellarObjectArray[4].mass/(pow(r,2));

    if( i % 1000000 == 0) cout << i <<  " Seconds and radius Earth and Sun: " << r << '\n';
/*    if( r < 7.4052E11 )
    {
      cout << "Kill Process" << '\n';
      k = 0;
      while( k < numberOfObjects )
      {
        cout << k << ' ' << StellarObjectArray[k].name << ' ' << StellarObjectArray[k].mass << ' ' 
        << StellarObjectArray[k].x << ' ' << StellarObjectArray[k].y << ' ' 
        << StellarObjectArray[k].u << ' ' << StellarObjectArray[k].v << ' ' 
        <<  '\n';
        cout << '\n';
        k++;
      }
      exit (EXIT_FAILURE);
    } */
    i++;
   
  }
  out.close();

  return 0;
}
