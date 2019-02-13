#include <stdlib.h>


#include "SDL2-2.0.9/include/SDL.h"


#pragma comment(lib, "SDL2-2.0.9\\lib\\x86\\SDL2.lib")
#pragma comment(lib, "SDL2-2.0.9\\lib\\x86\\SDL2main.lib")


enum main_states
{
	MAIN_CREATION,
	MAIN_START,
	MAIN_UPDATE,
	MAIN_FINISH,
	MAIN_EXIT,
	MAIN_FAILURE,
	MAIN_SUCCES
};

int main(int argc, char ** argv)
{
	int m_main_return = MAIN_FAILURE;
	main_states state = MAIN_CREATION;

}