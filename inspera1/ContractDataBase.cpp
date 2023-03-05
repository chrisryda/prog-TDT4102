#include "ContractDataBase.h"

InsuranceContract ContractDataBase::getContract(int id)
{
    // BEGIN: 1b

    for (InsuranceContract ic : contracts) {
        if (ic.getId() == id) {
            return ic;
        }
    }

    // END: 1b

    // Returning an empty contract if no contract with the given id is found.
    return InsuranceContract{};
}

int ContractDataBase::numberOfInsuranceType(InsuranceType type)
{
    // BEGIN: 1c

    int sum = 0;
    for (InsuranceContract ic : contracts) {
        if (ic.getInsuranceType() == type) {
            sum++;
        }
    }
    
    return sum;
    // END: 1c
}

int ContractDataBase::addContract(string holderName, InsuranceType insType, int value)
{
    // BEGIN: 1d 

    int max_id = 0;
    for (InsuranceContract ic : contracts) {
        if (ic.getId() > max_id) {
            max_id = ic.getId();
        }
    }
    
    int new_id = max_id+1;
    InsuranceContract ic{holderName, insType, value, new_id};
    contracts.emplace_back(ic);
    
    return new_id;

    // END: 1d
}

void ContractDataBase::saveContracts(string filename)
{
    // BEGIN: 1e

    filesystem::path fn{filename};
    ofstream os{fn};

    for (InsuranceContract ic : contracts) {
        os << ic.getHolder() << "," << insuranceTypeToString(ic.getInsuranceType()) << "," << ic.getValue() << "," << ic.getInsuranceText() << endl;
    } 

    // END: 1e
}

void ContractDataBase::loadContracts(string filename)
{
    ifstream inFile{filename};
    if (!inFile)
    {
        error("Couldn't open file: ", filename);
    }

    string line;
    while (getline(inFile, line))
    {
        stringstream ss{line};
        char seperator;

        string holderName;
        getline(ss, holderName, ',');

        string insType;
        getline(ss, insType, ',');

        int value;
        ss >> value;
        ss >> seperator;

        int id;
        ss >> id;
        ss >> seperator;

        string insuranceText;
        getline(ss, insuranceText, ',');

        contracts.push_back({holderName, stringToInsuranceType.at(insType), value, id, insuranceText});
    }
}
