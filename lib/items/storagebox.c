/* A storage box
 *
 */
#include <lib.h>
#include <save.h>

inherit LIB_STORAGE;

mixed *BoxInventory =({});
string BoxID;

void LoadBoxInventory();
void SaveBox();

static void create() {
	::create();
	BoxInventory = ({});
	BoxID = 0;
	SetMaxCarry(-1);
	SetCanLock(1);
	SetLocked(1);
  SetLockStrength(100);
	AddSave( ({ "BoxInventory" }) );
}

void heart_beat() {
	if (BoxID) 
	  SaveBox();
}


string SetBoxID(string box) {
	BoxID = box;
	set_heart_beat(10);
	unguarded( (: restore_object, SAVE_BOXES + BoxID :) );
	LoadBoxInventory();
	return BoxID;
}

string GetBoxID() {
	return BoxID;
}

object *GetBoxInventory() {
	return BoxInventory;
}

void SaveBox() {
  if (!environment()) return;
  BoxInventory = filter(map(all_inventory(), (: $1->GetSaveString() :)),
		       (: $1 :));
	unguarded( (: save_object, SAVE_BOXES + BoxID :) );
}

void LoadBoxInventory() {
    if( BoxInventory ) {
        foreach(string obdata in BoxInventory) {
	    object ob;
	    mixed tmp;
	    
            tmp = restore_variable(obdata);
	    if( arrayp(tmp) ) {
		ob = new(tmp[0]);
		if( ob ) ob->eventConvertObject(tmp, 1);
	    }
	    else {
		if( !catch(ob = new(tmp["#base_name#"])) ) {
		    if( ob ) {
			ob->eventLoadObject(tmp, 1);
		    }
		}
	    }
        }
    }
    BoxInventory = 0;
}
