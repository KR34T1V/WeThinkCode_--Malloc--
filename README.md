# WeThinkCode_--Malloc--
Recreation of the system commands Malloc, Realloc and Free

## Malloc()
Malloc() uses mmap(2) to reserve memory from the system, it reserves memory chunks based on the size requested. To optimize the performance of malloc it will only call mmap(2) once for every 100 allocations of the same size type. If memory is freed in one of these chunks it will be reused if it fits a new allocation, this causes the memory to be defragged and fit the most amount of allocations possible, in one chunk.

## Free()
Free() uses releases memory locked by malloc() and allows it to be used for a new allocation. If the last block of memory is freed in a chunk free() will use munmap(2) to release the reserved system memory for other processes to use.

## Realloc()
Realloc() will attempt to resize a piece of memory based on the users input, if it is posssible to increse/decrease the assigned memory, realloc() will resize and reserve/release the additional/excess memory in the chunk accordingly. If it is not possible to fit the resize, a new chunk will be reserved and the memory will be copied to the new chunk, the old memory will be freed. A pointer to the new allocated memory is returned.

- A TINY size type is any allocation from 1->32 bytes.

- A SMALL size type is any allocation from 33->128 bytes.

- LARGE size type is any allocation from 129->infinate bytes.
