/* Age command, coded by Durandel@haven
 * Edited by Zedd@Haven to make use of variable invis levels
 * Edited by Laoise to hide whoinvis people - Laoise
 */

#include <lib.h>
inherit LIB_DAEMON;
mixed cmd(string args){
    object ob;
    if(args) {
	int x,days,age2,hours,age3,mins,age4,sec;
	string name;
	ob = find_player(args);
    if( !ob || (rank(this_player()) <= ob->GetInvis()) || ob->GetWhoInvis() ) {
      write("Unable to find anyone by that name.");
                 return 1;
               }
	x = ob->GetAge();
	days = x/86400;
	age2 = x-(days*86400);
	hours = age2/3600;
	age3 = age2-(hours*3600);
	mins = (age3/60);
	age4 = age3-(mins*60);
	sec = age4;
	name = capitalize(args);
	write(""+name+" is:%^BOLD%^%^BLUE%^ "+days+"D "+hours+"h "+mins+"m "+sec+"s%^RESET%^");
        return 1;
    }
    else{
	int x,days,age2,hours,age3,mins,age4,sec;
	x = this_player()->GetAge();
	days = x/86400;
	age2 = x-(days*86400);
	hours = age2/3600;
	age3 = age2-(hours*3600);
	mins = (age3/60);
	age4 = age3-(mins*60);
	sec = age4;
	write("You are:%^BOLD%^%^BLUE%^ "+days+"D "+hours+"h "+mins+"m "+sec+"s%^RESET%^");
        return 1;
    }
}

string GetHelp() {
  return ( "Syntax \"age <user>\" \n\n"
          "returns the age in login time for target." );
 }
