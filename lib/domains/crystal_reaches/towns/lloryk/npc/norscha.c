#include <lib.h>
#include "../path.h"
#include <vendor_types.h>
inherit LIB_VENDOR;

static void create() {
  vendor::create();
  SetKeyName("norscha");
  SetShort("Norscha Torklerum, Keeper of the Lloryk Commissary");
  SetId( ({ "norscha", "torklerum", "keeper" }) );
  SetAdjectives( ({ "norscha", }) );
  SetLong("Norscha is quite comely as halflings go, and handles "
          "the needs of the Shire. Whenever someone needs anything, "
          "they simply come to Norscha and she is very willing to "
          "assist them.");
  SetMorality(400);
  SetRace("halfling");
  SetClass("rogue");
  SetLevel(18);
  SetGender("female");
  SetVendorType(VT_ALL);
  SetLocalCurrency("rounds");
  SetStorageRoom(LLORYK +"room/gen_strg");
  SetMaxSingleItem(25);
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
