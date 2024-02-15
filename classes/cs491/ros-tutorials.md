# ROS Tutorials

## Understanding ROS Topics

http://wiki.ros.org/ROS/Tutorials/UnderstandingTopics

### 1. Setup

Launch ROS:
```bash
roscore
```

In a new terminal, launch the `turtlesim` node:
```bash
rosrun turtlesim turtlesim_node
```

In another terminal, launch the keyboard teleoperation:
```bash
rosrun turtlesim turtle_teleop_key
```

### 2. ROS Topics

First, install rqt_graph:
```bash
sudo apt-get install ros-melodic-rqt
sudo apt-get install ros-melodic-rqt-common-plugins
```

Next, we can launch rqt_graph:
```bash
rosrun rqt_graph rqt_graph
```

You can view some commands with:
```bash
rostopic -h
```

We can use the `echo` command to view the data published
```bash
rostopic echo /turtle1/cmd_vel
```

Now, the data that we publish to `turtlesim_node` through the `turtle_teleop_key` will appear in this terminal.

To view all topics currently subscribed to and published, use:
```bash
rostopic list -h
```

For a more detailed list, you can use the verbose (`-v`) option:
```bash
rostopic list -v
```

### 3. ROS Messages

Communication between ROS nodes takes place in ROS messages from publisher to subscriber. In this case, `turtle_teleop_key` is our publisher and `turtlesim_node` is our subscriber.
```bash
rostopic type /turtle1/cmd_vel
```

To view the details of the message, we can use `rosmsg`:
```bash
rosmsg show geometry_msgs/Twist
```

### 4. rostopic Continued

We can use messages to directly communicate with ROS nodes:
```bash
rostopic pub -l /turtle1/cmd_vel geometry_msgs/Twist --'[2.0, 0.0, 0.0]' '[0.0, 0.0, 1.8]'
```


