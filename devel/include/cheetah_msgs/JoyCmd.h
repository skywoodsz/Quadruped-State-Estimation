// Generated by gencpp from file cheetah_msgs/JoyCmd.msg
// DO NOT EDIT!


#ifndef CHEETAH_MSGS_MESSAGE_JOYCMD_H
#define CHEETAH_MSGS_MESSAGE_JOYCMD_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace cheetah_msgs
{
template <class ContainerAllocator>
struct JoyCmd_
{
  typedef JoyCmd_<ContainerAllocator> Type;

  JoyCmd_()
    : header()
    , velDes()
    , cmd_model(0)
    , cmd_exit(false)  {
      velDes.assign(0.0);
  }
  JoyCmd_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , velDes()
    , cmd_model(0)
    , cmd_exit(false)  {
  (void)_alloc;
      velDes.assign(0.0);
  }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef boost::array<double, 6>  _velDes_type;
  _velDes_type velDes;

   typedef uint8_t _cmd_model_type;
  _cmd_model_type cmd_model;

   typedef uint8_t _cmd_exit_type;
  _cmd_exit_type cmd_exit;





  typedef boost::shared_ptr< ::cheetah_msgs::JoyCmd_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cheetah_msgs::JoyCmd_<ContainerAllocator> const> ConstPtr;

}; // struct JoyCmd_

typedef ::cheetah_msgs::JoyCmd_<std::allocator<void> > JoyCmd;

typedef boost::shared_ptr< ::cheetah_msgs::JoyCmd > JoyCmdPtr;
typedef boost::shared_ptr< ::cheetah_msgs::JoyCmd const> JoyCmdConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cheetah_msgs::JoyCmd_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cheetah_msgs::JoyCmd_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::cheetah_msgs::JoyCmd_<ContainerAllocator1> & lhs, const ::cheetah_msgs::JoyCmd_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.velDes == rhs.velDes &&
    lhs.cmd_model == rhs.cmd_model &&
    lhs.cmd_exit == rhs.cmd_exit;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::cheetah_msgs::JoyCmd_<ContainerAllocator1> & lhs, const ::cheetah_msgs::JoyCmd_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace cheetah_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::cheetah_msgs::JoyCmd_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cheetah_msgs::JoyCmd_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cheetah_msgs::JoyCmd_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cheetah_msgs::JoyCmd_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cheetah_msgs::JoyCmd_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cheetah_msgs::JoyCmd_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cheetah_msgs::JoyCmd_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f5f7dd9f0b7c557f47d3286f01c7eebb";
  }

  static const char* value(const ::cheetah_msgs::JoyCmd_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf5f7dd9f0b7c557fULL;
  static const uint64_t static_value2 = 0x47d3286f01c7eebbULL;
};

template<class ContainerAllocator>
struct DataType< ::cheetah_msgs::JoyCmd_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cheetah_msgs/JoyCmd";
  }

  static const char* value(const ::cheetah_msgs::JoyCmd_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cheetah_msgs::JoyCmd_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"float64[6] velDes\n"
"uint8 cmd_model\n"
"bool cmd_exit\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::cheetah_msgs::JoyCmd_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cheetah_msgs::JoyCmd_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.velDes);
      stream.next(m.cmd_model);
      stream.next(m.cmd_exit);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct JoyCmd_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cheetah_msgs::JoyCmd_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cheetah_msgs::JoyCmd_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "velDes[]" << std::endl;
    for (size_t i = 0; i < v.velDes.size(); ++i)
    {
      s << indent << "  velDes[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.velDes[i]);
    }
    s << indent << "cmd_model: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.cmd_model);
    s << indent << "cmd_exit: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.cmd_exit);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CHEETAH_MSGS_MESSAGE_JOYCMD_H
