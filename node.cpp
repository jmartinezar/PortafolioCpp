#include "node.h"
#include <vector>

node::node()
{
  x_c = 0.0;
  y_c = 0.0;
  width = 0.0;
  height = 0.0;
  total_mass = 0.0;
  mass_center_x = 0.0;
  mass_center_y = 0.0;
  node1 = null;
  node2 = null;
  node3 = null;
  node4 = null;
}

node::node(double _x_c, double _y_c, double _w, double _h)
{
  x_c = _x_c;
  y_c = _y_c;
  width = _w;
  height = _h;
  total_mass = 0.0;
  mass_center_x = 0.0;
  mass_center_y = 0.0;
  node1 = null;
  node2 = null;
  node3 = null;
  node4 = null;
}

void node::ParticlesIn(double _x_c, double _y_c, double _width, double _height, std::vector<double> x, std::vector<double> y)
{
  int count = 0;
  for(int ii = 0; ii < x.size(); ++ii)
    {
      if(((x[ii] > _x_c - 0.5*_width) and (x[ii] < _x_c + 0.5*_width)) and ((y[ii] > _y_c - 0.5*_height) and (y[ii] > _y_c + 0.5*_height)))
	{
	  ++count;
	}
    }
  N = count;
}

void cal_total_mass(std::vector<double> m)
{
  double result = 0.0;
  for(int ii = 0; ii<m.size(); ++ii)
    {
      result += m[ii];
    }
  return result;
}

void cal_x_cm(std::vector<double> m, std::vector<double> x, double tm)
{
  double result = 0.0;
  for(int ii = 0; ii<m.size(); ++ii)
    {
      result += x[ii]*m[ii]/tm;
    }
  mass_center_x = result;
}

void cal_y_cm(std::vector<double> m, std::vector<double> y, double tm)
{
  double result = 0.0;
  for(int ii = 0; ii<m.size(); ++ii)
    {
      result += y[ii]*m[ii]/tm;
    }
  mass_center_y = result;
}
