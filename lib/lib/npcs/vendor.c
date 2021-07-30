/*    /lib/vendor.c
 *    From the Dead Souls LPC Library
 *    The standard vendor npc
 *    created by Descartes of Borg 950522
 *    Version: @(#) vendor.c 1.10@(#)
 *    Last Modified: 97/01/01
 */

#include <lib.h>
#include <daemons.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_SENTIENT;

private static mapping Costs         = ([]);
private static string  LocalCurrency = "ducats";
private static int     MaxItems      = 40;
private static int     MaxSingleItem = 4;
private static string  StorageRoom   = 0;
private static mapping Values        = ([]);
private static int     VendorType    = VT_TREASURE;

string GetLocalCurrency();
int eventBrowse(object who, string args);
mixed eventBuy(object who, object array obs);
int eventPrice(object who, string args);
mixed eventSell(object who, string what);
int eventShowItem(object who, string args);

/* ******************** vendor.c attributes ********************** */
int GetCost(object ob, object who) {
    int cost, mod;
    float comparison;
    // this person has already checked on this object
    if( Costs[who] && !undefinedp(Costs[who][ob]) ) {
	    return Costs[who][ob];
      }
    cost = ob->GetValue();
    mod = who->GetSkillLevel("bargaining");
    if (!mod) mod = 1;
    comparison = GetSkillLevel("bargaining") / mod;
    if (who->GetCharisma() > 35) comparison -= 0.05;
    if (who->GetCharisma() > 50) comparison -= 0.05;
    if (who->GetCharisma() > 75) comparison -= 0.05;
    if (who->GetCharisma() > 100) comparison -= 0.05;
    if (who->GetCharisma() > 115) comparison -= 0.05;
    if (comparison < 1.0) comparison = 1.0;
    if (comparison > 3.0) comparison = 3.0;
    if (who->GetTestChar())  debug("Comp: " + comparison);
    cost = to_int(cost * comparison);
    
    
    cost = to_int(cost * currency_rate(GetLocalCurrency()));
    if (cost < 1) cost = 1;
    if( !Costs[who] ) {
	    Costs[who] = ([ ob : cost ]);
      } else {
	    Costs[who][ob] = cost;
    }
    if (GetSkillLevel("bargaining") > who->GetSkillLevel("bargaining")) {
      who->eventPrint("You're not sure that " + GetCapName() + " is giving you the best of deals.");
    }
    if (GetSkillLevel("bargaining") < who->GetSkillLevel("bargaining")) {
      who->eventPrint("You feel you might be getting a good deal from " + GetCapName() + ".");
    }  
    return cost;
}

int GetValue(object ob, object who) {
    int value, mod;
    float comparison;
    
    if( Values[who] && !undefinedp(Values[who][ob]) ) {
	    return Values[who][ob];
      }
    value = ob->GetValue();
    mod = GetSkillLevel("bargaining");
    if (!mod) mod = 1;
    comparison = who->GetSkillLevel("bargaining") / mod;
    if (who->GetCharisma() > 35) comparison += 0.05;
    if (who->GetCharisma() > 50) comparison += 0.05;
    if (who->GetCharisma() > 75) comparison += 0.05;
    if (who->GetCharisma() > 100) comparison += 0.05;
    if (who->GetCharisma() > 115) comparison += 0.05;
    if (comparison > 1.0) comparison = 1.0;
    if (comparison < 0.1) comparison = 0.1;
    if (who->GetTestChar())  debug("Comp: " + comparison);
    value = to_int(value * comparison);
    
   
    value = to_int(value * currency_rate(GetLocalCurrency()));
    if (value < 1) value = 1;
    if( !Values[who] ) {
	    Values[who] = ([ ob : value ]);
       } else {
	    Values[who][ob] = value;
    }
    if (GetSkillLevel("bargaining") > who->GetSkillLevel("bargaining")) {
      who->eventPrint("You're not sure that " + GetCapName() + " is giving you the best of deals.");
    }
    if (GetSkillLevel("bargaining") < who->GetSkillLevel("bargaining")) {
      who->eventPrint("You feel you might be getting a good deal from " + GetCapName() + ".");
    }
    return value;
}

string GetLocalCurrency() {
    return LocalCurrency;
}

string SetLocalCurrency(string str) {
    return (LocalCurrency = str);
}

int GetMaxItems() {
    return MaxItems;
}

int SetMaxItems(int x) {
    return (MaxItems = x);
}

int GetMaxSingleItem() {
    return MaxSingleItem;
}

int SetMaxSingleItem(int x) {
    return (MaxSingleItem = x);
}

string GetStorageRoom() {
    return StorageRoom;
}

string SetStorageRoom(string room) {
    return (StorageRoom = room);
}

int GetVendorType() {
    return VendorType;
}

int SetVendorType(int x) {
    return (VendorType = x);
}

int GetLastClean() {
  return VENDOR_D->GetVendorTime(this_object());
}

/* ********************* vendor.c modals ******************** */
int CanCarry(int amount) {
    return 1;
}

mixed CanBuy(object who, object *obs) {
    if( !load_object(StorageRoom) ) {
	return "There is a bug with the vendor's storage, please report it.";
    }
    return 1;
}

mixed CanSell(object who, string what) {
    if( !load_object(StorageRoom) ) {
	return "There is a bug with the vendor's storage, please report it.";
    }
    return 1;
}

/* ************************ vendor.c events ********************** */
int eventAppraise(object who, string args) {
    object ob;
    int x;

    if( !args || args == "" ) {
        eventForce("speak appraise what?");
        return 1;
    }
    if( !(ob = present(args = lower_case(args), who)) ) {
        eventForce("speak You have no such thing!");
        return 1;
    }
    if( !((int)ob->GetVendorType() & GetVendorType()) ) {
        eventForce("speak I have no use for " + ob->GetShort());
        return 1;
    }
    x = GetValue(ob, this_player());
    eventForce("speak " + who->GetName() + ", I will offer "
               "you " + x + " " + GetLocalCurrency() + " for " +
               ob->GetDefiniteShort());
    return 1;
}

void eventGreet(object who) {
  eventForce("speak You could <ask " + GetKeyName() + " to> browse, sell, or buy something.");
  who->eventPrint("<help vendors> for more information on using vendors");
}

mixed eventAsk(object who, string str) {
    string cmd, args;
    object array obs;
    object ob;
    mixed tmp;
	if (who->GetReputation(GetTown()) < -100) {
    	eventForce("speak Why would I trade with someone as disliked as you?");
    	return 1;
    }    
    if( !str || str == "" ) {
	eventForce("speak what do you want from me?");
	return 1;
    }
    if( sscanf(str, "%s %s", cmd, args) != 2 ) {
	cmd = str;
	args = 0;
    }
    switch(cmd) {
	case "appraise":
	if( !args ) {
	    eventForce("speak Appraise what?");
	    return 1;
	}
	return eventAppraise(who, args);

	case "browse":
	return eventBrowse(who, args);

	case "buy":
	if( !args ) {
	    eventForce("speak What do you want me to buy?");
	    return 1;
	}
	else if( args == "all" ) {
	    obs = filter(all_inventory(who), (: (int)$1->CanSell() :));
	}
	else {
	    if( !(ob = present(args, who)) ) {
		eventForce("speak I do not understand what you want me to buy!");
		eventForce("shrug " + (string)this_player()->GetKeyName());
		return 1;
	    }
	    obs = ({ ob });
	}
	return eventBuy(who, obs);

	case "price":
        if( !args ) {
	    eventForce("speak the price for what?");
	    return 1;
	}
	return eventPrice(who, args);

	case "sell":
        if( !args ) {
	    eventForce("speak What would you like me to sell?");
	    return 1;
	}
	tmp = CanSell(who, args);
	if( tmp == 1 ) {
	    return eventSell(who, args);
	}
	else if( stringp(tmp) ) {
	    eventForce("speak " + tmp);
	    return 1;
	}
	else {
	    return 0;
	}

	case "show":
        if( !args ) {
	    eventForce("speak what would you like me to show you?");
	    return 1;
	}
	return eventShowItem(who, args);
	
	default:
	eventForce("speak I am not quite sure what you want from me");
	return 1;
    }
}
	
int eventBrowse(object who, string args) {
    object array obs;
    string array list;
    object sroom;
    int i, maxi;

    if( !args ) {
	args = "all";
    }
    if( !(sroom = load_object(StorageRoom)) ) {
        eventForce("speak I am having terrific difficulties today");
        return 1;
    }
    if( !(maxi = sizeof(obs = all_inventory(sroom))) ) {
        eventForce("speak I have nothing to sell right now.");
        return 1;
    }
    list = ({ " #  Description", "" });
    i = this_player()->GetScreen()[0];
    while( i-- ) {
	list[1] += "_";
    }
    for(i=0; i<maxi; i++) {
        int ok;
        int gat;

        ok = 0;
        gat = (int)obs[i]->GetArmourType();
        switch(args) {
            case "all": ok = 1; break;
            case "weapon": case "weapons":
              ok = (gat & A_WEAPON) && ((int)obs[i]->GetClass() > 1);
              break;
            case "armour": case "armours":
              ok = (int)obs[i]->GetProperty("armour");
              break;
            case "bag": case "bags":
              ok = (int)obs[i]->GetProperty("bag");
              break;
            case "ring": case "rings":
              ok = gat & A_RING;
              break;
            case "glove": case "gloves":
              ok = gat & (A_GLOVE | A_LONG_GLOVE);
              break;
            case "boot": case "boots":
              ok = gat & (A_BOOT | A_LONG_BOOT);
              break;
            case "sock": case "socks":
              ok = gat & (A_SOCK | A_LONG_SOCK);
              break;
            case "helm": case "helmet":
              ok = gat & A_HELMET;
              break;
            case "visor": case "visors":
              ok = gat & A_VISOR;
              break;
            case "pants":
              ok = gat & A_PANTS;
              break;
            case "shirt": case "shirts":
              ok = gat & A_SHIRT;
              break;
            case "cloak": case "cloaks":
              ok = gat & A_CLOAK;
              break;
            case "belt": case "belts":
              ok = gat & A_BELT;
              break;
            case "vest": case "vests":
              ok = gat & A_VEST;
              break;
            case "shield": case "shields":
              ok = gat & A_SHIELD;
              break;
            case "body armour": case "body armours":
              ok = gat & A_BODY_ARMOUR;
              break;
            case "blunt": case "knife": case "blade": case "projectile":
            case "blunts": case "knives": case "blades": case "projectiles":
              ok = ((string)obs[i]->GetWeaponType() == args) ||
                (pluralize((string)obs[i]->GetWeaponType()) == args);
              break;
            default:
              ok = (int)obs[i]->id(args);
              break;
        }
        if( !ok ) {
	    continue;
	}
        list += ({ sprintf("%:-3d %s", (i+1), (string)obs[i]->GetShort()) });
    }
    if( !sizeof(list) ) {
        eventForce("frown");
        eventForce("speak I have nothing like that to sell.");
        return 1;
    }
    this_player()->eventPage(list);
    return 1;
}

mixed eventBuy(object who, object array obs) {
    object array tmp;
    object sroom;
    int train;

    sroom = load_object(StorageRoom);
    if( sizeof(all_inventory(sroom)) > GetMaxItems() ) {
        eventForce("speak I am having trouble getting rid of the things I "
		   "have to sell right now.");
        return 1;
    }
    if( !sizeof(obs) ) {
        eventForce("speak you have nothing to sell!");
        return 1;
    }
    tmp = ({});
    foreach(object ob in obs) {
        int value;

	if( !ob->GetShort() ) {
	    continue;
	}
	if( !(ob->GetVendorType() & GetVendorType()) ) {
            eventForce("speak I do not buy things like " +
		       ob->GetShort() + ".");
            continue;
        }
	if (ob->GetWorn())
	{
	    eventForce("speak I cannot buy "+ob->GetDefiniteShort()+" while you "
		    "are using it.");
	    continue;
	}
	value = GetValue(ob, who);
	if( value < 1 ) {
            eventForce("speak " + ob->GetDefiniteShort() + " is worthless!");
            continue;
        }
	if( !ob->CanSell(who) ) {
	    eventForce("speak You cannot sell " + ob->GetDefiniteShort() +".");
	    continue;
	}
        if( sizeof(filter(all_inventory(sroom),
                          (: $1->GetShort() == $(ob)->GetShort() :)))
	    >= MaxSingleItem ) {
            eventForce("speak " + ob->GetDefiniteShort() + " is too " +
                       "common.");
            continue;
        }
        eventForce("speak " + ob->GetShort() + "! Excellent!");
        if( !ob->eventMove(sroom) ) {
            sroom->sell_off();
            eventForce("speak I cannot seem to carry that. Try again in a moment.");
            return 1;
        }
        if( who->AddCurrency(GetLocalCurrency(), value) == -1 ){
            eventForce("speak you cannot carry that much money!");
            ob->eventMove(environment());
            continue;
        }
	train = value/100;
	if( train > 100 ) {
	    train = 100;
	}
	tmp += ({ ob });
	send_messages("sell", "$agent_name $agent_verb " + ob->GetShort() +
		      " to $target_name for " + value + " " + GetLocalCurrency() + ".", who, this_object(),
		      environment(who));
    }
    if( !sizeof(tmp) ) {
	eventForce("speak I am sorry, " + who->GetName() + ", "
		   "that we could not come to a better agreement.");
    }
    else {
	map(tmp, function(object ob) {
                     if( ob->GetDestroyOnSell() ) {
			 ob->eventDestruct();
		     }
		  });
    }
    return 1;
}

int eventPrice(object who, string args) {
    object array obs;
    object ob, sroom;
    int x;

    if( !args || args == "" ) {
        eventForce("speak price what?");
        return 1;
    }
    if( !(sroom = load_object(StorageRoom)) ) {
        eventForce("speak today is not really a good day for me");
        return 0;
    }
    obs = all_inventory(sroom);
    if( x = to_int(args) ) {
        if( x < 1 || x > sizeof(obs) ) {
	    ob = 0;
	}
        else {
	    ob = obs[x-1];
	}
    }
    else {
	ob = present(args = lower_case(args), sroom);
    }
    if( !ob ) {
        eventForce("speak I have no such thing!");
        return 1;
    }
    if( !(x = GetCost(ob, this_player())) ) {
        eventForce("speak that thing has no value!");
        return 1;
    }
    eventForce("speak " + who->GetName() + ", I will take " +
               x + " " + GetLocalCurrency() + " for " +
               ob->GetDefiniteShort());
    return 1;
}

mixed eventSell(object who, string what) {
    object ob, sroom;
    int cost, train;
    
    sroom = load_object(StorageRoom);
    if( !(ob = present(what, sroom)) ) {
        eventForce("speak I have nothing like that to sell");
        return 1;
    }
    cost = GetCost(ob, who);
    if( (int)who->GetCurrency(GetLocalCurrency()) < cost ) {
        eventForce("speak " + ob->GetShort() + " would cost " + cost + " " + GetLocalCurrency() + ", which you don't have!");
        return 1;
    }
    if( !((int)ob->eventMove(this_object())) ) {
	message("error", "An error occurred moving the object, use bug -r.",
		who);
	return 1;
    }
    eventForce("speak here is " + (string)ob->GetShort() + " for " + cost +
               " " + GetLocalCurrency() + "!");
    ob->eventMove(who);
    if( environment(ob) == this_object() ) {
        eventForce("speak you cannot carry that!");
	  ob->eventMove(environment());
    }
    train = cost/100;
    if( train > 100 ) {
	train = 100;
    }
    who->eventTrainSkill("bargaining", train, GetSkillLevel("bargaining"), 1);
    who->AddCurrency(GetLocalCurrency(), -cost);
    return 1;
}

int eventShowItem(object who, string args) {
    object ob, sroom;
    int x;

    if( !args || args == "" ) {
        eventForce("speak show you what?");
        return 1;
    }
    if( !(sroom = load_object(StorageRoom)) ) {
        eventForce("speak I am having troubles right now");
        return 1;
    }
    if( x = to_int(args) ) {
        object array obs;
     
        x--;
        obs = all_inventory(sroom);
        if( x >= sizeof(obs) || x < 0 )  { ob = 0; } else { ob = obs[x]; }
	  } else {
	    ob = present(args = lower_case(args), sroom);
      }
    if( !ob ) {
        eventForce("speak I have no such thing to show you");
        return 1;
    }
    who->eventPrint(GetName() + " shows you " + ob->GetDefiniteShort() + ".");
    ob->eventShow(who);
    return 1;
}

/* ********************* vendor.c driver applies ****************** */
mixed direct_buy_str_from_liv(string str) { 
    return CanSell(this_player(), remove_article(lower_case(str))); 
}

mixed direct_sell_liv_obj() {
    return 1;
}

mixed indirect_sell_obj_to_liv() {
    return 1;
}

void heart_beat() {
  object sroom;
  ::heart_beat();
  VENDOR_D->eventReset(this_object());
}
