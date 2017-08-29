#define check_line_line( x1,  y1,  x2,  y2,  x3,  y3,  x4,  y4) \
  ( !((((x1 - x2) * (y3 - y1) + (y1 - y2) * (x1 - x3)) * \
            ((x1 - x2) * (y4 - y1) + (y1 - y2) * (x1 - x4)) > 0.0) || \
           (((x3 - x4) * (y1 - y3) + (y3 - y4) * (x3 - x1)) * \
            ((x3 - x4) * (y2 - y3) + (y3 - y4) * (x3 - x2)) > 0.0 )))

#define intersect( x1,  y1,  x2,  y2,  x3,  y3,  x4,  y4) \
  ( ((x1 - x2) * (y3 - y1) + (y1 - y2) * (x1 - x3)) * \
         ((x1 - x2) * (y4 - y1) + (y1 - y2) * (x1 - x4)))

int check_point_triangle(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3){
  if ((x1 - x3) * (y1 - y2) == (x1 - x2) * (y1 - y3)) {
    return 0;
  }

  int cx = (x1 + x2 + x3) / 3,
      cy = (y1 + y2 + y3) / 3;

  if (intersect( x1, y1, x2, y2, x, y, cx, cy ) < 0.0 ||
      intersect( x2, y2, x3, y3, x, y, cx, cy ) < 0.0 ||
      intersect( x3, y3, x1, y1, x, y, cx, cy ) < 0.0 ) {
    return 0;
  }
  return -1;
};


int check_triangle_triangle(int ox[3], int oy[3], int dx[3], int dy[3]) {
  return check_line_line(ox[0], oy[0], ox[1], oy[1], dx[1], dy[1], dx[2], dy[2]) ||
         check_line_line(ox[0], oy[0], ox[1], oy[1], dx[2], dy[2], dx[0], dy[0]) ||
         check_line_line(ox[1], oy[1], ox[2], oy[2], dx[0], dy[0], dx[1], dy[1]) ||
         check_line_line(ox[1], oy[1], ox[2], oy[2], dx[2], dy[2], dx[0], dy[0]) ||
         check_line_line(ox[2], oy[2], ox[0], oy[0], dx[0], dy[0], dx[1], dy[1]) ||
         check_line_line(ox[2], oy[2], ox[0], oy[0], dx[1], dy[1], dx[2], dy[2]) ||
         check_point_triangle(ox[0], oy[0], dx[0], dy[0], dx[1], dy[1], dx[2], dy[2]) ||
         check_point_triangle(dx[0], dy[0], ox[0], oy[0], ox[1], oy[1], ox[2], oy[2]);
};

