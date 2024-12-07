#include <sys/mman.h>
#include <iostream>
#include "memoryallocator.h"
#include "treenode.h"

void* initialize(size_t mem_size) {
    size_t page_size = PAGESIZE;
    if (page_size == -1) {
        std::cerr << "Unable to identify system page size." << std::endl;
        return nullptr;
    }
    if (mem_size % page_size != 0) {
        mem_size = ((mem_size / page_size) + 1) * page_size;
    }
    mem_size = closest_power_of_two(mem_size);
    void* mem_ptr = mmap(nullptr, mem_size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (mem_ptr == MAP_FAILED) {
        std::cerr << "Unable to allocate memory for size " << mem_size << "." << std::endl;
        return nullptr;
    }
    return mem_ptr;
}

void* buddy_alloc(size_t size) {

}

void* buddy_realloc(size_t size) {

}

void buddy_dealloc(void* pointer) {

}

size_t closest_power_of_two(size_t x) {
    if (x == 0) return 0;
    return pow(2, ceil(log2(x)));
}