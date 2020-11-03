#ifndef _ROS_SERVICE_Person_h
#define _ROS_SERVICE_Person_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace learning_service
{

static const char PERSON[] = "learning_service/Person";

  class PersonRequest : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef uint8_t _age_type;
      _age_type age;
      typedef uint8_t _gender_type;
      _gender_type gender;
      enum { unknown =  0 };
      enum { male =  1 };
      enum { female =  2 };

    PersonRequest():
      name(""),
      age(0),
      gender(0)
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
      *(outbuffer + offset + 0) = (this->age >> (8 * 0)) & 0xFF;
      offset += sizeof(this->age);
      *(outbuffer + offset + 0) = (this->gender >> (8 * 0)) & 0xFF;
      offset += sizeof(this->gender);
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
      this->age =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->age);
      this->gender =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->gender);
     return offset;
    }

    const char * getType(){ return PERSON; };
    const char * getMD5(){ return "2354270d28e8bf05f6f2a45875247e52"; };

  };

  class PersonResponse : public ros::Msg
  {
    public:
      typedef const char* _result_type;
      _result_type result;

    PersonResponse():
      result("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_result = strlen(this->result);
      varToArr(outbuffer + offset, length_result);
      offset += 4;
      memcpy(outbuffer + offset, this->result, length_result);
      offset += length_result;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_result;
      arrToVar(length_result, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_result; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_result-1]=0;
      this->result = (char *)(inbuffer + offset-1);
      offset += length_result;
     return offset;
    }

    const char * getType(){ return PERSON; };
    const char * getMD5(){ return "c22f2a1ed8654a0b365f1bb3f7ff2c0f"; };

  };

  class Person {
    public:
    typedef PersonRequest Request;
    typedef PersonResponse Response;
  };

}
#endif
