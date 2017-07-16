#include <lib.h>
inherit LIB_ROOM;

string CheckSign();

static void create() {
   room::create();
   SetShort("a plain room");
   SetLong("There is a sign in this plain room.");
   SetItems( ([
                "sign" : (: CheckSign :),
           ]) );
}


string CheckSign()
{
  string *languages;
  int i;
  
  languages = this_player()->GetLanguages();
  
  for(i=0;i < sizeof(languages);i++)
  {
  if(languages[i] == "Enlan")
  {
    return "The sign reads in a language you know.";
  }
  }
  return "You cannot understand the sign.";
}
