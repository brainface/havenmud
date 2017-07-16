/*  The 'set' verb.  For use with combat styles */
#include <lib.h>
#include <daemons.h>
inherit LIB_VERB;

string *Options = ({ "style", "owner", "captain", "swimming", "marriage", "crew", "surname", "language" });

static void create() {
  ::create();
  SetVerb("set");
  SetRules("STR to STR");
  SetErrorMessage("Set what to what?");
  SetHelp("Syntax:    'set style to STR' \n"
          "           'set owner to STR' \n"
          "           'set captain to STR' \n"
          "           'set crew to STR STR STR...' \n"
          "           'set swimming to on/off' \n"
          "           'set marriage to yes/no' \n"
          "           'set surname to STR' \n"
          "           'set language to STR' \n"
          "\nAllows the player to 'set' something.");
  }

mixed can_set_str_to_str(string verb, string style) {
  object ob = STYLES_D->GetStyle(style);
  if (member_array(verb, Options) == -1) {
    return "Set what to what?";
    }
  if (verb == "style") {
    if (style == "none") { return 1; }
    if (!ob) {
       return "Set style to what?";
       }
    if (!ob->CanStyle(this_player())) {
      return "You cannot seem to use that style.";
      }
    if (!this_player()->GetCombatStyleLevel(style)) {
      return "You do not know that style.";
     }
    }
  if (verb == "captain") {
  	ob = environment(this_player());
  	if (!ob || !vehiclep(ob)) return "But you are not in a vehicle!";
  	if (ob->GetOwner() != this_player()->GetKeyName())
  	  return "You don't seem to be the owner of this vessel.";
  	return 1;
  }
  if (verb == "owner") {
  	ob = environment(this_player());
  	if (ob->GetOwner() != this_player()->GetKeyName())
  	  return "You don't seem to be the owner here.";
  	return 1;
  }	
  if (verb == "swimming") {
    return 1;
  }
  if (verb == "crew") {
 	ob = environment(this_player());
  if (ob->GetOwner() == this_player()->GetKeyName())
  	return 1;
  return "You don't seem to be the owner here.";
  }
  if (verb == "surname") {
  	if (this_player()->GetSurname())
  		return "Your surname has already been set to " + this_player()->GetSurname();
  	return 1;
  }
  if (verb == "language") {
  	if (newbiep(this_player()))
  		return "Newbies cannot set their default language.";
  	if (this_player()->GetLanguageLevel(lower_case(style)) < 100)
  		return "You do not know the " + style + " language well enough to do that.";  	
  	return 1;
  }
  return 1;
}

mixed do_set_str_to_str(string verb, string style) {
  object env;
  if (verb == "style") {
    if (style == "none") { 
      this_player()->eventPrint("You stop using combat techniques.");
      this_player()->SetCombatStyle(0);
      return 1;
      }
    this_player()->SetCombatStyle(style);
    this_player()->eventPrint("Current combat style set to: " +
                              style);
    return 1;
  }
  if (verb == "captain") {
  	environment(this_player())->SetCaptain(style);
  	return 1;
  }
  if (verb == "owner") {
  	environment(this_player())->SetOwner(style);
  	return 1;
  }
  if (verb == "crew") {
  	environment(this_player())->SetCrew(explode(style, " "));
  	return 1;
  }
  if (verb == "swimming") {
    if (style == "on") { 
      this_player()->SetPermanentProperty("swimmer", 1);
      this_player()->eventPrint("You can now enter ocean rooms.  %^BOLD%^RED%^THIS IS DANGEROUS.%^RESET%^");
      return 1;
    }
    if (style == "off") {
      this_player()->RemovePermanentProperty("swimmer");
      this_player()->eventPrint("You are now safe from wandering into ocean rooms.");
      return 1;
    }
    this_player()->eventPrint("Set swimming to on or set swimming to off?");
    return 1;
  }
    if (verb == "marriage") {
    if (style == "yes") { 
      this_player()->SetProperty("marry", 1);
      this_player()->eventPrint("You can now be married.");
      return 1;
    }
    if (style == "no") {
      this_player()->RemoveProperty("marry");
      this_player()->eventPrint("You will now refuse marriage.");
      return 1;
    }
    this_player()->eventPrint("Set marriage to yes or set marriage to no?");
    return 1;
  }
    if (verb == "surname") {
    	this_player()->SetSurname(capitalize(style));
    	this_player()->SetShort("");
    	this_player()->eventPrint("You are now " + this_player()->GetShort() + ".");
    	CHAT_D->eventSendChannel("SET", "reports", this_player()->GetKeyName() + " has set surname \"" + style + "\".");
      return 1;
    }
    if (verb == "language") {
    	this_player()->SetPermanentProperty("defaultlanguage", style);
    	this_player()->eventPrint("You will now speak " + style + " by default.");
    	return 1;
    }
  return -1;
}

           

