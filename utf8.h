//#ifndef UTF8_H
//#define UTF8_H

unsigned char *toUtf8(unsigned char *ascii,int size);
bool isStartByte(unsigned char *sign);
unsigned char *makeUtf8(unsigned char* convertchar);
unsigned char *makeUTF8fromChar(unsigned int sign);




#ifdef WIN32
//#define ENABLE_SNDFILE_WINDOWS_PROTOTYPES  1
#define _CRT_SECURE_DEPRECATE_MEMORY
//#include <windows.h>
#include <memory.h>
#include <wchar.h>
// for gcc 4.3!!
//#include <cstdlib>
typedef wchar_t         m_char;
typedef unsigned char   m_typuchar;
#define m_string       string
#define m_wstring      wstring
#define m_strcpy       wcscpy
#define m_strncpy      wcsncpy
#define m_strcmp       wcscmp
#define m_sprintf      swprintf
#define m_printf       wprintf
#define m_strrchr      wcsrchr
#define m_strstr       wcsstr
#define m_strdup       wcsdup
#define m_strlen       wcslen
#define m_atoll        wtoll
#define m_fopen        _wfopen
#define m_cout         wcout
#define m_strcat       wcscat
#define m_ctomb         wctomb
#define m_gets          fgetws
#define M_STR(text)      L##text
//wctomb
#else
typedef char            m_char;
typedef unsigned char   m_typuchar;
#define m_string       string
#define m_wstring      wstring
#define m_strcpy       strcpy
#define m_strncpy      strncpy
#define m_strcmp       strcmp
#define m_sprintf      sprintf
#define m_printf       printf
#define m_strrchr      strrchr
#define m_strstr       strstr
#define m_strdup       strdup
#define m_strlen       strlen
#define m_atoll        atoll
#define m_cout         cout
#define m_fopen        fopen
#define m_strcat       strcat
 #define m_gets          fgets
#define M_STR(text)      text
#endif


/*
#ifdef WIN32
#define AE (unsigned char)142
#define ae (unsigned char)132
#define OE (unsigned char)153
#define oe (unsigned char)148
#define UE (unsigned char)154
#define ue (unsigned char)129
#define ss (unsigned char)225
#endif

#ifdef __APPLE__
*/
#define AE (unsigned char)128
#define ae (unsigned char)138
#define OE (unsigned char)133
#define oe (unsigned char)154
#define UE (unsigned char)134
#define ue (unsigned char)159
#define ss (unsigned char)167
//#endif

//! [ISO-8859-1 (Latin-1]
//! die ersten 256 Zeichen
//! sind Identsich mit Unicode
//! identifier 2Byte = 00;
enum{
    UNI_AE      = 196,//0xC4
    UNI_ae      = 228,//0xE4
    UNI_OE      = 214,//0xD6
    UNI_oe      = 246,//0xF6
    UNI_UE      = 220,//0xDC
    UNI_ue      = 252,//0xFC
    UNI_ss      = 223,//0xDF

    UNI_Agrave  = 192, //0xB4
    UNI_Aacute  = 193, //0xB4
    UNI_Acirc   = 194, //0xB4
    UNI_Atilde  = 195, //0xB4
    UNI_Auml    = 196, //0xB4
    UNI_Aring   = 197, //0xB4
    UNI_AElig   = 198, //0xB4
    UNI_Ccedil  = 199, //0xB4
    UNI_Egrave  = 200, //0xB4
    UNI_Eacute  = 201, //0xB4
    UNI_Ecirc   = 202, //0xB4
    UNI_Euml    = 203, //0xB4
    UNI_Igrave  = 204, //0xB4
    UNI_Iacute  = 205, //0xB4
    UNI_Icirc   = 206, //0xB4
    UNI_Iuml    = 207, //0xB4
    UNI_ETH     = 208, //0xB4
    UNI_Ntilde  = 209, //0xB4
    UNI_Ograve  = 210, //0xB4
    UNI_Oacute  = 211, //0xB4
    UNI_Ocirc   = 212, //0xB4
    UNI_Otilde  = 213, //0xB4
    UNI_Ouml    = 214, //0xB4
    UNI_times   = 215, //0xB4
    UNI_Oslash  = 216, //0xB4
    UNI_Ugrave  = 217, //0xB4
    UNI_Uacute  = 218, //0xB4
    UNI_Ucirc   = 219, //0xB4
    UNI_Uuml    = 220, //0xB4
    UNI_Yacute  = 221, //0xB4
    UNI_THORN   = 222, //0xB4
    UNI_szlig   = 223, //0xB4
    UNI_agrave  = 224, //0xB4
    UNI_aacute  = 225, //0xB4
    UNI_acirc   = 226, //0xB4
    UNI_atilde  = 227, //0xB4
    UNI_auml    = 228, //0xB4
    UNI_aring   = 229, //0xB4
    UNI_aelig   = 230, //0xB4
    UNI_ccedil  = 231, //0xB4
    UNI_egrave  = 232, //0xB4
    UNI_eacute  = 233, //0xB4
    UNI_ecirc   = 234, //0xB4
    UNI_euml    = 235, //0xB4
    UNI_igrave  = 236, //0xB4
    UNI_iacute  = 237, //0xB4
    UNI_icirc   = 238, //0xB4
    UNI_iuml    = 239, //0xB4
    UNI_eth     = 240, //0xB4
    UNI_ntilde  = 241, //0xB4
    UNI_ograve  = 242, //0xB4
    UNI_oacute  = 243, //0xB4
    UNI_ocirc   = 244, //0xB4
    UNI_otilde  = 245, //0xB4
    UNI_ouml    = 246, //0xB4
    UNI_divide  = 247, //0xB4
    UNI_oslash  = 248, //0xB4
    UNI_ugrave  = 249, //0xB4
    UNI_uacute  = 250, //0xB4
    UNI_ucirc   = 251, //0xB4
    UNI_uuml    = 252, //0xB4
    UNI_yacute  = 253, //0xB4
    UNI_thorn   = 254, //0xB4
    UNI_yuml    = 255 //0xB4

};

//! UNICODE
//! identifier 2Byte = 195;//C3
enum{
    UTF8_AE     = 132,//0x84
    UTF8_ae     = 164,//0xA4
    UTF8_OE     = 150,//0x96
    UTF8_oe     = 182,//0xB6
    UTF8_UE     = 156,//0x9C
    UTF8_ue     = 188,//0xBC
    UTF8_ss     = 159,//0x9F

    UTF8_Agrave = 128, //0xB4
    UTF8_Aacute = 129, //0xB4
    UTF8_Acirc  = 130, //0xB4
    UTF8_Atilde = 131, //0xB4
    UTF8_Auml   = 132, //0xB4
    UTF8_Aring  = 133, //0xB4
    UTF8_AElig  = 134, //0xB4
    UTF8_Ccedil = 135, //0xB4
    UTF8_Egrave = 136, //0xB4
    UTF8_Eacute = 137, //0xB4
    UTF8_Ecirc  = 138, //0xB4
    UTF8_Euml   = 139, //0xB4
    UTF8_Igrave = 140, //0xB4
    UTF8_Iacute = 141, //0xB4
    UTF8_Icirc  = 142, //0xB4
    UTF8_Iuml   = 143, //0xB4
    UTF8_ETH    = 144, //0xB4
    UTF8_Ntilde = 145, //0xB4
    UTF8_Ograve = 146, //0xB4
    UTF8_Oacute = 147, //0xB4
    UTF8_Ocirc  = 148, //0xB4
    UTF8_Otilde = 149, //0xB4
    UTF8_Ouml   = 150, //0xB4
    UTF8_times  = 151, //0xB4
    UTF8_Oslash = 152, //0xB4
    UTF8_Ugrave = 153, //0xB4
    UTF8_Uacute = 154, //0xB4
    UTF8_Ucirc  = 155, //0xB4
    UTF8_Uuml   = 156, //0xB4
    UTF8_Yacute = 157, //0xB4
    UTF8_THORN  = 158, //0xB4
    UTF8_szlig  = 159, //0xB4
    UTF8_agrave = 160, //0xB4
    UTF8_aacute = 161, //0xB4
    UTF8_acirc  = 162, //0xB4
    UTF8_atilde = 163, //0xB4
    UTF8_auml   = 164, //0xB4
    UTF8_aring  = 165, //0xB4
    UTF8_aelig  = 166, //0xB4
    UTF8_ccedil = 167, //0xB4
    UTF8_egrave = 168, //0xB4
    UTF8_eacute = 169, //0xB4
    UTF8_ecirc  = 170, //0xB4
    UTF8_euml   = 171, //0xB4
    UTF8_igrave = 172, //0xB4
    UTF8_iacute = 173, //0xB4
    UTF8_icirc  = 174, //0xB4
    UTF8_iuml   = 175, //0xB4
    UTF8_eth    = 176, //0xB4
    UTF8_ntilde = 177, //0xB4
    UTF8_ograve = 178, //0xB4
    UTF8_oacute = 179, //0xB4
    UTF8_ocirc  = 180, //0xB4
    UTF8_otilde = 181, //0xB4
    UTF8_ouml   = 182, //0xB4
    UTF8_divide = 183, //0xB4
    UTF8_oslash = 184, //0xB4
    UTF8_ugrave = 185, //0xB4
    UTF8_uacute = 186, //0xB4
    UTF8_ucirc  = 187, //0xB4
    UTF8_uuml   = 188, //0xB4
    UTF8_yacute = 189, //0xB4
    UTF8_thorn  = 190, //0xB4
    UTF8_yuml   = 191 //0xB4
};
