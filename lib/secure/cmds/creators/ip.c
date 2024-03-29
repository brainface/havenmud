/*  Returns the IP of the offender */
#include <lib.h>
inherit LIB_DAEMON;
inherit LIB_HELP;

mixed cmd(string person) {
  object target;

  if(angelp(this_player())) { return 0; }
  if(!person) {
      return "Query IP of whom?";
      }
  if(!(target = find_player(person))) {
      return "No such person.";
      }
  if(target->GetInvis() > rank(this_player())) {
      return "No such person.";
      }
  if (rank(target) > rank(this_player())) {
  	  return "This person logs in from <private>";
  	  }
  return (capitalize(person) + " logs in from " + 
               query_ip_number(target) );
}

string GetHelp(string a) {
  return ("Syntax:  \"ip PERSON\"  \n\n"
          "Returns the IP number for siteban and such. \n"
          "See also:  register, tempban");
  }
