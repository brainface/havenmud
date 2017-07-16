#include <lib.h>
#include <dirs.h>
#include <daemons.h>
inherit LIB_DAEMON;

int Level;
string Class;
string Town;
string *Religion;

mixed cmd(string args) {
  string letter, file;
  string *characters;
  string cl;
  mapping links;
  object target;
  string who;
  
  if (archp(this_player()) && args) {
    target = find_player(args);
    if (!target) {
      return "Cannot find " + args + " to list links.";
    }
    if (rank(target) > rank(this_player())) {
      return "Cannot list links for someone of higher rank.";
    }
  }
  if (!target) target = this_player();
  who = target->GetEmail();
  CHARACTER_D->CleanLinks();
  links = CHARACTER_D->GetLink(who);
  if (!links) {
    return "No links for that person registered!";
  }
  this_player()->eventPrint("Registered with email " + who);
  this_player()->eventPrint(sprintf("%-20s %-15s %-15s %-15s %-15s %-s", "Name", "Class", "Town", "Religion", "Level", "Days Til Purge"));
  characters = links["characters"];
  characters = sort_array(characters, 1);
  foreach(string person in characters) {
    file = save_file(person);
    unguarded( (: restore_object, file :) );
    if (!(cl = Class)) cl = "Classless";
    if (!immortal_exists(person)) {
      this_player()->eventPrint(sprintf("%-20s %-15s %-15s %-15s %-15s %-d", capitalize(person), cl, Town, Religion[0], Level,
             ((time() - (this_player()->GetLoginTime())) / 86400)));

    } else {
      this_player()->eventPrint(sprintf("%-20s %-15s", capitalize(person) , "Staff Member"));
    }
  }
  return 1;
}

string GetHelp(string u) {
  string tmp = "Syntax:     <links> \n\n"
               "Displays the character links registered to your email address along with some "
               "basic information about each character.\n";
  if (archp(this_player())) {
    tmp += "\nArch+ syntax:    <links PLAYER> \n\n"
           "Checks link info for a target player.  Player must be logged on.";
    }
  return tmp;
}
