/*    /adm/sefun/pointers.c
 *    from Dead Souls
 *    sefuns for testing things
 *    created by Descartes of Borg 940213
 */

#include <dirs.h>
#include <config.h>
#include "sefun.h"
#include <council.h>
#include <daemons.h>
int sagep(object);
int musep(object);


int archp(object ob) {
    string str;

    if(!ob) ob = previous_object();
    if(!creatorp(ob)) return 0;
    if (adminp(ob)) return 1;
    return (member_group(ob, "ASSIST") || member_group(ob, "SECURE"));
}

varargs int creatorp(object ob) {
    if(!ob) ob = previous_object();
    if(!ob || !userp(ob)) return 0;
    return !(strsrch(file_name(ob), DIR_CRES));
}

varargs int noncreatorp(object ob) {
	return !creatorp(ob);
}

int testcharp(object ob) {
  if (!ob) ob = previous_object();
  return ob->GetTestChar();
}

int immortalp(object ob) {
	if (!ob) ob = previous_object();
	if (!creatorp(ob)) return 0;
	return (!ob->GetAngel());
}

int angelp(object ob) {
	if (!ob) ob = previous_object();
	if (!creatorp(ob)) return 0;
	return ob->GetAngel();
}


int assistp(object ob) {
    string str;

    if(!ob) ob = previous_object();
    if(!creatorp(ob)) return 0;
    if (adminp(ob) || securep(ob)) return 1;
    return (member_group(ob, "ASSIST") );
}

int spiritp(object ob) {
  if (!ob) ob = previous_object();
  return musep(ob);
}

int securep(object ob) {
    string str;

    if(!ob) ob = previous_object();
    if(!creatorp(ob)) return 0;
    if (adminp(ob)) return 1;
    return (member_group(ob, "SECURE") );
}

int metap(object ob) { 
  return securep(ob);
}

int adminp(object ob) {
    string str;

    if(!ob) ob = previous_object();
    if(!creatorp(ob)) return 0;
    return (member_group(ob, "ADMIN") );
}

int duukp(object ob) {
    string str;

    if(!ob) ob = previous_object();
    return (base_name(ob) == DIR_CRES "/d/duuk" );
}

int melp(object ob) {
    string str;

    if(!ob) ob = previous_object();
    return (base_name(ob) == DIR_CRES "/m/melchezidek" );
}

int thoinp(object ob) {
  return 0;
}

int laoisep(object ob) {
    string str;
   if(!ob) ob = previous_object();
    return (base_name(ob) == DIR_CRES "/l/laoise" );
}
int zaxanp(object ob) {
    string str;
    if(!ob) ob = previous_object();
    return (base_name(ob) == DIR_CRES "/z/zaxan" );
}

int musep(object ob) {
    string str;

    if(!ob) ob = previous_object();
    if(!creatorp(ob)) return 0;
    if (archp(ob)) return 1;
    return (member_group(ob, "MUSE") );
}

int sagep(object ob) { return musep(ob); }

int hiddenp(object ob) {
    if(!objectp(ob)) error("Bad argument 1 to hiddenp().\n");
    return !find_object(file_name(ob));
}


varargs int playerp(object ob) {
    if( !ob ) ob = previous_object();
    return (userp(ob) && !creatorp(ob));
}

varargs int newbiep(object ob) {
    if( !ob ) ob = previous_object();
    if (!userp(ob)) return 0;
    return (!creatorp(ob) && ((int)ob->GetLevel() <= MAX_NEWBIE_LEVEL));
}

int high_mortalp(object ob) {
    if(!ob) ob = previous_object();
    if (!userp(ob)) return 0;
    return (!creatorp(ob) && ((int)ob->GetLevel() > 24));
}


int legendp(object ob) {
	if (!ob) ob = previous_object();
	if (!userp(ob)) return 0;
	return (!creatorp(ob) && ((int)ob->GetLevel() > 49));
}

int avatarp(object ob) {
    if( !ob ) ob = previous_object();
    if (!userp(ob)) return 0;
    return (!creatorp(ob) && (int)ob->GetLevel() > 99);
}

int demigodp(object ob) {
    if( !ob ) ob = previous_object();
    if (!userp(ob)) return 0;
    return (!creatorp(ob) && (int)ob->GetLevel() > 249);
}

int epicp(object ob) {
    if( !ob ) ob = previous_object();
    if (!userp(ob)) return 0;
    return (!creatorp(ob) && (int)ob->GetLevel() >= 400);
}


int rank(object ob) {
	if (!ob) ob = previous_object();
	if (!userp(ob))    return 1;
	if (duukp(ob))     return 10;
	if (zaxanp(ob))    return 9;
	if (laoisep(ob))   return 8;
	if (melp(ob))      return 7;	
	if (adminp(ob))    return 7;
	if (securep(ob))   return 6;
	if (assistp(ob))   return 5;
	if (musep(ob))     return 4;
	if (immortalp(ob)) return 3;
	if (angelp(ob))    return 2;
	if (playerp(ob))   return 1;
	return 1;
}

string string_rank(int rank) {
    switch(rank) {
	case 1: 
	    return "Player";
	    break;
	case 2:
	    return "Angel";
	    break;
	case 3:
	    return "Immortal";
	    break;
	case 4:
	    return "Muse";
	    break;
	case 5:
	    return "Arch-Angel";
	    break;
	case 6:
	    return "Metatron";
	    break;
	case 7:
	    return "Melchezidek";
	    break;
	case 8:
	    return "Laoise";
	    break;
	case 9:
	    return "Zaxan";
	    break;
  case 10:
      return "Duuk";
      break;
  default:
    return "Not a number 1-10!";
  }
}

int vehiclep(object ob) {
  if (!ob) ob = previous_object();
  if (ob->GetProperty("PROP_VEHICLE")) return 1;
  return 0;
}

int greatermusep(object ob) { return sagep(ob); }
