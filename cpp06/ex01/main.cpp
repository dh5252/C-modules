

#include "includes/Serializer.hpp"

int main()
{
    {
        std::cout << "\nIntegrated Test" << std::endl;

        Data dt;
        Data *convertPtr = NULL;

        dt.name = "init data";
        convertPtr = Serializer::deserialize(Serializer::serialize(&dt));

        std::cout << dt.name << " " << convertPtr->name << std::endl;
    }


    return 0;
}