/*    /lib/inventory.c
 *    from the Dead Souls LPC Library
 *    gives a person information about their inventory
 *    created by Descartes of Borg 950412
 */

#include <lib.h>
#include <rounds.h>
#include <vendor_types.h>

inherit LIB_DAEMON;

void eventInventory();
void eventInventoryWorn();
void eventInventoryWielded();
void eventInventoryCarried();
void eventInventoryOther();
void doReturn(string ret);

mixed cmd(string args) {
	if(creatorp(this_player())) {
		args = "";
	}
	if(!args) {
		 eventInventory();
	} else {
	switch(args) {
		case "worn":    eventInventoryWorn();
				break;
		case "carried": eventInventoryCarried();
				break;
		case "wielded": eventInventoryWielded();
				break;
		default:        eventInventory();
				break;
	}
	}
  return 1;
}

void eventInventory() {
    mapping borg;
    string *shorts;
    string ret;
    int i;

    shorts = map(filter(all_inventory(this_player()), 
			(: !((int)$1->GetInvis(this_player())) :)),
		 (: (string)$1->GetEquippedShort() :));
    borg = ([]);
    if( !(i = sizeof(shorts)) ) {
	message("system", "You are carrying nothing.", this_player());
	return;
    }
    if( i == 1 ) ret = "You are carrying just this one item:\n";
    else ret = "You are carrying the following items:\n";
    while(i--) if( shorts[i] ) borg[shorts[i]]++;
    i = sizeof(shorts = keys(borg));
    while(i--) ret += capitalize(consolidate(borg[shorts[i]], shorts[i]))+"\n";
    doReturn(ret);
}

void eventInventoryWorn() {
	string *worn;
	string ret;
	object who = this_player();
	int i;

	worn = filter(all_inventory(this_player()),
			(: !(int)$1->GetClass() && (int)$1->GetWorn() :)); 
	i = sizeof(worn);
	if( !i ) {
		message("system", "You are not wearing anything.", who);
		return;
	}
	if( i == 1 ) ret = "You are wearing just this one item:\n";
	else ret = "You are wearing the following items:\n";

	while(i--) {
		if(who->GetBriefMode()) {
	    worn[i] = worn[i]->GetShort(); 
          } else {
		worn[i] = worn[i]->GetEquippedShort();
	}
	    ret += capitalize(worn[i]) + "\n";
        }
	doReturn(ret);
}
void eventInventoryWielded() {
	mixed *worn;
	mixed *weapons = this_player()->GetWielded();
        string ret;
        object who = this_player();
        int i;

	worn = filter(weapons, (: (string)$1->GetEquippedShort() :));
        i = sizeof(worn);
        if( !i ) {
                message("system", "You are not wielding anything.", who);
                return;
        }
        if( i == 0 ) ret = "You are wielding just this one item:\n";
        else ret = "You are wielding the following items:\n";

        while(i--) {
		if(who->GetBriefMode()) {
            worn[i] = worn[i]->GetShort();
	} else {
	    worn[i] = worn[i]->GetEquippedShort();
	} 
            ret += capitalize(worn[i]) + "\n";
        }
        doReturn(ret);
}

void eventInventoryCarried() {
        string *carried;
        string ret;
        object who = this_player();
        int i;

	debug("doing carried");
        carried = filter(all_inventory(this_player()),
                        (: !((int)$1->GetInvis(this_player())) && !(int)$1->GetWorn() :)); 
        i = sizeof(carried);
        if( !i ) {
                message("system", "You are not carrying anything.", who);
                return;
        }
        if( i == 1 ) ret = "You are carrying just this one item:\n";
        else ret = "You are carrying the following items:\n";

        while(i--) {
            carried[i] = carried[i]->GetEquippedShort();
            ret += capitalize(carried[i]) + "\n";
        }
        doReturn(ret);
}


void doReturn(string ret) {
	object who = this_player();
        message("look", ret, who);
        message("other_action", (string)this_player()->GetName() + " checks " +
            possessive(this_player()) + " possessions.",
            environment(this_player()), ({ this_player() }));
}

void help() {
    message("help", 
	    "Syntax: <inventory>\n"
	    "        <inventory worn>\n"
            "        <inventory wielded>\n"
	    "        <inventory carried>\n\n"	
	    "By default inventory ists all items you are carrying currently.  This command "
	    "will take up one round of combat if you happen to be in "
	    "combat. However, you can specify to view only what is being "
            "worn, wielded, or carried.", this_player());
}
