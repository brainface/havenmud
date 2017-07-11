
/*  An Immortals listing cmd */
#include <lib.h>
#include <dirs.h>
inherit LIB_DAEMON;
inherit LIB_HELP;

private int Angel, Retired;
private string CapName;

static void create() {
  daemon::create();
  SetNoClean(1);
  }

mixed cmd(string rank) {
  string *Angels = ({ });
  string *Immortals = ({ });
  string *Muses = ({ });
  string *Assists = ({ });
  string *Secures = ({ });
  string *Admins = ({ });
  string *dirs = unguarded( (: get_dir, DIR_CRES  "/" :));
  foreach(string letter in dirs) {
    string *files = unguarded( (: get_dir, DIR_CRES  "/" + 
                                           letter + "/" :) );
    foreach(string file in files) {
        mixed immortal = unguarded( (: restore_object, 
                                       DIR_CRES  "/" + letter +
                                       "/" + file[0..strlen(file)-3] :) );
        if (!Retired) {
          Angels += ({ CapName });
          if (!Angel) { 
            Angels -= ({ CapName });
            Immortals += ({ lower_case(CapName) });
            }
          }
        }
      }  
  foreach(string immortal in Immortals) {
    if (member_group(immortal, "MUSE")) {
      Immortals -= ({ immortal });
      Muses += ({ immortal });
      }
    if (member_group(immortal, "ASSIST")) {
      Immortals -= ({ immortal });
      Assists += ({ immortal });
      }
    if (member_group(immortal, "SECURE")) {
      Immortals -= ({ immortal });
      Secures += ({ immortal });
      }
    if (member_group(immortal, "ADMIN")) {
         Immortals -= ({ immortal });
          Admins += ({ immortal });
       }
    }
  foreach(string person in Secures) {
    Secures -= ({ person });
    if (!member_group(person, "ADMIN"))
    Secures += ({ capitalize(person) });
    else Admins += ({ capitalize(person) });
    }
  foreach(string person in Admins) {
     Admins -= ({ person });
     Admins += ({ capitalize(person) });
     if (person == "skeeve") Admins -= ({ capitalize(person) });
     }
  foreach(string person in Assists) {
    Assists += ({ capitalize(person) });
    Assists -= ({ person });
    }
  foreach(string person in Muses) {
    Muses -= ({ person });
    Muses += ({ capitalize(person) });
    }
  foreach(string person in Immortals) {
    Immortals -= ({ person });
    Immortals += ({ capitalize(person) });
    if (person == "louise") Immortals -= ({ capitalize(person) });
    }
  message("system",
   "Admins          : " + implode(Admins, ", ") + "\n"
   "Secures         : " + implode(Secures, ", ") + "\n"
   "Arches          : " + implode(Assists, ", ") + "\n"
   "Senior          : " + implode(Muses, ", ") + "\n"
   "Terraformers    : " + implode(Immortals, ", ") + "\n"
   "Apprentices     : " + implode(Angels, ", "), this_player() );
 return 1;
}

string GetHelp(string blah) {
  return "Syntax:     \"immortals\"     \n\n"
    "Lists all active Staffmembers of Haven."
    ;
 }

