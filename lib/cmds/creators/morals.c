/* The morals command
 * Gives a summary of Player Moralaty Information
 * Created by Dylanthalus@Haven
 * Based on Summ created by Duuktsaryth@Haven, modified by Zaxan@Haven
 */

#include <lib.h>

inherit LIB_DAEMON;
inherit LIB_HELP;

private string calculateFormatString(int screenSize);

static void create() {
   help::create();
   SetHelp("Syntax: morals \n\n"
          "Shows a list of all players logged on, \n"
          "including their morality rating and morality \n"
          "description.\n\n"
          "See also:  summ, who, people, where, rpeople");
}

mixed cmd(string arg) {
   object *who;
   string *display = ({ });
   string msg, FormStr;
   string bar;
   int Screen, i, maxi;

   if (angelp(this_player())) {
      return "Summary:  You are an angel.";
   }
   if (!creatorp(this_player())) return 0;
   Screen = this_player()->GetScreen()[0];
   FormStr = calculateFormatString(Screen);
   bar = "";
   for(i=0;i<Screen;i++) {
      bar += "-";
   }
   msg = "\nSummary of player info:";
   msg += "\n"+bar;
   msg += "\nNAME             MORALITY  DESCRIPTION";
   msg += "\n"+bar+"\n";
   who = filter(users(), (: playerp :));
   who = filter(who, (: !($1->GetTestChar()) :) );
   who = filter(who, (: living :));
   display = distinct_array(who);
   maxi = sizeof(display = sort_array(display,"people_sort",this_object()));
   msg += implode(map_array(display, "map_info", this_object(), 
                  FormStr), "\n") + "\n";
   msg += bar;
   message("system", msg, this_player());
   return 1;
}

static int people_sort(object alpha, object beta) {
   int x, y;

   if((x = (int)alpha->GetLevel()) > (y = (int)beta->GetLevel())) {
      return -1;
   }
   else if(x < y) {
      return 1;
   } else {
      return strcmp((string)alpha->GetKeyName(),(string)beta->GetKeyName());
   }
}

private string calculateFormatString(int screenSize) {
   int nomSize = (((screenSize - 21) * 12) / 54);
   int ipSize = (((screenSize - 21) * 18) / 54);
   int envSize = (((screenSize - 21) * 24) / 54);

   if(nomSize < 12) nomSize = 12;
   if(ipSize < 18) ipSize = 18;
   if(envSize < 24) envSize = 24;

   return "%:-5s %:-3s %:-" +
           nomSize+ "s %:-" +
           ipSize+ "s %:-5s %:-3s %:-" +
           envSize+ "s";
}

static string map_info(object ob, string formatString) {
   string name, morality, desc;

  name = capitalize(ob->GetKeyName());
   morality = ob->GetMorality();
   desc = ob->GetMoralityDescription();
   return sprintf("%-16s %-9d %-13s", name, morality, desc);
}
