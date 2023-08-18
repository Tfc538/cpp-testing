#include <iostream>

/************************************
************* Variables *************
************************************/
bool saveInfo;
std::string firstName;
std::string lastName;
std::string city;
std::string state;
std::string country;
std::string format;
const char* hobbies[] = {};
const char* languages[] = {};
const char* pets[] = {};
int age;


/*************************************
 * *********** Functions *************
 * **********************************/

int askUser(std::string question, auto variable)
{
    question += " ";
    std::cout << question << std::endl;
    std::cin >> variable;

    if (variable == "")
    {
        std::cout << "You did not enter a value. Please try again." << std::endl;
        askUser(question, variable);
        return 1;
    }

    return 0;
}

int askUserArray(std::string question, auto variable)
{
    question += " ";
    
    std::cout << question << std::endl;
    std::cout << "Enter a value and press enter. When you are done with the list, please enter a blank value." << std::endl;

    std::string input;
    while (input != "")
    {
        std::cin >> input;
        variable.push_back(input);
    }

    if (variable.size() == 0)
    {
        std::cout << "You did not enter a value. Please try again." << std::endl;
        askUserArray(question, variable);
        return 1;
    }

    return 0;
}

int writeJson(std::string firstName, std::string lastName, std::string city, std::string state, std::string country, int age, const char* hobbies[], const char* languages[], const char* pets[])
{
    std::cout << "{" << std::endl;
    std::cout << "    \"firstName\": \"" << firstName << "\"," << std::endl;
    std::cout << "    \"lastName\": \"" << lastName << "\"," << std::endl;
    std::cout << "    \"city\": \"" << city << "\"," << std::endl;
    std::cout << "    \"state\": \"" << state << "\"," << std::endl;
    std::cout << "    \"country\": \"" << country << "\"," << std::endl;
    std::cout << "    \"age\": " << age << "," << std::endl;
    std::cout << "    \"hobbies\": [" << std::endl;
    for (int i = 0; i < sizeof(hobbies); i++)
    {
        std::cout << "        \"" << hobbies[i] << "\"" << std::endl;
    }
    std::cout << "    ]," << std::endl;
    std::cout << "    \"languages\": [" << std::endl;
    for (int i = 0; i < sizeof(languages); i++)
    {
        std::cout << "        \"" << languages[i] << "\"" << std::endl;
    }
    std::cout << "    ]," << std::endl;
    std::cout << "    \"pets\": [" << std::endl;
    for (int i = 0; i < sizeof(pets); i++)
    {
        std::cout << "        \"" << pets[i] << "\"" << std::endl;
    }
    std::cout << "    ]" << std::endl;
    std::cout << "}" << std::endl;
}

int writeXml(std::string firstName, std::string lastName, std::string city, std::string state, std::string country, int age, const char* hobbies[], const char* languages[], const char* pets[])
{
    std::cout << "<user>" << std::endl;
    std::cout << "    <firstName>" << firstName << "</firstName>" << std::endl;
    std::cout << "    <lastName>" << lastName << "</lastName>" << std::endl;
    std::cout << "    <city>" << city << "</city>" << std::endl;
    std::cout << "    <state>" << state << "</state>" << std::endl;
    std::cout << "    <country>" << country << "</country>" << std::endl;
    std::cout << "    <age>" << age << "</age>" << std::endl;
    std::cout << "    <hobbies>" << std::endl;
    for (int i = 0; i < sizeof(hobbies); i++)
    {
        std::cout << "        <hobby>" << hobbies[i] << "</hobby>" << std::endl;
    }
    std::cout << "    </hobbies>" << std::endl;
    std::cout << "    <languages>" << std::endl;
    for (int i = 0; i < sizeof(languages); i++)
    {
        std::cout << "        <language>" << languages[i] << "</language>" << std::endl;
    }
    std::cout << "    </languages>" << std::endl;
    std::cout << "    <pets>" << std::endl;
    for (int i = 0; i < sizeof(pets); i++)
    {
        std::cout << "        <pet>" << pets[i] << "</pet>" << std::endl;
    }
    std::cout << "    </pets>" << std::endl;
    std::cout << "</user>" << std::endl;
}

int writeCsv(std::string firstName, std::string lastName, std::string city, std::string state, std::string country, int age, const char* hobbies[], const char* languages[], const char* pets[])
{
    std::cout << "firstName,lastName,city,state,country,age,hobbies,languages,pets" << std::endl;
    std::cout << firstName << "," << lastName << "," << city << "," << state << "," << country << "," << age << ",";
    for (int i = 0; i < sizeof(hobbies); i++)
    {
        std::cout << hobbies[i] << ",";
    }
    std::cout << ",";
    for (int i = 0; i < sizeof(languages); i++)
    {
        std::cout << languages[i] << ",";
    }
    std::cout << ",";
    for (int i = 0; i < sizeof(pets); i++)
    {
        std::cout << pets[i] << ",";
    }
    std::cout << std::endl;
}

int askForUserData()
{
        /* Ask user for input */
    askUser("What is your first name?", firstName);
    askUser("What is your last name?", lastName);
    askUser("What city do you live in?", city);
    askUser("What state do you live in?", state);
    askUser("What country do you live in?", country);
    askUser("How old are you?", age);
    askUserArray("What are your hobbies?", hobbies);
    askUserArray("What languages do you know?", languages);
    askUserArray("What pets do you have?", pets);

    // Print out the user's information
    std::cout << "Your name is " << firstName << " " << lastName << "." << std::endl;
    std::cout << "You are " << age << " years old." << std::endl;
    std::cout << "You live in " << city << ", " << state << ", " << country << "." << std::endl;
    
    std::cout << "Your hobbies are: " << std::endl;
    for (int i = 0; i < sizeof(hobbies); i++)
    {
        std::cout << hobbies[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "You know the following languages: " << std::endl;
    for (int i = 0; i < sizeof(languages); i++)
    {
        std::cout << languages[i] << std::endl;
    }
    std::cout << std::endl;

    std::cout << "You have the following pets: " << std::endl;
    for (int i = 0; i < sizeof(pets); i++)
    {
        std::cout << pets[i] << std::endl;
    }
    std::cout << std::endl;

    return 0;
}

const std::string doesFileExist(const std::string& fileName)
{
    if (FILE *file = fopen(fileName.c_str(), "r"))
    {
        fclose(file);
        // return fileName;
        return fileName;
    }
    else
    {
        return "";
    }
}

const std::string readJson()
{
    std::string fileName = doesFileExist("userData.json");

    if (fileName != "")
    {
        // Parse json

        
}

int main()
{


    /* If a file named "userData.json" or "userData.csv" or "userData.xml exists ask if he wants to continue and save that data in another format" */
    std::string fileName = doesFileExist("userData.json");

    if (fileName != "")
    {
        std::cout << "A file named " << fileName << " already exists. Would you like to continue and save that data in another format? (y/n)" << std::endl;
        std::cin >> saveInfo;

        if (saveInfo)
        {
            std::cout << "In what format would you like to save this information? (json, xml, csv)" << std::endl;
            std::cin >> format;

            if (format == "json")
            {
                

    std::cout << "Would you like to save this information? (y/n)" << std::endl;
    std::cin >> saveInfo;

    if (saveInfo)
    {
        std::cout << "In what format would you like to save this information? (json, xml, csv)" << std::endl;
        std::cin >> format;

        if (format == "json")
        {
            // Save as json


        }
        else if (format == "xml")
        {
            // Save as xml
        }
        else if (format == "csv")
        {
            // Save as csv
        }
        else
        {
            std::cout << "Invalid format. Not saving information." << std::endl;
        }        
    }
    else
    {
        std::cout << "Not saving information." << std::endl;
    }
}
