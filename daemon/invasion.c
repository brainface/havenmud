/*  A daemon to control invasions.
 * Duuktsaryth 10-03-97
 */
#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

int LastInvasion = 0;
private object *Invasions = ({ });
string GetLastInvasion();
object *AddInvasion(object);
object *GetInvasions();
object *RemoveInvasion(object);
void eventRegisterInvasion(object, object);
void eventStartInvasion(object);
void eventInvaderDied(object who, object inv);
void eventEndInvasion(object);

static void create() {
  daemon::create();
  SetNoClean(1);
}

object *AddInvasion(object inv) {
  return (Invasions += ({ inv }) );
}

object *RemoveInvasion(object inv) {
  Invasions -= ({ inv });
  foreach(object invader in inv->GetInvaderObjects()) {
      invader->eventDestruct();
     }
  inv->eventDestruct();
  return (Invasions);
}

object *GetInvasions() {
  return (Invasions);
}

void eventRegisterInvasion(object invasion, object tripper) {
  LastInvasion = time();
  if (!invasion) return;
  unguarded( (: log_file, "players/invasions", capitalize(tripper->GetKeyName()) + " started " + base_name(invasion) + " " + ctime(time()) + ".\n" :) );
  AddInvasion(invasion);
  if(invasion->GetMessage("announce"))  {
    CHAT_D->eventSendChannel("Invasion Message", "ooc", invasion->GetMessage("announce") );
    eventStartInvasion(invasion);
  }
}

void eventStartInvasion(object invasion) {
  object tmp;
  int num;

  foreach(string npc in keys(invasion->GetInvaders())) {
    num = (invasion->GetInvaders()[npc]);
    while(num) {
      tmp = new(npc);
      if (!tmp) { 
        CHAT_D->eventSendChannel("INVASION_D", "error", "Problem with: " + npc);
        break;
        }
      tmp->eventMove(invasion->GetStartLocation());
      tmp->SetInvasionObject(invasion);
      invasion->AddInvader(tmp);
      num--;
      }
    }
  tmp = new(invasion->GetLeader());
  tmp->SetInvasionObject(invasion);
  tmp->eventMove(invasion->GetStartLocation());
  invasion->AddInvader(tmp);
  invasion->SetLeaderObject(tmp);
}

void eventInvaderDied(object who, object invasion) {
  invasion->RemoveInvader(who);
  if (!sizeof(invasion->GetInvaderObjects())) {
    eventEndInvasion(invasion);
  }
  if (who  == invasion->GetLeaderObject()) {
    if(invasion->GetMessage("leader_died")) {
      CHAT_D->eventSendChannel("Invasion Message", "ooc", 
        invasion->GetMessage("leader_died") );
    }
  }
}

void eventEndInvasion(object invasion) {
  if(invasion->GetMessage("defeated"))  {
    CHAT_D->eventSendChannel("Invasion Message", "ooc", 
      invasion->GetMessage("defeated") );
    call_out( (: RemoveInvasion, invasion :), 5);
  }
}

string GetLastInvasion() {
  return (ctime(LastInvasion));
 }
