#ifndef MACRO_DEFINITIONS_H
#define MACRO_DEFINITIONS_H

#define LOGIC_BOARD_TAG "[Logic Board]"
#define LOGIC_BOARD_TYPE__TEST "Test"
#define LOGIC_BOARD_TYPE__BASIC "Basic"
#define CHASSIS_TAG "[Chassis]"
#define CHASSIS_TYPE__SMALL "Small"
#define CHASSIS_TYPE__SMALL_MOTOR_COUNT 2
#define CHASSIS_TYPE__MEDIUM "Medium"
#define CHASSIS_TYPE__MEDIUM_MOTOR_COUNT 2
#define CHASSIS_TYPE__LARGE "Large"
#define CHASSIS_TYPE__LARGE_MOTOR_COUNT 4
#define MOTOR_DRIVE_TAG "[Drive Motors]"
#define MOTOR_DRIVE_TYPE__BASIC "Basic"
#define TYRE_TAG "[Tyres]"
#define TYRE_TYPE__BASIC "Basic"

#define BASE_PATH "C:/VirtualRobot"
#define RELATIVE_PATH_ROBOTS "Robots"
#define RELATIVE_PATH_PROGRAMS "Programs"
#define ROBOT_EXTENSION ".rbt"
#define ROBOT_EXTENSION_LENGTH 4
#define PROGRAM_EXTENSION ".prgm"
#define PROGRAM_EXTENSION_LENGTH 5

enum EMotor_Drive_Locations {
	REAR_LEFT_e,
	REAR_RIGHT_e,
	CENTRE_LEFT_e,
	CENTRE_RIGHT_e
};

#endif // !MACRO_DEFINITIONS_H
