#include <lib.h>
#include <domains.h>
#include <daemons.h>

int eventFail(object who, object spell) {
  object *victims = ({ who });
  object env = environment(who);
  string destination;
  
  victims = filter(all_inventory(env), (: !$1->isDummy() :) );
  send_messages( ({ }),
    "As $agent_possessive_noun spell fails, a %^BLACK%^BOLD%^rift%^RESET%^ is torn in reality!",
    who, 0, env);
  switch(random(4)) {
  	case 0:
  		destination = DOMAIN_PLANES "virtual/first/" + ( random(20) - random(50)) + "," + ( random(50) - random(50));
  		break;
    case 1:
    	destination = DOMAIN_PLANES "virtual/fire/" + ( random(50) - random(50)) + "," + ( random(50) - random(50));
    	break;
    case 2:
    	destination = DOMAIN_PLANES "virtual/forest/" + ( random(50) - random(50)) + "," + ( random(50) - random(50));
    	break;
    case 3:
  		destination = DOMAIN_PLANES "virtual/first/" + ( random(50) - random(50)) + "," + ( random(50) - random(50));
  		break;
    
    }
   victims->eventMoveLiving(destination, "$N is sucked through the rift!", "$N appears from a rift!");
   if (playerp(who)) CHAT_D->eventSendChannel("FAILURE", "reports", capitalize(who->GetKeyName()) + " got the catastrophic rift failure!");
   return 1;
}