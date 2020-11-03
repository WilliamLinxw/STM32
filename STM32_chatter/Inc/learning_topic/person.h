#ifndef _ROS_learning_topic_person_h
#define _ROS_learning_topic_person_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace learning_topic
{

  class person : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef uint8_t _gender_type;
      _gender_type gender;
      typedef uint8_t _age_type;
      _age_type age;
      enum { unknown =  0 };
      enum { male =  1 };
      enum { female =  2 };

    person():
      name(""),
      gender(0),
      age(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->gender >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gender);
      *(outbuffer + offset + 0) = (this->age >> (8 * 0)) & 0xFF;
      offset += sizeof(this->age);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      this->gender =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gender);
      this->age =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->age);
     return offset;
    }

    const char * getType(){ return "learning_topic/person"; };
    const char * getMD5(){ return "6bb86bda68e6529d23ed2cd8ba6da694"; };

  };

}
#endif
