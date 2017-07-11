#include <save.h>
#include <lib.h>
#define BADWORD "<BadWord[TM]>"
inherit LIB_DAEMON;

static void create() {
  ::create();
  SetNoClean(1);
}

string *BadWords = ({ "shit", "fuck", "pussy", 
                      "cock", "dick", "bitch",
                      "cunt", "asshole", "nigger",
                      "fag", 
                   });

string *Censored = ({ "ooc", "dc", "ds", "time" });

string* GetBadWords() { return distinct_array(BadWords); }
string* GetCensored() { return copy(Censored); }


string* AddBadWord(mixed str) {
  if (!securep(this_player())) error("No permission to AddBadWord().");
  if (!stringp(str) && !arrayp(str)) error("Bad argument to AddBadWord().  Must be a string or string array.");
  if (stringp(str)) str = ({ str });
  BadWords = distinct_array(BadWords += str);
  unguarded( (: save_object, SAVE_CENSOR :) );
  return copy(BadWords);
}

string* AddCensored(mixed str) {
  if (!securep(this_player())) error("No permission to AddCensored().");
  if (!stringp(str) && !arrayp(str)) error("Bad argument to AddCensored().  Must be a string or string array.");
  if (stringp(str)) str = ({ str });
  Censored = distinct_array(Censored += str);
  return copy(Censored);
}

string* RemoveBadWord(mixed str) {
  if (!securep(this_player())) error("No permission to RemoveBadWord().");
  if (!stringp(str) && !arrayp(str)) error("Bad argument to RemoveBadWord().  Must be a string or string array.");
  if (stringp(str)) str = ({ str });
  BadWords = distinct_array(BadWords -= str);
  return copy(BadWords);
}

string* RemoveCensored(mixed str) {
  if (!securep(this_player())) error("No permission to RemoveCensored().");
  if (!stringp(str) && !arrayp(str)) error("Bad argument to RemoveCensored().  Must be a string or string array.");
  if (stringp(str)) str = ({ str });
  Censored = distinct_array(Censored -= str);
  return copy(Censored);
}

string doCensor(string str) {
  int a;

  foreach (string word in BadWords) {
    if (strsrch(lower_case(str), lower_case(word)) == -1) continue;
    while ((a = strsrch(lower_case(str), lower_case(word))) != -1) {
      if (!a) {
      str = BADWORD + str[(a+sizeof(word))..(sizeof(str)-1)];
      } else {
      str = str[0..(a-1)] + BADWORD + str[(a+sizeof(word))..(sizeof(str)-1)];
      }
    }
  }
  return str;
}
