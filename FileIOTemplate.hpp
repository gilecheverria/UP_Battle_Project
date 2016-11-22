#include <cstdio>
#include <cstdlib>

// Use a template to be able to write files of different types of data
template <class T>
class FileIOTemplate {

    private:
        static FILE * openAndCheck(std::string file_name, std::string mode);

    public:
        static void writeNewData(T & data_object, std::string file_name);
        static int readData(T data_array[], size_t items, std::string file_name);
};

template <class T>
FILE * FileIOTemplate<T>::openAndCheck(std::string file_name, std::string mode)
{
    FILE * file_ptr = nullptr;

    // Open the file. Convert C++ strings to C arrays of characters for the parameters
    file_ptr = fopen(file_name.c_str(), mode.c_str());
    if (file_ptr == nullptr)
    {
        std::cout << "Error: Unable to open file '" << file_name << "'!\n";
        exit(1);
    }
    return file_ptr;
}

// Asks the user for input on the data required to fill an object, and saves it to a file
// The class provided must implement the method "inputData" for this to work
template <class T>
void FileIOTemplate<T>::writeNewData(T & data_object, std::string file_name)
{
    FILE * file_ptr = nullptr;

    data_object.inputData();
    file_ptr = openAndCheck(file_name, "ab");
    fwrite(&data_object, sizeof (T), 1, file_ptr);
    fclose(file_ptr);
}

// Read items from a file and stores them in an array of the required type
// Returns the amount that were found
template <class T>
int FileIOTemplate<T>::readData(T data_array[], size_t items, std::string file_name)
{
    FILE * file_ptr = fopen(file_name.c_str(), "rb");
    size_t items_read = 0;

    if (file_ptr)
    {
        // Read up to the maximum size of the array of elements
        items_read = fread(data_array, sizeof (T), items, file_ptr);
        fclose(file_ptr);
    }
    return items_read;
}
