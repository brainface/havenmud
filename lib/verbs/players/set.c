/*  The 'set' verb.  For use with combat styles */
#include <lib.h>
#include <daemons.h>
inherit LIB_VERB;

string *Options = ({ "owner", "captain", "swimming", "marriage", "crew", "surname", "language", "status", "prompt", "autosave", "accessibility"});

static void create() {
  ::create();
  SetVerb("set");
  SetRules("STR to STR");
  SetErrorMessage("Set what to what?");
  SetHelp("Syntax:    "
          "           'set owner to STR' \n"
          "           'set captain to STR' \n"
          "           'set crew to STR STR STR...' \n"
          "           'set swimming to on/off' \n"
          "           'set marriage to yes/no' \n"
          "           'set surname to STR' \n"
          "           'set language to STR' \n"
          "           'set status to full/normal/off\n"
          "           'set prompt to on/off\n"
          "           'set autosave to quiet'\n"
          "           'set accessibility to on/off'\n"
          "\nAllows the player to 'set' something.");
  }

mixed can_set_str_to_str(string verb, string style) {
  object ob;
  if (member_array(verb, Options) == -1) {
    return "Set what to what?";
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
  if (verb == "status") {
    if (style != "full" && style != "normal" && style != "off") 
      return "set status to full, or set status to normal, or set status to off?";
  return 1;
  }
  if (verb == "prompt") {
  	if (style == "on") return 1;
  	if (style == "off") return 1;
  	return "Set prompt to on or set prompt to off?";
  } 
	if (verb == "autosave") {
		if (style == "quiet") return 1;
		return "Set autosave to quiet to toggle spammy autosave.";
	}
  return 1;
}

mixed do_set_str_to_str(string verb, string style) {
  object env;
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
    if (verb == "status") {
      this_player()->SetPermanentProperty("status", style);
      this_player()->eventPrint("You will now display the " + style + " status option.");
      return 1;
    }
    if (verb == "prompt") {
  		if (style == "on") { 
  			this_player()->SetPlayerPrompt(">");
  			this_player()->eventPrint("Prompt returned to normal.");
  			return 1;
  		}
  		if (style == "off") {
  			this_player()->SetPlayerPrompt("");
  			this_player()->eventPrint("Prompt disabled.");
  			return 1;
  		}
  }
  if (verb == "autosave") {
  	if (this_player()->GetProperty("no_autosave_spam")) {
  		this_player()->RemovePermanentProperty("no_autosave_spam");
  		this_player()->eventPrint("Autosave will be spammy again.");
  	} else {
  		this_player()->SetPermanentProperty("no_autosave_spam", 1);
  		this_player()->eventPrint("Autosave will do its job quietly now.");
  	}
  	return 1;
  }
  if (verb == "accessibility") {
      switch(style) {
        case "on":
            if (creatorp(this_player())) {
                this_player()->SetProperty("accessibility_mode", 1);
            } else {
                this_player()->SetPermanentProperty("accessibility_mode", 1);
            }
            this_player()->eventPrint("Accessibility mode enabled.");
            break;
        case "off":
            if (creatorp(this_player())) {
                this_player()->RemoveProperty("accessibility_mode");
            } else {
                this_player()->RemovePermanentProperty("accessibility_mode");
            }
            this_player()->eventPrint("Accessibility mode disabled.");
            break;
        default:
            this_player()->eventPrint("You can set accessibility to on or off");
            break;
      }
      return 1;
  }	
  return -1;
}

           

