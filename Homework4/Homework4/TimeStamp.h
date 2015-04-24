///////////////////////////////////////////////////////////////////////////////
// TimeStamp.h
//
// This file declares the Class TimeStamp. This class will return the current
// date and time. Time resolution is to the 100's of milliseconds, however, 
// actual accuracy is OS and platform dependent. For most Windows PC platforms, 
// the actual resolution is 10 milliseconds.
//
// Author: Joe Waclawski
// Purpose: CIS554 
///////////////////////////////////////////////////////////////////////////////
#include <string>
using std::string;

// TimeStamp Class declaration
class TimeStamp
{
public:
// Public Interface

///////////////////////////////////////////////////////////////////////////////
// Method: GetTime
// Parameters: None
// Returns: string containing Date and Time in following format:
//      The current time is Fri Oct 02 21:05:58.906
///////////////////////////////////////////////////////////////////////////////
	string GetTime(void);
};