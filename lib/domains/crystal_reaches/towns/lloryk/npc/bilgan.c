// edited by Torak 2013
// this shop owner now gives eclat halflings the commie discount
// and refuses to deal with outsiders.
// like the other shop owners of lloryk

#include <lib.h>
#include <daemons.h>
#include "../path.h"
#include <vendor_types.h>

inherit LIB_VENDOR;

static void create() {
 ::create();
 SetKeyName("Bilgan");
 SetShort("Bilgan, a halfling Shopkeep");
 SetId( ({ "bilgan", "shopkeep", "halfling" }) );
 SetAdjectives( ({ "halfling"}) );
 SetRace("halfling");
 SetGender("male");
 SetClass("merchant");
 SetMorality(-50);
 SetLimit(1);
 SetLevel(20);
 SetLong(
    "Bilgan the shopkeep has a very shady look to him. His "
    "wild black hair stands up in patches near the crown of "
    "his head as if he just woke up from rest. His eyes are "
    "dark brown, which compliment his generic face. "
    "His body appears quite frail but strong enough to last a "
    "bit against violent attackers in his shop."
  );
 SetAction(5, ({
    "!say Welcome to my shop!",
    "!smile warmly",
  }) );
 SetInventory( ([
   LLORYK "obj/smoke/bvest"   : "wear leather vest",
   ]) );
// SetMenuItems( ([
//    "cigar"           : SHOP_OBJ  "cigar",
//    "chai leaf roll"  : SHOP_OBJ  "chaileaf",
//    "wooden pipe"     : SHOP_OBJ  "lpipe",
//    "vodka"           : SHOP_OBJ  "vodka",
//    ]) );
 SetLocalCurrency("rounds");
  SetVendorType(VT_SMOKE);
  SetStorageRoom(LLORYK "room/smoke_strg");
}

int GetCost(object who, object what) {
  return 0;
}

int GetValue(object who, object what) {
  return 0;
}

mixed eventBuy(object who, object array obs) {
    object array tmp;
    object sroom;
    int train;

    sroom = load_object(GetStorageRoom());
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
	value = GetValue(ob, who);
	if( !ob->CanSell(who) ) {
	    eventForce("speak You cannot sell " + ob->GetDefiniteShort() +".");
	    continue;
	}
        eventForce("speak " + ob->GetShort() + "! Excellent!");
        if( !ob->eventMove(sroom) ) {
            eventForce("speak I cannot seem to carry that");
            return 1;
        }
	train = value/100;
	if( train > 100 ) {
	    train = 100;
	}
	who->eventTrainSkill("bargaining", train, GetSkillLevel("bargaining"),
			     1);
	tmp += ({ ob });
	send_messages("give", "$agent_name $agent_verb " + ob->GetShort() +
		      " to $target_name.", who, this_object(),
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

mixed CanSell(object who, string what) {
   if (who->GetRace() != "halfling" || who->GetReligion() != "Eclat") {
    eventForce("speak Sorry, I only deal with Eclat halflings!");
    return 0;
    }
    return ::CanSell(who, what);
}
