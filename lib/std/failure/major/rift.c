#include <lib.h>
#include <domains.h>
#include <daemons.h>

int eventFail(object who, object spell) {
  object *victims = ({ who });
  object env = environment(who);
  string destination;
  
  send_messages( ({ }),
    "As $agent_possessive_noun spell fails, a %^BLACK%^BOLD%^rift%^RESET%^ is torn in reality!",
    who, 0, env);
  if(env->GetProperty("no teleport")) {
    send_messages( ({ }),
      "The rift immediately %^BOLD%^CYAN%*implodes%^RESET%^ as arcane wards react, sending a shockwave rippling outwards!",
      who, 0, env);    
    victims->eventCollapse();    
    return 1;
  }

  switch(random(4)) {
        case 0:
                destination = DOMAIN_PLANES "virtual/first/" + ( random(20) - random(20)) + "," + ( random(20) - random(20));
                break;
    case 1:
        destination = DOMAIN_PLANES "virtual/fire/" + ( random(20) - random(20)) + "," + ( random(20) - random(20));
        break;
    case 2:
        destination = DOMAIN_PLANES "virtual/forest/" + ( random(50) - random(50)) + "," + ( random(50) - random(50));
        break;
    case 3:
                destination = DOMAIN_PLANES "virtual/upper/" + ( random(20) - random(20)) + "," + ( random(20) - random(20));
                break;

    }
   victims->eventMoveLiving(destination, "$N is sucked through the rift!", "$N appears from a rift!");
   if (playerp(who)) CHAT_D->eventSendChannel("FAILURE", "reports", capitalize(who->GetKeyName()) + " got the major rift failure!");
   return 1;
}

