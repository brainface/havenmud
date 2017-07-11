/* A shiny new describe command
 * Goes nicely with the shiny new
 * describe daemon, yes?
 * Duuk
 *
 * data[0] = eyes
 * data[1] = hair
 * data[2] = skin
 * data[3] = skin description
 * data[4] = extra data
 */
#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;
#include <description.h>
string GetHelp(string);

int cmd(string args) {
        string thing, value;
        int t;
        mapping options;
        string *data = this_player()->GetLongDaemonData();
        object who = this_player();
        if (!args) {
                 who->eventPrint("You must <describe THING as WHAT>.  Try again.");
                 who->eventPrint(GetHelp(who->GetRace()));
                 return 1;
                }
        if (creatorp(who)) {
                who->eventPrint("You describe yourself as a dumbass.  Nice job.");
                who->eventPrint(GetHelp(args));
                return 1;
                } 
        if (sscanf(args, "%s as %s", thing, value) != 2 && args != "extra" && args != "clear" ) {       
                who->eventPrint("You must <describe THING as WHAT>.  Try again.");
                who->eventPrint(GetHelp(who->GetRace()));
                return 1;
        }
        if (args == "extra") thing = "extra";
        if (args == "clear") thing = "clear";

        // clear custom desc
        if (thing == "clear") {
          who->SetExternalDesc("$N is nondescript.");
          who->eventPrint("Your description will now be the default for your race and features!");
          return 1;
        }    
        
        // custom descriptions
        if (thing == "me" || thing = "custom") {
          if(strlen(value) > 2000) {
            who->eventPrint("That description is " + strlen(value) + " characters. Please use under 2000.");
            return 1;
          }
          CHAT_D->eventSendChannel("STORY","reports",
            capitalize(who->GetKeyName()) + " has set their description to " 
            + value);
          who->SetExternalDesc(value);
          who->eventPrint("You have set your description to: " + who->GetExternalDesc());
          who->eventPrint("Please remember all description changes are logged. Don't be evil.");
          return 1;
        }
        
        switch(thing) {
          case "eyes":
            t = 0;
            options = Eyes;
            break;
          case "hair":
            t = 1;
            options = Hair;
            break;
          case "skintone":
            t = 2;
            options = SkinTone;
            break;
          case "skintype":
            t = 3;
            options = SkinType;
            break;
          case "extra":
            t = 4;
            options = ExtraData;
            value = ExtraData[who->GetRace()];
            break;
          default:
            who->eventPrint( "You must describe either your eyes, hair, skintone, "
                   "skintype, or extra.  See \"help describe\" for available lists.");
            return 1;
            break;
          }
        if (data[t]) {
                who->eventPrint("Sorry, but your " + thing + " has already been set to "
                       + data[t] + ".");
                return 1;
                }
  if (!sizeof(options[who->GetRace()])) {
        who->eventPrint("Your race may not set a value for " + thing + ".");
        return 1;
  }
  if (t != 4)
  if (member_array(value, options[who->GetRace()]) == -1) {
        who->eventPrint("Sorry, but the options for your race are " +
             conjunction(options[who->GetRace()], "or") + ". Please use <describe "
             "WHAT as VALUE> using one of those values for your " + thing);
        return 1;
  }
  data[t] = value;
  this_player()->SetLongDaemonData(data);
  who->eventPrint(capitalize(thing) + " has been set!");
  return 1;
}

string GetHelp(string str) {
        string tmp = ""; string race;
        if (str == "describe") {
        tmp +=  "Syntax:       describe <WHAT> as <VALUE> \n" ;
        tmp +=  "              describe\n";
        tmp +=  "          ie: describe eyes as blue\n\n" ;
        tmp +=  "Use this command to list options and set options for "
          "your character description.  You must have done this "
          "prior to level 8, or you will no longer be able to "
          "advance. To see your options, use \"describe\" without "
          "arguments.\n\n";
        tmp +=  "You may also: describe me as <DESCRIPTION> \n";
        tmp +=  "          or: describe clear \n";
        tmp +=  "to provide your character with a more detailed ";
        tmp +=  "custom description at any time. The clear option ";
        tmp +=  "will reset your description to the default values.";
  return tmp;
  }                   
  if (str == "all") {
        tmp +=  "Options for \"eyes\" are: \n" ;
        foreach(race in keys(Eyes)) {
                tmp +=  pluralize(race) + " : " + conjunction(Eyes[race], "or") + "\n" ;
        }
        tmp += "\nOptions for \"hair\" are: \n";
        foreach(race in keys(Hair)) {
                tmp += pluralize(race) + " : " + conjunction(Hair[race], "or") + "\n";
        }
        tmp += "\nOptions for \"skintone\" are: \n";
        foreach(race in keys(SkinTone)) {
                tmp += pluralize(race) + " : " + conjunction(SkinTone[race], "or") + "\n";
        }
        tmp += "\nOptions for \"skintype\" are: \n";
        foreach(race in keys(SkinType)) {
                tmp += pluralize(race) + " : " + conjunction(SkinType[race], "or") + "\n";
        }
        tmp += "\nTo set your \"extra\" string, just use \"describe extra\".";
        tmp += "\nIn addition to standard features, you may always \"describe "
          "custom as <customdescription>\": This will replace the default "
          "description with whatever you write. Unlike other features, you may "
          "change this description as the game progresses whenever you wish.";
        return tmp;
}
  race = str;
  if (member_array(race, keys(Eyes)) == -1) {
        return "No options for race " + race + ".";
        }
  tmp +=  "Options for \"eyes\" are: " ;
  tmp +=  pluralize(race) + " : " + conjunction(Eyes[race], "or") + "\n" ;
        tmp += "\nOptions for \"hair\" are: ";
        tmp += pluralize(race) + " : " + conjunction(Hair[race], "or") + "\n";
        tmp += "\nOptions for \"skintone\" are: ";
        tmp += pluralize(race) + " : " + conjunction(SkinTone[race], "or") + "\n";
        tmp += "\nOptions for \"skintype\" are: ";
  tmp += pluralize(race) + " : " + conjunction(SkinType[race], "or") + "\n";
  tmp += "\nThe extra data for " + pluralize(race) + " is " + ExtraData[race];
        return tmp;
}

