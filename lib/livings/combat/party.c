/*    /lib/combat.c
 *    from the Dead Souls LPC Library
 *    combat events and data
 *    created by Descartes of Borg 950124
 *    Version: @(#) combat.c 1.40@(#)
 *    Last modified: 96/11/17
 */

#include <lib.h>
#include <rounds.h>
#include <daemons.h>
#include <position.h>
#include <damage_types.h>
#include <function.h>

private static string Party;

string GetName();
mixed GetProperty(string key);
string array AddChannel(mixed val);
string array RemoveChannel(mixed val);
int eventForce(mixed args);

static void create() {
    Party = 0;
}



string SetParty(string str) {
    if( file_name(previous_object()) != PARTY_D ) return Party;
    if( str ) AddChannel(str);
    else RemoveChannel(Party);
    return (Party = str);
}

string GetParty() {
    return Party;
}


static int Destruct() {
    if( GetParty() ) PARTY_D->eventLeaveParty(this_object());
    return 1;
}

