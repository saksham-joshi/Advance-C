#ifndef _CUSTOM_FILE_READER_
#define _CUSTOM_FILE_READER_

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    char* _filename;
    char* _content;
    char* _seek;
    size_t _size;
    HANDLE _hFile;
    HANDLE _hMapping;
} CustomFile;

typedef CustomFile* FilePtr;

inline static CustomFile openFile(const char* const __filename)
{
    HANDLE hFile = CreateFileA(
        __filename,
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE)
    {
        fprintf(stderr, "Failed to open file: %s\n", __filename);
        
        exit(EXIT_FAILURE);
    }

    DWORD fileSize = GetFileSize(hFile, NULL);

    if (fileSize == INVALID_FILE_SIZE || fileSize == 0)
    {
        CloseHandle(hFile);

        fprintf(stderr, "File is empty or error determining size.\n");

        exit(EXIT_FAILURE);
    }

    HANDLE hMapping = CreateFileMappingA(
        hFile,
        NULL,
        PAGE_READONLY,
        0,
        0,
        NULL
    );

    if (!hMapping) {
        CloseHandle(hFile);
        fprintf(stderr, "Failed to create file mapping.\n");
        exit(EXIT_FAILURE);
    }

    LPVOID data = MapViewOfFile(
        hMapping,
        FILE_MAP_READ,
        0,
        0,
        0
    );

    if (!data) {
        CloseHandle(hMapping);
        CloseHandle(hFile);
        fprintf(stderr, "Failed to map view of file.\n");
        exit(EXIT_FAILURE);
    }

    CustomFile file;
    file._filename = _strdup(__filename);
    file._content = (char*)data;
    file._seek = file._content;
    file._size = fileSize;
    file._hFile = hFile;
    file._hMapping = hMapping;

    return file;
}

inline static void readData(FilePtr __file, void* __write_on, unsigned int __bytes_to_read)
{
    if ((__file->_seek - __file->_content + __bytes_to_read) > __file->_size)
    {
        fprintf(stderr, "Read beyond file bounds\n");

        exit(EXIT_FAILURE);
    }

    memcpy(__write_on, __file->_seek, __bytes_to_read);

    __file->_seek += __bytes_to_read;
}

inline static void closeFile(FilePtr __file)
{
    UnmapViewOfFile(__file->_content);

    CloseHandle(__file->_hMapping);

    CloseHandle(__file->_hFile);

    free(__file->_filename);
}

#endif
