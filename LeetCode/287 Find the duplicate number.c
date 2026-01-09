inline int findDuplicate(int* __ar, int __len) 
{
    char* tracker = (char*) calloc(__len, sizeof(char));

    const int* it = __ar;
    const int*const end = __ar + __len;

    while ( it < end )
    {
        if(tracker[*it] != 0 )
        {
            free(tracker);

            return *it;
        }

        // insert anything other than zero
        tracker[*it] = 'x';
        ++it;
    }

    // code will never reach here as per conditions given in
    // problem's description in leetcode
    free(tracker);

    return 0;
}