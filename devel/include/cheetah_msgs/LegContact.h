// Generated by gencpp from file cheetah_msgs/LegContact.msg
// DO NOT EDIT!


#ifndef CHEETAH_MSGS_MESSAGE_LEGCONTACT_H
#define CHEETAH_MSGS_MESSAGE_LEGCONTACT_H


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
struct LegContact_
{
  typedef LegContact_<ContainerAllocator> Type;

  LegContact_()
    : contact_state()  {
      contact_state.assign(false);
  }
  LegContact_(const ContainerAllocator& _alloc)
    : contact_state()  {
  (void)_alloc;
      contact_state.assign(false);
  }



   typedef boost::array<uint8_t, 4>  _contact_state_type;
  _contact_state_type contact_state;





  typedef boost::shared_ptr< ::cheetah_msgs::LegContact_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::cheetah_msgs::LegContact_<ContainerAllocator> const> ConstPtr;

}; // struct LegContact_

typedef ::cheetah_msgs::LegContact_<std::allocator<void> > LegContact;

typedef boost::shared_ptr< ::cheetah_msgs::LegContact > LegContactPtr;
typedef boost::shared_ptr< ::cheetah_msgs::LegContact const> LegContactConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::cheetah_msgs::LegContact_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::cheetah_msgs::LegContact_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::cheetah_msgs::LegContact_<ContainerAllocator1> & lhs, const ::cheetah_msgs::LegContact_<ContainerAllocator2> & rhs)
{
  return lhs.contact_state == rhs.contact_state;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::cheetah_msgs::LegContact_<ContainerAllocator1> & lhs, const ::cheetah_msgs::LegContact_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace cheetah_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::cheetah_msgs::LegContact_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::cheetah_msgs::LegContact_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cheetah_msgs::LegContact_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::cheetah_msgs::LegContact_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cheetah_msgs::LegContact_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::cheetah_msgs::LegContact_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::cheetah_msgs::LegContact_<ContainerAllocator> >
{
  static const char* value()
  {
    return "40087f53ea89d1d89eb8e5a82b6a3984";
  }

  static const char* value(const ::cheetah_msgs::LegContact_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x40087f53ea89d1d8ULL;
  static const uint64_t static_value2 = 0x9eb8e5a82b6a3984ULL;
};

template<class ContainerAllocator>
struct DataType< ::cheetah_msgs::LegContact_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cheetah_msgs/LegContact";
  }

  static const char* value(const ::cheetah_msgs::LegContact_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::cheetah_msgs::LegContact_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool[4] contact_state\n"
;
  }

  static const char* value(const ::cheetah_msgs::LegContact_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::cheetah_msgs::LegContact_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.contact_state);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LegContact_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::cheetah_msgs::LegContact_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::cheetah_msgs::LegContact_<ContainerAllocator>& v)
  {
    s << indent << "contact_state[]" << std::endl;
    for (size_t i = 0; i < v.contact_state.size(); ++i)
    {
      s << indent << "  contact_state[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.contact_state[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // CHEETAH_MSGS_MESSAGE_LEGCONTACT_H