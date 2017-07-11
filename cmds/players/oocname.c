/*  Changes their OOC Name */
#include <lib.h>
#include <config.h>
#include <daemons.h>
inherit LIB_DAEMON;
inherit LIB_HELP;

mixed cmd(string what) {
  string *name;
  int count = 0;

  if (this_player()->GetProperty("restrict_oocname"))
   {
      return "You have been restricted from changing your OOC name.";
   }
  if (what == "0")
  {
    this_player()->SetOOCName(0);
    return "Your OOC name has been reset.";
  }
  if (!what) return ("Your name is " + this_player()->GetOOCName());
  what = strip_colours(what);
  if (creatorp(this_player())) return "Immortals are forbidden.";
  if ((user_exists(lower_case(what)) || find_living(lower_case(what))) &&
       this_player()->GetKeyName() != lower_case(what)) {
    return "That name is taken.";
 }
  foreach(object user in filter(users(), 
             (: ($1 != this_player()) && ($1->GetOOCName() ) :))) {
    if (lower_case(what) == lower_case(user->GetOOCName()))  {
	    return "That name is taken.";
      }
  }
 if (strlen(what) > MAX_USER_NAME_LENGTH) return "Too long!";

 name = explode(what, "");
 foreach(string letter in name) {
   if (!regexp(lower_case(letter), "[-a-z ']") ) count++;
 }   
 if (count != 0) return "Characters allowed: a-Z ' -.";
 if (strsrch(lower_case(what), "duuk") != -1) return "No little Duukies.";
 if(lower_case(what) == "a shadow" ||
    lower_case(what) == "a presence") {
    return "That is not allowed.";
 }
 CHAT_D->eventSendChannel("OOCName", "reports", capitalize(this_player()->GetKeyName())+" has changed "
                          + possessive(this_player()->GetGender()) +" OOC name to "+what+".");
 return "Your new OOCName is " + (this_player()->SetOOCName(capitalize(what)));
 }

string GetHelp(string blah) {
  return "Syntax:         \"oocname STRING\"  \n"
         "                \"oocname\"         \n\n"
         "Used without argument, sets your out of character name.\n"
         "Used with a string, sets your OOC Name to that.\n\n"
         "  You may not use the name of any existing player.\n"
         "  You may not use anything vaguely inappropriate.\n"
         "  Immortals can tell who you are.  We will remove your\n"
         "  ooc line permanently, or remove the oocname option, if\n"
         "  it is abused.";
 }

