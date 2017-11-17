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
    double pi = 3.1459, Gc = 6.674083E-11; 


    double gravity_AB(StellarObject Objects[], int m, int n) 
    {
      double g, r;

      r = pow( ( pow( ( Objects[m].x - Objects[n].x ), 2) + pow( ( Objects[m].y - Objects[n].y ), 2)  ), 0.5 );
      g = Gc * Objects[n].mass /(pow(r,2));
      
      return(g);
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
      ifstream in ("data1.txt", ios_base::in);
    
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
  int i, j, numberOfObjects=5, secondsLimit = 31558000;
  int dummy1, dummy2;
  compute_values computeValues; // computeValues is an object
  read_file readFile; //readFile is an object
  StellarObject StellarObjectArray[numberOfObjects];
  int size = sizeof(StellarObjectArray) / sizeof(StellarObjectArray[0]);

  readFile.readDataFile(StellarObjectArray, size);

  ofstream out;
  out.open ("/home/john/temp/2d2Object_output.txt");
  
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
    if( i % 1000000 == 0) out << i << ' ' << StellarObjectArray[0].x << ' ' << StellarObjectArray[0].y << " * "
    << StellarObjectArray[1].x << ' ' << StellarObjectArray[1].y << " * "
    << StellarObjectArray[2].x << ' ' << StellarObjectArray[2].y << ' '
    << StellarObjectArray[3].x << ' ' << StellarObjectArray[3].y << '\n';
    while( j < numberOfObjects )
    {
      computeValues.sumForces(StellarObjectArray, numberOfObjects, j);
      j++;
    }
    if( i % 1000000 == 0) cout << i <<  " Seconds" << '\n';
    i++;
   
  }
  out.close();

  return 0;
}
