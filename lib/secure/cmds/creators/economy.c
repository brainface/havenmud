#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

int cmd(string str) {
    string type, key;
    float rate, infl, wt;

    if( !str ) {
	string *tmp;
	string curr;
	
	tmp = ({ "Currency        Rate" });
	foreach( curr in (string *)ECONOMY_D->__QueryCurrencies() )
          tmp += ({ sprintf("%:-15s %:-7s",
	            curr, currency_rate(curr) + ""  ) });
	this_player()->eventPage(tmp, "system");
	return 1;
    }
    if(!archp(previous_object())) return 0;
    log_file("economy", (string)previous_object()->GetCapName()+": " +
	     str+" ("+ctime(time())+")\n");
    if(sscanf(str, "add %s %f", type, rate) == 2) {
        ECONOMY_D->add_currency(type, rate);
        message("info", "Currency "+type+" added!", this_player());
    }
    else if(sscanf(str, "change %s for %s to %f", key, type, wt) == 3) {
        ECONOMY_D->change_currency(type, key, wt);
        message("info", "Changed: "+key+" for "+type+" to "+wt, this_player());
    }
    else return 0;
    return 1;
}

void help() {
    message("help", "Syntax: <economy add [type] [exchange rate] >\n"
      "        <economy change [what] for [currency] to [value]>\n\n"
      "This allows only approval people to modify the economic settings for "
      "the mud.  The add parameter signifies that the arch intends to add "
      "a new currency to the game.  The change parameter instead signifies "
      "that the arch is changing something in a currenct currency.  Examples:\n"
      "<economy add gold 1.0 0.03 0.1>\n<economy change rate for gold to 1.1>\n"
      "The exchange rate parameter is multiplied by the value of "
      "query(\"value\") in mud objects to give the value in the currency of "
      "an object.  The inflation rate parameter of the add command sets "
      "the percentage rate by which the value of the currency "
      "will inflate (or deflate) over the course of a mud year.  The weight "
      "paramter sets how much one piece of the currency will weigh in "
      "standard mud weight units.  Finally, changing values for current "
      "currencies use the parameters: rate, inflation, weight.", this_player()
    );
}
