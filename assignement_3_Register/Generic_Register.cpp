#include "Generic_Register.h"

template <class T>
Generic_Register<T>::Generic_Register(T* Register){
    PrvRegAddress = Register;
    prvRead = ~(T)0;
    prvWrite = ~(T)0;
}

template <class T>
Reg_tenuErrorStatus Generic_Register<T>::setRegisterValue(T Copy_RegValue){
    Reg_tenuErrorStatus Loc_enuErrorStatus= OK;
    if (prvWrite != (~(T)0)){
        Loc_enuErrorStatus = NOK;
    }
    else{
        *PrvRegAddress = Copy_RegValue;
    }
    return Loc_enuErrorStatus;
}

template <class T>
Reg_tenuErrorStatus Generic_Register<T>::getRegisterValue(T & Ref_Regvalue){
    Reg_tenuErrorStatus Loc_enuErrorStatus= OK;
    if (prvRead != (~(T)0)){
        Loc_enuErrorStatus = NOK;
    }
    else{
        Ref_Regvalue = *PrvRegAddress;
    }
    return Loc_enuErrorStatus;
}

template <class T>
Reg_tenuErrorStatus Generic_Register<T>::setBit(std::uint8_t Copy_uint8BitNum){
    Reg_tenuErrorStatus Loc_enuErrorStatus= OK;
    if (((prvWrite >> Copy_uint8BitNum)&1)){
        Loc_enuErrorStatus = NOK;
    }
    else{
        *PrvRegAddress |= (1 << Copy_uint8BitNum);
    }
    return Loc_enuErrorStatus;
}

template <class T>
Reg_tenuErrorStatus Generic_Register<T>::clearBit(std::uint8_t Copy_uint8BitNum){
    Reg_tenuErrorStatus Loc_enuErrorStatus= OK;
    if (((prvWrite >> Copy_uint8BitNum)&1)){
        Loc_enuErrorStatus = NOK;
    }
    else{
        *PrvRegAddress &= ~(1 << Copy_uint8BitNum);
    }
    return Loc_enuErrorStatus;
}

template <class T>
Reg_tenuErrorStatus Generic_Register<T>::getBit(std::uint8_t Copy_uint8BitNum, std::uint8_t* Add_uint8BitValue){
    Reg_tenuErrorStatus Loc_enuErrorStatus= OK;
    if (((prvRead >> Copy_uint8BitNum)&1)){
        Loc_enuErrorStatus = NOK;
    }
    else{
        *Add_uint8BitValue = ((PrvRegAddress >> Copy_uint8BitNum) & 1);
    }
    return Loc_enuErrorStatus;
}

template <class T>
Reg_tenuErrorStatus Generic_Register<T>::setPermission(std::uint8_t Copy_uint8BitNum, Reg_tenumPermission permission){
    Reg_tenuErrorStatus Loc_enuErrorStatus= OK;
    switch(permission){
        case Read_Only:
            prvRead |= (1 << Copy_uint8BitNum);
            prvWrite &= ~(1 << Copy_uint8BitNum);
            break;
        case Write_only:
            prvWrite |= (1 << Copy_uint8BitNum);
            prvRead &= ~(1 << Copy_uint8BitNum);
            break;
        case Read_Write:
            prvWrite |= (1 << Copy_uint8BitNum);
            prvRead |= (1 << Copy_uint8BitNum);
            break;
        case Reserved:
            prvRead &= ~(1 << Copy_uint8BitNum);
            prvWrite &= ~(1 << Copy_uint8BitNum);
            break;
        default:
            Loc_enuErrorStatus = NOK;
            break;
    }
    return Loc_enuErrorStatus;
}