#include <ros/ros.h>

int main(int argc, char* argv[]) {
    ros::init(argc, argv, "local_mapper_node");
    ros::NodeHandle nh;
    
    

    ros::Rate r(10);
    int c= 1;
    while(c==1 && ros::ok()){
        std::cout<<"  --------------------------"<<std::endl;

        //..................................................................
        ros::spinOnce();
        r.sleep();
    }

    return 0; 
}
