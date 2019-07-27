#include "CustomString.h"

CustomString::CustomString () 
{
    length = 0;
    body   = new char[0];
}

CustomString::CustomString (char ch) 
{
    length = 1;
    body   = new char(ch);
}

CustomString::CustomString (const char* ch) 
{
    if (ch) {

        int n = 0;

        while (ch[n] != '\0') { 
            n++;
        }

        length = n;
        body   = new char[n];

        for (int i = 0; i < n; i++) {
            body[i] = ch[i];
        }

    } else {
        length = 0;
        body   = new char[0];
    }
}

CustomString::CustomString (const CustomString& st) 
{
    length = st.len();
    body   = new char[length];

    for (int i = 0; i < length; i++) {
        body[i] = st[i];
    }
}

CustomString::~CustomString ( ) 
{
    delete[] body;
}

char CustomString::operator[] (int id) const
{
    if (id >= length) throw 1;
    return body[id];
}

// Sets string value

CustomString& CustomString::operator= (const CustomString& st) 
{
    if(this == &st) {
        return *this;
    }

    delete[] body;

    length = st.len();
    body   = new char[length];

    for (int i = 0; i < length; i++) {
        body[i] = st[i];
    }

    return *this;
}

// Append to string

CustomString& CustomString::operator+= (const CustomString& st) 
{
    int   leng = length + st.len();
    char* data = new char[leng];

    for (int i = 0; i < length; i++) {
        data[i] = body[i];
    }

    for (int i = 0; i < st.len(); i++) {
        data[length + i] = st[i];
    }

    delete[] body;

    length = leng;
    body   = data;

    return *this;    
}

// String concatenation

CustomString operator+ (const CustomString& ls, const CustomString& rs) 
{
    int   llen = ls.len();
    int   rlen = rs.len();

    char* data = new char[llen + rlen];

    for (int i = 0; i < llen; i++) {
        data[i] = ls[i];
    }

    for (int i = 0; i < rlen; i++) {
        data[llen + i] = rs[i];
    }

    return CustomString(data);
}

CustomString operator+ (const CustomString& ls, char rs) 
{
    return ls + CustomString(rs);
}

CustomString operator+ (const CustomString& ls, const char* rs) 
{
    return ls + CustomString(rs);
}

CustomString operator+ (char ls, const CustomString& rs) 
{
    return CustomString(ls) + rs;
}

CustomString operator+ (const char* ls, const CustomString& rs) 
{
    return CustomString(ls) + rs;
}

// String equality

bool operator== (const CustomString& ls, const CustomString& rs)
{
    if(ls.len() != rs.len()) return false;

    for (int i = 0; i < ls.len(); i++) {
        if (ls[i] != rs[i]) return false;
    }

    return true; 
}

bool operator== (const CustomString& ls, char rs) 
{
    return (ls == CustomString(rs));
}

bool operator== (const CustomString& ls, const char* rs) 
{
    return (ls == CustomString(rs));
}

bool operator== (char ls, const CustomString& rs) 
{
    return (CustomString(ls) == rs);
}

bool operator== (const char* ls, const CustomString& rs) 
{
    return (CustomString(ls) == rs);
}

// String non-equality

bool operator!= (const CustomString& ls, const CustomString& rs) 
{
    return !(ls == rs);
}

bool operator!= (const CustomString& ls, char rs) 
{
    return !(ls == rs);
}

bool operator!= (const CustomString& ls, const char* rs) 
{
    return !(ls == rs);
}

bool operator!= (char ls, const CustomString& rs) 
{
    return !(ls == rs);
}

bool operator!= (const char* ls, const CustomString& rs) 
{
    return !(ls == rs);
}

// Stream operators

std::ostream& operator<< (std::ostream& str, const CustomString& st) 
{
    if (st.len() > 0) {
        for (int i = 0; i < st.len(); i++) {
            str << st[i];
        }
    } else {
        str << "";
    }

    return str;
}

std::istream& operator>> (std::istream& str, CustomString& st) 
{
    char* c = new char[255];

    str >> c;
    st = CustomString(c);

    delete[] c;
    
    return str;
}

// "next" functions

CustomString& CustomString::append (const CustomString& st)
{
    int   leng = length + st.len();
    char* data = new char[leng];

    for (int i = 0; i < length; i++) {
        data[i] = body[i];
    }

    for (int i = 0; i < st.len(); i++) {
        data[length + i] = st[i];
    }

    delete[] body;

    length = leng;
    body   = data;

    return *this;  
}

int CustomString::compare (const CustomString& st) {

    if(this == &st) return 0;

    if (length > st.length) return 1;
    if (length < st.length) return -1;

    for (int i = 0; i < length; i++) {
        if (body[i] > st[i]) return 1;
        if (body[i] < st[i]) return -1;
    }

    return 0;
}

int CustomString::len ( ) const 
{
    return length;
}

CustomString& CustomString::resize (int s) 
{
    char* data = new char[s];
    int   cont = length < s ? length : s;

    for (int i = 0; i < cont; i++) {
        data[i] = body[i];
    }

    delete[] body;

    length = s;
    body   = data;

    return *this;  
}

CustomString& CustomString::clear () 
{
    delete[] body;

    length = 0;
    body   = new char[0];

    return *this;  
}

void CustomString::swap (CustomString& st) 
{
    int   leng = st.len();
    char* data = st.body;

    st.length = length;
    st.body   = body;

    length = leng;
    body   = data;
}

int CustomString::substr (const CustomString& st)
{
    if (length < st.length) return -1;

    for (int i = 0; i < length; i++) {
        if (body[i] == st.body[0]) {
            if (length - i < st.length) return -1;

            bool flag = true;
            for (int j = i + 1; j < st.length; j++) {
                if (body[j] != st.body[j - i]) {
                    flag = false;
                    break;       
                }
            }
            if (flag) return i;
        }
    }

    return -1;
}

CustomString& CustomString::insert (const CustomString& st, int pos) 
{
    if (pos > length) throw 1;

    int   leng = length + st.len();
    char* data = new char[leng];

    for (int i = 0; i < leng; i++) {
        if (i < pos || i >= pos + st.len()) {
            data[i] = body[i < pos ? i : i - st.len()]; 
        } else {
            data[i] = st[i - pos];
        }
    }

    delete[] body;

    length = leng;
    body   = data;

    return *this;  
}

void CustomString::move (CustomString& st)
{
    length = st.length;
    body   = st.body;

    st.body   = nullptr;
    st.length = 0;
}
