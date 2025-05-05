#include "dobby.h"

typedef struct {
    // 前4个字段（偏移 0-31 字节）
    uint64_t hook_vaddr;    // 0   (hook_block[0])
    uint64_t hook_size;     // 8   (hook_block[1])
    uint64_t code_vaddr;    // 16  (hook_block[2])
    uint64_t code_size;     // 24  (hook_block[3])

    // 中间4个字段（偏移 32-63 字节）
    uint64_t patched_vaddr; // 32  (hook_block[4])
    uint64_t original_vaddr;// 40  (hook_block[5])
    uint64_t instrument_vaddr; //48 (hook_block[6])
    uint64_t patch_size;    // 56  (hook_block[7])

    // 后3个字段（偏移 64-87 字节）
    uint64_t patch_hash;    // 64  (hook_block[8])
    void *target_replace;   // 72  (hook_block[9])
    void *instrument_handler; //80 (hook_block[10])
} StaticInlineHookBlock;

int dobby_create_instrument_bridge(void *targetData);

bool dobby_static_inline_hook(StaticInlineHookBlock *hookBlock, StaticInlineHookBlock *hookBlockRVA, uint64_t funcRVA,
                              void *funcData, uint64_t targetRVA, void *targetData, uint64_t InstrumentBridgeRVA,
                              void *patchBytes, int patchSize);


BOOL ActiveCodePatch(char* machoPath, uint64_t vaddr, char* patch);
BOOL DeactiveCodePatch(char* machoPath, uint64_t vaddr, char* patch);
NSString* StaticInlineHookPatch(char* machoPath, uint64_t vaddr, char* patch);
void* StaticInlineHookFunction(char* machoPath, uint64_t vaddr, void* replace);
BOOL StaticInlineHookInstrument(char* machoPath, uint64_t vaddr, void(*callback)(RegisterContext*));


