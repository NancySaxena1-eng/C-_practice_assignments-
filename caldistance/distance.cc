

#include"distance.h"
#include<iostream>
#include<cmath>
/*Overloading  for two points */

float distance(XYPoint p1, XYPoint p2){
        //calculating distance between p1 and p2
  	float z = sqrt((p2.x - p1.x) * (p2.x - p1.x)
		       +(p2.y - p1.y) * (p2.y - p1.y));
 	return z;

}
float distance(XYPoint p1, XYPoint p2, XYPoint p3){
	//calculating distance between p1 and p2
  	float a = distance(p1, p2);
	//calculate distance between p3 and p2
  	float b = distance(p2, p3);
	//adding the distances
	float z = a + b;
	return z;


}
float distance(XYPoint p1, XYPoint p2, XYPoint p3, XYPoint p4){
	//calculate the distance between p1 to p3 
  	float a = distance(p1, p2, p3);
	//calculate the distance between p3 and p4
  	float b = distance(p3, p4);
	//adding all the distances
	float z = a + b;
	return z;

}
float distance(XYPoint p1, XYPoint p2, XYPoint p3, XYPoint p4, XYPoint p5){
	//calculate the distance between p1 to p4
  	float a = distance(p1, p2, p3, p4);
	//calculate the distance between p4 and p5
  	float b = distance(p4, p5);
	//adding all the distances
	float z = a + b;
	return z;

}
