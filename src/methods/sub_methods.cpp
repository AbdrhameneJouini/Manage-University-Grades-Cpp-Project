#include "../../inc/methods.h"
#include <fstream>

template <typename Var_type>
bool Valid_ID(Var_type ID, string fileName)
{

    ifstream Etudiant("../../data/base.text");
    return true;
}

bool Valid_Mail(string mail_)
{
    int at_sign_pos = mail_.find('@');
    if (at_sign_pos == -1)
    {
        return false;
    }
    /*
    since @ exists we need to create 2 substrings and check them
    ==> @ MUST NOT EXIST in these substrings (if it does then the user typed @ twice and did not respect the format)
    */
    string mail_part_1 = mail_.substr(0, at_sign_pos);
    string mail_part_2 = mail_.substr(at_sign_pos, mail_.size() - at_sign_pos);
    if (mail_part_1.find('@') != -1 || mail_part_2.find('@') != 1)
    {
        return false;
    }

    /*
    now the only thing to check for is that the second substring must be
    in 'zzze.xx' format
    */
    int pos_point = mail_part_2.find('.');
    if (pos_point == -1 || pos_point == mail_part_2.size() - 1)
    {
        return false;
    }
    return true;
}