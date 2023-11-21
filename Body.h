#ifndef _BODY_H_
#define _BODY_H_

#pragma pack(push, 1)

class Body
{
 public:
  double x;
  double y;
  double z;
  double v_x;
  double v_y;
  double v_z;

 public:
  Body();
};

#pragma pack(pop)

#endif
