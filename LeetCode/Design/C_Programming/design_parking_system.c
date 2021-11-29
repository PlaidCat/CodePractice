/*
 * 1603. Design Parking System
 *
 * https://leetcode.com/problems/design-parking-system/
 * 
 * Runtime: 68 ms (54.24% Better)
 * Memory Usage: 20.7 MB (71.9 Better than)
 */

#include <stdlib.h>
#include <stdio.h>


/*
 * Using Basic 2d array
 * 
 * [CarType 0:big, 1:medium, 3:small][count 0:Max,1:Cur]
 * 
 */
typedef struct {
  int parking[3][2];
} ParkingSystem;


ParkingSystem* parkingSystemCreate(int big, int medium, int small) {
  ParkingSystem  *obj= (ParkingSystem*)malloc(sizeof(ParkingSystem));
  obj->parking[0][0] = big;
  obj->parking[0][1] = 0;
  obj->parking[1][0] = medium;
  obj->parking[1][1] = 0;
  obj->parking[2][0] = small;
  obj->parking[2][1] = 0;
  return obj;
    
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType) {
  if (obj->parking[carType-1][0] == obj->parking[carType-1][1])
    return false;
  obj->parking[carType-1][1]++;
  return true;
}

void parkingSystemFree(ParkingSystem* obj) {
    free(obj);
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/