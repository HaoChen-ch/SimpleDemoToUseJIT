
#include <iostream>
#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/IR/Constants.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Bitcode/BitcodeReader.h"

using namespace llvm;


int main() {
    InitializeNativeTarget();
    InitializeAllAsmParsers();
    InitializeNativeTargetAsmPrinter();
    std::string Error;
    LLVMContext Context;

    ErrorOr<std::unique_ptr<MemoryBuffer>> buffer = MemoryBuffer::getFile("../equal.bc");


    outs() << buffer.getError().message() << "\n";

    Expected<std::unique_ptr<Module>> M = getOwningLazyBitcodeModule(move(buffer.get()), Context);

    outs() << *(move(M.get())) << "\n";
    std::unique_ptr<ExecutionEngine> EE;
    EE.reset(EngineBuilder(move(M.get())).setEngineKind(llvm::EngineKind::JIT).create());
    bool (*equal)(char *, char *) = nullptr;
    equal = ((bool (*)(char *, char *)) EE->getFunctionAddress(std::string("equal")));
    char *a = "hello";
    char *b = "hello";
    bool res = equal(a, b);
    outs() << "res : " << res << "\n";
    return 0;
}