#include <iostream>
#include "utf8.h"

using namespace std;



//utf8Result[0]   = 0;
//utf8Result[1]   = 0;
//startByte[0]    = 0;
//startByte[1]    = 0;




//! strlen von asci darf nicht 0 sein sonst memory leak!!
//! size is optional not used at the moment!
unsigned char *toUtf8(unsigned char *ascii,int size)
{
    unsigned char *fromUtfChar = NULL;
    unsigned char *returnchar = NULL;
    bool charsOk = true;
    if(size == 0)
        size = m_strlen((m_char*)ascii);
    int y =0;
    for(int i= 0; i < size; i++)
    {
        if(ascii[i] > 127)
        {
            i = size;
            //cout << "groesser 127 !!!" << endl;
            if(!(isStartByte(ascii+y)))
            {
                //printf("Sign: %d\n", (unsigned char*)ascii[i]);
                fromUtfChar = makeUtf8(ascii);
                charsOk = false;
            }
        }
        y++;
    }
    //! damit kein invalid free auftaucht:!!
    //cout << "charsOk: " << charsOk << endl;

    if(fromUtfChar)
    {
        int len = m_strlen((m_char*)fromUtfChar);
        if(len > 0)
        {
            returnchar = new unsigned char[len+1];
            for (int i= 0; i<len; i++)
                returnchar[i] = fromUtfChar[i];
            returnchar[len] = 0;
        }
        if(fromUtfChar)
        {
            delete []fromUtfChar;
            fromUtfChar=NULL;
        }


    }

    else
    {
        returnchar = new unsigned char[size+1];
        if(size >0)
        {
            for (int i=0; i<size; i++)
                returnchar[i] = ascii[i];
            returnchar[size]=0;
        }
    }
    return returnchar;
}

bool isStartByte(unsigned char *sign)
{
    bool startbyte = false;
    unsigned char *pointer = sign;
    //printf("Bytes: %d %d\n", pointer[0],pointer[1]);
    //! test auf 2 Byte Sequenz
    if(((pointer[0] > 0xC1) && (pointer[0] < 0xE0)) && ((pointer[1] > 127) && (pointer[1] < 192)))
    {
        startbyte = true;
    }
    //! test auf 3 Byte Sequenz
    if(  ( (pointer[0] > 0xDF)&&(pointer[0]< 0xF0) ) && ( (pointer[1] > 127)&&(pointer[1] < 192) )  )
    {
        startbyte = true;
    }
    //! test auf 4 Byte Sequenz
    if(  ( (pointer[0] > 0xEF) && (pointer[0] < 0xF5) )&& ( (pointer[1] > 127)&&(pointer[1] < 192) )  )
    {
        startbyte = true;
    }
    return startbyte;

}

//! not Tested!
unsigned int findUTFStartByte(unsigned char *signs)
{

    unsigned int startByte[2];
    int numberOfStartBytes = 0;
    int startBytePosition = -1;
    //! startbyte C2(194) wird ignoriert da identisch mit UNICODE
    for(unsigned int i=0; i< m_strlen((m_char*)signs); i++)
    {
        if((signs[i] > 0xC2) && (signs[i] < 0xE0))
        {
            startBytePosition = i;
            numberOfStartBytes = 1;
            m_printf(M_STR("possible 2 Byte Startsequenz found at %d\n"),i);
        }
        if((signs[i] > 0xDF) && (signs[i] < 0xF0))
        {
            startBytePosition = i;
            numberOfStartBytes = 1;
            m_printf(M_STR("possible 3 Byte Startsequenz found at %d\n"),i);
        }
        if((signs[i] > 0xEF) && (signs[i] < 0xF5))
        {
            startBytePosition = i;
            numberOfStartBytes = 3;
            m_printf(M_STR("possible 4 Byte Startsequenz found at %d\n"),i);
        }
    }
    startByte[1]=startBytePosition;
    startByte[0]=numberOfStartBytes;
    return *startByte;
}

unsigned char *makeUtf8(unsigned char* convertchar)
{
    unsigned char *utf8char = NULL;
    int size = m_strlen((m_char*)convertchar);
    //! 21 BYTESLOST:
    utf8char = new unsigned char[size*2+1];
    int utfcounter =0;
    for(int i=0; i<size*2+1; i++)
        utf8char[i]= 0;
    for(int y = 0; y < size ; y++)
    {
        if(convertchar[y] > 127)
        {
            unsigned char *make = makeUTF8fromChar(convertchar[y]);
            utf8char[utfcounter]= make[0];
            utfcounter++;
            utf8char[utfcounter]  =   make[1];
            //printf("utf8char %d ", convertchar[y]);
            //printf("utf8char %c\n", utf8char[y]);
        }
        else
            utf8char[utfcounter]  =   convertchar[y];
        utfcounter++;
    }
    utf8char[utfcounter] =0;
    return utf8char;
}

unsigned char *makeUTF8fromChar(unsigned int sign)
{
    unsigned char utf8Result[2];
    if(sign < 192)
    {
        utf8Result[0] = 0xC2;
        utf8Result[1] = sign;
    }
    else
    {

        switch(sign)
        {
            //! die wichtigsten nach oben gestellt:
        case UNI_AE:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_AE;
            break;
        case UNI_ae:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_ae;
            break;
        case UNI_OE:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_OE;
            break;
        case UNI_oe:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_oe;
            break;
        case UNI_UE:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_UE;
            break;
        case UNI_ue:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_ue;
            break;
        case UNI_ss:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_ss;
            break;


        case UNI_Agrave:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Agrave;
            break;
        case UNI_Aacute:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Aacute;
            break;
        case UNI_Acirc:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Acirc;
            break;
        case UNI_Atilde:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Atilde;
            break;
            //case UNI_Auml:
            //    utf8Result[0] = 0xC3;
            //    utf8Result[1] = UTF8_Auml;
            //    break;
        case UNI_Aring:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Aring;
            break;
        case UNI_AElig:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_AElig;
            break;
        case UNI_Ccedil:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Ccedil;
            break;
        case UNI_Egrave:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Egrave;
            break;
        case UNI_Eacute:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Eacute;
            break;
        case UNI_Ecirc:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Ecirc;
            break;
        case UNI_Euml:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Euml;
            break;
        case UNI_Igrave:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Igrave;
            break;
        case UNI_Iacute:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Iacute;
            break;
        case UNI_Icirc:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Icirc;
            break;
        case UNI_Iuml:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Iuml;
            break;
        case UNI_ETH:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_ETH;
            break;
        case UNI_Ntilde:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Ntilde;
            break;
        case UNI_Ograve:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Ograve;
            break;
        case UNI_Oacute:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Oacute;
            break;
        case UNI_Ocirc:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Ocirc;
            break;
        case UNI_Otilde:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Otilde;
            break;
            //case UNI_Ouml:
            //    utf8Result[0] = 0xC3;
            //    utf8Result[1] = UTF8_Ouml;
            //    break;
        case UNI_times:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_times;
            break;
        case UNI_Oslash:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Oslash;
            break;
        case UNI_Ugrave:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Ugrave;
            break;
        case UNI_Uacute:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Uacute;
            break;
        case UNI_Ucirc:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Uacute;
            break;
            //case UNI_Uuml:
            //    utf8Result[0] = 0xC3;
            //    utf8Result[1] = UTF8_Uuml;
            //    break;
        case UNI_Yacute:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_Yacute;
            break;
        case UNI_THORN:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_THORN;
            break;
            //case UNI_szlig:
            //    utf8Result[0] = 0xC3;
            //    utf8Result[1] = UTF8_szlig;
            //    break;
        case UNI_agrave:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_agrave;
            break;
        case UNI_aacute:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_aacute;
            break;
        case UNI_acirc:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_acirc;
            break;
        case UNI_atilde:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_atilde;
            break;
            //case UNI_auml:
            //    utf8Result[0] = 0xC3;
            //    utf8Result[1] = UTF8_auml;
            //    break;
        case UNI_aring:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_aring;
            break;
        case UNI_aelig:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_aelig;
            break;
        case UNI_ccedil:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_ccedil;
            break;
        case UNI_egrave:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_egrave;
            break;
        case UNI_eacute:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_eacute;
            break;
        case UNI_ecirc:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_ecirc;
            break;
        case UNI_euml:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_euml;
            break;
        case UNI_igrave:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_igrave;
            break;
        case UNI_iacute:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_iacute;
            break;
        case UNI_icirc:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_icirc;
            break;
        case UNI_iuml:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_iuml;
            break;
        case UNI_eth:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_eth;
            break;
        case UNI_ntilde:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_ntilde;
            break;
        case UNI_ograve:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_ograve;
            break;
        case UNI_oacute:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_oacute;
            break;
        case UNI_ocirc:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_ocirc;
            break;
        case UNI_otilde:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_otilde;
            break;
            //case UNI_ouml:
            //    utf8Result[0] = 0xC3;
            //    utf8Result[1] = UTF8_ouml;
            //    break;
        case UNI_divide:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_divide;
            break;
        case UNI_oslash:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_oslash;
            break;
        case UNI_ugrave:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_ugrave;
            break;
        case UNI_uacute:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_uacute;
            break;
        case UNI_ucirc:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_ucirc;
            break;
            //case UNI_uuml:
            //    utf8Result[0] = 0xC3;
            //    utf8Result[1] = UTF8_uuml;
            //    break;
        case UNI_yacute:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_yacute;
            break;
        case UNI_thorn:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_thorn;
            break;
        case UNI_yuml:
            utf8Result[0] = 0xC3;
            utf8Result[1] = UTF8_yuml;
            break;
        }
    }
    return utf8Result;
}

