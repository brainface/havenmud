/*    /lib/key.c
 *    from the Nightmare V Object Library
 *    handles such things as breaking when someone uses it
 *    created by Descartes of Borg 960121
 */

#include "include/key.h"

private int Disabled, DisableChance;
private string KeyID;

static void create() {
    AddSave(({ "Disabled", "DisableChance", "KeyID" }));
    Disabled = 0;
    DisableChance = 50;
    KeyID = "";
}

mixed indirect_lock_obj_with_obj(object target, object key, string id) {
    if( environment() != this_player() ) return "#You don't have the key!";
    if( GetDisabled() ) return capitalize(GetShort()) + " is broken.";
    else return 1;
}    

mixed indirect_unlock_obj_with_obj(object target, object key, string id) {
    if( environment() != this_player() ) return "#You don't have the key!";
    if( GetDisabled() ) return capitalize(GetShort()) + " is broken.";
    return 1;
}

mixed eventLockLock(object who, string id, object what) { return 1; }

mixed eventUnlockLock(object who, string id, object what) {
    if( GetDisableChance() > random(100) ) {
	SetDisabled(1);
	who->eventPrint(capitalize(GetShort()) + " gets twisted "
			"slightly out of shape as you try to use it..");
	return 1;
    }
    return 1;
}

int SetDisableChance(int x) { return (DisableChance = x); }

int GetDisableChance() { return DisableChance; }

int SetDisabled(int x) { return (Disabled = x); }

int GetDisabled() { return Disabled; }

string SetKeyID(string i) { return KeyID = i; }

string GetKeyID() { return KeyID; }

static mixed *AddSave(mixed *vars) { return ({}); }

