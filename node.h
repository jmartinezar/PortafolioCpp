#ifndef _NODE_H_
#define _NODE_H_

class node
{
 public:
  int N; //Quantity of bodies in node
  double x_c; //x center position
  double y_c; //y center position
  double width; //width of node
  double height; //height of node
  double total_mass; //total mass of bodies in node
  double mass_center_x; //x center mass of all bodies in node
  double mass_center_y; //y center mass of all bodies in node
  std::vector<double> * node1;
  std::vector<double> * node2;
  std::vector<double> * node3;
  std::vector<double> * node4;

 public:
  //Inicialized all values at 0 and the assigned code
  node();
  
  //Inicialized all values indicated
  node(double _x_c, double  _y_c, double _w, double _h);
  
  //Count the bodies that node contains
  void ParticlesIn(double _x_c, double _y_c, double width, double height, std::vector<double> x, std::vector<double> y);
  
  //Divide the node in 4 nodes
  void DivideNode(int _N);
  
  //Calculate total mass
  double cal_total_mass(std::vector<double> m);
  
  //Calculate x position of center mass
  void cal_x_cm(std::vector<double> m, std::vector<double> x, double tm);
  
  //Calculate y position of center mass
  void cal_x_cm(std::vector<double> m, std::vector<double> y, double tm);
};

#endif
