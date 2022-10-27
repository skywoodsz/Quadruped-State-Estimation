//
// Created by skywoodsz on 22-10-25.
//

#ifndef SRC_ROBOT_MATH_H
#define SRC_ROBOT_MATH_H

#include <vector>
#include <Eigen/Dense>

#include <kf_estimator/dog_type.h>

template <typename T>
T square(T a)
{
    return a * a;
}

/*!
 * Convert a quaternion to RPY.  Uses ZYX order (yaw-pitch-roll), but returns
 * angles in (roll, pitch, yaw).
 */
template <typename T>
Vec3<T> quatToRPY(const Eigen::Quaternion<T>& q)
{
    Vec3<T> rpy;

    T as = std::min(-2. * (q.x() * q.z() - q.w() * q.y()), .99999);
    rpy(2) =
            std::atan2(2 * (q.x() * q.y() + q.w() * q.z()), square(q.w()) + square(q.x()) - square(q.y()) - square(q.z()));
    rpy(1) = std::asin(as);
    rpy(0) =
            std::atan2(2 * (q.y() * q.z() + q.w() * q.x()), square(q.w()) - square(q.x()) - square(q.y()) + square(q.z()));
    return rpy;
}

template <typename T>
Mat3<T> quaternionToRotationMatrix(const Eigen::Quaternion<T>& q)
{
    T w = q.w();
    T x = q.x();
    T y = q.y();
    T z = q.z();
    Mat3<T> r;
    r << 1 - 2 * (y * y + z * z), 2 * (x * y - w * z), 2 * (x * z + w * y), 2 * (x * y + w * z), 1 - 2 * (x * x + z * z),
            2 * (y * z - w * x), 2 * (x * z - w * y), 2 * (y * z + w * x), 1 - 2 * (x * x + y * y);
    return r;
}

template <typename T>
Eigen::Quaternion<T> RpyToQuat(Vec3<T> rpy)
{
    // Abbreviations for the various angular functions
    double cy = cos(rpy(2) * 0.5);
    double sy = sin(rpy(2) * 0.5);
    double cp = cos(rpy(1) * 0.5);
    double sp = sin(rpy(1) * 0.5);
    double cr = cos(rpy(0) * 0.5);
    double sr = sin(rpy(0) * 0.5);

    Eigen::Quaternion<T> q;
    q.w() = cr * cp * cy + sr * sp * sy;
    q.x() = sr * cp * cy - cr * sp * sy;
    q.y() = cr * sp * cy + sr * cp * sy;
    q.z() = cr * cp * sy - sr * sp * cy;

    return q;
}

#endif //SRC_ROBOT_MATH_H
