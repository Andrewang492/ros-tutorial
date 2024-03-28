#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"
//beginner_tutorials/AddTwoInts.h is the header file generated from the srv file that we created earlier.

bool add(beginner_tutorials::AddTwoInts::Request  &req,
         beginner_tutorials::AddTwoInts::Response &res) {
  res.sum = req.a + req.b; // a server takes requests. It will give back this response.
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("add_two_ints", add); // advertise,ready to publish on the topic.
  // doesn't actually publsih ...?
  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}
