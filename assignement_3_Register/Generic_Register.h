#ifndef GENERIC_REGSTER_H
#define GENERIC_REGSTER_H

#include <iostream>


typedef enum{
    NOK,
    OK
}Reg_tenuErrorStatus;

typedef enum{
    Read_Only,
    Write_only,
    Read_Write,
    Reserved
}Reg_tenumPermission;

template <class T>
class Generic_Register
{
    public:
        T * PrvRegAddress;
        T prvRead;
        T prvWrite;

    Generic_Register(T* Register);
    Reg_tenuErrorStatus setRegisterValue(T Copy_RegValue);
    Reg_tenuErrorStatus getRegisterValue(T & Ref_Regvalue);
    Reg_tenuErrorStatus setBit(std::uint8_t Copy_uint8BitNum);
    Reg_tenuErrorStatus clearBit(std::uint8_t Copy_uint8BitNum);
    Reg_tenuErrorStatus getBit(std::uint8_t Copy_uint8BitNum, std::uint8_t* Add_uint8BitValue);
    Reg_tenuErrorStatus setPermission(std::uint8_t Copy_uint8BitNum, Reg_tenumPermission permission);
};




#endif  /* GENERIC_REGSTER_H */