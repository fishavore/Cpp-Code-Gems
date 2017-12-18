#pragma once

#include <Windows.h>

struct protect_mem_t {
	protect_mem_t(void* addr, size_t size) : addr(addr), size(size), is_protected(FALSE) {
		protect();
	}
	~protect_mem_t() { release(); }
	BOOL protect() {
		if (!is_protected) {
			// To catch only read access you should change PAGE_NOACCESS to PAGE_READONLY
			is_protected = VirtualProtect(addr, size, PAGE_NOACCESS, &old_protect);
		}
		return is_protected;
	}
	BOOL release() {
		if (is_protected)
			is_protected = !VirtualProtect(addr, size, old_protect, &old_protect);
		return !is_protected;
	}

protected:
	void*   addr;
	size_t  size;
	BOOL    is_protected;
	DWORD   old_protect;
};