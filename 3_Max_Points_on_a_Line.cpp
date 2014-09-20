/** 
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line. 
 **/

#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
	int max_points = 2, pt_cnt_1, pt_cnt_2, pt_cnt_3;
	float slopes_res[points.size() - 1];
	int slope_cnt_1, slope_cnt_2, same_slope_points, max_same_slop_points, same_points = 0;

	if (points.size() < 3)
	    return points.size();

	for (pt_cnt_1 = 0; pt_cnt_1 < points.size() - 1; pt_cnt_1++) {
	    for (pt_cnt_2 = pt_cnt_1 + 1; pt_cnt_2 < points.size(); pt_cnt_2++) {
		if (points[pt_cnt_1].x == points[pt_cnt_2].x) {
		    /* To avoid divisor is zero (floating point exception) */
		    slopes_res[pt_cnt_2 - 1] = numeric_limits<float>::max();
		} else {
		    slopes_res[pt_cnt_2 - 1] = (float)(points[pt_cnt_1].y - points[pt_cnt_2].y) /
			(float)(points[pt_cnt_1].x - points[pt_cnt_2].x);
		}
	    }
	    same_points = 0;
	    max_same_slop_points = 1;
	    for (slope_cnt_1 = pt_cnt_1; slope_cnt_1 < points.size() - 1; slope_cnt_1++) {
		same_slope_points = 2;
		pt_cnt_2 = slope_cnt_1 + 1;
		/* Consider the same points */
		if ((points[pt_cnt_1].x == points[pt_cnt_2].x)
			&& (points[pt_cnt_1].y == points[pt_cnt_2].y)) {
		    same_points++;
		    continue;
		}
		for (slope_cnt_2 = slope_cnt_1 + 1; slope_cnt_2 < points.size() - 1; slope_cnt_2++) {
		    pt_cnt_3 = slope_cnt_2 + 1;
		    /* Consider the same points */
		    if ((points[pt_cnt_1].x == points[pt_cnt_3].x)
			    && (points[pt_cnt_1].y == points[pt_cnt_3].y)) {
			continue;
		    }
		    /* Same slope mean points on the same line */
		    else if (slopes_res[slope_cnt_2] == slopes_res[slope_cnt_1]) {
			same_slope_points++;
		    }
		}

		if (same_slope_points > max_same_slop_points)
		    max_same_slop_points = same_slope_points;
	    }
	    if (max_same_slop_points + same_points > max_points)
		max_points = max_same_slop_points + same_points;

	    if (max_points >= (points.size() - 1 - pt_cnt_1))
		break; /* Last total points are less than current maximum points count */
	}

	return max_points;
    }
};

void test_case(vector<Point> &points)
{
    Solution *a = new Solution();
    for(auto p : points) {
	cout<<"("<<p.x<<","<<p.y<<")"<<" - ";
    }
    cout<<endl;

    cout<<"return:"<<a->maxPoints(points)<<endl;
}

int main(int argc, char *argv[])
{
    Point p_array_a[] = { {1, 2}, {2, 4}, {3, 6}, {4, 7} }; 
    Point p_array_b[] = { {0, 0}, {1, 1}, {0, 0} }; 
    Point p_array_c[] = { {1, 1}, {1, 1}, {2, 3} }; 
    Point p_array_d[] = { {1, 1}, {1, 1}, {1, 1} }; 
    Point p_array_e[] = { {84,250}, {0,0}, {1,0}, {0,-70}, {0,-70}, {1,-1}, {21,10}, {42,90}, {-42,-230} }; 
    Point p_array_f[] = { {40,-23}, {9,138}, {429,115}, {50,-17}, {-3,80}, {-10,33}, {5,-21}, {-3,80}, {-6,-65}, {-18,26}, {-6,-65}, {5,72}, {0,77}, {-9,86}, {10,-2}, {-8,85}, {21,130}, {18,-6}, {-18,26}, {-1,-15}, {10,-2}, {8,69}, {-4,63}, {0,3}, {-4,40}, {-7,84}, {-8,7}, {30,154}, {16,-5}, {6,90}, {18,-6}, {5,77}, {-4,77}, {7,-13}, {-1,-45}, {16,-5}, {-9,86}, {-16,11}, {-7,84}, {1,76}, {3,77}, {10,67}, {1,-37}, {-10,-81}, {4,-11}, {-20,13}, {-10,77}, {6,-17}, {-27,2}, {-10,-81}, {10,-1}, {-9,1}, {-8,43}, {2,2}, {2,-21}, {3,82}, {8,-1}, {10,-1}, {-9,1}, {-12,42}, {16,-5}, {-5,-61}, {20,-7}, {9,-35}, {10,6}, {12,106}, {5,-21}, {-5,82}, {6,71}, {-15,34}, {-10,87}, {-14,-12}, {12,106}, {-5,82}, {-46,-45}, {-4,63}, {16,-5}, {4,1}, {-3,-53}, {0,-17}, {9,98}, {-18,26}, {-9,86}, {2,77}, {-2,-49}, {1,76}, {-3,-38}, {-8,7}, {-17,-37}, {5,72}, {10,-37}, {-4,-57}, {-3,-53}, {3,74}, {-3,-11}, {-8,7}, {1,88}, {-12,42}, {1,-37}, {2,77}, {-6,77}, {5,72}, {-4,-57}, {-18,-33}, {-12,42}, {-9,86}, {2,77}, {-8,77}, {-3,77}, {9,-42}, {16,41}, {-29,-37}, {0,-41}, {-21,18}, {-27,-34}, {0,77}, {3,74}, {-7,-69}, {-21,18}, {27,146}, {-20,13}, {21,130}, {-6,-65}, {14,-4}, {0,3}, {9,-5}, {6,-29}, {-2,73}, {-1,-15}, {1,76}, {-4,77}, {6,-29} }; 
    Point p_array_g[] = { {1, 2}, {4, 6}, {2, 4}, {1, 2}, {3, 6}, {4, 7} }; 
    vector<Point> v_p_a(p_array_a, p_array_a + sizeof(p_array_a) / sizeof(Point));
    vector<Point> v_p_b(p_array_b, p_array_b + sizeof(p_array_b) / sizeof(Point));
    vector<Point> v_p_c(p_array_c, p_array_c + sizeof(p_array_c) / sizeof(Point));
    vector<Point> v_p_d(p_array_d, p_array_d + sizeof(p_array_d) / sizeof(Point));
    vector<Point> v_p_e(p_array_e, p_array_e + sizeof(p_array_e) / sizeof(Point));
    vector<Point> v_p_f(p_array_f, p_array_f + sizeof(p_array_f) / sizeof(Point));
    vector<Point> v_p_g(p_array_g, p_array_g + sizeof(p_array_g) / sizeof(Point));

    test_case(v_p_a);
    test_case(v_p_b);
    test_case(v_p_c);
    test_case(v_p_d);
    test_case(v_p_e);
    test_case(v_p_f);
    test_case(v_p_g);

    return 0;
}
