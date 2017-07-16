/* Invader Object
 * Handled interaction with INVASION_D
 * Duuktsaryth@Haven 10-05-97
 */
#include <lib.h>
#include <rooms.h>
#include <daemons.h>
inherit LIB_NPC;
private object invasion;
private string EnemyTown;
object SetInvasionObject(object);
object GetInvasionObject();

static void create() {
  npc::create();
  invasion = 0;
  EnemyTown = 0;
  SetNoClean(1);
  SetProperty("invader", 1);
 }

string SetEnemyTown(string s) { EnemyTown = s; }
string GetEnemyTown()         { return EnemyTown; }

object SetInvasionObject(object arg) {
  return (invasion = arg);
 }

object GetInvasionObject() {
  return (invasion);
 }

varargs int eventDie(object agent) {
  if (agent && EnemyTown) agent->AddReputation(EnemyTown, 1);
  if(GetInvasionObject()) {
    INVASION_D->eventInvaderDied(this_object(), GetInvasionObject());
  if (GetInvasionObject()->GetPlayerTitle()) 
  if(this_object() == GetInvasionObject()->GetLeaderObject()) {
     if (agent) agent->AddTitle(GetInvasionObject()->GetPlayerTitle());
    }
  }
  npc::eventDie(agent);
 }

void heart_beat() {
  ::heart_beat();
  if (!environment()) { 
    eventMove(ROOM_VOID);
    call_out( (: eventDie, this_object() :), 0);
    }
}