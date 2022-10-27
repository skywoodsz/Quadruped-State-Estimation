// Generated by gencpp from file cheetah_msgs/LegPrefix.msg
// DO NOT EDIT!


#ifndef CHEETAH_MSGS_MESSAGE_LEGPREFIX_H
#define CHEETAH_MSGS_MESSAGE_LEGPREFIX_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace cheetah_msgs
{
template <class ContainerAllocator>
struct LegPrefix_
{
  typedef LegPrefix_<ContainerAllocator> Type;

  LegPrefix_()
    : prefix(0)  {
    }
  LegPrefix_(const ContainerAllocator& _alloc)
    : prefix(0)  {
  (void)_alloc;
    }



   typedef uint8_t _prefix_type;
  _prefix_type prefix;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(FL)
  #undef FL
#endif
#if defined(_WIN32) && defined(FR)
  #undef FR
#endif
#if defined(_WIN32) && defined(RL)
  #undef RL
#endif
#if defined(_WIN32) && defined(RR)
  #undef RR
#endif

  enum {
    FL = 0u,
    FR = 1u,
    RL = 2u,
    RR = 3u,
  };


  typedef boost::shared_ptr< ::cheetah_msgs::LegPrefix_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cheetah_msgs::LegPrefix_<ContainerAllocator> const> ConstPtr;

}; // struct LegPrefix_

typedef ::cheetah_msgs::LegPrefix_<std::allocator<void> > LegPrefix;

typedef boost::shared_ptr< ::cheetah_msgs::LegPrefix > LegPrefixPtr;
typedef boost::shared_ptr< ::cheetah_msgs::LegPrefix const> LegPrefixConstPtr;

// constants requiring out of line definition

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cheetah_msgs::LegPrefix_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cheetah_msgs::LegPrefix_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::cheetah_msgs::LegPrefix_<ContainerAllocator1> & lhs, const ::cheetah_msgs::LegPrefix_<ContainerAllocator2> & rhs)
{
  return lhs.prefix == rhs.prefix;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::cheetah_msgs::LegPrefix_<ContainerAllocator1> & lhs, const ::cheetah_msgs::LegPrefix_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace cheetah_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::cheetah_msgs::LegPrefix_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cheetah_msgs::LegPrefix_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cheetah_msgs::LegPrefix_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cheetah_msgs::LegPrefix_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cheetah_msgs::LegPrefix_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cheetah_msgs::LegPrefix_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cheetah_msgs::LegPrefix_<ContainerAllocator> >
{
  static const char* value()
  {
    return "08a2102fbe59e65ff737affde7a563d2";
  }

  static const char* value(const ::cheetah_msgs::LegPrefix_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x08a2102fbe59e65fULL;
  static const uint64_t static_value2 = 0xf737affde7a563d2ULL;
};

template<class ContainerAllocator>
struct DataType< ::cheetah_msgs::LegPrefix_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cheetah_msgs/LegPrefix";
  }

  static const char* value(const ::cheetah_msgs::LegPrefix_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cheetah_msgs::LegPrefix_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 FL = 0\n"
"uint8 FR = 1\n"
"uint8 RL = 2\n"
"uint8 RR = 3\n"
"\n"
"uint8 prefix\n"
;
  }

  static const char* value(const ::cheetah_msgs::LegPrefix_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cheetah_msgs::LegPrefix_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.prefix);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LegPrefix_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cheetah_msgs::LegPrefix_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cheetah_msgs::LegPrefix_<ContainerAllocator>& v)
  {
    s << indent << "prefix: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.prefix);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CHEETAH_MSGS_MESSAGE_LEGPREFIX_H
