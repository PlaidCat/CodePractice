
/*
 * https://leetcode.com/problems/robot-room-cleaner
 * 
 * Weekly Challenge (Hard)
 * 
 * Runtime: 60 ms (5.69% Better)
 * Memory Usage: 9.9 MB (15.39% Better than)
 * 
 *  https://leetcode.com/PlaidCat/
 *
*  This can be structured much better and will likely return to it again in the future.
 *  
 * /

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

struct path_dir {
  pair<int,int> loc;
  int dir;
};

class Solution {
private:
  int cur_x = 0;
  int cur_y = 0;
  int min_x = 0;
  int min_y = 0;
  int max_x = 0;
  int max_y = 0;
  //0 - up; 1 - left; 2 - down; 3 - right
  int cur_direction = 0; 
  map<pair<int,int>,int> robo_map;
  vector<struct path_dir> path;
public:
    void uturn(Robot& robot){
      robot.turnRight();
      robot.turnRight();
      cur_direction = (cur_direction+2)%4;
    }
  
    void reorient_robot(Robot& robot){
      while(cur_direction != path.back().dir){
        robot.turnRight();
        cur_direction = (cur_direction+1)%4;
      }
    }
    void update_bounds(){
      if(cur_x < min_x)
        min_x = cur_x;
      if(cur_x > max_x)
        max_x = cur_x;
      if(cur_y < min_y)
        min_y = cur_y;
      if(cur_y > max_y)
        max_y = cur_y;
    }
  
    void print_map(){
      for(int y = min_y; y < max_y+1; ++y){
        for(int x = min_x; x < max_x+1; ++x){
          if((cur_y == y) && (cur_x == x)){
            switch (cur_direction){
              case 0:
                printf("u");
                break;
              case 1:
                printf("r");
                break;
              case 2:
                printf("d");
                break;
              case 3:
                printf("l");
                break;
            }
            
          }else if((y == 0) && (x == 0)){
            printf("s");
          }else{
            pair<int,int> tmp(x,y);
            switch (robo_map[tmp]){
              case 0:
                printf("?");
                break;
              case 1:
                printf("*");
                break;
              case 2:
                printf("X");
                break;
              default:
                printf("?");
                break;
            }
          }
        }
        printf("\n");
      }
    }
  
    void clean_direction(Robot& robot){
      int tries = 0;
      int stuck = 0;
      do{
        bool clean = false;
        pair<int,int> new_loc = make_direction();
        if (robo_map[new_loc] == 0){
         // printf("[%i][%i] Not Vistned\n", new_loc.first, new_loc.second);
          if (robot.move()){
            stuck = 0;
            struct path_dir tmp;
            tmp.loc = new_loc;
            tmp.dir = cur_direction;
            path.push_back(tmp);
            cur_x = new_loc.first;
            cur_y = new_loc.second;
            update_bounds();
            //printf("[%i][%i] Robot Moved\n", cur_x, cur_y);
            robo_map[new_loc] = 1;
            robot.clean();
            //print_map();
          }else{
           // printf("{%i}[%i][%i] Robot Cant Move to [%i][%i] ... turning right from {%i} ",
           //        tries, cur_x, cur_y, new_loc.first, new_loc.second, cur_direction);
            robo_map[new_loc] = 2;
            robot.turnRight();
            cur_direction = (cur_direction+1)%4;
           // printf("-> {%i}\n", cur_direction);
            stuck++;
          }
        }else{
          
          if (stuck > 1 && (cur_direction == path.back().dir)){
           // printf("{%i}[%i][%i] Robot Stuck .. Backing up -> ", tries, cur_x, cur_y);
           // printf("\n\tpath.size(%i)\n",path.size());
            pair<int, int> rev_loc;
            stuck = 0;
            uturn(robot);
            robot.move();
            path.pop_back();
            if (path.size()>0){
              reorient_robot(robot);
              cur_x = path.back().loc.first;
              cur_y = path.back().loc.second;
            }

            //printf("[%i][%i]\n", cur_x, cur_y);
            //print_map();
            
          } else {
            //printf("{%i}[%i][%i] Already Vistned  [%i][%i] ... turning right from {%i} ",
            //       tries, cur_x, cur_y, new_loc.first, new_loc.second, cur_direction);
            robot.turnRight();
            cur_direction = (cur_direction+1)%4;
            //printf("-> {%i}\n", cur_direction);
            stuck++;
          }
        }
        //printf("{%i} path.size(%i)\n", tries, path.size());
        tries++;
      }while(path.size()>0);
    }
    pair<int,int> make_direction(){
      pair<int,int> new_dir;
      switch(cur_direction){
        case 0:
          new_dir.first = cur_x;
          new_dir.second = cur_y-1;
          break;
        case 1:
          new_dir.first = cur_x+1;
          new_dir.second = cur_y;
          break;
        case 2:
          new_dir.first = cur_x;
          new_dir.second = cur_y+1;
          break;
        case 3:
          new_dir.first = cur_x-1;
          new_dir.second = cur_y;
          break;
      }
      return new_dir;
    }
    void cleanRoom(Robot& robot) {
      //printf("0 \x18 1 \x19 2 \x1a 3 \x1b");
      pair<int,int> cur_loc(cur_x,cur_y);
      if (!robo_map[cur_loc]){
        //printf("[%i][%i] Not Cleaned ... Clean()\n", cur_x, cur_y);
        robot.clean();
        robo_map[cur_loc] = true;
        struct path_dir tmp;
        tmp.loc = cur_loc;
        tmp.dir = 0;
        path.push_back(tmp);
      }else{
        //printf("[%i][%i] Cleaned ... skipping\n", cur_x, cur_y);
      }
      //print_map();
      //move up from root
      clean_direction(robot);
      //printf("cleaned all up\n");
      //robot.turnLeft();
      //cur_direction = 1;
      print_map();

      
    }
};