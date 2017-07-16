//      /adm/simul_efun/translate.c
//      from the Dead Souls Mudlib
//      translates a string into nonsense for non-proficient speakers
//      created by Descartes of Borg 930823
//      based on a speak function by Valodin@Dead Souls
#include <daemons.h>

string translate(string str, int prof, string lang) {
    if( prof >= 100 ) return str;
    else {
	string *words;
	string *Flubs = LANGUAGE_D->GetLanguage(lang);
	int fs, i, maxi;

	fs = sizeof(Flubs);
	words = explode(str, " ");
	for(i=0, maxi = sizeof(words); i < maxi; i++)
	  if( random(100) >= prof ) words[i] = Flubs[random(fs)];
	return implode(words, " ");
    }
}
