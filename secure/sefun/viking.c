//      /adm/simul_efun/translate.c
//      from the Dead Souls Mudlib
//      translates a string into nonsense for non-proficient speakers
//      created by Descartes of Borg 930823
//      based on a speak function by Valodin@Dead Souls
#include <daemons.h>

string viking(string str) {
	string *words;
	string *Flubs = LANGUAGE_D->GetLanguage("viking");
	int fs, i, maxi;

	fs = sizeof(Flubs);
	words = explode(str, " ");
	for(i=0, maxi = sizeof(words); i < maxi; i++)
          words[i] = Flubs[random(fs)];
	return implode(words, " ");
    }
