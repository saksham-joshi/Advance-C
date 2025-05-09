#pragma once

#ifndef _CUSTOM_FILE_READER_
#define _CUSTOM_FILE_READER_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct BinaryReader;

typedef struct BinaryReader* FilePtr;

#ifdef _WIN64
    #include<windows.h>

    struct BinaryReader
    {
        char* _filename;
        char* _content;
        char* _seek;
        size_t _size;
        HANDLE _hfile;
        HANDLE _hmapping;
    };

    inline static struct BinaryReader openFile(const char* const __filename)
    {
        struct BinaryReader output = { 0 };

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
            errno = ENOENT;

            perror("Failed to open file");

            return output;
        }

        DWORD fileSize = GetFileSize(hFile, NULL);

        if (fileSize == INVALID_FILE_SIZE || fileSize == 0)
        {
            errno = ENOENT;

            perror("Failed to find file size");

            CloseHandle(hFile);

            return output;
        }

        HANDLE hMapping = CreateFileMappingA(
            hFile,
            NULL,
            PAGE_READONLY,
            0,
            0,
            NULL
        );

        if (!hMapping)
        {
            errno = EPERM;

            perror("Failed to create file mapping");

            CloseHandle(hFile);

            return output;
        }

        LPVOID data = MapViewOfFile(
            hMapping,
            FILE_MAP_READ,
            0,
            0,
            0
        );

        if (!data)
        {
            CloseHandle(hMapping);

            CloseHandle(hFile);

            errno = EPERM;

            perror("Failed to map view of file.\n");

            return output;
        }

        output._filename = _strdup(__filename);
        output._content = (char*)data;
        output._seek = output._content;
        output._size = fileSize;
        output._hfile = hFile;
        output._hmapping = hMapping;

        return output;
    }

    inline static void readData(FilePtr __file, void* __write_on, unsigned int __bytes_to_read)
    {
        if ( (size_t)(__file->_seek - __file->_content + __bytes_to_read) > __file->_size)
        {
            errno = ESPIPE;

            perror("File read is out of bound");

            return;
        }

        memcpy(__write_on, __file->_seek, __bytes_to_read);

        __file->_seek += __bytes_to_read;
    }

    inline static void closeBinaryReader(FilePtr __file)
    {
        UnmapViewOfFile(__file->_content);

        CloseHandle(__file->_hfile);

        CloseHandle(__file->_hmapping);

        __file->_hfile = __file->_hmapping = NULL;

        free(__file->_filename);

        __file->_filename = NULL;
    }

    inline static unsigned int getSeekPos( FilePtr __file )
    {
        return __file->_seek - __file->_content;
    }

#else 
    #error "THIS SOURCE CODE CAN ONLY BE COMPILED FOR WINDOWS OS"

#endif


#endif
