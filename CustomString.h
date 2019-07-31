#ifndef GS_CUSTOM_STRING_H
#define GS_CUSTOM_STRING_H

#include <iostream>

class CustomString
{
    
    char* body;   // String body
    int   length; // String length

public:

    // Constructors and destructor

    CustomString ( );                       // Empty string constructor
    CustomString (char ch);                 // Constructor with single character
    CustomString (const char* ch);          // char* string constructor
    CustomString (const CustomString& st);  // Copy string constructor
    CustomString (CustomString&& st);       // Move string constructor
    ~CustomString ( );                      // String destructor

    // Index value in String

    char  operator[] (int id) const;

    // Sets string value

    CustomString& operator= (const CustomString& st);

    // Move assignment operator
    CustomString& operator=(CustomString&& st);

    // Append to string

    CustomString& operator+= (const CustomString& st);

    // String concatenation

    friend CustomString operator+ (const CustomString& ls, const CustomString& rs);
    friend CustomString operator+ (const CustomString& ls, char                rs);
    friend CustomString operator+ (const CustomString& ls, const char*         rs);
    friend CustomString operator+ (char                ls, const CustomString& rs);
    friend CustomString operator+ (const char*         ls, const CustomString& rs);

    // String equality

    friend bool operator== (const CustomString& ls, const CustomString& rs);
    friend bool operator== (const CustomString& ls, char                rs);
    friend bool operator== (const CustomString& ls, const char*         rs);
    friend bool operator== (char                ls, const CustomString& rs);
    friend bool operator== (const char*         ls, const CustomString& rs);

    // String non-equality

    friend bool operator!= (const CustomString& ls, const CustomString& rs);
    friend bool operator!= (const CustomString& ls, char                rs);
    friend bool operator!= (const CustomString& ls, const char*         rs);
    friend bool operator!= (char                ls, const CustomString& rs);
    friend bool operator!= (const char*         ls, const CustomString& rs);

    // Stream operators

    friend std::ostream& operator<< (std::ostream& str, const CustomString& st);
    friend std::istream& operator>> (std::istream& str,       CustomString& st);

    // "next" functions

    CustomString& append (const CustomString& st);
    /* return 0 if two strings as equal
     * return 1 if first string is longer, or the first non-matching character is greater
     * return -1 if first string is shorter, or the first non-matching character is lowel */
    int compare (const CustomString& st);
    int len ( ) const;
    CustomString& resize (int size);
    CustomString& clear  ();
    void swap (CustomString& st);
    /* return the position of the 1st character, if successfully find a specific substring in the existing one
     * return -1 otherwise */
    int substr (const CustomString& st);
    CustomString& insert (const CustomString& st, int pos);
};

#endif // GS_CUSTOM_STRING_H
