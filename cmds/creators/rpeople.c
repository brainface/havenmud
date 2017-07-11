//
// The 'ips' command
// Gives player's IP Address
// Created by Haun@Haven
//

#include <lib.h>

inherit LIB_DAEMON;
inherit LIB_HELP;

private string calculateFormatString(int screenSize);

static void create() {
   help::create();
   SetHelp("Syntax: <rpeople> \n\n"
           "Returns IP Address Information and OOC Name for all players logged on.\n\n"
           "See also: finger, oocname \n");
}

mixed cmd(string args) {
   object *who;
   string *display;
   string msg, bar, FormStr;
   int i, maxi, Screen;

   if(angelp(this_player())) {
      return "You cannot view player's IP Information!";
   }
   if (!creatorp(this_player())) return 0;
   Screen = this_player()->GetScreen()[0];
   FormStr = calculateFormatString(Screen);
   bar = "";
   for(i=0;i<Screen;i++) {
      bar += "-";
   }
   msg = "\n"+bar;
   msg += "\n"+"%^YELLOW%^BOLD%^Player Name        OOC Name           IP Address "
          "%^RESET%^";
   msg += "\n"+bar+"\n";
   who = filter(users(), (: playerp :) );
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
   return strcmp((string)alpha->GetCapName(),(string)beta->GetCapName());
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
   string name, ipname, oocname;
   string HostSite;

   name = capitalize(ob->GetKeyName());
   ipname = ob->GetHostSite();
   oocname = ob->GetOOCName();
   return sprintf("%-18s %-18s %-20s", name, oocname, ipname);
}
