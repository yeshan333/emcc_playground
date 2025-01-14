// https://github.com/3dgen/cppwasm-book/blob/master/wasm-in-action-book-examples/ch5/02/unaligned.cc
#ifndef EM_PORT_API
#	if defined(__EMSCRIPTEN__)
#		include <emscripten.h>
#		if defined(__cplusplus)
#			define EM_PORT_API(rettype) extern "C" rettype EMSCRIPTEN_KEEPALIVE
#		else
#			define EM_PORT_API(rettype) rettype EMSCRIPTEN_KEEPALIVE
#		endif
#	else
#		if defined(__cplusplus)
#			define EM_PORT_API(rettype) extern "C" rettype
#		else
#			define EM_PORT_API(rettype) rettype
#		endif
#	endif
#endif

#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <stdint.h>

struct ST {
	uint8_t	c[4];
	float	f;
};

void throw_unalign_err() {
	printf("Hello, World!\n");
	char *buf = (char*)malloc(100);
	ST *pst = (ST*)(buf + 2);

	pst->c[0] = pst->c[1] = pst->c[2] = pst->c[3] = 123;
	pst->f = 3.14f;

	printf("c[0]:%d,c[1]:%d,c[2]:%d,c[3]:%d,f:%f\n",
		pst->c[0], pst->c[1], pst->c[2], pst->c[3], pst->f);

	free(buf);
}

int main() {
	throw_unalign_err();
	return 0;
}