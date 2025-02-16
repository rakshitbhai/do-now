

#include "util.h"

int main()
{
    // Start measuring time
    startCount();
    // Start Your Code From Here
    initialize();
    // Let user update their list
    interrupt();
    // Generate file structure according to today's date
    generate();
    // End Your Program before this line otherwise you willl hit the safeline  region
    // End measuring time
    endCount();
    return 0;
}
