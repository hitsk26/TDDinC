void RunTimeError(const char * message,int prameter,
				  const char * file, int line);


#define RUNTIME_ERROR(description,parameter)\
	RuntimeError(description,parameter,__FILE__,__LINE__)

