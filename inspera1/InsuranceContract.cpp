#include "InsuranceContract.h"
#include "Utilities.h"

InsuranceContract::InsuranceContract(string holderName, InsuranceType insType, int value, int id, string insText)
    : holderName{holderName}, insType{insType}, value{value}, id{id}, insuranceText{insText}
{
    if (insuranceText == "Text missing!")
    {
        // BEGIN: 2c2
        vector<vector<string>> categories = loadSvada();
        insuranceText = svadaGenerator(categories);

        // END: 2c2
    }
}

string insuranceTypeToString(InsuranceType t)
{
    // BEGIN: 1a

    switch (t)
    {
    case InsuranceType::Car:
        return "Car";
        break;
    case InsuranceType::Contents:
        return "Contents";
        break;
    case InsuranceType::Travel:
        return "Travel";
        break;
    default:
        return "No such type";
        break;
    }
    
    // END: 1a
}   

ostream &operator<<(ostream &os, InsuranceContract obj)
{
    os << "Holder: " << obj.getHolder() << '\n';
    os << "Insurance type: " << insuranceTypeToString(obj.getInsuranceType()) << '\n';
    os << "Id: " << to_string(obj.getId()) << '\n';
    os << "Value: " << to_string(obj.getValue()) << '\n';
    os << "Insurance text:\n"
       << obj.getInsuranceText() << '\n';
    return os;
}
