/*    /lib/std/wagon_seller.c
 *    Largely a copy of barkeep
 *    
 *    
 *    
 *    
 */

#include <lib.h>
#include <daemons.h>
 
inherit LIB_NPC;
inherit LIB_BUY;

private string  LocalCurrency = "imperials";
private mapping StableItems     = ([]);

string GetLocalCurrency();
mixed eventSell(object who, string args);

/* ******************* barkeep.c attributes *********************** */
int GetCost(string item) {
    float f = currency_rate(GetLocalCurrency());

    if( !StableItems[item] ) return 0;
    if( f < 0.1 ) f = 1.0;
    return to_int(to_float(StableItems[item]->GetValue()) * f);
}

string GetLocalCurrency() {
    return LocalCurrency;
}
 
string SetLocalCurrency(string str) {
    return (LocalCurrency = str);
}
 
mapping AddStableItem(string item, string file) {
    StableItems[item] = file;
    return StableItems;
}
 
mapping GetStableItems() {
    return StableItems;
}
 
mapping RemoveStableItem(string item) {
    map_delete(StableItems, item);
    return StableItems;
}
 
mapping SetStableItems(mapping mp) {
    return (StableItems = mp);
}

/* *********************** barkeep.c modals ************************ */
int CanCarry(int cmt) {
    return 1;
}

mixed CanSell(object who, string what) {
    if( !StableItems[what] ) {
return "There is no such thing for sale.";
    }
    return buy::CanSell(who, what);
}

/* *********************** barkeep.c events *********************** */
mixed eventBuyItem(object who, string cmd, string args) {
    mixed tmp;
    
    if( !args || args == "" ) {
        eventForce("speak err, what do you want me to sell?");
   
     return 1;
    }
    args = remove_article(lower_case(args));
    tmp = CanSell(who, args);
    if( tmp != 1 ) {
      if( tmp ) {
        who->eventPrint(tmp);
      } else {
        eventForce("speak I cannot sell right now");
      }
      return 1;
    }
    return eventSell(who, args);
}

mixed eventSell(object who, string args) {
    object wagon;
    int x;
    x = GetCost(args);
    if (!environment(this_object())) {
    	eventForce("speak I'm sorry, I'm having trouble telling where I'm at. [OOC: Please send this information in a bug report.]");
    }
    if( x > (int)who->GetCurrency(GetLocalCurrency()) ) {
        eventForce("speak You do not have that much in " + GetLocalCurrency());
        return 1;
    }
    if (who->GetReputation(GetTown()) < -100) {
      eventForce("speak Why would I sell to someone as disliked as you?");
      return 1;
    }
    if( !(wagon = load_object(StableItems[args])) ) {
        eventForce("speak I am having a problem with that item right now.");
        return 1;
    }
    wagon = new(StableItems[args]);
    if( !wagon ) {
        eventForce("speak I seem to be having some troubles.");
        return 1;
    }      
    wagon->SetVehicleName("v"+(time()-1488000000));
    wagon->SetOwner(who->GetKeyName());
    wagon->SetVId(wagon->GetId());
    wagon->eventMoveLiving(environment(this_object()));
    CHAT_D->eventSendChannel("WAGON SALE","reports",
      capitalize(who->GetKeyName()) + " bought a wagon with maker number: " +
        wagon->GetVehicleName() +".");
    VEHICLES_D->AddShip(wagon); //need to change this eventually.    
    send_messages("charge", "$agent_name $agent_verb $target_name " +
                x + " "  + GetLocalCurrency() + " for the wagon.",
                this_object(), who, environment(who) ); 
    who->AddCurrency(GetLocalCurrency(), -x);
    eventForce("speak Thank you for your business, " +
               (string)who->GetName());
    return 1;
}

int eventList(object who, string cmd, string args) {
    string array wares = ({});
    string ware;

    if( !sizeof(keys(StableItems)) ) {
        eventForce("speak I have nothing to sell right now.");
        return 1;
    }
    foreach(ware in keys(StableItems)) {
    string array adjectives = StableItems[ware]->GetAdjectives();
    string adj = "";
    
    if( sizeof(adjectives) ) {
        adj = adjectives[random(sizeof(adjectives))] + " ";       
    }
        wares += ({ ware + " for " + GetCost(ware) }) ;
    }
    eventForce("speak I currently sell " + item_list(wares) + ".");
    eventForce("speak Prices are in " + GetLocalCurrency() + " of course.");
    return 1;
}

/* ********************* barkeep.c driver applies *********************** */
static void create() {
    npc::create();
    SetCommandResponses( ([      
         ({ "list", "show", "browse" }) : (: eventList :),
         ({ "sell" }) : (: eventBuyItem :),
     ]) );
}

void eventGreet(object who) {                                   
  eventForce("speak You could <ask " + GetKeyName() + " to browse> to see a list of "
             "the things I have for sale, or <ask " + GetKeyName() + " to sell> one of the "
             "items I sell.");
}

