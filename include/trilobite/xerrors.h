/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#ifndef TRILOBITE_XERRORS_H
#define TRILOBITE_XERRORS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xtest.h"

//
//
//
// Macros without message parameter
#define XERROR_PTR_NULL(pointer) XERRORS((pointer) != NULL, "Null pointer error")
#define XERROR_PTR_NOT_NULL(pointer) XERRORS((pointer) == NULL, "Not null pointer error")
#define XERROR_PTR_INVALID(pointer) XERRORS((pointer) != NULL, "Invalid pointer error")
#define XERROR_PTR_ARRAY_BOUNDS(pointer, index, size) XERRORS((index) >= 0 && (index) < (size), "Array index out of bounds")
#define XERROR_PTR_INVALID_MEMORY_ACCESS(pointer) XERRORS(pointer != NULL, "Invalid memory access")

// Macros with message parameter
#define XERROR_PTR_NULL_MSG(pointer, message) XERRORS((pointer) != NULL, message)
#define XERROR_PTR_NOT_NULL_MSG(pointer, message) XERRORS((pointer) == NULL, message)
#define XERROR_PTR_INVALID_MSG(pointer, message) XERRORS((pointer) != NULL, message)
#define XERROR_PTR_ARRAY_BOUNDS_MSG(pointer, index, size, message) XERRORS((index) >= 0 && (index) < (size), message)
#define XERROR_PTR_INVALID_MEMORY_ACCESS_MSG(pointer, message) XERRORS(pointer != NULL, message)

//
//
//

// Macros without message parameter
#define XERRORS_FILE_OPEN(file) XERRORS((file) != NULL, "Failed to open file")
#define XERRORS_FILE_READ(file) XERRORS(fread(buffer, sizeof(char), size, file) == size, "Failed to read from file")
#define XERRORS_FILE_WRITE(file) XERRORS(fwrite(data, sizeof(char), size, file) == size, "Failed to write to file")
#define XERRORS_FILE_SEEK(file, offset, whence) XERRORS(fseek(file, offset, whence) == 0, "Failed to seek within file")
#define XERRORS_FILE_TELL(file) XERRORS(ftell(file) != -1L, "Failed to get file position")
#define XERRORS_FILE_CLOSE(file) XERRORS(fclose(file) == 0, "Failed to close file")
#define XERRORS_FILE_EOF(stream) XERRORS(!feof(stream), "End of file (EOF) reached")

// Macros with message parameter
#define XERRORS_FILE_OPEN_MSG(file, message) XERRORS((file) != NULL, message)
#define XERRORS_FILE_READ_MSG(file, message) XERRORS(fread(buffer, sizeof(char), size, file) == size, message)
#define XERRORS_FILE_WRITE_MSG(file, message) XERRORS(fwrite(data, sizeof(char), size, file) == size, message)
#define XERRORS_FILE_SEEK_MSG(file, offset, whence, message) XERRORS(fseek(file, offset, whence) == 0, message)
#define XERRORS_FILE_TELL_MSG(file, message) XERRORS(ftell(file) != -1L, message)
#define XERRORS_FILE_CLOSE_MSG(file, message) XERRORS(fclose(file) == 0, message)
#define XERRORS_FILE_EOF_MSG(stream, message) XERRORS(!feof(stream), message)


//
// Array-related error macros
//
// Macros without message parameter
#define XERRORS_ARRAY_INVALID_SIZE(size) XERRORS((size) > 0, "Invalid array size")
#define XERRORS_ARRAY_INDEX_OUT_OF_BOUNDS(index, size) XERRORS((index) >= 0 && (index) < (size), "Array index out of bounds")
#define XERRORS_ARRAY_NULL_POINTER(array) XERRORS((array) != NULL, "Null array pointer")
#define XERRORS_ARRAY_INVALID_OPERATION(condition) XERRORS(condition, "Invalid array operation")
#define XERRORS_ARRAY_INDEX(array, index) XERRORS((index) >= 0 && (index) < sizeof(array) / sizeof(array[0]), "Array index out of bounds")

// Macros with message parameter
#define XERRORS_ARRAY_INVALID_SIZE_MSG(size, message) XERRORS((size) > 0, message)
#define XERRORS_ARRAY_INDEX_OUT_OF_BOUNDS_MSG(index, size, message) XERRORS((index) >= 0 && (index) < (size), message)
#define XERRORS_ARRAY_NULL_POINTER_MSG(array, message) XERRORS((array) != NULL, message)
#define XERRORS_ARRAY_INVALID_OPERATION_MSG(condition, message) XERRORS(condition, message)
#define XERRORS_ARRAY_INDEX_MSG(array, index, message) XERRORS((index) >= 0 && (index) < sizeof(array) / sizeof(array[0]), message)


#ifdef __cplusplus
}
#endif

#endif
