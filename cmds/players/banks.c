/* Banks Command */
#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
        int i, x, y, cols, total, cols2, curr, amt;
        string *lines, *arr, *limbs, *tmp, str, tmp1;
        mapping mp;
        object who = this_player();
        float val;

        if (creatorp(who)) {
                if (!args) {
                        who->eventPrint("List the Bank Information of whom?");
                        return 1;
                }
                if (!(who = find_player(args))) {
                        this_player()->eventPrint("Unable to find such a person, check who next time.");
                        return 1;
                }
        }
        if (creatorp(who))
        {
            this_player()->eventPrint("You think Immortals get payed for this, dream on.");
            return 1;
        }
 if (creatorp(this_player())){        
    cols = ((int *)this_player()->GetScreen())[0];
    cols2 = 15;
    tmp1 = "The bank information of " + (string)who->GetCapName() + ".";
    lines = ({ center(tmp1, cols) });
    total = 0;
    
    lines += explode(format_page(arr, x), "\n") + ({ "", "Banks:" });
    foreach(string bank in who->GetBanks()) {
    	lines += explode(format_page(arr, x), "\n") + ({ " " + bank + ":" });
    	mp = (mapping)who->GetAccountInfo(bank);
    	tmp = filter(keys(mp), (: member_array($1, ECONOMY_D->GetCurrencies()) > -1 :));
        foreach(str in tmp) {
          if( mp[str] < 1 ) continue;
          lines += explode(format_page(arr, x), "\n") + ({ "   " + str 
          	+ ": " + mp[str] });
         if( mp[str] ) {
            if( currency_rate(str) )
            val = mp[str] / currency_rate(str);
            else val = 0;
            if( currency_rate("imperials") )
              total += to_int( val * currency_rate("imperials") );
         }
        }
      lines += ({ "" });   
    }
    lines += explode(format_page(arr, x), "\n");
    lines += ({ (string)who->GetName()+" has amassed a wealth of " +
             total + " imperials in " + possessive(who) + " bank accounts." });
    lines += ({ (string)who->GetName()+" has amassed a net worth of " +
             (int)who->GetNetWorth() + "." });
    arr = filter( map((string *)who->GetCurrencies(),
                 (: ($(who))->GetCurrency($1) &&
                    sprintf("%d %s", ($(who))->GetCurrency($1), $1) :)),
                 (: $1 :));
    lines += ({ "Money on hand: "+implode(arr, ", ") });
     this_player()->eventPage(lines, "system");
    return 1;
 } else {
 	if (!args) args = who->GetKeyName();
 	  cols = ((int *)this_player()->GetScreen())[0];
    cols2 = 15;
    tmp1 = "The bank information of " + (string)who->GetCapName() + ".";
    lines = ({ center(tmp1, cols) });
    total = 0;
    
    lines += explode(format_page(arr, x), "\n") + ({ "", "You have an account at "
    	     "the following banks." });
    foreach(string bank in who->GetBanks()) {
    	lines += explode(format_page(arr, x), "\n") + ({ " " + bank + ":" });
    	mp = (mapping)who->GetAccountInfo(bank);
    	tmp = filter(keys(mp), (: member_array($1, ECONOMY_D->GetCurrencies()) > -1 :));
        foreach(str in tmp) {
          if( mp[str] < 1 ) continue;
          lines += explode(format_page(arr, x), "\n") + ({ "   " + str 
          	+ ": " + mp[str] });
        }
      lines += ({ "" });   
    }
     this_player()->eventPage(lines, "system");
    return 1;
 }
}

string GetHelp(string blah) {
  if( creatorp(this_player()) )
    return "Syntax: <banks [player]>\n\n"
           "This command will list all the banks a player "
           "has an account in as well as the money in those accounts.";
  else
    return "Syntax: <banks>\n\n"
           "This command will display a list of all banks that "
           "you have an account with as well as the money in your "
           "accounts.";
}
