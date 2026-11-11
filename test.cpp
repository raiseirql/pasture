#include "llvm/Support/InitLLVM.h"

int main(int argc, char **argv) {
	llvm::InitLLVM initLLVM(argc, argv);
	return 0;
}